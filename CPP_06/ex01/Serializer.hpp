#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "iostream"
#include "Data.hpp"

class Serializer {
	
	public:
	Serializer() = delete;
	~Serializer() = delete;
	Serializer(const Serializer &src) = delete;
	Serializer& operator=(const Serializer &src) = delete;

	uintptr_t	serialize(Data* ptr);
	Data*		deserialize(uintptr_t raw);
};


#endif