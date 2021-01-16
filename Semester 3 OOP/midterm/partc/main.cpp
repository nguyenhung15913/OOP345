/*#include <iostream>
using namespace std;
enum PassengerType { Child, Youth, Adult, Senior, None };
struct Passenger {
	std::string name;
	PassengerType type = PassengerType::None;
public:
	bool isEmpty() const { return type == PassengerType::None; }
	Passenger() { }
	Passenger(const std::string& n, PassengerType t) {
		name = n;
		type = t;
	}
};
std::ostream& operator<<(std::ostream& os, const Passenger& client)
{
	os << "\n Passenger Name = " << client.name;
	os << "\n Passenger Type = " << client.type;
	os << "\n";
	return os;
}
template <typename T>
void print(T& val)
{
	std::cout << "l-value: " << val << std::endl;
}
template <typename T>
void print(T&& val)
{
	std::cout << "r-value: " << val << std::endl;
}
int main()
{
	static float xyz = 55;
	Passenger henry("Henry", Senior);
	Passenger mary("Mary", Child);
	double a{ 1000 };
	print(a);
	print(a + double(60));
	print(xyz);
	print(std::move(henry));
	print(mary);
	return 0;
}*/