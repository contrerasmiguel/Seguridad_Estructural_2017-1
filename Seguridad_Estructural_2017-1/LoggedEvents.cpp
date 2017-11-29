#include "LoggedEvents.h"

LoggedEvents::~LoggedEvents()
{
	clearAndFree();
}

void LoggedEvents::add(DateTime dt, string desc)
{
	loggedEvents.push_back(new LoggedEvent(dt, desc));
}

void LoggedEvents::clearAndFree()
{
	for (auto& le : loggedEvents) {
		delete le;
	}
	loggedEvents.clear();
}

void LoggedEvents::clear()
{
	clearAndFree();
}

string LoggedEvents::showFromDate(DateTime& dt) const
{
	string output;
	long numEvents = 0;

	output = "EVENTOS A PARTIR DE " + dt.toString() + "\n";
	for (auto& loggedEvent : loggedEvents) {
		if (loggedEvent->getDateTime()->after(dt)) {
			numEvents += 1;
			output += "\n[" + loggedEvent->getDateTime()->toString() + "] " + loggedEvent->getDescription();
		}
	}

	if (numEvents == 0) {
		output += "No hay eventos a partir de la fecha especificada.";
	}

	output += "\n";
	return output;
}

string LoggedEvents::showUntilDate(DateTime& dt) const
{
	string output;
	long numEvents = 0;

	output = "EVENTOS ANTES DE " + dt.toString() + "\n";
	for (auto& loggedEvent : loggedEvents) {
		if (loggedEvent->getDateTime()->before(dt)) {
			numEvents += 1;
			output += "\n[" + loggedEvent->getDateTime()->toString() + "] " + loggedEvent->getDescription();
		}
	}

	if (numEvents == 0) {
		output += "No hay eventos antes de la fecha especificada.";
	}

	output += "\n";
	return output;
}

string LoggedEvents::showBetweenDates(DateTime& dtA, DateTime& dtB) const
{
	string output;
	long numEvents = 0;

	output = "EVENTOS A ENTRE " + dtA.toString() + " Y " + dtB.toString() + "\n";
	for (auto& loggedEvent : loggedEvents) {
		if (loggedEvent->getDateTime()->after(dtA) && loggedEvent->getDateTime()->before(dtB)) {
			numEvents += 1;
			output += "\n[" + loggedEvent->getDateTime()->toString() + "] " + loggedEvent->getDescription();
		}
	}

	if (numEvents == 0) {
		output += "No hay eventos entre las fechas especificadas.";
	}

	output += "\n";
	return output;
}

string LoggedEvents::showEverything() const
{
	string output;
	output = "TODOS LOS EVENTOS\n";
	for (auto& loggedEvent : loggedEvents) {
		output += "\n[" + loggedEvent->getDateTime()->toString() + "] " + loggedEvent->getDescription();
	}
	output += "\n";
	return output;
}