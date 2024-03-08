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
	const std::string CHARACTERS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$%^&*()-_=+[]{}|;:,./";

	std::random_device random_device;
	std::mt19937 generator(random_device());
	std::uniform_int_distribution<int> distribution(0, CHARACTERS.size() - 1);

	std::string key;
	for (int i = 0; i < length; i++) {
		key += CHARACTERS[distribution(generator)];
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

	std::string argt = argv[1];
	if (arg1 == "-t") {		
		int t_value = std::stoi(argv[2]);
		std::string testKey = generateRandomKey(t_value);
		std::cout << testKey;

		return 0;
	}

	return 0;
}
