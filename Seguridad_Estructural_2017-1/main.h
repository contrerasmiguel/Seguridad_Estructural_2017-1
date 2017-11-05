#pragma once

#include "ConfigurationManager.h"
#include "DetectionRecord.h"
#include <iostream>
#include "KeyboardWatch.h"

using std::cin;
using std::cout;
using std::endl;

enum Option
{
	  OPTION_WATCH = 1
	, OPTION_DECRYPT = 2
	, OPTION_EXIT = 3
};

void startKeyboardWatch();
void startLogDecrypt();
Option readOption();
void showMenu();
int main(int argCount, char* arguments[]);
