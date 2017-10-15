#include "LogFileManager.h"

const string LogFileManager::FILE_NAME = "registro_eventos.txt";

void LogFileManager::logEvent(string eventDescription) const {
	//cout << "LogFileManager: abriendo archivo de registro '" << FILE_NAME << "'..." << endl;
	ofstream ofs(FILE_NAME, ios::app);

	if (ofs) {
		//cout << "LogFileManager: archivo de registro abierto correctamente." << endl;
		ofs << endl << eventDescription;
	}
	
	else {
		cerr << "LogFileManager: ocurrio un error al intentar abrir el archivo de registro." << endl;
	}
}