#pragma once

#include <chrono>
#include <sstream>
#include <string>

using std::endl;
using std::stringstream;
using std::string;

class DateTime
{
private:
	int year, month, day, hour, minute, second;

public:
	DateTime();
	DateTime(int y, int m, int d, int h, int min, int s);
	int getYear() const;
	int getMonth() const;
	int getDay() const;
	int getHour() const;
	int getMinute() const;
	int getSecond() const;
	bool after(DateTime& dt) const;
	bool before(DateTime& dt) const;
	string toString() const;
};

