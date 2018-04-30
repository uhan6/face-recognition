#include "opencv2/opencv.hpp"

#include "proj_com.h"
#include "go88_lib.h"

using namespace cv;
using namespace std;
using namespace project_common;

int create_new_face();
int check_face();


int init() {
	{
		using namespace go88;
		// 如果路径不存在，创建目录，把默认INS进行序列化 存储
		if (!Utils::IS_EXIST_PATH(Com::INS()->SERIALIZATION_PATH)) {
			Utils::CREATE_FOLDER(Utils::GET_FOLDER(Com::INS()->SERIALIZATION_PATH));
			Com::INS()->serialization();
		}
		else {
			// 路径存在就反序列化
			Com::INS()->un_serialization();
		}

	}
	return 0;
}


int face_recognition() {

	init();

	int c = 0;
	while (c != 2) {
		cout << "新增人脸：0；检测人脸：1；退出：2；" << endl;
		cin >> c;

		if (c == 0) {
			create_new_face();
		}
		else if (c == 1) {
			check_face();
		}
	}
	return 0;
}
