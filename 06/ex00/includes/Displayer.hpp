#ifndef _Displayer_HPP_
#define _Displayer_HPP_

#include <iostream>

class Displayer {
	public:
		static void	display(char c, int mask);
		static void	display(int n, int mask);
		static void	display(float f, int mask);
		static void	display(double d, int mask);
	private:
		Displayer();
		Displayer(Displayer const &obj);
		~Displayer();
		Displayer &operator=(const Displayer &obj);
};

#endif
