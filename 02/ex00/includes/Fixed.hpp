#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
	public:
		Fixed();
		Fixed(Fixed const &ref);
		~Fixed();
		int		getRawBits(void);
		void	setRawBits(int const raw);

	private:
		int					n;
		static const int	bits;
};

#endif
