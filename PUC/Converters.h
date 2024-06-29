#pragma once

#include <Bits.h>
#include <bitset>
#include <math.h>
#include <string>


namespace DataConverter {

	constexpr float BitValueRelativeByte = 0.125f;
	constexpr double BitValueRelativeKB = 0.000125;



	template<std::size_t bitsetlenght> int BinaryToInt(std::bitset<bitsetlenght>& b) {
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

	std::string ConvertSigs(std::string sig, bool idapa);

	std::string UpperString(std::string text);

	std::string LowerString(std::string text);

	std::string InvertString(std::string text);

	std::string StringToCaptalizedCase(std::string text);

	float BitToByte(float bitcount);

	float BitToKBT(float bitcount);
}
