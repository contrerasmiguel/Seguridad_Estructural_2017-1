#pragma once

#include "DateTime.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::to_string;

class Video
{
private:
	const static string FILE_EXTENSION;
	string generateFileName(DateTime* dt) const;

public:
	// Tiempo de grabación en segundos.
	const static int RECORD_TIME;

	string record(DateTime* dt) const;
};

