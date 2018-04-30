#pragma once

#include "opencv2/opencv.hpp"
#include "tinyxml2.h"

#include "go88_lib.h"


using namespace cv;
using namespace std;
using namespace tinyxml2;


namespace project_common {


	// Common 公共的环境常量和变量
	class Com {
	public:
		// 得到 instance 实例 单例模式
		static Com* INS();

		// 序列化路径
		static const string SERIALIZATION_PATH;
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
		// 序列化：xml <num>"?"</num>
		int _int_num;

		// 人物名字，key:id val:name 键值对
		// 序列化：xml <id_name>
		//					<id_name_pair>
		//						<id>?</id>
		//						<name>?</name>
		//					</id_name_pair>
		//			   </id_name>
		map<int, string> _map_id_name;

		// 人物名字和图片数量，key:name val:index 目录下面最后一张图片的序号
		// 序列化：xml <name_index>
		//					<name_index_pair>
		//						<name>?</name>
		//						<index>?</index>
		//					</name_index_pair>
		//			   </name_index>
		map<string, int> _map_name_index;

		// 照片路径和标签 img1;0
		// 序列化：xml <images_labels>
		//					<images_labels_pair>
		//						"img_src":0
		//					</name_index_pair>
		//			   </images_labels>
		vector<string> _vct_images_labels;

		// cascade 模板文件路径
		// 序列化：xml <cascade_path>
		//					"path"
		//			   </cascade_path>
		string _str_cascade_path;
	};
}