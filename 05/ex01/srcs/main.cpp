#include "Bureaucrat.hpp"
#include "Form.hpp"

void	deleteStuff(Bureaucrat *&b, Form *&form) {
	delete b;
	b = NULL;
	delete form;
	form = NULL;
}

int	main() {
	Bureaucrat	*b;
	Form		*form;

	try {
		b = new Bureaucrat("Michel", 1);
		form = new Form("form", 1);
		b->signForm(*form);
		b->signForm(*form);
		deleteStuff(b, form);

		b = new Bureaucrat("Michel", 2);
		form = new Form("form", 1);
		b->signForm(*form);
		deleteStuff(b, form);
	} catch (std::exception &e) {
		deleteStuff(b, form);
		std::cout << e.what();
	}

	b = new Bureaucrat("Michel", 2);
	form = new Form("form", 1);
	try {
		form->beSigned(*b);
	} catch (std::exception &e) {
		deleteStuff(b, form);
		std::cout << e.what() << std::endl;
	}
}
