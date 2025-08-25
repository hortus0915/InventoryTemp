#pragma once
#include "Item.h"


class Potion :  public Item
{
	int healAmount_;
public:
	Potion(string name = "", int price = 0, int healAmount = 0)
		: Item(name, price), healAmount_(healAmount) {
	}
	void PrintInfo() const {
		Item::PrintInfo();
		cout << "  [È¸º¹·®: " << healAmount_ << "]" << '\n';
	}
};

