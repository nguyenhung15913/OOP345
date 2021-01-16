#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <thread>
#include <memory>
#include <functional>
using namespace std;
constexpr double GST{ 0.13 };
constexpr unsigned CUTOFF_YEAR{ 1900 };
struct Game {
	std::string description;
	unsigned year;
	double price;
	double price_w_tax;
};

void AddGST(vector<Game>::iterator begin, vector<Game>::iterator end);

void byName(const Game& game) {
	std::cout << game.description;
}
void byYear(const Game& game) {
	std::cout << game.year;
}

class Library {
	vector<Game> object;
	void(*displayGame)(const Game& game) = nullptr;
	bool gamePrice;
public: 
	Library& operator+=(const Game& value) {
		if (value.year >= CUTOFF_YEAR) {
			object.push_back(value);
		}
		else {
			cout << "ok";
		}
		
	}
	void display(void(*displayFn)(const Game& game), const char* str) {
		displayGame = displayFn;
		for (auto& i : object) {
			displayGame(i);	
		}
		std::thread t1(std::bind(AddGST, this->object.begin(), this->object.begin() + this->object.size() / 2));
		std::thread t2(std::bind(AddGST, (this->object.begin() + this->object.size() / 2), this->object.end()));
		t1.join();
		t2.join();
	}
};

void AddGST(vector<Game>::iterator begin, vector<Game>::iterator end)
{
	for (auto i = begin; i != end; i++) {
		i->price += GST;
		i->price_w_tax= i->price;
	}
}

int main() {
	Game game[]{
	{"Monopoly ", 1903, 22.47},
	{"Game of Life", 1860, 19.93},
	{"Battleship ", 1914, 16.99},
	{"Candyland ", 1949, 19.21},
	{"Clue ", 1950, 44.99},
	{"Sorry ", 2013, 16.99}
	};
	Library* boardgames = new Library();
	for (const auto& bg : game) {
		*boardgames += bg;
	}
	std::cout << std::fixed << std::setprecision(2);
	boardgames->display(byName, "\nBy Name");
	boardgames->display(byYear, "\nBy Year");
	delete boardgames;
}

