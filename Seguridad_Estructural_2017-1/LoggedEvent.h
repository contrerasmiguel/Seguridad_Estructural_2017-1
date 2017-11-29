#pragma once

#include "DateTime.h"
#include <string>

using std::string;

class LoggedEvent
{
private:
	const DateTime dateTime;
	const string description;

public:
	LoggedEvent(DateTime dt, string desc);
	const DateTime* getDateTime() const;
	const string getDescription() const;
};

