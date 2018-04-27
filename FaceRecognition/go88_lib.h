#ifndef GO88_LIB_H
#define GO88_LIB_H

#include "opencv2/opencv.hpp"
#include <iostream>
#include <fstream>
#include <io.h>

#include "my_proto.MsgCom.pb.h"

using namespace cv;
using namespace std;


namespace my_ocv_project_common_180418 {


	// Common 公共的环境常量和变量
	class Com {
	public:
		// 得到 instance 实例 单例模式
		static Com* INS();

		// 序列化路径
		static const string PROTO_PATH;
		// 人脸图片路径
		static const string FACES_FOLDER;

		// 序列化 路径为 PROTOPATH
		int serialization();
		// 反序列化
		int un_serialization();

		// 得到人物数量
		int get_num();

		// 设置人物数量
		void set_num(int num);

		// 通过人物名字得到人物的分类id
		int get_id(string name);

		// 设置人物的分类id
		string get_name(int id);

		// 得到一个人物的图片index，从1开始
		int get_index(string name);

		// 设置一个人物的图片index
		int set_index(string name, int index);

		// 是否存在人物的名字
		int is_exist_name(string name);

		// 是否存在此分类id
		int is_exist_id(int id);

		// 人物，key:id val:name 键值对
		map<int, string>& get_id_name();

		// 人物名字和图片index
		map<string, int>& get_name_index();

		// 照片路径和标签
		vector<string>& get_img_lb();

		// cascade 模板文件路径
		string get_cascade_path();

	private:
		//单例模式构造函数私有
		Com();

		// 单例实例指针
		static Com* _instance;

		// 人物数量
		// 序列化：proto  int32
		int _int_num;

		// 人物名字，key:id val:name 键值对
		// 序列化：proto 中用一个string储存 "{0;id0}{1;id1}{2;id2}"
		map<int, string> _map_id_name;

		// 人物名字和图片数量，key:name val:index 目录下面最后一张图片的序号
		// 序列化：proto 中用一个string储存 "{name0;8}{name1;3}{name2;9}"
		map<string, int> _map_name_index;

		// 照片路径和标签 img1;0
		// 序列化：proto 中用一个string储存 "{img1;0}{img2;0}{img3;1}"
		vector<string> _vct_images_labels;

		// cascade 模板文件路径
		// 序列化：proto string
		string _str_cascade_path;
	};
}

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

#endif // !GO88_LIB_H