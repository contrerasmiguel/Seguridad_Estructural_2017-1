#pragma once

#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::cerr;
using std::endl;
using std::ofstream;
using std::ios;
using std::string;

class LogFileManager
{
private:
	static const string FILE_NAME;

public:
	void logEvent(string eventDescription) const;
};

