#include "opencv2/opencv.hpp"
#include "opencv2/face.hpp"
#include <windows.h>
#include <thread>

#include "proj_com.h"
#include "go88_lib.h"

using namespace cv;
using namespace std;
using namespace cv::face;
using namespace project_common;


struct ThreadParm
{
	// 共有id
	int *frame_id;
	// 平均花在 detectMultiScale() 上的时间
	float *avg_delay;

	// thread 0
	Mat *frame;
	vector<Mat> *t0_faces;
	vector<Rect> *t0_rects;

	// thread 1
	vector<Rect> *t1_rects;
	vector<int> *t1_labels;

	// thread over
	int *t0_over;
	int *t1_over;
};


void pretreatment_thread(ThreadParm *tp);
void modelpredict_thread(ThreadParm *tp);


CRITICAL_SECTION T0_SECTION;
CRITICAL_SECTION T1_SECTION;


int check_face() {
	// 开启相机
	VideoCapture cap(0);
	if (!cap.isOpened()) {
		cout << "相机加载错误！" << endl;
		return 0;
	}

	Mat cap_frame;
	int frame_id = 0;
	vector<Mat> t0_faces;
	vector<Rect> t0_rects;
	vector<Rect> t1_rects;
	vector<int> t1_labels;
	int t0_over = 0;
	int t1_over = 0;
	// 平均帧
	float avg_delay = 0;

	ThreadParm *tp = new ThreadParm;
	cap >> cap_frame;
	tp->frame_id = &frame_id;
	tp->frame = &cap_frame;
	tp->t0_faces = &t0_faces;
	tp->t0_rects = &t0_rects;
	tp->t1_rects = &t1_rects;
	tp->t1_labels = &t1_labels;
	tp->t0_over = &t0_over;
	tp->t1_over = &t1_over;

	tp->avg_delay = &avg_delay;

	// 初始化访问控制信号标识
	InitializeCriticalSection(&T0_SECTION);
	InitializeCriticalSection(&T1_SECTION);

	thread t0(pretreatment_thread, tp);
	thread t1(modelpredict_thread, tp);
	t0.detach();
	t1.detach();

	int i = 1;
	int _frame_id = 0;

	clock_t start, end;
	start = clock();

	Mat frame;
	vector<Rect> _rects;
	vector<int> _labels;
	cout << "按 q 退出检测" << endl;
	while (i != -1) {
		char key = waitKey(1);

		// 更新 Mat
		end = clock();
		if (end - start > 33) {
			cap >> cap_frame;
			_frame_id = ++_frame_id % 100000000;
			frame_id = _frame_id;
			frame = cap_frame.clone();

			_rects.clear();
			_labels.clear();
			// 取出 t1
			EnterCriticalSection(&T1_SECTION);
			_rects.assign((*tp->t1_rects).begin(), (*tp->t1_rects).end());
			_labels.assign((*tp->t1_labels).begin(), (*tp->t1_labels).end());
			LeaveCriticalSection(&T1_SECTION);

			for (int i = 0; i < _rects.size(); i++) {
				Point center(_rects[i].x + _rects[i].width*0.5, _rects[i].y + _rects[i].height*0.5);
				ellipse(frame, center, Size(_rects[i].width*0.5, _rects[i].height*0.5), 0, 0, 360, Scalar(220, 90, 60), 3, 8, 0);

				char * delay = new char[20];
				sprintf(delay, "avg delay : %0.2f ms", *tp->avg_delay);
				putText(frame, delay, Point(0, 25),
					FONT_HERSHEY_COMPLEX, 0.8, Scalar(0, 0, 0));
				/*rectangle(frame, _rects[i], Scalar(0, 0, 255), 1);
				string label = to_string(_rects[i].width) + " x " + to_string(_rects[i].height);
				putText(frame, label, Point(_rects[i].x, _rects[i].y - 20),
							FONT_HERSHEY_COMPLEX, 1, Scalar(0, 0, 0));
				cout << label << endl;*/

				if (_labels[i] != -1) {
					putText(frame, Com::INS()->get_name(_labels[i]), Point(_rects[i].x, _rects[i].y),
						FONT_HERSHEY_COMPLEX, 1, Scalar(0, 0, 0));
				}
				else {
					putText(frame, "unknow", Point(_rects[i].x, _rects[i].y),
						FONT_HERSHEY_COMPLEX, 1, Scalar(0, 0, 0));
				}
			}

			imshow("检测", frame);
			start = clock();
		}

		switch (key) {
		case 'q':
			i = -1;
			break;
		default:
			break;
		}
	}
	destroyAllWindows();
	// 结束识别线程
	frame_id = -1;
	//t0.~thread();
	//t1.~thread();
	while (!((*tp->t0_over) && (*tp->t1_over))) {
		Sleep(10);
	}

	return 1;
}

