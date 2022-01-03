#ifndef BASE_HPP
#define BASE_HPP
#include <cstdlib>
#include <iostream>
#include <ctime>

class Base {
public:
	virtual ~Base();
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
