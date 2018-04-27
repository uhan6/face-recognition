#include "opencv2/opencv.hpp"
#include "opencv2/face.hpp"

#include "go88_lib.h"

using namespace std;
using namespace cv;
using namespace cv::face;
using namespace my_ocv_project_common_180418;


int train_model();


int create_new_face() {
	// 开启相机
	VideoCapture cap(0);
	if (!cap.isOpened()) {
		cout << "相机加载错误！" << endl;
		return 0;
	}

	cout << "输入人物名称：" << endl;
	string name;
	cin >> name;

	// 图片索引
	int i = 1;

	// 不存在人物，新增人物
	if (!Com::INS()->is_exist_name(name)) {
		// id , name
		Com::INS()->get_id_name().insert(pair<int, string>(Com::INS()->get_num(), name));
		// name , index
		Com::INS()->get_name_index().insert(pair<string, int>(name, 1));
		Com::INS()->set_num(Com::INS()->get_num() + 1);
	}
	else {
		i = Com::INS()->get_index(name);
	}

	string faces_folder = Com::FACES_FOLDER + name + "\\";
	go88::Utils::CREATE_FOLDER(faces_folder);

	cout << "按 p 拍照，按 q 退出拍照。" << endl;
	Mat frame;
	while (i != -1) {
		char key = waitKey(10);
		cap >> frame;
		imshow("拍照", frame);

		string faces_path = faces_folder + to_string(i) + ".jpg";

		bool no_correct_face = true;
		//Mat re_face;
		vector<Mat> faces;
		vector<Rect> rects;
		switch (key) {
		case'p':
			faces.clear();
			rects.clear();
			// 如果没有人脸, 进行下一循环
			if (!go88::Utils::PRETREATMENT(frame, faces, rects, Com::INS()->get_cascade_path())) {
				continue;
			}
			if (faces.size() > 1) {
				cout << "人脸数量过多！" << endl;
				continue;
			}

			// 存储人脸照片
			imwrite(faces_path, faces[0]);

			// 存储标签
			Com::INS()->get_img_lb().push_back(faces_path + ";" + to_string(Com::INS()->get_id(name)));

			imshow(name + to_string(i), faces[0]);
			waitKey(300);
			destroyWindow(name + to_string(i));

			i++;
			break;
		case 'q':
			i = -1;
			break;
		default:
			break;
		}
	}
	destroyAllWindows();
	cout << "人物照片存储目录为：\"D:\\opencv_faces\\" + name + "\"" << endl;

	// 序列化 保存 Com 类
	Com::INS()->serialization();

	cout << "开始训练模型，请等待" << endl;
	train_model();
	cout << "模型训练完成" << endl;

	return 1;
}


int train_model() {
	vector<Mat> images;
	vector<int> labels;

	// 读取照片和标签
	for (int i = 0; i < Com::INS()->get_img_lb().size(); i++) {
		vector<string> vct = go88::Utils::SPLIT(Com::INS()->get_img_lb()[i], ';');
		images.push_back(imread(vct[0], 0));
		labels.push_back(stoi(vct[1]));
	}

	//cout << "faces size  " << images.size() << "labels size  " << labels.size() << endl;

	// 训练模型
	Ptr<EigenFaceRecognizer> eigen_model = EigenFaceRecognizer::create(Com::INS()->get_num());
	Ptr<FisherFaceRecognizer> fisher_model = FisherFaceRecognizer::create(Com::INS()->get_num());
	Ptr<LBPHFaceRecognizer> lbphf_model = LBPHFaceRecognizer::create();

	eigen_model->train(images, labels);
	fisher_model->train(images, labels);
	lbphf_model->train(images, labels);

	// 存储model
	eigen_model->save("res/model/eigen_model.xml");
	fisher_model->save("res/model/fisher_model.xml");
	lbphf_model->save("res/model/lbphf_model.xml");

	return 1;
}
