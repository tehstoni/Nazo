#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>
#include <iomanip>
#include <sstream>
#include <random>
#include <Windows.h>


std::string generateRandomKey(int length) {
	std::string key;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 255);
	for (int i = 0; i < length; i++) {
		key += dis(gen);
	}
	return key;
}

std::string XOR(std::string input, std::string xorkey) {
	std::string output;
	for (int i = 0; i < input.size(); i++) {
		output += input[i] ^ xorkey[i % xorkey.size()];
	}
	return output;
}


int main (int argc, char* argv[]) {

	if (argc < 2) {
		std::cout << ("Usage: <Encoding/Encryption Type> [Output Language] [Output Filename] [-h]");
		return 1;
	}

	std::string arg1 = argv[1];
	if (arg1 == "-h" || arg1 == "--help") {
		const char* helpMessage = R"(
	Usage: <Encoding/Encryption Type> [Output Language] [Output Filename]

	Nazo is a tool to help build shellcode loaders. It will encrypt and encode shellcode to be used in C, C++, C#, or python (no judgement here).
			
	Options:
		-h, --help		Show this message and exit

		-e				Encoding/Encryption Types: XOR, RC4, AES, IPv4, IPv6

		-l				Output Language: C, C++, C#, Python.

		-o				Output Filename: The name of the file to output the shellcode to.
						If the name ends in .ico, Nazo will output an icon file, the files needed to import it, 
						the code to load it from the resources, and the compiler arguments needed to compile. 
	)";

		std::cout << helpMessage << "\n";
		return 0;
	}



	return 0;
}
