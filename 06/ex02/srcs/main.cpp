#include "Base.hpp"
#include <cstdlib>
#include <ctime>

void	test() {
	Base	base;
	Base	*ptr = base.generate();
	base.identify(*ptr);
	delete ptr;
}

int	main() {
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
		test();
	A a;
	Base base;
	base.identify(a);
}
