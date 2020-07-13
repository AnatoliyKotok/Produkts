#pragma once
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
class Produkts
{
public:
	Produkts() = default;
	Produkts(const string name, double price, size_t count) : nameP(name), price(price), count(count) {

	}
	const string& getName() const {
		return nameP;
	}
	const double& getPrice()const {
		return price;
	}
	const size_t& getCount()const {
		return count;
	}
	void print() {
		cout << "Name->" << nameP << endl;
		cout << "Price->" << price << endl;
		cout << "Count->" << count << endl;

	}
private:
	string nameP;
	double price;
	size_t count;
};

class BinaryP {
public:
	static void write(const Produkts& p, const string& fname) {
		ofstream file(fname, ios_base::binary);
		if (!file) {
			cerr << "Error\n";
			return;
		}
		size_t length = p.getName().size();
		file.write(reinterpret_cast<char*>(&length), sizeof(length));
		file.write(p.getName().c_str(), length);
		file.write(reinterpret_cast<const char*>(&p.getPrice()), sizeof(p.getPrice()));
		file.write(reinterpret_cast<const char*>(&p.getCount()), sizeof(p.getCount()));
	}
	Produkts read(const string& fname) {
		string result;
		double price;
		size_t count;
		ifstream file(fname, ios_base::binary);
		if (!file.is_open()) {
			cerr << "Error" << endl;
			return Produkts();
		}
		size_t length;
		file.read(reinterpret_cast<char*>(&length), sizeof(length));
		result.resize(length);
		file.read(const_cast<char*>(result.c_str()), length);
		file.read(reinterpret_cast<char*>(&price), sizeof(price));
		file.read(reinterpret_cast<char*>(&count), sizeof(count));
		return Produkts(result, price, count);
	}
};
