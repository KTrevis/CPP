#ifndef _AMateria_HPP_
#define _AMateria_HPP_

#include <iostream>
#include "ICharacter.hpp"

class	AMateria {
	public:
		virtual ~AMateria();
		AMateria(AMateria const &obj);
		AMateria			&operator=(const AMateria &obj);
		std::string const	&getType() const;
		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target) = 0;

	protected:
		AMateria(std::string const &type);
		AMateria();
		const std::string	type;
};

#endif
