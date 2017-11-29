#pragma once

#include "LoggedEvent.h"
#include <vector>

using std::vector;

class LoggedEvents
{
private:
	vector<LoggedEvent*> loggedEvents;
	void clearAndFree();

public:
	~LoggedEvents();
	void add(DateTime dt, string desc);
	void clear();
	string showFromDate(DateTime& dt) const;
	string showUntilDate(DateTime& dt) const;
	string showBetweenDates(DateTime& dtA, DateTime& dtB) const;
	string showEverything() const;
};

