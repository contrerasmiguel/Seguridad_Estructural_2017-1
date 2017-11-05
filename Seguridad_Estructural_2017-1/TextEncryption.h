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
	string encryptText(string text) const;
	string decryptText(string text) const;
};