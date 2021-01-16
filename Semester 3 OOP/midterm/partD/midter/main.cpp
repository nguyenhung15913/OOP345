// main.cpp
#include <iostream>
#include "foo.h"
const int wordLength = 8;
int add(int a, int b) {
	int xy = 0;
	return (a + b);
}
int main(char* argv[]) {
	Foo vzk(100, 55);
	std::cout << add(500, 100) << std::endl;
	std::cout << vzk.getValue(50) << std::endl;
}