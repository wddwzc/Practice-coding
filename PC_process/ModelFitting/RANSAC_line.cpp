#include <iostream>
#include <random>
#include <algorithm>
#include <ctime>
#include <bits/stdc++.h>
using namespace std;

class Point
{
public:
    Point() {
        x = 0;
        y = 0;
    }
    Point(const Point & p) {
        x = p.x;
        y = p.y;
    }
    Point(double x_, double y_) {
        x = x_;
        y = y_;
    }
    ~Point() {};
    double norm() {
        return sqrt(x * x + y * y);         
    }
    double dot(Point &vec) {
        double ret;
        ret = vec.x * x + vec.y * y;
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
        return ret;
    }
    double x;
    double y;
};

// ransac拟合直线
void ransac(const vector<Point> &data, vector<Point> &inlier, vector<Point> &outlier){
    float sigma = 2.0;
    size_t num_iter = 100;
    int pre_total_inliner = 0.0;
    
    Point best_n(0.0, 0.0);
    Point best_p(0.0, 0.0);
    size_t sz = data.size();
    vector<Point> best_in;

    for(size_t i = 0; i < num_iter; ++i){
        size_t index1 = rand() % sz;
        size_t index2;
        do {
            index2 = rand() % sz;
        } while (index1 == index2);

        // 选出采样点
        Point p1(data[index1]);
        Point p2(data[index2]);
        // 当前line的法向量
        Point n(p1.y - p2.y, p2.x - p1.x);
        // cout << "Point1:" << p1.x << " " << p1.y << "  Point2:" << p2.x << " " << p2.y << endl;
        // cout << "Selected:" << index1 << " " << index2 << "  norm:" << n.x << " " << n.y << endl;
        double k = (p1.y - p2.y) / (p1.x - p2.x);
        double b = p1.y - k * p1.x;
        cout << "K:  " << k << endl;
        cout << "B:  " << b << endl;

        int num_inliners = 0;

        vector<Point> pt_inlier;
        for(size_t j = 0; j < sz; ++j){
            Point cur_p(data[sz]);
            cur_p = cur_p - p1;
            if(fabs(n.cross(cur_p).norm() / n.norm()) < sigma) {
                pt_inlier.push_back(cur_p);
                num_inliners++;
            }
        }

        if(num_inliners > pre_total_inliner){
            best_n = n;
            best_p = p1;
            pre_total_inliner = num_inliners;
            best_in = pt_inlier;
        }
    }

    for(size_t j = 0; j < sz; ++j){
        Point cur_p(data[sz]);
        cur_p = cur_p - best_p;
        if(abs(best_n.dot(cur_p)) / best_n.norm() < sigma){
            inlier.push_back(data[sz]);
        }
        else {
            outlier.push_back(data[sz]);
        }
    }
    cout << "Best normalization:" << best_n.x << "---" << best_n.y << endl;
    cout << "Best inlier ratio:" << (float)inlier.size() / (float)sz << endl;

    size_t best_sz = best_in.size();
    double xy_mean = 0, x_mean = 0, y_mean = 0, x2_mean = 0;
    for (auto &p : best_in) {
        xy_mean += p.x * p.y;
        x_mean += p.x;
        y_mean += p.y;
        x2_mean += p.x * p.x;
    }
    xy_mean /= best_sz;
    x_mean /= best_sz;
    y_mean /= best_sz;
    x2_mean /= best_sz;
    int k = (xy_mean + x_mean * y_mean) / (x2_mean - x_mean * x_mean);
    int bbb = y_mean - k * x_mean;

}


int main() {
    // 直线方程 y = ax + b
    double a = -2.5, b = 10.4;

    // 随机产生数据
    // 生成 inlier
    srand((int)time(0));
    double noise, cur_x;
    vector<Point> data;
    cout << "Inlier" << endl;
    for (int i = 0; i < 100; ++i) {
        Point cur_point;
        cur_x = (double)(rand() % 100);
        cur_point.x = cur_x;
        noise = (double)(rand() % 100) / 200.0;
        cur_point.y = a * cur_x + b + noise;
        data.push_back(cur_point);
        cout << "(" << cur_point.x << "," << cur_point.y << ")";
    }
    // 生成 outlier
    cout << endl << "outlier" << endl;
    for (int i = 0; i < 20; ++i) {
        Point cur_point;
        cur_point.x = (double)(rand() % 100);
        cur_point.y = (double)(rand() % 100);
        data.push_back(cur_point);
        cout << "(" << cur_point.x << "," << cur_point.y << ")";
    }
    cout << endl;

    vector<Point> inlier;
    vector<Point> outlier;
    ransac(data, inlier, outlier);
    cout << inlier.size() << endl;
    cout << outlier.size() << endl;
    system("pause");
    return 0;
}