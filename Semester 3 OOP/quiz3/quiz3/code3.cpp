#include <iostream>
#include <vector>

int main() {
	std::vector<int> first;
	std::vector<int> second(4, 100);
	std::vector<int> third(second.begin(), second.end());
	std::vector<int>fourth(std::move(third));
	std::vector<int> fifth(fourth);

	int myints[] = { 16,2,77,29 };
	std::vector<int> sixth(myints, myints + sizeof(myints) / sizeof(int));
	std::cout << std::endl << "The contents of first are:";
	for (std::vector<int>::iterator it = first.begin(); it != first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl << "The contents of second are:";
	for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl << "The contents of third are:";
	for (std::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl << "The contents of fourth are:";
	for (std::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl << "The contents of fifth are:";
	for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl << "The contents of sixth are:";
	for (std::vector<int>::iterator it = sixth.begin(); it != sixth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	return 0;
}