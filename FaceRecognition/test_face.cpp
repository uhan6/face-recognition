#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int test_face() {
	String img_file =  "res/lena.jpg";
	String cascade_file = "res/haarcascade_frontalface_alt.xml";
	CascadeClassifier face_cascade;
	face_cascade.load(cascade_file);

	Mat image = imread(img_file), img_gray;
	vector<Rect> faces;

	cvtColor(image, img_gray, CV_BGR2GRAY);
	equalizeHist(img_gray, img_gray);

	face_cascade.detectMultiScale(img_gray, faces);
	
	cout << faces.size() << endl;

	for (int i = 0; i < faces.size(); i++) {
		int x = faces[i].x;
		int y = faces[i].y;
		int w = faces[i].width;
		int h = faces[i].height;
		Rect rect(x, y, w, h);
		Mat img = Mat(image, rect).clone();
		imshow("face" + i, img);
		rectangle(image, rect, Scalar(0, 0, 255), 1);
	}
	imshow("Faces", image);
	
	waitKey(0);
	destroyAllWindows();

	return 0;
}