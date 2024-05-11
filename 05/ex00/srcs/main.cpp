#include "Bureaucrat.hpp"

void	testGradeValues() {
	Bureaucrat	*b;

	std::cout << "GRADE TOO HIGH TEST" << std::endl;
	try {
		b = new Bureaucrat("Michel", 1);
		delete b;
		b = new Bureaucrat("Michel", 0);
		delete b;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "GRADE TOO LOW TEST" << std::endl;
	try {
		b = new Bureaucrat("Michel", 150);
		delete b;
		b = new Bureaucrat("Michel", 151);
		delete b;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void	testGradeChange() {
	Bureaucrat	*b;
	b = new Bureaucrat("Michel", 150);
	std::cout << "DECREMENT CHANGE" << std::endl;
	std::cout << *b << std::endl;
	try {
		b->decrementGrade();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	delete b;
	b = new Bureaucrat("Michel", 1);
	std::cout << "INCREMENT CHANGE" << std::endl;
	std::cout << *b << std::endl;
	try {
		b->incrementGrade();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	delete b;
}

int	main() {
	testGradeValues();
	testGradeChange();
}
