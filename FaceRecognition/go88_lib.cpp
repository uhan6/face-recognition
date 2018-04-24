#include "go88_lib.h"


namespace my_ocv_project_common_180418 {


	Com::Com() {
		this->_int_num = 0;
		this->_str_cascade_path = "res\\haarcascade_frontalface_alt.xml";
	}


	// Com 类中成员、变量初始化
	Com* Com::INS() {
		if (Com::_instance == NULL) {
			_lock_locales();
			//lock()
			//if (Com::instance == NULL) {
			Com::_instance = new Com();
			//}
			//unlock()
			_unlock_locales();
		}
		return Com::_instance;
	}


	Com* Com::_instance = NULL;

	const string Com::PROTO_PATH = "D:\\opencv_faces\\common.dat";
	const string Com::FACES_FOLDER = "D:\\opencv_faces\\";


	int Com::serialization() {

		string str_id_name = "";
		map<int, string>::iterator iter;
		for (iter = _map_id_name.begin(); iter != _map_id_name.end(); iter++) {
			str_id_name.append("{");
			str_id_name.append(to_string(iter->first) + ";" + iter->second);
			str_id_name.append("}");
		}

		string str_name_index = "";
		map<string, int>::iterator iter2;
		for (iter2 = _map_name_index.begin(); iter2 != _map_name_index.end(); iter2++) {
			str_name_index.append("{");
			str_name_index.append(iter2->first + ";" + to_string(iter2->second));
			str_name_index.append("}");
		}

		string str_images_labels = "";
		for (int i = 0; i < _vct_images_labels.size(); i++) {
			str_images_labels.append("{");
			str_images_labels.append(_vct_images_labels[i]);
			str_images_labels.append("}");
		}

		my_proto::MsgCom msg_com;
		msg_com.set_num(this->_int_num);
		msg_com.set_id_name(str_id_name);
		msg_com.set_name_index(str_name_index);
		msg_com.set_images_labels(str_images_labels);
		msg_com.set_cascade_path(this->_str_cascade_path);

		// 储存
		fstream output(Com::PROTO_PATH, ios::out | ios::trunc | ios::binary);
		if (!msg_com.SerializePartialToOstream(&output)) {
			cerr << "序列化失败！" << endl;
			return 0;
		}
		return 1;
	}


	int Com::un_serialization() {
		my_proto::MsgCom msg_com;
		// 读取
		fstream input(Com::PROTO_PATH, ios::in | ios::binary);
		if (!msg_com.ParseFromIstream(&input)) {
			cerr << "反序列化失败！" << endl;
			return 0;
		}

		this->_int_num = msg_com.num();
		this->_str_cascade_path = msg_com.cascade_path();

		// 去除 尾的  }  {a;b } {c;d } {e;f
		string str_images_labels = msg_com.images_labels().substr(0, msg_com.images_labels().length() - 1);
		string str_id_name = msg_com.id_name().substr(0, msg_com.id_name().length() - 1);
		string str_name_index = msg_com.name_index().substr(0, msg_com.name_index().length() - 1);

		vector<string> vct_str_images_labels = go88::Utils::SPLIT(str_images_labels, '}');
		vector<string> vct_str_id_name = go88::Utils::SPLIT(str_id_name, '}');
		vector<string> vct_str_name_index = go88::Utils::SPLIT(str_name_index, '}');

		for (int i = 0; i < vct_str_images_labels.size(); i++) {
			this->_vct_images_labels.push_back(vct_str_images_labels[i].substr(1));
		}

		for (int i = 0; i < vct_str_id_name.size(); i++) {
			vector<string> vct = go88::Utils::SPLIT(vct_str_id_name[i].substr(1), ';');
			this->_map_id_name.insert(pair<int, string>(stoi(vct[0]), vct[1]));
		}
		for (int i = 0; i < vct_str_name_index.size(); i++) {
			vector<string> vct = go88::Utils::SPLIT(vct_str_name_index[i].substr(1), ';');
			this->_map_name_index.insert(pair<string, int>(vct[0], stoi(vct[1])));
		}


		return 1;
	}


	int Com::get_num() {
		return this->_int_num;
	}


	void Com::set_num(int num) {
		this->_int_num = num;
	}


	int Com::get_id(string name) {
		map<int, string>::iterator _iter;

		for (_iter = _map_id_name.begin(); _iter != _map_id_name.end(); _iter++) {
			if (_iter->second == name) {
				return _iter->first;
			}
		}
		return -1;
	}


	string Com::get_name(int id) {
		map<int, string>::iterator _iter;

		for (_iter = _map_id_name.begin(); _iter != _map_id_name.end(); _iter++) {
			if (_iter->first == id) {
				return _iter->second;
			}
		}
		return NULL;
	}


