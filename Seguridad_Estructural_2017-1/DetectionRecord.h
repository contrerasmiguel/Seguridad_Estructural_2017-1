#pragma once

#include <chrono>
#include "DateTime.h"
#include "KeyboardEventListener.h"
#include "LogFileManager.h"
#include "Video.h"

using std::chrono::duration;
using std::chrono::steady_clock;
using std::chrono::time_point;
using std::milli;

class DetectionRecord : public KeyboardEventListener
{
private:
	Video video;
	LogFileManager logFileManager;
	time_point<steady_clock> lastDetectionTimePoint;
	double getTimeDifference() const;
	bool hasDetected;

public:
	DetectionRecord();
	void onDetect();
	void onDetectStop();
};

