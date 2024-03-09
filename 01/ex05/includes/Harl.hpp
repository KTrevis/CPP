#ifndef HARL_HPP
# define HARL_HPP

#include <string>

class Harl {
	public:
		Harl();
		~Harl();
		void	complain(std::string level);

	private:
		int		strToIndex(std::string str);
		void	debug();
		void	info();
		void	warning();
		void	error();
};

#endif
