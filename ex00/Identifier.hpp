#include <iostream>
#include <string>

#ifndef IDENTIFIER_HPP
# define IDENTIFIER_HPP

#define F_UNKNOWN 0
#define F_INT 1
#define F_FLOAT 2
#define F_DOUBLE 3
#define F_CHAR 4

class Identifier {
public:
	Identifier(const std::string& input);
	Identifier(const Identifier& copy);
	~Identifier();
	Identifier& operator=(const Identifier& rhs);

	int getType(const std::string& input);

private:
	static const size_t m_specifics_count = 3;
	static const std::string m_specifics_float[m_specifics_count];
	static const std::string m_specifics_double[m_specifics_count];
	static const std::string m_charset;

	std::string m_input;
	const size_t m_string_length;
	const char m_last_char;
	const size_t m_dot_count;

	bool isInArray(const std::string& to_find, const std::string* array, const size_t array_size);
	bool isCorrectlyFormatted(const char c, const size_t index);
	size_t stringCount(const std::string& str, const char to_count);
};
const std::string Identifier::m_specifics_float[m_specifics_count] = { "-inff", "+inff", "nanf" };
const std::string Identifier::m_specifics_double[m_specifics_count] = { "-inf", "+inf", "nan" };
const std::string Identifier::m_charset = "0123456789-.f";

#endif
