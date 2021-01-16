/*Code 1*/
#include <iostream>

class A {
	int xyz;
public:
	A() { std::cout << " Class-A Defaut Constructor" << std::endl; };
	A(int num) : xyz(num) {};
	A(const A& src) { std::cout << " Class-A Copy Constructor - l-value " << std::endl; };
	A(const A&& src) { std::cout << "Class-A Move Constructor - R-value" << std::endl; };
	A& operator=(const A& src) { std::cout << " Class-A Copy Assignment - l - value" << std::endl; return *this;};
	A& operator=(const A&& src) { std::cout << " Class-A Move Assignment - R - value" << std::endl; return *this; };
};

class X {
	int ddd;
public:
	X(int num) : ddd(num) {};
	X() { std::cout << " Class-X Default Constructor" << std::endl; }
	X(const X& src) { std::cout << " Class-X Copy Constructor - l-value " << std::endl; };
	X(const X&& src) { std::cout << " Class-X Move Constructor - R - value " << std::endl; };
	X& operator=(const X& src) { std::cout << " Class-X Copy Assignment - l - value" << std::endl; return *this;};
	X& operator=(const X&& src) { std::cout << " Class-X Move Assignment - R - value" << std::endl; return *this; };
	A bb;
};

A s;
A b;
A foo() { return b; };
A& bar() { return s; };

int main() {
	std::cout << "***1***" << std::endl;
	s = A(20);
	std::cout << "***2***" << std::endl;
	s = foo();
	std::cout << "***3***" << std::endl;
	A s2 = bar();
	std::cout << "***4***" << std::endl;
	s= X().bb;
} 