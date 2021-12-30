#include <cctype>
#include <iostream>
#include "Serialize.hpp"

uintptr_t serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}

int main(void) {
	Data* data_ptr = new Data;

	data_ptr->magic_number = 42;
	data_ptr->magic_string = "Hello, World!";

	uintptr_t serialized = serialize(data_ptr);
	Data *deserialized = deserialize(serialized);

	std::cout << "Serialized value: " << serialized << std::endl;
	std::cout << "Serialized deserialized value: " << serialize(deserialized) << std::endl;

	std::cout << "Original magic number: " << deserialized->magic_number << std::endl;
	std::cout << "Original magic string: " << deserialized->magic_string << std::endl;

	std::cout << "Deserialized magic number: " << deserialized->magic_number << std::endl;
	std::cout << "Deserialized magic string: " << deserialized->magic_string << std::endl;

	delete data_ptr;
	return 0;
}
