#pragma once

#include "DateTime.h"
#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::cerr;
using std::endl;
using std::ofstream;
using std::ios;
using std::string;
using std::to_string;

class LogFileManager
{
private:
	static const string FILE_NAME;
	string generateTimeStamp(DateTime* dt) const;

public:
	void logDetect(DateTime* dt, string videoName) const;
	void logDetectStop(DateTime* dt) const;
};

