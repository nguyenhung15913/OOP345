/*static*/

//#include "generic.h"
//void increment();
//void display();
//int main() {
//	increment();
//	display();
//	counter++;
//	std::cout << "[main] counter = " << counter << std::endl;
//	std::cout << "[main] address of counter = " << &counter << std::endl;
//}

#include <iostream>

/*Command line argument*/

//int main(int argc, char* argv[]) {
//	int i;
//
//	std::cout << "Course: " << argv[0] << std::endl;
//
//	for (int i = 0; i < argc; i++)
//	{
//	std::cout << " - [" << argv[i][0] << "][" << argv[i][3] << "]" << std::endl;
//	}
//}

/*unsigned*/

//int main() {
//	unsigned char x = 0;
//	unsigned char y = 150;
//	std::cout << "Entering the loop" << std::endl;
//	for (; x < 2 * y; x++) {
//	std::cout << "x=" << (int)x << std:: endl;
//	}
//	std::cout << "Came out of the loop" << std::endl;
//	std::cout << " X = " << (int)x << std::endl;

/*error*/

//int main() {
//	int n0 = 7;
//	int n1 = 7.2;
//	int n2{ 6 };
//	int n3 = { 5.5 };
//
//	std::cout << n0 << std::endl;
//	std::cout << n1 << std::endl;
//	std::cout << n2 << std::endl;
//}

/*auto*/

//int main() {
//	int a[]{ 1,2,3,4,5,6 };
//	const auto n = 6;
//	for (auto i = 0; i < n; i++) {
//		std::cout << a[i] << ' ';
//	}
//	std::cout << std::endl;
//}

/*convert by static_cast*/

//int main() {
//	int* i;
//	char* c;
//	i = c; // error
//
//	int* i;
//	char* c;
//	i = static_cast<int*>(static_cast<void*>(c));
//int i = 5;
//void* v = &i;
//std::cout << *v << std:: end; // error
//int i = 5;
//void* v = &i;
//std::cout << *static_cast<int*>(v) << std::endl;
//}


/*reference*/

//template <typename T>
//void print(T& val) {
//	std::cout << "l-value:" << val << std::endl;
//}
//
//template <typename T>
//void print(T&& val) {
//	std::cout << "r-value:" << val << std::endl;
//}
//
//int main() {
//	static int xyz = 55;
//	int a{ 900 };
//	float c(30);
//	print(a);
//	print(float(30));
//	print(a + c);
//	print(a + c);
//	print(xyz);
//	print(std::move(a));
//}

// Curly brace -> l-value, parenthesese -> r-value, move->r-value

/*auto and ref*/ 
//int main() {
//
//	int foo(10);
//	/*Change foo to bar*/
//	auto bar = std::ref(foo);
//	++bar;
//	++foo;
//	std::cout << foo << '\n';
//
//	/*dont change anything just display*/
//	int bar;
//	bar = std::ref(foo);
//	++bar;
//	std::cout << foo << '\n';
//	std::cout << bar << '\n';
//}

/*auto for each*/

//int main() {
//	int a[]{ 1,2,3,4,5,6 };
//	for (auto e : a) {
//		e += 2;
//	}
//
//	for (auto& e : a) {
//		e++;
//	}
//	for (auto& e : a) {
//		std::cout << e << ' ';
//	}
//	std::cout << std::endl;
//}

/*class*/ 
//class Subject { unsigned number;    
//char desc[41];      
//Subject preRequisite; // error phai bo asterisk vao
//}

/*class 2*/ 
//class Subject {
//	const int id = 100;
//	Subject() : id(5) {
//		id = 5; error vi co constant
//	}
//};

/*range*/

//int main() {
//	unsigned char x = 0;
//	unsigned char y = 150;
//	x = 2 * y;
//	std::cout << "x=" << (int)x << std::endl;
//}