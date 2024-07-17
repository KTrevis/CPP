#include "iter.hpp"
#include <cstdlib>
#include <cstring>
#include <iostream>

template<typename T>
void	increment(T &n) {
	n++;
	std::cout << n << std::endl;
}

void	intTest() {
	const int size = 10;
	int arr[size];
	for (int i = 0; i < size; i++) {
		arr[i] = i + 1;
	}
	iter(arr, size, increment<int>);
}

void	stringTest() {
	char str[] = "aled";
	iter(str, strlen(str), increment<char>);
	std::cout << str << std::endl;
}

int	main() {
	intTest();
	stringTest();
}
