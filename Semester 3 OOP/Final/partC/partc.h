#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <numeric>
#include <list>
using namespace std;

struct Device
{
	std::string model;
	std::string maker; // the brand of the device
	double price = 0.0;
};

std::list<Device> handleElectronics(std::vector<Device>& object) {
	//Question 1
	auto countSamsung = count_if(object.begin(), object.end(), [&](const Device& theDev) {
		return theDev.maker == "Samsung";
		});
	list<Device> list(countSamsung);
	copy_if(object.begin(), object.end(), list.begin(), [&](const Device& theDev) {
		return theDev.maker == "Samsung";
	});

	//Question 2
	for_each(object.begin(), object.end(), [&](const Device& theDev) {
		cout << theDev.model << ":" << theDev.price << endl;
	});

	//Question 3
	auto total = accumulate(object.begin(), object.end(), 0, [](const size_t& res, const Device& theDev) {
		return res + theDev.price;
		});
	cout << "Average word count of all articles: " << total / object.size() << endl;

	//Question 4
	sort(object.begin(), object.end(), [&](const Device& theDev, const Device& theDev2) {
		return theDev.maker > theDev2.maker;
	});

	return list;
}
