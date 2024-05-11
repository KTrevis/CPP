#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main() {
	{
		ShrubberyCreationForm	form;
		Bureaucrat				b("Michel", 1);

		b.executeForm(form);
	}
	{
		ShrubberyCreationForm	form;
		Bureaucrat				b("Michel", 150);

		b.executeForm(form);
	}
}
