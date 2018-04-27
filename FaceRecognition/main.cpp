#include "opencv2/opencv.hpp"


int test_video();
int test_face();
int test_capture();
int face_recognition();


int main(void)
{
	// 测试配置环境
	/*String filePath = "D:/Program Files/opencv/sources/samples/data/lena.jpg";
	Mat img = imread(filePath);
	imshow("lena", img);
	resize(img, img, Size(img.cols/2, img.rows/2));
	imshow("resize", img);
	waitKey(0);*/

	// 视频取背景图片
	//test_video();
	// 检测图片中的人脸
	//test_face();
	// 检测摄像头中的人脸
	//test_capture();
	face_recognition();
	
	return 0;
}