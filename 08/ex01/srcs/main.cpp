#include "Span.hpp"
#include <iostream>

int main() {
	try {
		std::vector<int> arr;
		arr.push_back(6);
		arr.push_back(3);
		arr.push_back(17);
		arr.push_back(9);
		arr.push_back(11);
		Span sp(arr.size());
		sp.addNumbers(arr.begin(), arr.end());

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

		// Attempting to add more numbers
		try {
			sp.addNumber(42); // Should throw exception
		} catch (const std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}

		// Testing with empty span
		Span emptySpan(5);
		try {
			std::cout << "Shortest Span: " << emptySpan.shortestSpan() << std::endl;
		} catch (const std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}

		// Testing with one number
		Span singleSpan(5);
		singleSpan.addNumber(42);
		try {
			std::cout << "Shortest Span: " << singleSpan.shortestSpan() << std::endl;
		} catch (const std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}

	} catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
