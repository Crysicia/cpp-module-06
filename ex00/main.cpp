#include <iostream>
#include "Convert.hpp"

int main(int argc, char *argv[]) {
	Convert *converter;

	if (argc != 2) {
		std::cout << "Wrong number of arguments." << std::endl;
		return 1;
	}

	try { converter = new Convert(argv[1]); }
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
		return 1;
	}

	std::cout << "char: ";
	try { std::cout << converter->toChar() << std::endl; }
	catch (std::exception& e) { std::cout << e.what() << std::endl; }

	std::cout << "int: ";
	try { std::cout << converter->toInt() << std::endl; }
	catch (std::exception& e) { std::cout << e.what() << std::endl; }

	std::cout << "float: ";
	try {
		std::cout << converter->toFloat();
		if (!fmod(converter->toFloat(), 1)) { std::cout << ".0"; }
		std::cout << "f" << std::endl;
	} catch (std::exception& e) { std::cout << e.what() << std::endl; }


	std::cout << "double: ";
	try {
		std::cout << converter->toDouble();
		if (!fmod(converter->toDouble(), 1)) { std::cout << ".0"; }
		std::cout << std::endl;
	} catch (std::exception& e) { std::cout << e.what() << std::endl; }

	delete converter;
	return 0;
}
