#include <iostream>
#include "Inventory.h"
#include "Item.h"
#include <algorithm>
#include "Weapon.h"
#include "Potion.h"

using namespace std;

template<typename T>
void Inventory<T>::Assign(const Inventory<T>& other)
{
	if (this != &other) 
	{
		delete[] pItems_; 
		capacity_ = other.capacity_;
		size_ = other.size_;
		pItems_ = new T[capacity_];
		for (int i = 0; i < size_; ++i) {
			pItems_[i] = other.pItems_[i];
		}
		cout << "�κ��丮 �Ҵ� �Ϸ�" << '\n';
	}
}

template<typename T>
inline void Inventory<T>::AddItem(const T& item)
{
	if (size_ >= capacity_)
	{
		int newCap = capacity_ > 0 ? capacity_ * 2 : 1;
		Resize(newCap);
		cout << "�κ��丮 �뷮 ����: " << capacity_ << " -> " << newCap << '\n';
	}

	pItems_[size_] = item;
	++size_;


	cout << "size=" << GetSize()
		<< ", capacity=" << GetCapacity() << "\n";
}

template<typename T>
void Inventory<T>::Resize(int newCapacity)
{
	if (newCapacity <= 0) {
		delete[] pItems_;
		pItems_ = nullptr;
		capacity_ = 0;
		size_ = 0;
		return;
	}

	T* newBuf = new T[newCapacity];
	int copyCount = (size_ < newCapacity) ? size_ : newCapacity;
	for (int i = 0; i < copyCount; ++i) {
		newBuf[i] = pItems_[i];
	}

	delete[] pItems_;
	pItems_ = newBuf;
	capacity_ = newCapacity;
	size_ = copyCount; // ��ҵǸ� ����� �پ��
}

template<typename T>
void Inventory<T>::RemoveLastItem()
{
	if (size_ > 0)
	{
		--size_;
	}
	else
	{
		cout << "�κ��丮�� ��� �ֽ��ϴ�!" << '\n';
	}
}

template<typename T>
void Inventory<T>::PrintAllItems() const
{
	for (int i = 0; i < size_; i++)
	{
		pItems_[i].PrintInfo();
	}
}

template<typename T>
void Inventory<T>::SortItems()
{
	sort(pItems_, pItems_ + size_, CompareItemsByPrice);
}

template class Inventory<Item>;
template class Inventory<Weapon>;
template class Inventory<Potion>;
