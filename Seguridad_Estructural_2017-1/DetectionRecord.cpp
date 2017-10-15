#include "DetectionRecord.h"

string DetectionRecord::generateFileName(struct tm* info) const {
	char result[64];

	strftime(result, 63, "seguridad_%Y-%m-%d_%H-%M-%S.", info);
	string nameWithExtension = result + fileExtension;

	return nameWithExtension;
}

string DetectionRecord::generateTimeStamp(struct tm* info) const {
	char result[64];
	strftime(result, 63, "%Y-%m-%d %H:%M:%S", info);
	string timestamp = result;
	return timestamp;
}

void DetectionRecord::recordVideo(string videoName) const {
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
}

DetectionRecord::DetectionRecord(string fileExtension) : fileExtension(fileExtension) { }

void DetectionRecord::onDetect() const {
	time_t rawtime;
	struct tm* info;

	time(&rawtime);
	info = localtime(&rawtime);

	string fileName = generateFileName(info);
	string timeStamp = generateTimeStamp(info);
	string logDescription = "[" + timeStamp + "] Persona detectada sobre la alfombra. Video: " + fileName;

	logFileManager.logEvent(logDescription);

	recordVideo(fileName);
}

void DetectionRecord::onDetectStop() const {
	time_t rawtime;
	struct tm* info;

	time(&rawtime);
	info = localtime(&rawtime);

	string fileName = generateFileName(info);
	string timeStamp = generateTimeStamp(info);
	string logDescription = "[" + timeStamp + "] Fin de detección sobre alfombra. Video: " + fileName;

	logFileManager.logEvent(logDescription);
}