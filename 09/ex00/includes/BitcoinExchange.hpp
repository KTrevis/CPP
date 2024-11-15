#ifndef _BitcoinExchange_HPP_
#define _BitcoinExchange_HPP_

#include <iostream>
#include <map>
#include <vector>

class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &obj);
		~BitcoinExchange();
		BitcoinExchange &operator=(const BitcoinExchange &obj);
		void	convert(const std::string &filename);
	private:
		std::string	error(std::vector<std::string> &line);
		std::map<std::string, float> _database;
};

#endif
