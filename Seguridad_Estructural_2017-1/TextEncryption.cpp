#include "TextEncryption.h"

const short TextEncryption::DEFAULT_OFFSET = 7;

TextEncryption::TextEncryption() : offset(DEFAULT_OFFSET) { }

TextEncryption::TextEncryption(short offset) : offset(offset) { }

string TextEncryption::encryptText(string text) const
{
	string outputText;

	for (auto it = text.begin(); it != text.end(); ++it) {
		auto nextChar = (*it != ' ')
			? *it + offset
			: '$';

		outputText.append(1, nextChar);
	}

	return outputText;
}

string TextEncryption::decryptText(string text) const
{
	string outputText;

	for (auto it = text.begin(); it != text.end(); ++it) {
		auto nextChar = (*it != '$')
			? *it - offset
			: ' ';

		outputText.append(1, nextChar);
	}

	return outputText;
}
