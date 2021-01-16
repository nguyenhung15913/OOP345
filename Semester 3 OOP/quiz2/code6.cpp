/*code6

#include <iostream>
using namespace std;
template<class T> void f(T x, T y) { cout << " A-A" << endl; }
template<class T, class V> void f(T x, V y) { cout << "A-B" << endl; }
template<class T, class V, class D> void f(T x, V y, D z) { cout << "A-C" << endl; }
void f(int w, int z) { cout << "C-C" << endl; }
void f(int w, double z) { cout << "C-D" << endl; }

int main() {
	f(1, 2);
	f('a', 'b');
	f(1, 3.5);
	f(3.5, 1);
}*/