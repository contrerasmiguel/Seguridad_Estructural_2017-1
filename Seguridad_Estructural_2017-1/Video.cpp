#include "Video.h"

const string Video::FILE_EXTENSION = "avi";
const int Video::RECORD_TIME = 7;

string Video::generateFileName(DateTime* dt) const
{
	return "seguridad_" + to_string(dt->getYear()) + "-" + to_string(dt->getMonth()) + "-" + to_string(dt->getDay())
		+ "_" + to_string(dt->getHour()) + "-" + to_string(dt->getMinute()) + "-" + to_string(dt->getSecond()) + "." + FILE_EXTENSION;
}

string Video::record(DateTime* dt) const
{
	string videoName = generateFileName(dt);

	cout << "Video: camara grabando en archivo '" << videoName << "'." << endl;

	/*VideoCapture vcap(0);
	if (!vcap.isOpened()) {
		cout << "Error opening video stream or file" << endl;
		exit(1);
	}
	
	int video_lenght = 10;
	long int begin = time(NULL);
	long int end = begin + video_lenght;
	
	int frame_width = vcap.get(CV_CAP_PROP_FRAME_WIDTH);
	int frame_height = vcap.get(CV_CAP_PROP_FRAME_HEIGHT);
	
	VideoWriter video(videoName, CV_FOURCC('M', 'J', 'P', 'G'), 10, Size(frame_width, frame_height), true);
	
	for (;time(NULL) < end;) {
		Mat frame;
		vcap >> frame;
		video.write(frame);
		if (waitKey(30) >= 0) break;
	}*/

	return videoName;
}