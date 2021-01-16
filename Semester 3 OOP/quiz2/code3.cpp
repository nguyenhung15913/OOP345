/*code 3

#include <iostream>
#include <exception>
using namespace std;

class Base { virtual void dummy() {} };
class Derived :public Base { int a; };
class DerivedSecond : public Base { int b; };

int main() {
	try {
		Base* pba = new Derived;
		Base* pbc = new DerivedSecond;
		Base* pbb = new Base;

		Derived* pd;
		Base* pbase;

		pd = dynamic_cast<Derived*>(pba);
		if (pd == 0) cout << "Null pointer on first type-cast. \n";

		pd = dynamic_cast<Derived*>(pbc);
		if (pd == 0) cout << "Null pointer on second type-cast.\n";

		pd = dynamic_cast<Derived*>(pbb);
		if (pd == 0) cout << "Null pointer on third type-cast.\n";

		pbase = dynamic_cast<Base*>(pba);
		if (pbase == 0) cout << "Null pointer on fourth type-cast.\n";
	}
	catch (exception& e) {
		cout << "Exception: " << e.what();
	}
		return 0;
}*/