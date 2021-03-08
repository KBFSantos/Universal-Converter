#include <iostream>
#include <Bits.h>
#include <bitset>
#include <math.h>
#include <algorithm>
#include <string>

template<std::size_t N>
int BinaryToInt(std::bitset<N>& b) {
	constexpr int PowerBase = 2;
	int result = 0;
	int mult = 0;
	for (int i = 0; i <= b.size() - 1; i++) {
		if (b[i] != 1 && b[i] != 0)
			break;

		mult = pow(PowerBase, i);
		result += b[i] * mult;
		

	}
	return result;
}

std::string ConvertSigs(std::string sig,bool idapa) {
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

std::string UpperString(std::string text) {
	std::transform(text.begin(), text.end(), text.begin(), ::toupper);
	return text;
}

std::string LowerString(std::string text) {
	std::transform(text.begin(), text.end(), text.begin(), ::tolower);
	return text;
}