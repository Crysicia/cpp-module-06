#include <cctype>
#include <cstdlib>
#include <iostream>

class Convert {

};

#define F_UNKNOWN 0
#define F_INT 1
#define F_FLOAT 2
#define F_DOUBLE 3
#define F_CHAR 4

bool isCorrectlyFormatted(const char c, const size_t index, const size_t string_length) {
	static const std::string charset = "0123456789-.f";

	if (charset.find(c) == std::string::npos) { return false; }
	if (index == 0 && (!std::isdigit(c) && c != '-')) { return false; }
	if (index == 1 && (!std::isdigit(c) && c != '.')) { return false; }
	if (c == '-' && (index != 0 || index == string_length - 1)) { return false; }
	if (c == 'f' && (index != string_length - 1 || index == 0)) { return false; }
	return true;
}


int getType(const std::string &input) {
	size_t dot_count = 0;
	size_t string_length = input.length();
	const char last_char = input[string_length - 1];


	if (string_length == 1 && std::isprint(last_char)) { return F_CHAR; }
	for (size_t i = 0; i < string_length; i++) {
		if (!isCorrectlyFormatted(input[i], i, string_length)) { return F_UNKNOWN; }
		if (input[i] == '.') { dot_count++; }
	}
	if (last_char != 'f' && dot_count == 0) { return F_INT; }
	if (dot_count != 1) { return F_UNKNOWN; }
	if (!std::isdigit(input[input.rfind('.') + 1])) { return F_UNKNOWN; }
	if (last_char == 'f') { return F_FLOAT; }
	if (last_char != 'f') { return F_DOUBLE; }
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
