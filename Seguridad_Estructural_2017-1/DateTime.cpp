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

DateTime::DateTime(int y, int m, int d, int h, int min, int s)
	: year(y), month(m), day(d), hour(h), minute(min), second(s) { }

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

bool DateTime::after(DateTime& dt) const
{
	if (year == dt.year) {
		if (month == dt.month) {
			if (day == dt.day) {
				if (hour == dt.hour) {
					if (minute == dt.minute) {
						return second >= dt.second;
					}
					else {
						return minute > dt.minute;
					}
				}
				else {
					return hour > dt.hour;
				}
			}
			else {
				return day > dt.day;
			}
		}
		else {
			return month > dt.month;
		}
	}
	return year > dt.year;
}

bool DateTime::before(DateTime& dt) const
{
	if (year == dt.year) {
		if (month == dt.month) {
			if (day == dt.day) {
				if (hour == dt.hour) {
					if (minute == dt.minute) {
						return second <= dt.second;
					}
					else {
						return minute < dt.minute;
					}
				}
				else {
					return hour < dt.hour;
				}
			}
			else {
				return day < dt.day;
			}
		}
		else {
			return month < dt.month;
		}
	}
	return year < dt.year;
}

string DateTime::toString() const
{
	stringstream output;
	output << year << "-" << month << "-" << day
		<< " " << hour << ":" << minute << ":" << second;
	return output.str();
}