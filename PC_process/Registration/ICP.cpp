#include <iostream>
#include <opencv2/opencv.hpp>
#include <Eigen/eigen>

using namespace cv;
using namespace std;

void calNearestPointPairs(Eigen::Matrix3f R, Eigen::Vector3f t,
                          vector<Point3f>& pts1, vector<Point3f>& pts2,
                          vector<Point3f>& outPoints, vector<float> &error)
{
	outPoints.clear();
	error.clear();
	int num = pts1.size();

	// 对目标点云进行变换
	for (int i = 0; i < num; i++) {
		float x = Eigen::Vector3f(R(0, 0), R(0, 1), R(0, 2)).transpose() * Eigen::Vector3f(pts2[i].x, pts2[i].y, pts2[i].z) + t[0];
		float y = Eigen::Vector3f(R(1, 0), R(1, 1), R(1, 2)).transpose() * Eigen::Vector3f(pts2[i].x, pts2[i].y, pts2[i].z) + t[1];
		float z = Eigen::Vector3f(R(2, 0), R(2, 1), R(2, 2)).transpose() * Eigen::Vector3f(pts2[i].x, pts2[i].y, pts2[i].z) + t[2];
		
		pts2[i] = Point3f(x, y, z);
	}

	// 计算最邻近点对
	for (int i = 0; i < num; i++) {
		float min_dist = std::numeric_limits<float>::max();
		int index = 0;
		for (int j = 0; j < num; j++) {
			float dist = sqrt(pow(pts2[i].x - pts1[j].x, 2) + pow(pts2[i].y - pts1[j].y, 2) + pow(pts2[i].z - pts1[j].z, 2));
			if (dist < min_dist) {
				min_dist = dist;
				index = j;
			}
		}
		error.push_back(min_dist);
		outPoints.push_back(pts1[index]);
	}
}

void ICP(vector<Point3f> &src,  vector<Point3f> &target) {
	int N = src.size();

	float err = 1.0;
	Eigen::Matrix3f R_12;
	R_12 << 1, 0, 0, 0, 1, 0, 0, 0, 1;
	Eigen::Vector3f t_12;
	t_12[0] = 0;
	t_12[1] = 0;
	t_12[2] = 0;
	Eigen::Matrix4f H_12;
	H_12 << R_12(0, 0), R_12(0, 1), R_12(0, 2), t_12[0],
		    R_12(1, 0), R_12(1, 1), R_12(1, 2), t_12[1],
		    R_12(2, 0), R_12(2, 1), R_12(2, 2), t_12[2],
		    0, 0, 0, 1;

	vector<Point3f> pts1_match;
	vector<float> error;

	Eigen::Matrix3f R_final = R_12;
	Eigen::Vector3f t_final = t_12;
	Eigen::Matrix4f H_final = H_12;

	while (err > 0.001)
	{
		cout << "==================" << endl;
		// 计算最邻近点对
		pts1_match.clear();
		error.clear();
		calNearestPointPairs(R_12, t_12, pts1, pts2, pts1_match, error);
 
		// 计算点云中心坐标
		Point3f p1, p2;
		p1.x = 0;
		p1.y = 0;
		p2.x = 0;
		p2.y = 0;
		err = 0.f;
		for (int i = 0; i < N; i++)
		{
			p1 += pts1_match[i];
			p2 += pts2[i];
			err += error[i];
		}
		p1 = Point3f(Vec3f(p1) / N);
		p2 = Point3f(Vec3f(p2) / N);
		err = err / N;

		// 去中心化
		vector<Point3f> q1(N), q2(N);
		for (int i = 0; i < N; i++)
		{
			q1[i] = pts1_match[i] - p1;
			q2[i] = pts2[i] - p2;
		}

		// compute q1*q2^T
		Eigen::Matrix3f W = Eigen::Matrix3f::Zero();
		for (int i = 0; i < N; i++)
		{
			W += Eigen::Vector3f(q1[i].x, q1[i].y, q1[i].z) * Eigen::Vector3f(q2[i].x, q2[i].y, q2[i].z).transpose();
		}

		// SVD on W
        // 得到 UsigmaVT
		Eigen::JacobiSVD<Eigen::Matrix3f> svd(W, Eigen::ComputeFullU | Eigen::ComputeFullV);
		Eigen::Matrix3f U = svd.matrixU();
		Eigen::Matrix3f V = svd.matrixV();

        // 结果就是 UVT
		R_12 = U* (V.transpose());
		t_12 = Eigen::Vector3f(p1.x, p1.y, p1.z) - R_12 * Eigen::Vector3f(p2.x, p2.y, p2.z);

		H_12 << R_12(0, 0), R_12(0, 1), R_12(0, 2), t_12[0],
			    R_12(1, 0), R_12(1, 1), R_12(1, 2), t_12[1],
			    R_12(2, 0), R_12(2, 1), R_12(2, 2), t_12[2],
			    0, 0, 0, 1;
		
		//H_final = H_12*H_final; //更新变换矩阵
		//cout << H_final << endl;

		R_final = R_12 * R_final;  //更新旋转矩阵
		t_final = R_12 * t_final + t_12; //更新平移矩阵
		cout << R_final << endl;

		// 验证
		Eigen::AngleAxisf R_21;
		R_21.fromRotationMatrix(R_final.transpose());
		cout << "aix: " << R_21.axis().transpose() << endl;
		cout << "angle: " << R_21.angle() * 180 / CV_PI << endl;
		cout << "t: " << -t_final.transpose()/*(-R_final.transpose()*t_final).transpose()*/ << endl;
	}
}

void readTxt(string file, vector<Eigen::Vector3f> &srcPoints)
{
	ifstream fin(file, ios::in);
	if (!fin) {
		printf("The file is not exist!");
		return;
	}
 
	Eigen::Vector3f sp;
	while (!fin.eof())
	{
		fin >> sp[0] >> sp[1] >> sp[2];
		srcPoints.push_back(sp);
	}
 
	fin.close();
	return;
}
 
// ICP仿真
void main()
{
	string file = "..\\satellite.txt";
	vector<Eigen::Vector3f> srcPoints;
	readTxt( file, srcPoints);
 
	Eigen::AngleAxisf rotation_vector((5 * CV_PI / 180), Eigen::Vector3f(0, 1, 0));//绕y轴逆时针旋转5度
	Eigen::Matrix<float, 3, 3> R21 = rotation_vector.toRotationMatrix();
	cout << "R21: " << endl << R21 << endl;
	Eigen::Vector3f t21(1, 2, -1);
 
	vector<Eigen::Vector3f> targetPoints;
	Eigen::Vector3f tp;
	for (int n = 0; n < srcPoints.size(); n++)
	{
		tp = R21*srcPoints[n] + t21;
		targetPoints.push_back(tp);
	}
 
	vector<Point3f> p_c1, p_c2;
	for (int n = 0; n < srcPoints.size(); n++)
	{
		p_c1.push_back(Point3f(srcPoints[n][0], srcPoints[n][1], srcPoints[n][2]));//构造源点云
		p_c2.push_back(Point3f(targetPoints[n][0], targetPoints[n][1], targetPoints[n][2]));//构造目标点云：源点云绕y轴逆时针旋转5度(转yaw)，并平移t21
	}
 
	ICP(p_c1, p_c2);
 
	cout << "done!" << endl;
	getchar();
}