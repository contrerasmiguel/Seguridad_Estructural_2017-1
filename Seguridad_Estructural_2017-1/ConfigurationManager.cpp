#include "ConfigurationManager.h"

const vector<int> ConfigurationManager::DEFAULT_KEY_CODES = vector<int>{ 37, 102 };

ConfigurationManager::ConfigurationManager(string fileName) : configFileName(fileName) { }

vector<int> ConfigurationManager::getKeys() const {
	ifstream ifs(configFileName);
	vector<int> keyCodes;

	cout << "ConfigurationManager: abriendo archivo de configuracion '" << configFileName << "'..." << endl;

	if (ifs) {
		cout << "ConfigurationManager: archivo de configuracion abierto correctamente." << endl;
		ifs.seekg(0L, ios::beg);

		int keyCode;

		while (ifs >> keyCode) {
			keyCodes.push_back(keyCode);
		}
	}

	else {
		if (!std::experimental::filesystem::exists(configFileName)) {
			cout << "ConfigurationManager: no existe un archivo de configuracion." << endl;
			createConfigFile();
		}

		else {
			cerr << "ConfigurationManager: ocurrio un error al intentar abrir el archivo de configuracion." << endl;
		}

		keyCodes = DEFAULT_KEY_CODES;
	}

	return keyCodes;
}

void ConfigurationManager::createConfigFile() const
{
	cout << "ConfigurationManager: creando archivo de configuracion '"<< configFileName <<"'..." << endl;
	ofstream ofs(configFileName);

	if (ofs) {
		cout << "ConfigurationManager: archivo de configuracion creado." << endl;

		for (auto it = DEFAULT_KEY_CODES.begin(); it != DEFAULT_KEY_CODES.end(); ++it) {
			ofs << (*it) << " ";
		}
	}
	else {
		cerr << "ConfigurationManager: ocurrio un error al intentar crear el archivo de configuracion." << endl;
	}
}