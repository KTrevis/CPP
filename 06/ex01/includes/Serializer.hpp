#ifndef _Serializer_HPP_
#define _Serializer_HPP_

#include <stdint.h>
#include <iostream>

class	Data;

class Serializer {
	public:
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);

	private:
		Serializer();
		Serializer(Serializer const &obj);
		~Serializer();
		Serializer &operator=(const Serializer &obj);
};

#endif