	int Com::get_index(string name) {
		map<string, int>::iterator _iter;

		for (_iter = _map_name_index.begin(); _iter != _map_name_index.end(); _iter++) {
			if (_iter->first == name) {
				return _iter->second;
			}
		}
		return 0;
	}


	int Com::set_index(string name, int index) {
		map<string, int>::iterator _iter;

		for (_iter = _map_name_index.begin(); _iter != _map_name_index.end(); _iter++) {
			if (_iter->first == name) {
				_iter->second = index;
				return 1;
			}
		}
		return 0;
	}


	int Com::is_exist_name(string name) {
		map<int, string>::iterator _iter;

		for (_iter = _map_id_name.begin(); _iter != _map_id_name.end(); _iter++) {
			if (_iter->second == name) {
				return 1;
			}
		}
		return 0;
	}


	int Com::is_exist_id(int id) {
		map<int, string>::iterator _iter;

		for (_iter = _map_id_name.begin(); _iter != _map_id_name.end(); _iter++) {
			if (_iter->first == id) {
				return 1;
			}
		}
		return 0;
	}


	map<int, string>& Com::get_id_name() {
		return this->_map_id_name;
	}


	map<string, int>& Com::get_name_index() {
		return this->_map_name_index;
	}


	vector<string>& Com::get_img_lb() {
		return this->_vct_images_labels;
	}


	string Com::get_cascade_path() {
		return this->_str_cascade_path;
	}

}




namespace go88 {


	template<typename Out>
	void Utils::SPLIT(const string s, char delim, Out result) {
		stringstream ss(s);
		string item;
		while (getline(ss, item, delim)) {
			*(result++) = item;
		}
	}


	vector<string> Utils::SPLIT(const string s, char delim) {
		vector<string> elems;
		SPLIT(s, delim, back_inserter(elems));
		return elems;
	}


	int Utils::IS_EXIST_PATH(string path) {
		return !_access(path.c_str(), 0);
	}


	string Utils::GET_FOLDER(string path) {
		string folder_path;
		for (int i = path.length() - 1; i > 0; i--) {
			if (path[i] != '\\') {
				folder_path = path.substr(0, i);
			}
			else {
				folder_path = path.substr(0, i);
				break;
			}
		}
		return folder_path;
	}


	int Utils::CREATE_FOLDER(string folder_path) {
		string cmd = "md " + folder_path;
		return system(cmd.c_str());
	}


	int Utils::GET_FILES_NUM(string dir, string cach_path) {
		int i = -1;
		string cmd = "dir /b /a-d " + dir + "\\*.*  | find /V /C \" \" > " + cach_path;
		system(cmd.c_str());
		ifstream in(cach_path);
		in >> i;
		in.close();
		cmd = "del " + cach_path;
		system(cmd.c_str());
		return i;
	}


	vector<vector<string>> Utils::READ_CSV(const string& file_name, char separator) {
		vector<vector<string>> vct;
		ifstream file(file_name, ios::in);
		if (!file) {
			string error_message = "csv文件读取错误！";
			cout << error_message << endl;
		}
		string line;
		while (getline(file, line)) {
			stringstream liness(line);
			string str_col;
			vector<string> vct_col;
			while (true) {
				getline(liness, str_col, separator);
				if (str_col == NULL) {
					break;
				}else{
					vct_col.push_back(str_col);
				}
			}
			vct.push_back(vct_col);
		}
		return vct;
	}


	Mat Utils::NORM(InputArray input) {
		Mat input_mat = input.getMat();
		// 创建和返回一个归一化后的图像矩阵:  
		Mat output_mat;
		switch (input_mat.channels()) {
		case 1:
			cv::normalize(input, output_mat, 0, 255, NORM_MINMAX, CV_8UC1);
			break;
		case 3:
			cv::normalize(input, output_mat, 0, 255, NORM_MINMAX, CV_8UC3);
			break;
		default:
			input_mat.copyTo(output_mat);
			break;
		}
		return output_mat;
	}


	int Utils::PRETREATMENT(Mat frame, vector<Mat>& faces, vector<Rect> & rects, string model_path) {
		Mat _frame = frame.clone();

		CascadeClassifier face_cascade;
		face_cascade.load(model_path);

		// 转为灰度图
		Mat _frame_gray;
		cvtColor(_frame, _frame_gray, CV_BGR2GRAY);
		equalizeHist(_frame_gray, _frame_gray);

		// *** 需要优化，此步骤耗时过长
		//
		// 识别人脸
		face_cascade.detectMultiScale(_frame_gray, rects);

		for (int i = 0; i < rects.size(); i++) {
			Mat _face = Mat(_frame.clone(), rects[i]);
			resize(_face, _face, Size(100, 100), INTER_LINEAR);

			faces.push_back(_face);
		}

		return rects.size() > 0 ? 1 : 0;
	}
}