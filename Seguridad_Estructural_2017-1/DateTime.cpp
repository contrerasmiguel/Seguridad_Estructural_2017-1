#include "DateTime.h"

DateTime::DateTime()
{
	auto now = std::chrono::system_clock::now();
	auto now_c = std::chrono::system_clock::to_time_t(now);
	tm parts;
	localtime_s(&parts, &now_c);

	year = 1900 + parts.tm_year;
	month = 1 + parts.tm_mon;
	day = parts.tm_mday;
	hour = parts.tm_hour;
	minute = parts.tm_min;
	second = parts.tm_sec;
}

int DateTime::getYear() const
{
	return year;
}

int DateTime::getMonth() const
{
	return month;
}

int DateTime::getDay() const
{
	return day;
}

int DateTime::getHour() const
{
	return hour;
}

int DateTime::getMinute() const
{
	return minute;
}

int DateTime::getSecond() const
{
	return second;
}