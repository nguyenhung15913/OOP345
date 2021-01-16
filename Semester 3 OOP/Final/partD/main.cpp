//#include <iostream> // do not change
//using namespace std; // do not change
//struct A { // do not change
//	 int x; // do not change changed
//	A(const int c)
//	{
//		x = c;
//	}
//	void operator()() // do not change
//	{
//		cout << x << '/n';
//	}
//};
//void foo(void* c) // do not change
//{
//	int* j;
//	j = static_cast<int*>(c);
//	cout << *j << ':';
//}
//int main(int argc, char* argv[])
//{
//	int c{ 5 }; // do not change
//	foo(&c); // do not change
//	A a(c); // do not change
//	++(++c);
//	/*(c++)++;*/
//	if (argv[0][0] == 'x' && argc > 1)
//		a();
//	return 0;
//}

#include <iostream> // do not change
using namespace std; // do not change
struct A { // do not change
	 int x; // do not change
	A(const int c)
	{
		x = c;
	}
	void operator()() // do not change
	{
		cout << x << '\n';
	}
};
void foo(void* c) // do not change
{
	int* j;
	j = static_cast<int*>(c);
	cout << *j << ':';
}
int main(int argc, char* argv[])
{
	int c{ 5 }; // do not change
	foo(&c); // do not change
	A a(c); // do not change
	++(++c);
	if (argv[0][0] == 'x' && argc > 1)
		a();
	return 0;
}
