#pragma once

#include "DateTime.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "TextEncryption.h"

using std::cout;
using std::cerr;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::ios;
using std::string;
using std::stringstream;
using std::to_string;

class LogFileManager
{
private:
	static const string FILE_NAME;
	static const string DECRYPT_FILE_NAME;
	string generateTimeStamp(DateTime* dt) const;
	string generateTimeStampForDecryptFile(DateTime * dt) const;

public:
	void logDetect(DateTime* dt, string videoName) const;
	void logDetectStop(DateTime* dt) const;
	void decryptFile(short key) const;
};

