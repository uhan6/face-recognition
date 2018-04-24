#include "opencv2/opencv.hpp"
#include <thread>
#include <windows.h>

using namespace cv;
using namespace std;


struct parm
{
	Mat *image;
	vector<Rect> *rects;
};
void thread_face(parm *p);

CRITICAL_SECTION RECT_SECTION;


int test_capture() {
	// 开启相机
	VideoCapture cap(0);
	if (!cap.isOpened()) {
		cout << "相机加载错误！" << endl;
		return 0;
	}

	Mat image;
	vector<Rect> rects;
	InitializeCriticalSection(&RECT_SECTION);

	parm *p = new parm;
	cap >> image;
	p->image = &image;
	p->rects = &rects;

	thread t(thread_face, p);
	t.detach();
	Mat img;
	while (true) {
		waitKey(10);

		cap >> image;
		cap >> img;

		EnterCriticalSection(&RECT_SECTION);
		vector<Rect> t_rects(rects);
		LeaveCriticalSection(&RECT_SECTION);

		for (int i = 0; i < t_rects.size(); i++) {
			rectangle(img, t_rects[i], Scalar(0, 0, 255), 1);
		}

		imshow("capture", img);
		
	}

	waitKey(0);
	destroyAllWindows();

	return 0;
}

void thread_face(parm *p) {

	String cascade_file = "res/haarcascade_frontalface_alt.xml";
	CascadeClassifier face_cascade;
	face_cascade.load(cascade_file);

	while (true) {

		Mat image = (*(p->image)).clone();

		Mat img_gray;
		vector<Rect> faces;
		cvtColor(image, img_gray, CV_BGR2GRAY);
		equalizeHist(img_gray, img_gray);

		face_cascade.detectMultiScale(img_gray, faces);

		cout << faces.size() << endl;

		EnterCriticalSection(&RECT_SECTION);
		(*(p->rects)).clear();
		for (int i = 0; i < faces.size(); i++) {
			int x = faces[i].x;
			int y = faces[i].y;
			int w = faces[i].width;
			int h = faces[i].height;
			Rect rect(x, y, w, h);
			(*(p->rects)).push_back(rect);
		}
		LeaveCriticalSection(&RECT_SECTION);

	}

}