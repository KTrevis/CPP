#ifndef _PmergeMe_HPP_
#define _PmergeMe_HPP_

#include <deque>
#include <list>
#include <string>

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &obj);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe &obj);
		void	mergeInsertionSort(const std::string &input);
	private:
		void	sort(std::deque<int> &dq);
		void	sort(std::list<int> &list);
		std::deque<int>	_dq;
		std::list<int>	_list;
};

#endif
