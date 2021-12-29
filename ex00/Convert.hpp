#ifndef CONVERT_HPP
# define CONVERT_HPP
#include <string>
#include <iostream>

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

private:
	std::string m_input;
};

#endif
