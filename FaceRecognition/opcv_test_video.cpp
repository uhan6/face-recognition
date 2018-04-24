#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int test_video()
{
	String filePath = "D:/Program Files/opencv/sources/samples/data/video(620x252).mp4";
	VideoCapture cap;
	Mat video, reVideo, foreGround, backGround, fgMask;

	Ptr<BackgroundSubtractor> pBgModel =
		createBackgroundSubtractorMOG2().dynamicCast<BackgroundSubtractor>();
	
	cap.open(filePath);
	if (!cap.isOpened())
	{
		cout << "文件不存在!" << endl;
	}

	for (;;)
	{
		cap >> video;
		if (video.empty())
			break;
		// 进行缩放，减少计算
		resize(video, reVideo, Size(video.cols, video.rows), INTER_LINEAR);

		if (foreGround.empty())
			foreGround.create(reVideo.size(), reVideo.type());

		pBgModel->apply(reVideo, fgMask);

		GaussianBlur(fgMask, fgMask, Size(5, 5), 0);
		threshold(fgMask, fgMask, 10, 255, THRESH_BINARY);

		foreGround = Scalar::all(0);
		reVideo.copyTo(foreGround, fgMask);

		pBgModel->getBackgroundImage(backGround);

		imshow("TestVideo", video);
		imshow("backGround", backGround);
		imshow("foreGround", foreGround);
		imshow("fgMask", fgMask);

		char key = waitKey(1);

		if (key == 27)
			break;
	}

	waitKey(0);

	return 0;
}

