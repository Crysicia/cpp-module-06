#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base* generate(void) {
	Base* ptr = NULL;

	switch (std::rand() % 3)
	{
		case 0:
			ptr = new A;
			break;
		case 1:
			ptr = new B;
			break;
		case 2:
			ptr = new C;
			break;
	}
	return ptr;
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p) {
	try {
		A& a_ref = dynamic_cast<A&>(p);
		(void) a_ref;
		std::cout << "A" << std::endl;
		return ;
	} catch (std::exception& e) { }

	try {
		B& b_ref = dynamic_cast<B&>(p);
		(void) b_ref;
		std::cout << "B" << std::endl;
		return ;
	} catch (std::exception& e) { }

	try {
		C& c_ref = dynamic_cast<C&>(p);
		(void) c_ref;
		std::cout << "C" << std::endl;
		return ;
	} catch (std::exception& e) { }
}

int main(void) {
	std::srand(std::time(NULL));

	for (int i = 0; i < 5; i++) {
		std::cout << "---- Initialize random base class ----" << std::endl;
		Base* random_class = generate();

		std::cout << "---- Identify using pointer ----" << std::endl;
		identify(random_class);

		std::cout << "---- Identify using reference ----" << std::endl;
		identify(*random_class);

		delete random_class;
		std::cout << std::endl << std::endl;
	}

	return 0;
}
