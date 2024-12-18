#include "PmergeMe.hpp"
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <cwctype>
#include <deque>
#include <iostream>
#include <string>


PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const &obj) {
	if (this != &obj)
		*this = obj;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &obj) {
	if (this == &obj)
		return *this;
	return *this;
}

template <typename T>
static void	displayContainer(const T &container) {
	typename T::const_iterator it = container.begin();

	while (it != container.end()) {
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

static void	skipws(const std::string &str, size_t &i) {
	while (str[i] && std::iswspace(str[i]))
		i++;
}

template <typename T>
static bool	fillContainer(const std::string &str, T &container) {
	for (size_t i = 0; i < str.size(); i++) {
		skipws(str, i);
		if (i == str.size())
			break;
		size_t spacePos = str.find(" ", i);
		std::string substr = str.substr(i, spacePos);
		int n = std::atoi(substr.c_str());
		container.push_back(n);
		if (spacePos == std::string::npos)
			break;
		while (str[i] && isdigit(str[i]))
			i++;
	}
	return true;
}

/* void bubbleSort(std::deque<int>& v) { */
/* 	int n = v.size(); */
/*  */
/* 	for (int i = 0; i < n - 1; i++) { */
/* 		for (int j = 0; j < n - i - 1; j++) { */
/* 			if (v[j] > v[j + 1]) */
/* 				std::swap(v[j], v[j + 1]); */
/* 		} */
/* 	} */
/* } */

static std::deque<size_t> setJacobsthal() {
	std::deque<size_t> jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	while (1) {
		size_t size = jacobsthal.size();
		size_t n = 2 * jacobsthal[size - 1] + jacobsthal[size - 2];
		if (n < jacobsthal[size - 1])
			break;
		jacobsthal.push_back(n);
	}
	return jacobsthal;
}

static const std::deque<size_t> &getJacobsthal() {
	static std::deque<size_t> jacobsthal = setJacobsthal();
	return jacobsthal;
}

void	PmergeMe::mergeInsertionSort(const std::string &str) {
	getJacobsthal();
	fillContainer(str, _dq);
	std::cout << "BEFORE" << std::endl;
	displayContainer(_dq);
	std::deque<int> dq = _dq;

	clock_t	time = clock();
	sort(_dq);
	time = clock() - time;
	std::cout << "AFTER" << std::endl;
	displayContainer(_dq);
	std::cout << double(time) / CLOCKS_PER_SEC * 1000;
	std::cout << " miliseconds taken to sort deque" << std::endl;

	/* time = clock(); */
	/* bubbleSort(_dq); */
	/* time = clock() - time; */
	/* std::cout << double(time) / CLOCKS_PER_SEC * 1000; */
	/* std::cout << " miliseconds taken to bubble sort deque" << std::endl; */

	fillContainer(str, _list);

	time = clock();
	sort(_list);
	time = clock() - time;

	std::cout << double(time) / CLOCKS_PER_SEC * 1000;
	std::cout << " miliseconds taken to sort list" << std::endl;
}


template <typename T>
static T	merge(T &left, T &right) {
	T merged;
	typename T::iterator it1 = left.begin();
	typename T::iterator it2 = right.begin();

	while (it1 != left.end() && it2 != right.end()) {
		if (*it1 <= *it2) {
			merged.push_back(*it1);
			it1++;
		} else {
			merged.push_back(*it2);
			it2++;
		}
	}

	while (it1 != left.end()) {
			merged.push_back(*it1);
			it1++;
	}
	while (it2 != right.end()) {
			merged.push_back(*it2);
			it2++;
	}

	return merged;
}


void	PmergeMe::sort(std::list<int> &list) {
	if (list.size() <= 1)
		return;
	std::list<int> left, right;
	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator nextIt = list.begin();

	while (it != list.end()) {
		nextIt = it;
		nextIt++;
		if (nextIt == list.end())
			break;
		if (*it <= *nextIt) {
			left.push_back(*it);
			right.push_back(*nextIt);
		} else {
			left.push_back(*nextIt);
			right.push_back(*it);
		}
		it++;
		if (it != list.end())
			it++;
	}

	if (list.size() % 2 != 0)
    	left.push_back(list.back());

	sort(right);

	for (it = left.begin(); it != left.end(); it++) {
		std::list<int>::iterator pos = std::lower_bound(right.begin(), right.end(), *it);
		right.insert(pos, *it);
	}

	list = right;
}

void	PmergeMe::sort(std::deque<int> &dq) {
	if (dq.size() <= 1)
		return;
	std::deque<int> left, right;

	for (size_t i = 0; i + 1 < dq.size(); i += 2) {
		if (dq[i] <= dq[i + 1]) {
			left.push_back(dq[i]);
			right.push_back(dq[i + 1]);
		} else {
			left.push_back(dq[i + 1]);
			right.push_back(dq[i]);
		}
	}

	if (dq.size() % 2 != 0)
    	left.push_back(dq.back());

	sort(right);
	const std::deque<size_t> &jacobsthal = getJacobsthal();
	size_t i = 0;

	while (left.size() != 0) {
		size_t toInsert;
		if (i + 2 >= jacobsthal.size())
			toInsert = jacobsthal[jacobsthal.size() - 1];
		else toInsert = jacobsthal[i + 2];
		i++;
		if (toInsert >= left.size())
			toInsert = left.size() - 1;
		std::deque<int>::iterator pos = std::lower_bound(right.begin(), right.end(), left[toInsert]);
		right.insert(pos, left[toInsert]);
		left.erase(left.begin() + toInsert);
	}

	dq = right;
}
