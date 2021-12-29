#include <cctype>
#include <cstdlib>
#include <iostream>
#include "Identifier.hpp"

class Convert {
};

int main(int argc, char *argv[]) {
	int argument;
	std::string arg;

	if (argc != 2) { return 1; }
	Identifier test(argv[1]);

	std::cout << "get type: " << test.getType(argv[1]) << std::endl;
	arg = argv[1];
	argument = std::atoi(argv[1]);
	if (std::isprint(argument)) {
		std::cout << "Char: " << static_cast<char>(argument) << std::endl;
	}
	return 0;
}
