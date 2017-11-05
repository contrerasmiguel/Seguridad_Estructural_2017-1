#include "LogFileManager.h"

const string LogFileManager::FILE_NAME = "registro_eventos.txt";
const string LogFileManager::DECRYPT_FILE_NAME = "_desencriptado.txt";

void LogFileManager::logDetect(DateTime* dt, string videoName) const {
	//cout << "LogFileManager: abriendo archivo de registro '" << FILE_NAME << "'..." << endl;
	ofstream ofs(FILE_NAME, ios::app);
	TextEncryption cipher;

	if (ofs) {
		//cout << "LogFileManager: archivo de registro abierto correctamente." << endl;
		auto rawLogLine = "\n[" + generateTimeStamp(dt) + "] Inicio de deteccion sobre alfombra. Video: " + videoName;
		auto encryptedLine = cipher.encryptText(rawLogLine);
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
		auto rawLogLine = "\n[" + generateTimeStamp(dt) + "] Fin de deteccion sobre alfombra.";
		auto encryptedLine = cipher.encryptText(rawLogLine);
		ofs << encryptedLine;
	}

	else {
		cerr << "LogFileManager: ocurrio un error al intentar abrir el archivo de registro." << endl;
	}
}

void LogFileManager::decryptFile(short key) const
{
	DateTime dt;
	auto outputFileName = generateTimeStampForDecryptFile(&dt) + DECRYPT_FILE_NAME;

	ifstream ifs(FILE_NAME);
	

	if (!ifs) {
		cerr << "LogFileManager: aun no se ha registrado evento alguno." << endl;
	}
	else {
		ofstream ofs(outputFileName, ios::trunc);

		if (!ofs) {
			cerr << "LogFileManager: ocurrio un error al abrir el archivo: " << outputFileName << endl;
		}
		else {
			TextEncryption cipher(key);
			stringstream buffer;
			buffer << ifs.rdbuf();
			auto decryptedText = cipher.decryptText(buffer.str());
			ofs.write(decryptedText.c_str(), decryptedText.length());
			cout << "LogFileManager: se desencripto el registro de eventos en el archivo: " << outputFileName << endl;
		}
	}
}

string LogFileManager::generateTimeStamp(DateTime* dt) const
{
	return to_string(dt->getYear()) + "-" + to_string(dt->getMonth()) + "-" + to_string(dt->getDay())
		+ " " + to_string(dt->getHour()) + ":" + to_string(dt->getMinute()) + ":" + to_string(dt->getSecond());
}

string LogFileManager::generateTimeStampForDecryptFile(DateTime* dt) const
{
	return to_string(dt->getYear()) + "-" + to_string(dt->getMonth()) + "-" + to_string(dt->getDay())
		+ "_" + to_string(dt->getHour()) + "-" + to_string(dt->getMinute()) + "-" + to_string(dt->getSecond());
}