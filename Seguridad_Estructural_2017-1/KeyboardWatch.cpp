#include "KeyboardWatch.h"

const int KeyboardWatch::VK_Q = 0x51;

void KeyboardWatch::notifyDetectToListeners() const {
	//cout << "KeyboardWatch: llamado a funcion miembro onDetect en listeners." << endl;
	for (auto it = listeners.begin(); it != listeners.end(); ++it) {
		(*it)->onDetect();
	}
}

void KeyboardWatch::notifyDetectStopToListeners() const {
	//cout << "KeyboardWatch: llamado a funcion miembro onDetectStop en listeners." << endl;
	for (auto it = listeners.begin(); it != listeners.end(); ++it) {
		(*it)->onDetectStop();
	}
}

void KeyboardWatch::checkKeyboardState() {
	auto hasDetected = false;

	if (GetAsyncKeyState(VK_Q) & 0x80000) {
		exitRequest = true;
	}

	for (auto it = keys.begin(); it != keys.end(); ++it) {
		// Si el estado de la tecla fue PRESIONADA...
		if (GetAsyncKeyState(*it) & 0x8000) {
			hasDetected = true;
		}
	}

	// Si estado cambió de no detectado a detectado...
	if (hasDetected && !hadDetected) {
		notifyDetectToListeners();
	}

	// Si el estado cambió de detectado a no detectado...
	else if (!hasDetected && hadDetected) {
		notifyDetectStopToListeners();
	}

	// Actualizar el estado previo.
	hadDetected = hasDetected;
}

KeyboardWatch::KeyboardWatch(vector<int> keys) : keys(keys), hadDetected(false), exitRequest(false) { }

void KeyboardWatch::run() {
	cout << "KeyboardWatch: modalidad de deteccion activada." << endl;
	cout << "KeyboardWatch: presione Q para salir de la modalidad de deteccion." << endl;

	while (!exitRequest) {
		checkKeyboardState();
	}
}

forward_list<KeyboardEventListener*>* KeyboardWatch::getListeners() {
	return &listeners;
}