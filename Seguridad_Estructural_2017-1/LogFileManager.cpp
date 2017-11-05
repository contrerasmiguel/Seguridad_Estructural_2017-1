#include "LogFileManager.h"

const string LogFileManager::FILE_NAME = "registro_eventos.txt";

void LogFileManager::logDetect(DateTime* dt, string videoName) const {
	//cout << "LogFileManager: abriendo archivo de registro '" << FILE_NAME << "'..." << endl;
	ofstream ofs(FILE_NAME, ios::app);
	TextEncryption cipher;

	if (ofs) {
		//cout << "LogFileManager: archivo de registro abierto correctamente." << endl;
		auto rawLogLine = '\n' + "[" + generateTimeStamp(dt) + "] Inicio de deteccion sobre alfombra. Video: " + videoName;
		auto encryptedLine = cipher.encrypt(rawLogLine);
		ofs << encryptedLine;
	}
	
	else {
		cerr << "LogFileManager: ocurrio un error al intentar abrir el archivo de registro." << endl;
	}
}

void LogFileManager::logDetectStop(DateTime* dt) const {
	//cout << "LogFileManager: abriendo archivo de registro '" << FILE_NAME << "'..." << endl;
	ofstream ofs(FILE_NAME, ios::app);
	TextEncryption cipher;

	if (ofs) {
		//cout << "LogFileManager: archivo de registro abierto correctamente." << endl;
		auto rawLogLine = '\n' + "[" + generateTimeStamp(dt) + "] Fin de deteccion sobre alfombra";
		auto encryptedLine = cipher.encrypt(rawLogLine);
		ofs << encryptedLine;
	}

	else {
		cerr << "LogFileManager: ocurrio un error al intentar abrir el archivo de registro." << endl;
	}
}

string LogFileManager::generateTimeStamp(DateTime* dt) const
{
	return to_string(dt->getYear()) + "-" + to_string(dt->getMonth()) + "-" + to_string(dt->getDay())
		+ " " + to_string(dt->getHour()) + ":" + to_string(dt->getMinute()) + ":" + to_string(dt->getSecond());
}