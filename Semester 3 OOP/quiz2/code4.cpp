/*code4

#include <typeinfo>
#include <iostream>

class A {
	int x;
public:
	A(int a):x(a) {}
	virtual void display() const {
		std::cout << "A: " << x << std::endl;
	}
};

class B : public A {
	int y;
public:
	B(int a = 5, int b = 6) : A(a), y(b) {}
	void display() const {
		A::display();
		std::cout << "B: " << y << std::endl;
	}
};

class C : public B {
	int z;
public:
	C(int a = 4, int b = 6, int c = 7) :B(a, b), z(c) {}
	void display() const {
	B::display();
		std::cout << "C: " << z << std::endl;
	}
};

void show(const A* a) {
	C cref;
	if (typeid(*a) != typeid(cref)) {
		a->display();
	}
	else std::cout << typeid(cref).name() << " objects are private " << std::endl;
}

int main() {
	A* a[3];
	a[0] = new A(3);
	a[1] = new B(2, 5);
	a[2] = new C(4, 6, 7);
	for (int i = 0; i < 3; i++) {
		show(a[i]);
	}
	for (int i = 0; i < 3; i++) {
		std::cout << typeid(a[i]).name() << std::endl;
	}
	for (int i = 0; i < 3; i++) {
		delete a[i];
	}
} */