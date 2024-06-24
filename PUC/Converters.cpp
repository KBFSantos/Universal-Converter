#pragma once

#include "Converters.h"

std::string DataConverter::ConvertSigs(std::string sig, bool idapa) {
	if (idapa)
	{
		while (sig.find("?") != std::string::npos)
			sig.replace(sig.find("?"), 1, "00");
		while (sig.find(" ") != std::string::npos)
			sig.replace(sig.find(" "), 1, "\\x");
		sig.insert(0, "\\x");

		std::string mask = "";

		for (size_t i = 1; i <= sig.length() / 4; i++)
		{
			int32_t index = i * 4 - 1;

			if (sig.at(index) == '0' && sig.at(index - 1) == '0')
				mask += "?";
			else
				mask += "x";
		}

		std::cout << "Code Style Mask: " << mask << '\n';

		std::cout << "Code Style Pattern: " << sig << '\n';
	}
	else
	{
		while (sig.find("00") != std::string::npos)
			sig.replace(sig.find("00"), 2, "?");
		while (sig.find("\\x") != std::string::npos)
			sig.replace(sig.find("\\x"), 2, " ");

		std::cout << "IDA Style Sig: " << sig << '\n';
	}

	return sig;


}

std::string DataConverter::UpperString(std::string text) {
	std::transform(text.begin(), text.end(), text.begin(), ::toupper);
	return text;
}

std::string DataConverter::LowerString(std::string text) {
	std::transform(text.begin(), text.end(), text.begin(), ::tolower);
	return text;
}

std::string DataConverter::InvertString(std::string text) {

	std::string inversedString = LowerString(text);
	for (int i = 0; i < text.length(); i++) {

		if (i == 0)
			inversedString[i] = toupper(inversedString[i]);
		else
			inversedString[i * 2] = toupper(inversedString[i * 2]);

	}
	return inversedString;
}

std::string DataConverter::StringToCaptalizedCase(std::string text)
{
	std::string outText = text;
	for (int i = 0; i < text.length(); i++) {
		if (i == 0)
			outText[i] = toupper(outText[i]);
		else if (outText[i] == ' ')
			outText[i + 1] = toupper(outText[i + 1]);
		else
			outText[i] = tolower(outText[i]);

	}

	return outText;
}

float DataConverter::BitToByte(float bitcount) {
	return bitcount * BitValueRelativeByte;
}

float DataConverter::BitToKBT(float bitcount) {
	return bitcount * BitValueRelativeKB;
}
