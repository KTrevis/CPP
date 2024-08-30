#ifndef _Displayer_HPP_
#define _Displayer_HPP_

#include <iostream>

class Displayer {
	public:
		static void	display(char c);
		static void	display(int n);
		static void	display(float f);
		static void	display(double d);
	private:
		Displayer();
		Displayer(Displayer const &obj);
		~Displayer();
		Displayer &operator=(const Displayer &obj);
};

#endif
