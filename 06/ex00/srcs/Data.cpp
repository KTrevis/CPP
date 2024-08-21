#include "Data.hpp"

Data::Data() {}

Data::~Data() {}

Data::Data(Data const &obj) {
	if (this != &obj)
		*this = obj;
}

Data	&Data::operator=(const Data &obj) {
	if (this == &obj)
		return *this;
	return *this;
}
