#pragma once

#include "opencv2/opencv.hpp"
#include "facedetect-dll.h"

#include <iostream>
#include <io.h>		// _access() 函数头文件


using namespace cv;
using namespace std;


namespace go88 {


	// 自定义工具类
	class Utils {
	public:
		template<typename Out>
		static void SPLIT(const string s, char delim, Out result);

		// 字符串分割函数
		static vector<string> SPLIT(const string s, char delim);

		// 判断路径是否存在，文件和目录都可以判断
		static int IS_EXIST_PATH(string path);

		// 从路径中获得文件夹路径
		static string GET_FOLDER(string path);

		// 使用system md 命令创建文件，可以多级目录
		static int CREATE_FOLDER(string folder_path);

		// 用os命令获取目录下文件数量
		static int GET_FILES_NUM(string dir, string cach_path = "tempCMD.dat");

		// 读取 CSV 文件
		// 返回 vector<vector<string>>
		// 外面的 vector[i] 代表一行
		// 里面的 vector[i] 代表一列
		static vector<vector<string>> READ_CSV(const string& file_name, char separator = ';');

		// 特征归一化，将图片范围变为0-255 uint8类型
		static Mat NORM(InputArray input);

		// 图片预处理函数
		// 输入：从 capture >> frame 得到的frame
		// 输出：是否有正确的人脸
		// 引用：vector<Mat> faces 人脸图像
		//		 vector<Rect> rects 人脸图像在 frame 的位置 Rect
		static int PRETREATMENT(Mat frame, vector<Mat>& faces, vector<Rect> & rects);

		// 人脸检测函数
		// 对 libfacedetect 中 facedetect_multiview 函数进行封装
		//		float scale,	scale factor for scan windows
		//		int min_neighbors,	how many neighbors each candidate rectangle should have to retain it
		//		int min_object_width,	Minimum possible face size. Faces smaller than that are ignored.
		//		int max_object_width = 0,	Maximum possible face size. Faces larger than that are ignored. It is the largest posible when max_object_width=0.
		//		int doLandmark = 0	landmark detection
		static void FACEDETECT_MULTIVIEW(Mat &frame_gray, vector<Rect> &face_rects, float scale = 1.1f,
			int min_neighbors = 3, int min_object_width = 48, int max_object_width = 0, int doLandmark = 0);
	};
}
