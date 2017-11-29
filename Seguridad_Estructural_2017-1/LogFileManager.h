#pragma once

#include "DateTime.h"
#include <fstream>
#include <iostream>
#include "LoggedEvents.h"
#include <regex>
#include <sstream>
#include <string>
#include "TextEncryption.h"

using std::cout;
using std::cerr;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::ios;
using std::regex;
using std::regex_match;
using std::smatch;
using std::string;
using std::stringstream;
using std::to_string;

class LogFileManager
{
private:
	static const string FILE_NAME, DECRYPT_FILE_NAME;
	string generateTimeStamp(DateTime* dt) const;
	string generateTimeStampForDecryptFile(DateTime * dt) const;
	LoggedEvents loggedEvents;
	short decryptKey;
	static const short DEFAULT_DECRYPT_KEY;

public:
	LogFileManager();
	LogFileManager(short dk);
	void logDetect(DateTime* dt, string videoName) const;
	void logDetectStop(DateTime* dt) const;
	void decryptFile() const;
	LoggedEvents* getLoggedEvents();
};

