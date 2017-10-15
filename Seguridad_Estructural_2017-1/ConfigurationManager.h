#pragma once

#include <experimental\filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::ios;
using std::ofstream;
using std::string;
using std::vector;

class ConfigurationManager
{
private:
	string configFileName;
	static const vector<int> DEFAULT_KEY_CODES;
	void createConfigFile() const;

public:
	ConfigurationManager(string fileName);
	vector<int> getKeys() const;
};

