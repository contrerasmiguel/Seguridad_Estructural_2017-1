#include "main.h"

void startKeyboardWatch()
{
	// Esta es una lista de las teclas que sea estarán monitoreando.
	ConfigurationManager cm("configuracion_teclas.txt");

	// kw estará monitoreando las teclas contenidas en key tan pronto se llame al método run.
	KeyboardWatch kw(cm.getKeys());

	kw.getListeners()->push_front(&DetectionRecord());

	// Una vez configurados los listeners, se llama al método run.
	kw.run();
}

short askForKey()
{
	short key;
	cout << "Ingrese la clave para desencriptar el archivo: ";
	cin >> key;
	clearInputBuffer();
	return key;
}

void startLogDecrypt()
{
	LogFileManager logFileManager/*(askForKey())*/;
	logFileManager.decryptFile();
}

void clearInputBuffer()
{
	cin.clear();
	cin.ignore((std::numeric_limits<streamsize>::max)(), '\n');
}

bool stringToDateTime(int* y, int* m, int* d, int* h, int* min, int* s, string str)
{
	regex pattern("\\s*(\\d+)\\s*\\-\\s*(\\d+)\\s*\\-\\s*(\\d+)\\s+(\\d+)\\s*\\:\\s*(\\d+)\\s*\\:\\s*(\\d+)\\.*");
	smatch match;

	if (regex_search(str, match, pattern)) {
		*y = atoi(((string)match[1]).c_str());
		*m = atoi(((string)match[2]).c_str());
		*d = atoi(((string)match[3]).c_str());
		*h = atoi(((string)match[4]).c_str());
		*min = atoi(((string)match[5]).c_str());
		*s = atoi(((string)match[6]).c_str());
		return true;
	}
	return false;
}

void startFromDate()
{
	cout << "Ingrese la fecha de inicio con el siguiente formato: YYYY-MM-DD HH:MM:SS" << endl;
	string line;
	int y, m, d, h, min, s;
	bool esFormatoValido;
	do {
		getline(cin, line);
		esFormatoValido = stringToDateTime(&y, &m, &d, &h, &min, &s, line);
		if (!esFormatoValido || !DateTime(y, m, d, h, min, s).isValid()) {
			cerr << "El formato de la fecha ingresada es invalido." << endl;
		}
	} while (!esFormatoValido || !DateTime(y, m, d, h, min, s).isValid());
	DateTime dt(y, m, d, h, min, s);
	LogFileManager logFileManager;
	cout << endl << logFileManager.getLoggedEvents()->showFromDate(dt) << endl;
}

void startUntilDate()
{
	cout << "Ingrese la fecha tope con el siguiente formato: YYYY-MM-DD HH:MM:SS" << endl;
	string line;
	int y, m, d, h, min, s;
	bool esFormatoValido;
	do {
		getline(cin, line);
		esFormatoValido = stringToDateTime(&y, &m, &d, &h, &min, &s, line);
		if (!esFormatoValido || !DateTime(y, m, d, h, min, s).isValid()) {
			cerr << "El formato de la fecha ingresada es invalido." << endl;
		}
	} while (!esFormatoValido || !DateTime(y, m, d, h, min, s).isValid());
	DateTime dt(y, m, d, h, min, s);
	LogFileManager logFileManager;
	cout << endl << logFileManager.getLoggedEvents()->showUntilDate(dt) << endl;
}

void startBetweenDates()
{
	cout << "Ingrese la fecha de inicio con el siguiente formato: YYYY-MM-DD HH:MM:SS" << endl;
	string line;
	int y, m, d, h, min, s;
	bool esFormatoValido;
	do {
		getline(cin, line);
		esFormatoValido = stringToDateTime(&y, &m, &d, &h, &min, &s, line);
		if (!esFormatoValido || !DateTime(y, m, d, h, min, s).isValid()) {
			cerr << "El formato de la fecha ingresada es invalido." << endl;
		}
	} while (!esFormatoValido || !DateTime(y, m, d, h, min, s).isValid());
	DateTime dtA(y, m, d, h, min, s);

	cout << "Ingrese la fecha tope con el siguiente formato: YYYY-MM-DD HH:MM:SS" << endl;
	do {
		getline(cin, line);
		esFormatoValido = stringToDateTime(&y, &m, &d, &h, &min, &s, line);
		if (!esFormatoValido || !DateTime(y, m, d, h, min, s).isValid()) {
			cerr << "El formato de la fecha ingresada es invalido." << endl;
		}
	} while (!esFormatoValido || !DateTime(y, m, d, h, min, s).isValid());

	DateTime dtB(y, m, d, h, min, s);
	LogFileManager logFileManager;
	cout << endl << logFileManager.getLoggedEvents()->showBetweenDates(dtA, dtB) << endl;
}

void startShowEverything()
{
	LogFileManager logFileManager;
	cout << endl << logFileManager.getLoggedEvents()->showEverything() << endl;
}

Option readOption()
{
	int rawOption;
	cin >> rawOption;
	clearInputBuffer();
	return (Option)rawOption;
}

void showMenu()
{
	cout << "SELECCIONE UNA OPCION"
		<< endl << OPTION_WATCH << ". Activar sistema de vigilancia."
		<< endl << OPTION_DECRYPT << ". Desencriptar registro de eventos en archivo de texto."
		<< endl << OPTION_FROM_DATE << ". Mostrar eventos registrados a partir de una fecha."
		<< endl << OPTION_UNTIL_DATE << ". Mostrar eventos registrados hasta una fecha."
		<< endl << OPTION_BETWEEN_DATES << ". Mostrar eventos registrados entre dos fechas."
		<< endl << OPTION_SHOW_EVERYTHING << ". Mostrar todos los eventos."
		<< endl << OPTION_EXIT << ". Salir."
		<< endl;
}

int main(int argCount, char* arguments[])
{
	Option option;

	do {
		showMenu();
		option = readOption();

		if (option == OPTION_WATCH) {
			startKeyboardWatch();
		}
		else if (option == OPTION_DECRYPT) {
			startLogDecrypt();
		}
		else if (option == OPTION_FROM_DATE) {
			startFromDate();
		}
		else if (option == OPTION_UNTIL_DATE) {
			startUntilDate();
		}
		else if (option == OPTION_BETWEEN_DATES) {
			startBetweenDates();
		}
		else if (option == OPTION_SHOW_EVERYTHING) {
			startShowEverything();
		}
	} while (option != OPTION_EXIT);

	return 0;
}