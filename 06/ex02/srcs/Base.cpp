#include "Base.hpp"
#include <cstdlib>
#include <exception>

Base::~Base() {}

Base	*Base::generate() {
	switch (std::rand() % 3) {
		case 0: return new A;
		case 1: return new B;
		case 2: return new C;
	}
	return NULL;
}

void	Base::identify(Base &ref) {
	try {
		A &a = dynamic_cast<A &>(ref);
		static_cast<void>(a);
		std::cout << "A" << std::endl;
		return;
	} catch (std::exception &e) {}

	try {
		B &a = dynamic_cast<B &>(ref);
		static_cast<void>(a);
		std::cout << "B" << std::endl;
		return;
	} catch (std::exception &e) {}

	try {
		C &a = dynamic_cast<C &>(ref);
		static_cast<void>(a);
		std::cout << "C" << std::endl;
		return;
	} catch (std::exception &e) {}
}
