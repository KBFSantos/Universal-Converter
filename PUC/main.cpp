#include "Converters.h"
#include <Windows.h>


void PrintLogo();

void ClearCinBuffer();

int main() {
	SetConsoleTitleA("Universal Converter");
	do {
		system("cls");
		PrintLogo();

		int choose = 0;
		std::cout << "1 - Binary Converter\n2 - Signature Converter\n3 - ASCII Converter\n4 - Case Converter\n5 - Bit Converter\n\n";

		std::cout << "Select: ";
		
		std::cin >> choose;
		ClearCinBuffer();
		system("cls");


		std::string insertString = "";

		bool IdaPattern = false;

		std::cin.clear();

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
			std::string cascii;

			std::cout << "Insert Text: ";
			std::getline(std::cin >> std::ws, cascii);
			std::cout << "\n";

			std::cout << "Hexadecimal: ";
			for (int i = 0; i < cascii.length(); i++) {
				
				std::cout << std::hex << std::uppercase  << static_cast<int>(cascii[i]) << "  ";
			}
			std::cout << std::nouppercase;
			std::cout << std::dec;
			std::cout << "\n\n";
			std::cout << "Decimal: ";
			for (int i = 0; i < cascii.length(); i++) {

				std::cout << static_cast<int>(cascii[i]) << "  ";
			}

			std::cout << "\n\n";
			system("pause");
		}
		break;

		case 4: // Case Converter
		{
			std::string text;
			std::string textCapt;



			std::cout << "Insert Text: ";
			std::getline(std::cin >> std::ws, text);
			std::cout << "\n";
			textCapt = text;

			std::cout << "Upper Case: " << UpperString(text) << std::endl;

			std::cout << "\n";
			std::cout << "Lower Case: " << LowerString(text) << std::endl;
			std::cout << "\n";

			for (int i = 0; i < text.length(); i++) {
				if (i == 0)
					textCapt[i] = toupper(textCapt[i]);
				else if(textCapt[i] == ' ')
					textCapt[i + 1] = toupper(textCapt[i + 1]);
			}
			std::cout << "Captalized Case: " << textCapt << std::endl;


			std::cout << "\n\n";
			system("pause");
		}
		break;

		case 5:
		{
			float bitcountbuffer;
			std::cout << "Insert Bit Count: ";
			std::cin >> bitcountbuffer;
			std::cout << "\n";

			std::cout << "Byte: " << BitToByte(bitcountbuffer) << std::endl;

			std::cout << "\n";
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
		ClearCinBuffer();
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

void ClearCinBuffer() {
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(256, '\n');
	}
}