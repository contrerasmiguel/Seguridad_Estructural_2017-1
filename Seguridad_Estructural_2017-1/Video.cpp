#include "Video.h"

const string Video::FILE_EXTENSION = "avi";

string Video::generateFileName(DateTime* dt) const
{
	string salida = "seguridad_";
	salida += dt->getYear();
	salida += "-" + dt->getMonth();
	salida += "-" + dt->getDay();
	salida += +"_" + dt->getHour();
	salida += "-" + dt->getMinute();
	salida += "-" + dt->getSecond();
	salida += "." + FILE_EXTENSION;

	return salida;
}

string Video::record(DateTime* dt) const
{
	string videoName = generateFileName(dt);

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