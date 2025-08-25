#pragma once
#include "Item.h"


class Weapon : public Item
{
	int damage_;

public:
	Weapon(string name = "", int price = 0, int damage = 0)
		: Item(name, price), damage_(damage) {
	}

	void PrintInfo() const {
		Item::PrintInfo();
		cout << "  [°ø°Ý·Â: " << damage_ << "]" << '\n';
	}
};

