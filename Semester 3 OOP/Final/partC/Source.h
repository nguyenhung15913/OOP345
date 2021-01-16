/*#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <numeric>
#include <list>
using namespace std;
struct Article
{
	std::string author; // who wrote the article
	std::string title; // title of the article
	size_t cntWords; // number of words
	size_t pubDay; // day of the month, [1-31]
};

std::ostream& operator<<(std::ostream& out, const Article& theArt) {
	out << theArt.author << ":" << theArt.cntWords << ":" << theArt.pubDay << ":" << theArt.title;

	return out;
}

std::list<Article>& makeNews(std::vector<Article> object) {
	for_each(object.begin(), object.end(), [&](const Article& theArt) {
		cout << theArt << endl;
	});

	auto total = accumulate(object.begin(), object.end(), 0, [](const size_t&res, const Article& theArt) {
		return res + theArt.cntWords;
	});
	cout << "Average word count of all articles: " << total / object.size() << endl;

	auto countJohn = count_if(object.begin(), object.end(), [&](const Article& theArt) {
		return theArt.author == "John";
	});
	
	list<Article> list(countJohn);
	copy_if(object.begin(), object.end(), list.begin(),[&](const Article& theArt) {
		return theArt.author == "John";
	});

	sort(object.begin(), object.end(), [&](const Article& theArt, const Article& theArt2) {
		return theArt.pubDay > theArt2.pubDay;
	});

	return list;
}*/