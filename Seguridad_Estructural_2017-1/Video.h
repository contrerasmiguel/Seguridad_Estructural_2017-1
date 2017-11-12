#pragma once

#include "DateTime.h"
#include <iostream>
#include <string>
#include <thread>
#include <opencv2\opencv.hpp>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::thread;

class Video
{
private:
	const static string FILE_EXTENSION;
	string generateFileName(DateTime* dt) const;
	void backgroundRecord(string videoName) const;
	thread* backgroundThread;

public:
	Video();
	~Video();

	// Tiempo de grabación en segundos.
	const static int RECORD_TIME;

	string record(DateTime* dt);
};

