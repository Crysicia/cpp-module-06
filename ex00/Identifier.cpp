#include "Identifier.hpp"

Identifier::Identifier(const std::string& input) : m_input(input), m_string_length(input.length()), m_last_char(input[m_string_length - 1]), m_dot_count(stringCount(input, '.')) {}

Identifier::Identifier(const Identifier& copy) : m_input(copy.m_input), m_string_length(copy.m_string_length), m_last_char(copy.m_last_char), m_dot_count(copy.m_dot_count) {
	std::cout << "Identifier copy constructor called" << std::endl;
	*this = copy;
}

Identifier::~Identifier() {
	std::cout << "Identifier destructor called" << std::endl;
}

Identifier& Identifier::operator=(const Identifier& rhs) {
	std::cout << "Identifier copy operator called" << std::endl;
	if ( this == &rhs ) { return *this; }
// 	this->m_input = rhs.m_input;
// 	this->m_string_length = rhs.m_string_length;
// 	this->m_last_char = rhs.m_last_char;
// 	this->m_dot_count = rhs.m_dot_count;
	return *this;
}

size_t Identifier::stringCount(const std::string& str, const char to_count) {
	size_t total = 0;

	for (size_t i = 0; i < m_string_length; i++) { if (str[i] == to_count) { total++; } }
	return total;
}

bool Identifier::isInArray(const std::string& to_find, const std::string* array, const size_t array_size) {
	for (size_t i = 0; i < array_size; i++) { if (array[i] == to_find) { return true; } }
	return false;
}

bool Identifier::isCorrectlyFormatted(const char c, const size_t index) {

	if (m_charset.find(c) == std::string::npos) { return false; }
	if (index == 0 && (!std::isdigit(c) && c != '-')) { return false; }
	if (index == 1 && (!std::isdigit(c) && c != '.' && c != 'f')) { return false; }
	if (c == '-' && (index != 0 || index == m_string_length - 1)) { return false; }
	if (c == 'f' && (index != m_string_length - 1 || index == 0)) { return false; }
	return true;
}

int Identifier::getType(const std::string &input) {
	if (m_string_length == 1 && std::isprint(m_last_char)) { return F_CHAR; }
	if (isInArray(input, m_specifics_double, m_specifics_count)) { return F_DOUBLE; }
	if (isInArray(input, m_specifics_float, m_specifics_count)) { return F_FLOAT; }

	for (size_t i = 0; i < m_string_length; i++) { if (!isCorrectlyFormatted(input[i], i)) { return F_UNKNOWN; } }
	if (m_last_char != 'f' && m_dot_count == 0) { return F_INT; }
	if (!std::isdigit(input[input.rfind('.') + 1])) { return F_UNKNOWN; }
	if (m_last_char == 'f' && m_dot_count <= 1) { return F_FLOAT; }
	if (m_dot_count != 1) { return F_UNKNOWN; }
	if (m_last_char != 'f') { return F_DOUBLE; }
	return F_UNKNOWN;
}