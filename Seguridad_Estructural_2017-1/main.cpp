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

void startLogDecrypt()
{
	short key;
	LogFileManager logFileManager;

	cout << "Ingrese la clave para desencriptar el archivo: ";
	cin >> key;
	logFileManager.decryptFile(key);
}

Option readOption()
{
	int rawOption;
	cin >> rawOption;
	return (Option)rawOption;
}

void showMenu()
{
	cout << "SELECCIONE UNA OPCION"
		<< endl << "1. Activar sistema de vigilancia."
		<< endl << "2. Desencriptar registro de eventos."
		<< endl << "3. Salir."
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
	} while (option != OPTION_EXIT);

	return 0;
}