#include "DetectionRecord.h"

DetectionRecord::DetectionRecord() : hasDetected(false) { }

double DetectionRecord::getTimeDifference() const
{
	return duration<double, milli>(steady_clock::now() - lastDetectionTimePoint).count() / 1000.0;;
}

void DetectionRecord::onDetect() {
	if (!hasDetected && getTimeDifference() >= Video::RECORD_TIME) {
		cout << "DetectionRecord: presencia detectada." << endl;
		lastDetectionTimePoint = steady_clock::now();
		hasDetected = true;
		DateTime dt;
		auto videoName = video.record(&dt);
		logFileManager.logDetect(&dt, videoName);
	}
}

void DetectionRecord::onDetectStop() {
	if (hasDetected) {
		cout << "DetectionRecord: se dejo de detectar presencia." << endl;
		DateTime dt;
		logFileManager.logDetectStop(&dt);
		hasDetected = false;
	}
}