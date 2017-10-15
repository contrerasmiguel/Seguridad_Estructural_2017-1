#pragma once

#include <ctime>
#include "DateTime.h"
#include "KeyboardEventListener.h"
#include "LogFileManager.h"
#include <string>
#include "Video.h"

using std::string;

class DetectionRecord : public KeyboardEventListener
{
private:
	Video video;
	LogFileManager logFileManager;

public:
	void onDetect() const;
	void onDetectStop() const;
};

