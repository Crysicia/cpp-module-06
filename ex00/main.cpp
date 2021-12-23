#include <cctype>
#include <cstdlib>
#include <iostream>

class Convert {

};

#define F_UNKNOWN 0
#define F_INT 1
#define F_FLOAT 2
#define F_DOUBLE 3

int getType(const std::string &input) {
	size_t dot_count = 0;
	size_t string_length = input.length();

	for (size_t i = 0; i < string_length; i++) {
		if (!std::isdigit(input[i]) && input[i] != '.' && ((i != string_length - 1) && input[i] == 'f')) { return F_UNKNOWN; }
		if (input[i] == '.') { dot_count++; }
	}
	if (input[string_length - 1] == 'f' && dot_count == 1) { return F_FLOAT; }
	if (input[string_length - 1] != 'f' && dot_count == 1) { return F_DOUBLE; }
	if (input[string_length - 1] != 'f' && dot_count == 0) { return F_INT; }
	return F_UNKNOWN;
}

int main(int argc, char *argv[]) {
	int argument;
	std::string arg;

	if (argc != 2) { return 1; }

	std::cout << "get type: " << getType(argv[1]) << std::endl;
	arg = argv[1];
	argument = std::atoi(argv[1]);
	if (std::isprint(argument)) {
		std::cout << "Char: " << static_cast<char>(argument) << std::endl;
	}
	return 0;
}
