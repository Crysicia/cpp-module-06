#include "Convert.hpp"

Convert::Convert() : m_input(0.0) {}
Convert::Convert(const std::string& input) {
	if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0])) { 
		m_input = static_cast<double>(input[0]);
		return ;
	}
	if (!isCorrectlyFormatted(input))
		throw IncorrectFormatException();
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

bool Convert::isCorrectlyFormatted(const std::string& input) const {
	const size_t exceptions_count = 8;
	bool qualifier_reached = false;
	bool precision_reached = false;
	std::string exceptions[exceptions_count] = { "inf", "-inf", "+inf", "inff", "-inff", "+inff", "nan", "nanf" };

	for (size_t i = 0; i < exceptions_count; i++)
		if (input == exceptions[i])
			return true;

	for (size_t i = 0; i < input.length(); i++) {
		if (qualifier_reached)
			return false;

		if (i == 0 && !std::isdigit(input[0])) {
			if (!(input[0] == '-' || input[0] == '+'))
				return false;
			continue;
		}

		if (!std::isdigit(input[i])) {
			if (input[i] == '.' && !precision_reached)
				precision_reached = true;
			else if (input[i] == 'f' && !qualifier_reached) {
				qualifier_reached = true;
				precision_reached = true;
			} else {
				return false;
			}
		}
	}
	return true;
}

const char* Convert::CannotConvertException::what(void) const throw() {
	return "impossible";
}

const char* Convert::NotPrintableException::what(void) const throw() {
	return "Non displayable";
}

const char* Convert::IncorrectFormatException::what(void) const throw() {
	return "format incorrect";
}
