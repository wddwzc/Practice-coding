#include <iostream>
#include <fstream>
#include <random>
#include <cmath>
#include <algorithm>
#include <vector>
#include <time.h>

using namespace std;


class Point
{
public:
    Point() {
        x = 0;
        y = 0;
        z = 0;
    }
    Point(const Point &p) {
        x = p.x;
        y = p.y;
        z = p.z;
    }
    Point(double x_, double y_, double z_) 
        : x(x_), y(y_), z(z_)  { }
    ~Point() {};
    double norm() {
        return sqrt(x * x + y * y + z * z);
    }
    double dot(Point &vec) {
        double ret;
        ret = vec.x * x + vec.y * y + vec.z * z;
        return ret;
    }
    Point cross(Point &vec) {
        Point ret;
        ret.x = y * vec.z - z * vec.y;
        ret.y = z * vec.x - x * vec.z;
        ret.z = x * vec.y - y * vec.x;
        return ret;
    }
    
    Point operator-(Point &p) {
        Point ret;
        ret.x = x - p.x;
        ret.y = y - p.y;
        ret.z = y - p.z;
        return ret;
    }
    double x, y, z;
};



double distance(const Point &p1,const Point &p2){
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
}

void KMeans(const pcl::PointCloud<pcl::PointXYZ>::Ptr pt,const int k = 3){
    const size_t num_iter = 100;

    static std::random_device seed;
    static std::mt19937 random_number_generator(seed());
    std::uniform_int_distribution<size_t> indices(0, pt->points.size() - 1);

    std::vector<pcl::PointXYZ> means;
    for(size_t i=0;i<k;++i){
        means.push_back(pt->points[indices(random_number_generator)]);
    }

    
    std::vector<size_t> labels(pt->points.size());
    for(size_t i=0;i<num_iter;++i){
        for(size_t p=0;p<pt->points.size();++p){
            double best_dist = std::numeric_limits<double>::max();
            int best_cluster = 10;
            for(size_t cluster=0;cluster<k;++cluster){
                double dist = distance(pt->points[p],means[cluster]);
                if(dist<best_dist){
                    best_dist = dist;
                    best_cluster = cluster;
                }
            }
            labels[p] = best_cluster;
        }
    }

    std::vector<size_t> counts(k,0);
    for(size_t p=0;p<pt->points.size();++p){
        const auto cluster = labels[p];
        means[cluster].x += pt->points[p].x;
        means[cluster].y += pt->points[p].y;
        means[cluster].z += pt->points[p].z;
        counts[cluster]+=1;
    }

    for(size_t cluster=0;cluster<k;++cluster){
        means[cluster].x /= counts[cluster];
        means[cluster].y /= counts[cluster];
        means[cluster].z /= counts[cluster];
    }


    // visualization of k-means
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer(new pcl::visualization::PCLVisualizer("3D Viewer"));

    for(size_t cluster=0;cluster<k;++cluster){
        const pcl::PointCloud<pcl::PointXYZ>::Ptr res(new pcl::PointCloud<pcl::PointXYZ>);
        for(size_t i=0;i<pt->points.size();++i){ 
            if(labels[i]==cluster){
                res->points.push_back(pt->points[i]);
            }
        }
        pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> single_color(res,int(255/k*(cluster+1)), int(255/k*(cluster+1)), 150); 
        viewer->addPointCloud<pcl::PointXYZ>(res, single_color,"scene"+std::to_string(cluster));  
        
    }

}   

// ransac to segment ground
// sigma 内点阈值
// outlier 外点比例(大概)
// prob 至少一次good sample的概率
// sample_n 模型拟合最少采样
// iter_N 迭代次数
void ransac(vector<Point> &pointcloud,
            vector<Point> &ground,
            vector<Point> &scene,
            double sigma = 0.1,
            double outlier = 0.5,
            double prob = 0.99,
            int sample_n = 3,
            int iter_N = 100
            ) {
    
    iter_N = log(1 - prob) / log(1 - pow(1 - outlier, sample_n));
    int pre_total_inliner = 0.0;
    
    Point best_p(0.0, 0.0, 0.0);
    double best_d = 0.0;
    size_t sz = pointcloud.size();

    srand(time(NULL));
    for(size_t i = 0; i < iter_N; ++i){
        size_t index1 = rand() % sz;
        size_t index2 = rand() % sz;
        size_t index3 = rand() % sz;
        while (index1 == index2) {
            index2 = rand() % sz;
        }
        while (index3 == index1 || index3 == index2) {
            index3 = rand() % sz;
        }

        Point p1(pointcloud[index1]);
        Point p2(pointcloud[index2]);
        Point p3(pointcloud[index3]);

        Point v1 = p3 - p1;
        Point v2 = p2 - p1;

        Point abc = v1.cross(v2);
        double d = abc.dot(p1);

        int num_inliners = 0;

        for(size_t j = 0; j < sz; ++j){
            Eigen::Vector3f p(pt->points[j].x, pt->points[j].y, pt->points[j].z);
            if(abs((abc.dot(p) - d) / abc.norm()) < sigma){
                num_inliners++;
            }
        }

        if(num_inliners > pre_total_inliner){
            best_p = abc;
            best_d = d;
            pre_total_inliner = num_inliners;
        }
    }

    for(size_t j=0;j<sz;++j){
        Eigen::Vector3f p(pt->points[j].x,pt->points[j].y,pt->points[j].z);
        if(abs((best_abc.dot(p)-best_d)/best_abc.norm())<sigma){
            ground->points.push_back(pt->points[j]);
        }else{
            scene->points.push_back(pt->points[j]);
        }
    }
    
}



int main (int argc, char** argv){
    const std::string in_file("../000000.bin");
    // load point cloud
    std::fstream input(in_file.c_str(), std::ios::in | std::ios::binary);
    if(!input.good()){
        std::cerr << "Could not read file: " << in_file << std::endl;
        exit(EXIT_FAILURE);
    }
    input.seekg(0, std::ios::beg);

    pcl::PointCloud<pcl::PointXYZ>::Ptr points (new pcl::PointCloud<pcl::PointXYZ>);
    for (int i=0; input.good() && !input.eof(); i++) {
        pcl::PointXYZ point;
        input.read((char *) &point.x, 3*sizeof(float));
        char intensity;
        input.read((char *) &intensity, sizeof(float));
        points->push_back(point);
    }

    input.close();

    // visualize pointCloud
    // visualization(points);

    pcl::PointCloud<pcl::PointXYZ>::Ptr ground(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr scene(new pcl::PointCloud<pcl::PointXYZ>);
    ransac(points,ground,scene);

    //visualize scene and ground
    // visualization(ground,scene);

    KMeans(scene,5);

    return 0;
}
