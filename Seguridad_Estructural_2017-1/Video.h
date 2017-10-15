#pragma once

#include "DateTime.h"
#include <string>

using std::string;

class Video
{
private:
	const static string FILE_EXTENSION;
	string generateFileName(DateTime* dt) const;
public:
	string record(DateTime* dt) const;
};

