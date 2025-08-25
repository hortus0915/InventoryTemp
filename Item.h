#pragma once
#include <string>

#include <iostream>

using namespace std;

class Item
{
	string name_;
	int price_;
public:
	Item(string name_ = "", int price = 0)
		: name_(name_), price_(price) {};

	int GetPrice() const { return price_; }

	void PrintInfo() const
	{
		cout << "[이름: " << name_ << ", 가격: " << price_ << "G]" << '\n';
	};


};

inline bool CompareItemsByPrice(const Item& item1, const Item& item2)
{
	return item1.GetPrice() < item2.GetPrice();
}

