#pragma once

class KeyboardEventListener
{
public:
	virtual void onDetect() const = 0;
	virtual void onDetectStop() const = 0;
};
