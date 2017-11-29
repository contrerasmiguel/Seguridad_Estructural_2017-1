#pragma once

#include "ConfigurationManager.h"
#include "DateTime.h"
#include "DetectionRecord.h"
#include <iostream>
#include "KeyboardWatch.h"
#include <limits>
#include <regex>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::regex;
using std::regex_search;
using std::smatch;
using std::streamsize;

enum Option
{
	  OPTION_WATCH = 1
	, OPTION_DECRYPT = 2
	, OPTION_FROM_DATE = 3
	, OPTION_UNTIL_DATE = 4
	, OPTION_BETWEEN_DATES = 5
	, OPTION_SHOW_EVERYTHING = 6
	, OPTION_EXIT = 7
};

void startKeyboardWatch();
short askForKey();
void startLogDecrypt();
void clearInputBuffer();
bool stringToDateTime(int* y, int* m, int* d, int* h, int* min, int* s, string str);
void startFromDate();
void startUntilDate();
void startBetweenDates();
void startShowEverything();
Option readOption();
void showMenu();
int main(int argCount, char* arguments[]);
