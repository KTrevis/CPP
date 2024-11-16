#include "BitcoinExchange.hpp"
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

static std::vector<std::string> split(std::string str, const std::string &lim) {
	std::vector<std::string> arr;
	std::string word;
	size_t pos = 0;

	while ((pos = str.find(lim)) != std::string::npos) {
		word = str.substr(0, pos);
		if (word != "") {
			arr.push_back(word);
		}
		str.erase(0, pos + lim.length());
	}
	if (str != "") {
			word = str;
		arr.push_back(word);
	}
	return arr;
}

static std::vector<std::string> getFile(const std::string &filename) {
	std::ifstream file(filename.c_str());
	std::vector<std::string> content;
	std::string line;

	if (file.fail())
		throw std::runtime_error("Failed to read file: " + filename);
	while (std::getline(file, line))
		content.push_back(line);
	return content;
}

static bool isPositiveNumber(const std::string &str, bool isFloat = true) {
	for (int i = 0; str[i]; i++) {
		if (isFloat && i != 0 && str[i] == '.')
			continue;
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

BitcoinExchange::BitcoinExchange() {
	std::vector<std::string> file = getFile("./data.csv");

	if (file[0] != "date,exchange_rate")
		throw std::runtime_error("btc constructor: first line wrongly formatted");
	for (size_t i = 1; i < file.size(); i++) {
		std::vector<std::string> line = split(file[i], ",");

		if (line.size() != 2)
			throw std::runtime_error("btc constructor: line wrongly formatted");

		if (!isPositiveNumber(line[1]))
			throw std::runtime_error("btc constructor: value should be a positive number");

		if (_database.find(line[0]) != _database.end())
			throw std::runtime_error("btc constructor: found duplicate dates");
		_database[line[0]] = std::atof(line[1].c_str());
	}
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &obj) {
	if (this != &obj)
		*this = obj;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &obj) {
	if (this == &obj)
		return *this;
	_database = obj._database;
	return *this;
}

static bool	dateFormatIsValid(const std::string &str) {
	std::vector<std::string> date = split(str, "-");
	int n;
	if (date.size() != 3)
		return false;

	const std::string &year = date[0];
	if (!isPositiveNumber(year) || year.size() != 4)
		return false;

	const std::string &month = date[1];
	n = std::atoi(month.c_str());
	if (!isPositiveNumber(month) || month.size() != 2 || n <= 0 || n > 13)
		return false;

	const std::string &day = date[2];
	n = std::atoi(day.c_str());
	if (!isPositiveNumber(day) || day.size() != 2 || n <= 0 || n > 31)
		return false;
	return true;
}

std::string	BitcoinExchange::error(std::vector<std::string> &line) {
	if (line.size() != 2)
		return "Error: bad input => ";

	if (!dateFormatIsValid(line[0]))
		return "Error: date format invalid => ";

	if (!isPositiveNumber(line[1]))
		return "Error: not a positive number => ";

	float f = std::atof(line[1].c_str());
	if (f < 0 || f > 1000)
		return "Error: number should be between 0 and 1000 => ";

	std::map<std::string, float>::iterator it = _database.find(line[0]);
	if (it == _database.end())
		it = _database.upper_bound(line[0]);
	if (it == _database.end())
		return "Error: find failed => ";

	std::cout << line[0] << " => ";
	std::cout << f << " = ";
	std::cout << f * it->second << std::endl;
	return "";
}

void	BitcoinExchange::convert(const std::string &filename) {
	std::vector<std::string> file = getFile(filename);
	
	if (file[0] != "date | value") {
		std::cerr << "Error: first line invalid " << file[0] << std::endl;
		return;
	}

	for (size_t i = 1; i < file.size(); i++) {
		std::vector<std::string> line = split(file[i], " | ");
		const std::string &err = error(line);
		if (err != "")
			std::cerr << err << file[i] << std::endl;
	}
}
