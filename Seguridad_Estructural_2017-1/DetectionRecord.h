#pragma once

#include <ctime>
#include "KeyboardEventListener.h"
#include "LogFileManager.h"
#include <string>

using std::string;

class DetectionRecord : public KeyboardEventListener
{
private:
	LogFileManager logFileManager;
	const string fileExtension;

	string generateFileName(struct tm* info) const;

	string generateTimeStamp(struct tm* info) const;

	void recordVideo(string videoName) const;

public:
	DetectionRecord(string fileExtension);

	void onDetect() const;

	void onDetectStop() const;
};

