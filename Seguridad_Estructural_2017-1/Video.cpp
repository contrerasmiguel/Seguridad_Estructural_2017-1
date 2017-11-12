#include "Video.h"

using namespace cv;

const string Video::FILE_EXTENSION = "avi";
const int Video::RECORD_TIME = 7;

Video::Video() : backgroundThread(NULL) { }

Video::~Video()
{
	if (backgroundThread != NULL) {
		backgroundThread->join();
		delete backgroundThread;
	}
}

string Video::generateFileName(DateTime* dt) const
{
	return "seguridad_" + to_string(dt->getYear()) + "-" + to_string(dt->getMonth()) + "-" + to_string(dt->getDay())
		+ "_" + to_string(dt->getHour()) + "-" + to_string(dt->getMinute()) + "-" + to_string(dt->getSecond()) + "." + FILE_EXTENSION;
}

string Video::record(DateTime* dt)
{
	string videoName = generateFileName(dt);

	if (backgroundThread != NULL) {
		backgroundThread->join();
		delete backgroundThread;
	}
	
	backgroundThread = new thread(&Video::backgroundRecord, this, videoName);

	return videoName;
}

void Video::backgroundRecord(string videoName) const 
{
	int video_lenght = RECORD_TIME;
	time_t begin = time(NULL);
	time_t end = begin + video_lenght;
	VideoCapture vcap(0);

	if (vcap.isOpened()) {
		double frame_width = vcap.get(CV_CAP_PROP_FRAME_WIDTH);
		double frame_height = vcap.get(CV_CAP_PROP_FRAME_HEIGHT);

		VideoWriter video(videoName, CV_FOURCC('M', 'J', 'P', 'G'), 10, Size((int)frame_width, (int)frame_height), true);

		cout << "Video: camara grabando en archivo '" << videoName << "'." << endl;
		cout << "Video: se reactivara la deteccion de presencia despues de " << video_lenght << " segundos." << endl;

		for (;time(NULL) < end;) {
			Mat frame;
			vcap >> frame;
			video.write(frame);
			if (waitKey(30) >= 0) break;
		}

		cout << "Video: la camara ha terminado de grabar." << endl;
	}
	else {
		cerr << "Video: no se detecto una camara." << endl;
		cout << "Video: se reactivara la deteccion de presencia despues de " << video_lenght << " segundos." << endl;
	
		for (;time(NULL) < end;) {
			if (waitKey(30) >= 0) break;
		}
	}
	cout << "Video: se ha reactivado la deteccion de presencia." << endl;
}