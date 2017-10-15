#pragma once

#include "DateTime.h"
#include <string>

using std::string;

class Video
{
private:
	const string fileExtension;
	string generateFileName(DateTime* dt) const;
public:
	Video(string fileExtension);
	string record(DateTime* dt) const;
};

