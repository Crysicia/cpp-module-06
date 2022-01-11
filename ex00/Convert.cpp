#include "Convert.hpp"

Convert::Convert() : m_input(0.0) {}
Convert::Convert(const std::string& input) {
	if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0])) { 
		m_input = static_cast<double>(input[0]);
		return ;
	}
	m_input = std::stod(input);
}

Convert::Convert(const Convert& copy) : m_input(copy.m_input) { *this = copy; }
Convert::~Convert() {}
Convert& Convert::operator=(const Convert& rhs) {
	if ( this == &rhs ) { return *this; }
	this->m_input = rhs.m_input;
	return *this;
}

char Convert::toChar(void) {
	if (isnan(m_input) || isinf(m_input) || m_input < 0 || m_input > 128) { throw CannotConvertException(); }
	if (!std::isprint(m_input)) { throw NotPrintableException(); }
	return static_cast<char>(m_input);
}

int Convert::toInt(void) {
	if (isnan(m_input) || isinf(m_input) || m_input < INT_MIN || m_input > INT_MAX) { throw CannotConvertException(); }
	return static_cast<int>(m_input);
}

float Convert::toFloat(void) {
	return static_cast<float>(m_input);
}

double Convert::toDouble(void) {
	return m_input;
}

const char* Convert::CannotConvertException::what(void) const throw() {
	return "impossible";
}

const char* Convert::NotPrintableException::what(void) const throw() {
	return "Non displayable";
}
