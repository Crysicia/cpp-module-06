#ifndef CONVERT_HPP
# define CONVERT_HPP
#include <string>
#include <iostream>
#include <cmath>

class Convert {
public:
	Convert(const std::string& input);
	Convert(const Convert& copy);
	~Convert();
	Convert& operator=(const Convert& rhs);

	char toChar(void);
	int toInt(void);
	float toFloat(void);
	double toDouble(void);

	class CannotConvertException : public std::exception {
		const char* what(void) const throw();
	};

	class NotPrintableException : public std::exception {
		const char* what(void) const throw();
	};

private:
	double m_input;
};

#endif
