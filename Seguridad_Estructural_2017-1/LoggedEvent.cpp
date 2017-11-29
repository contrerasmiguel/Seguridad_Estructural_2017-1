#include "LoggedEvent.h"

LoggedEvent::LoggedEvent(DateTime dt, string desc) : dateTime(dt), description(desc) { }

const DateTime* LoggedEvent::getDateTime() const
{
	return &dateTime;
}

const string LoggedEvent::getDescription() const
{
	return description;
}