#pragma once

#include <forward_list>
#include <iostream>
#include "KeyboardEventListener.h"
#include <vector>
#include "windows.h"

using std::cout;
using std::endl;
using std::forward_list;
using std::vector;

class KeyboardWatch
{
private:
	forward_list<KeyboardEventListener*> listeners;
	vector<int> keys;
	bool hadDetected;

	// Notificación de inicio de detección.
	void notifyDetectToListeners() const;

	// Notificación de final de detección.
	void notifyDetectStopToListeners() const;

	// Verifica el estado de las teclas. Si hay un cambio de estado, notifica a los listeners.
	void checkKeyboardState();

public:
	KeyboardWatch(vector<int> keys);

	// Arranca el monitoreo.
	void run();

	// Devuelve la lista de listeners.
	forward_list<KeyboardEventListener*>* getListeners();
};

