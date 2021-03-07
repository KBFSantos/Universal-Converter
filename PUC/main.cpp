#include "Converters.h"
#include <Windows.h>

void PrintLogo();

int main() {
	SetConsoleTitleA("Universal Converter");
	do {
		system("cls");
		PrintLogo();

		int choose = 0;
		std::cout << "1 - Binary Converter\n2 - Signature Converter\n3 - ASCII Converter\n\n";

		std::cout << "Select: ";
		std::cin.clear();
		std::cin >> choose;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
		system("cls");


		std::string insertString = "";

		bool IdaPattern = false;

		switch (choose) {

		case 1: // Binary Converter - 32 bits max size
		{
			std::bitset<32> binary;

			std::cout << "Insert Binary: ";
			std::cin >> binary;


			std::cout << "\n" << "Interger: " << BinaryToInt(binary) << std::endl;
			std::cout << "HexaDecimal: " << std::hex  << std::uppercase << BinaryToInt(binary) << std::dec << std::nouppercase << std::endl;
			std::cout << "Char: " << static_cast<char>(BinaryToInt(binary)) << std::endl;

			std::cout << "\n";
			system("pause");
		}
		break;

		case 2: // Signature Converter - IDA Style/Code Style - Credits penhax
		{


			std::cout << "Insert the Pattern: "; std::cin >> insertString;

			if (insertString.find("\\x") != std::string::npos) {
				IdaPattern = false;
				std::cout << "\n\n";
				ConvertSigs(insertString, IdaPattern);
			}
			else if (insertString.find("?") != std::string::npos) {
				IdaPattern = true;
				std::cout << "\n\n";
				ConvertSigs(insertString, IdaPattern);
			}
			else {
				std::cout << "\n\n";
				std::cout << "Error invalid Pattern!" << '\n';

			}

			std::cout << "\n";
			system("pause");
		}
		break;

		case 3: // ASCII Converter
		{
			char cascii[200];

			std::cout << "Insert Text: ";
			std::cin >> cascii;

			std::cout << "\n";

			std::cout << "Hexadecimal: ";
			for (int i = 0; i < strlen(cascii); i++) {
				
				std::cout << std::hex << std::uppercase  << static_cast<int>(cascii[i]) << "  ";
			}
			std::cout << std::nouppercase;
			std::cout << std::dec;
			std::cout << "\n\n";
			std::cout << "Decimal: ";
			for (int i = 0; i < strlen(cascii); i++) {

				std::cout << static_cast<int>(cascii[i]) << "  ";
			}

			std::cout << "\n\n";
			system("pause");
		}
		break;

		default:
		{
			std::cout << "\n";
			std::cout << "Incorrect Option";
			std::cout << "\n\n";
			system("pause");
		}
		break;





		}
	} while (true);
	



}

void PrintLogo() {
	setlocale(LC_ALL, "");

	std::cout << R"(
  _   _       _                          _    ____                          _            
 | | | |_ __ (_)_   _____ _ __ ___  __ _| |  / ___|___  _ ____   _____ _ __| |_ ___ _ __ 
 | | | | '_ \| \ \ / / _ \ '__/ __|/ _` | | | |   / _ \| '_ \ \ / / _ \ '__| __/ _ \ '__|
 | |_| | | | | |\ V /  __/ |  \__ \ (_| | | | |__| (_) | | | \ V /  __/ |  | ||  __/ |   
  \___/|_| |_|_| \_/ \___|_|  |___/\__,_|_|  \____\___/|_| |_|\_/ \___|_|   \__\___|_|   
                                                                                         )" << "\n\n";
}