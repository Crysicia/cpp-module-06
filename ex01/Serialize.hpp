#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP
#include <string>

struct Data {
	int magic_number;
	std::string magic_string;
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif
