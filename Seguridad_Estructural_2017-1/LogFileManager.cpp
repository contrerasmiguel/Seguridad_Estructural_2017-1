#include "LogFileManager.h"

const string LogFileManager::FILE_NAME = "registro_eventos.txt";
const string LogFileManager::DECRYPT_FILE_NAME = "_desencriptado.txt";
const short LogFileManager::DEFAULT_DECRYPT_KEY = 7;

LogFileManager::LogFileManager() : decryptKey(DEFAULT_DECRYPT_KEY) { }

LogFileManager::LogFileManager(short dk) : decryptKey(dk) { }

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

void LogFileManager::decryptFile() const
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
			TextEncryption cipher(decryptKey);
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

LoggedEvents* LogFileManager::getLoggedEvents()
{
	loggedEvents.clear();
	ifstream ifs(FILE_NAME);

	if (ifs) {
		TextEncryption cipher(decryptKey);
		stringstream cipheredBuffer;
		cipheredBuffer << ifs.rdbuf();
		auto decryptedText = cipher.decryptText(cipheredBuffer.str());
		stringstream decipheredLines;
		decipheredLines << decryptedText;

		string line;
		regex pattern("\\[\\s*(\\d+)\\s*\\-\\s*(\\d+)\\s*\\-\\s*(\\d+)+\\s+(\\d+)\\s*\\:\\s*(\\d+)\\s*\\:\\s*(\\d+)\\s*\\]\\s*(.*)");

		while (getline(decipheredLines, line)) {
			smatch match;

			if (regex_search(line, match, pattern)) {
				auto y = atoi(((string)match[1]).c_str());
				auto m = atoi(((string)match[2]).c_str());
				auto d = atoi(((string)match[3]).c_str());
				auto h = atoi(((string)match[4]).c_str());
				auto min = atoi(((string)match[5]).c_str());
				auto s = atoi(((string)match[6]).c_str());
				auto desc = (string)match[7];

				loggedEvents.add(DateTime(y, m, d, h, min, s), desc);
			}
		}
	}

	return &loggedEvents;
}