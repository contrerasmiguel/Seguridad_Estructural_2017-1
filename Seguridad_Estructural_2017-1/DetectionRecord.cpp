#include "DetectionRecord.h"

DetectionRecord::DetectionRecord(string fileExtension) : video(fileExtension) { }

void DetectionRecord::onDetect() const {
	DateTime dt;
	auto videoName = video.record(&dt);
	logFileManager.logDetect(&dt, videoName);
}

void DetectionRecord::onDetectStop() const {
	DateTime dt;
	logFileManager.logDetectStop(&dt);
}