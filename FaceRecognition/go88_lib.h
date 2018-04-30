#pragma once

#include "opencv2/opencv.hpp"
#include <iostream>
#include <io.h>


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
		// 读取 csv 文件，转换为 Mat 和 label 传递为引用类型

		// 特征归一化，将图片范围变为0-255 uint8类型
		static Mat NORM(InputArray input);

		// 图片预处理函数
		// 输入：从 capture >> frame 得到的frame
		//		 model_path 使用的 xml 文件路径
		// 输出：是否有正确的人脸
		// 引用：vector<Mat> faces 人脸图像
		//		 vector<Rect> rects 人脸图像在 frame 的位置 Rect
		static int PRETREATMENT(Mat frame, vector<Mat>& faces, vector<Rect> & rects, string model_path);
	};
}
