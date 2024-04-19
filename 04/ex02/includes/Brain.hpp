#ifndef _Brain_HPP_
#define _Brain_HPP_

#include <iostream>

class Brain {
	public:
		Brain();
		Brain(Brain const &obj);
		~Brain();
		Brain &operator=(const Brain &obj);
		void	displaySomeIdeas();
	
	private:
		std::string	ideas[100];
};
#endif
