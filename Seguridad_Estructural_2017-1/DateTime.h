#pragma once
#include <chrono>
#include <ctime>

class DateTime
{
private:
	int year, month, day, hour, minute, second;

public:
	DateTime();
	int getYear() const;
	int getMonth() const;
	int getDay() const;
	int getHour() const;
	int getMinute() const;
	int getSecond() const;
};

