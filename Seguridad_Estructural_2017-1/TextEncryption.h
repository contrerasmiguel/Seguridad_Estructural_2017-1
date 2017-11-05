#pragma once
#include <string>

using std::string;

class TextEncryption
{
private:
	const short offset;
	static const short DEFAULT_OFFSET;

public:
	TextEncryption();
	TextEncryption(short offset);
	string encrypt(string text) const;
	string decrypt(string text) const;
};