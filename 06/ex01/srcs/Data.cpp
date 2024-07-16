#include "Data.hpp"

Data::Data() {
}

Data::~Data() {
}

Data::Data(Data const &obj) {
	if (this != &obj)
		*this = obj;
}

Data	&Data::operator=(const Data &obj) {
	if (this == &obj)
		return *this;
	this->name = obj.name;
	return *this;
}

const std::string	&Data::getName() const {
	return this->name;
}

void	Data::setName(const std::string &name) {
	this->name = name;
}
