#include "Convert.hpp"

Convert::Convert(const std::string& input) : m_input(input) {}

Convert::Convert(const Convert& copy) : m_input(copy.m_input) {
	std::cout << "Convert copy constructor called" << std::endl;
	*this = copy;
}

Convert::~Convert() {
	std::cout << "Convert destructor called" << std::endl;
}

Convert& Convert::operator=(const Convert& rhs) {
	std::cout << "Convert copy operator called" << std::endl;
	if ( this == &rhs ) { return *this; }
	this->m_input = rhs.m_input;
	return *this;
}

char Convert::toChar(void) {

}

int Convert::toInt(void) {

}

float Convert::toFloat(void) {

}

double Convert::toDouble(void) {

}
