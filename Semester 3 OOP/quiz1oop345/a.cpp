#include "generic.h"
void increment() {
	int counter = 2;
	counter = counter + 2;
	std::cout << " [increment] address of counter = " << &counter << std::endl;

}

void display() {
	std::cout << "[display] counter = " << counter << std::endl;
	std::cout << "[display] address of counter = " << &counter << std::endl;
}