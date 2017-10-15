#include "main.h"

int main(int argCount, char* arguments[])
{
	// Esta es una lista de las teclas que sea estarán monitoreando.
	ConfigurationManager cm("configuracion_teclas.txt");

	// kw estará monitoreando las teclas contenidas en key tan pronto se llame al método run.
	KeyboardWatch kw(cm.getKeys());

	DetectionRecord dr("avi");
	kw.getListeners()->push_front(&dr);

	// Una vez configurados los listeners, se llama al método run.
	kw.run();

	return 0;
}