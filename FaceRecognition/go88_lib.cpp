#include "go88_lib.h"


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
				}
				else {
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


	int Utils::PRETREATMENT(Mat frame, vector<Mat>& faces, vector<Rect> & rects) {
		Mat _frame = frame.clone();

		// 转为灰度图，均值化
		Mat _frame_gray;
		cvtColor(_frame, _frame_gray, CV_BGR2GRAY);
		equalizeHist(_frame_gray, _frame_gray);

		// 使用 libfacedection 的 facedetect_multiview
		// 在 go88_lib 中封装
		go88::Utils::FACEDETECT_MULTIVIEW(_frame_gray, rects, 1.2f, 3, 100, 300, 0);

		for (int i = 0; i < rects.size(); i++) {
			Mat _face = Mat(_frame.clone(), rects[i]);
			resize(_face, _face, Size(100, 100), INTER_LINEAR);

			faces.push_back(_face);
		}

		return rects.size() > 0 ? 1 : 0;
	}


	void Utils::FACEDETECT_MULTIVIEW(Mat &frame_gray, vector<Rect> &face_rects, float scale,
		int min_neighbors, int min_object_width, int max_object_width, int doLandmark) {

		// libfacedetect 的缓冲区大小, 不要更改
		const int DETECT_BUFFER_SIZE = 0x20000;
		// 结果
		int * p_results = NULL;
		//pBuffer指针用于检测函数。
		unsigned char * p_buffer = (unsigned char *)malloc(DETECT_BUFFER_SIZE);

		int cols = frame_gray.cols;
		int rows = frame_gray.rows;

		p_results = facedetect_multiview(p_buffer, (unsigned char*)(frame_gray.ptr(0)),
			cols, rows, (int)frame_gray.step, scale, min_neighbors, min_object_width, max_object_width, doLandmark);

		for (int i = 0; i < (p_results ? *p_results : 0); i++)
		{
			short * p = ((short*)(p_results + 1)) + 142 * i;
			int x = p[0];
			int y = p[1];
			int w = p[2];
			int h = p[3];
			int neighbors = p[4];
			int angle = p[5];

			// 边界判断
			x = x >= 0 ? x : 0;
			y = y >= 0 ? y : 0;
			w = (x + w <= cols) ? w : (cols - x);
			h = (y + h <= rows) ? h : (rows - y);

			face_rects.push_back(Rect(x, y, w, h));
		}
	}


}