void pretreatment_thread(ThreadParm *tp) {

	// 计算delay
	int delay_time = 0;
	int delay_num = 0;

	// 线程内暂存，线程安全
	vector<Mat> _faces;
	vector<Rect> _rects;

	CascadeClassifier face_cascade;
	face_cascade.load(Com::INS()->get_cascade_path());

	int _frame_id = 0;
	while (_frame_id != -1) {

		// 每一帧控制是否进行刷新
		int frame_id = *tp->frame_id;
		if (_frame_id != frame_id) {
			_frame_id = frame_id;

			_faces.clear();
			_rects.clear();

			// 从 frame 中获取人脸
			Mat _frame = (*tp->frame).clone();

			// 转为灰度图
			Mat _frame_gray;
			cvtColor(_frame, _frame_gray, CV_BGR2GRAY);
			equalizeHist(_frame_gray, _frame_gray);

			// 计时器
			clock_t start;
			start = clock();

			//	*** 需要优化，此步骤耗时过长 ***
			//  
			//	在摄像头 480 x 640 像素下参数: 平均 40-50 ms
			//	InputArray image, 输入
			//	CV_OUT std::vector<Rect>& objects, 存放人脸位置
			//	double scaleFactor = 1.1, 默认 1.1速度太低慢, 缩放 1.5准确率过低, 用 1.3
			//	int minNeighbors = 3, 默认 3 表明至少有3次重叠检测，才认为人脸确实存在
			//	int flags = 0, 新分类器已经不使用了
			//	Size minSize = Size(), 人脸最小尺寸
			//	Size maxSize = Size(), 人脸最大尺寸
			face_cascade.detectMultiScale(_frame_gray, _rects, 1.3f, 3, 0, Size(150, 150), Size(400, 400));

			// 计算平均延迟
			if (_rects.size() > 0) {
				delay_time += clock() - start;
				delay_num++;
				if (delay_num > 20) {
					*tp->avg_delay = (delay_time * 1.0) / delay_num;
					delay_time = 0;
					delay_num = 0;
				}
			}

			for (int i = 0; i < _rects.size(); i++) {
				Mat _face = Mat(_frame.clone(), _rects[i]);
				resize(_face, _face, Size(100, 100), INTER_LINEAR);

				_faces.push_back(_face);
			}

			// 复制到 t0
			EnterCriticalSection(&T0_SECTION);
			(*tp->t0_faces).clear();
			(*tp->t0_faces).assign(_faces.begin(), _faces.end());
			(*tp->t0_rects).clear();
			(*tp->t0_rects).assign(_rects.begin(), _rects.end());
			LeaveCriticalSection(&T0_SECTION);
		}
	}
	*tp->t0_over = 1;
}


void modelpredict_thread(ThreadParm *tp) {
	
	// 结果
	char * output = new char[50];

	// 读取model
	Ptr<EigenFaceRecognizer> eigen_model = EigenFaceRecognizer::load<EigenFaceRecognizer>("res/model/eigen_model.xml");
	Ptr<FisherFaceRecognizer> fisher_model = FisherFaceRecognizer::load<FisherFaceRecognizer>("res/model/fisher_model.xml");
	Ptr<LBPHFaceRecognizer> lbphf_model = LBPHFaceRecognizer::load<LBPHFaceRecognizer>("res/model/lbphf_model.xml");

	// 线程内暂存，线程安全
	vector<Mat> _faces;
	vector<Rect> _rects;
	vector<int> _labels;

	int _frame_id = 0;
	while (_frame_id != -1) {

		// 每一帧控制是否进行刷新
		int frame_id = *tp->frame_id;
		if (_frame_id != frame_id) {
			_frame_id = frame_id;


			_faces.clear();
			_rects.clear();
			_labels.clear();
			// 读取 t0 faces rects
			EnterCriticalSection(&T0_SECTION);
			_faces.assign((*tp->t0_faces).begin(), (*tp->t0_faces).end());
			_rects.assign((*tp->t0_rects).begin(), (*tp->t0_rects).end());
			LeaveCriticalSection(&T0_SECTION);

			vector<Mat> predict_faces;
			for (int i = 0; i < _faces.size(); i++) {
				Mat tmp_face = _faces[i].clone();
				cvtColor(tmp_face, tmp_face, CV_BGR2GRAY);
				equalizeHist(tmp_face, tmp_face);
				predict_faces.push_back(tmp_face);
			}

			// 识别
			for (int i = 0; i < predict_faces.size(); i++) {
				int eigen_label = -1, fisher_label = -1, lbphf_label = -1;
				double eigen_cfd = 0.0, fisher_cfd = 0.0, lbphf_cfd = 0.0;
				eigen_model->predict(predict_faces[i], eigen_label, eigen_cfd);
				fisher_model->predict(predict_faces[i], fisher_label, fisher_cfd);
				lbphf_model->predict(predict_faces[i], lbphf_label, lbphf_cfd);

				sprintf(output, "eigen : %d ~ %0.2f, fisher : %d ~ %0.2f, lbphf : %d ~ %0.2f", 
					eigen_label, eigen_cfd, fisher_label, fisher_cfd, lbphf_label, lbphf_cfd);
				cout << output << endl;

				int finaly_lb = -1;
				if (eigen_label == fisher_label) {
					finaly_lb = eigen_label;
				}
				else if (fisher_label == lbphf_label) {
					finaly_lb = fisher_label;
				}
				else if (lbphf_label == eigen_label) {
					finaly_lb = lbphf_label;
				}
				_labels.push_back(finaly_lb);
			}


			// 复制数据到 t1
			EnterCriticalSection(&T1_SECTION);
			(*tp->t1_rects).clear();
			(*tp->t1_rects).assign(_rects.begin(), _rects.end());
			(*tp->t1_labels).clear();
			(*tp->t1_labels).assign(_labels.begin(), _labels.end());
			LeaveCriticalSection(&T1_SECTION);
		}
	}
	*tp->t1_over = 1;
}