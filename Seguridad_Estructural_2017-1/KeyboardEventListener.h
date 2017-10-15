#pragma once

class KeyboardEventListener
{
public:
	virtual void onDetect() = 0;
	virtual void onDetectStop() = 0;
};
