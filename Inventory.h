#pragma once
#include <iostream>

using namespace std;

template<typename T>
class Inventory {

private:
	T* pItems_;
	int capacity_;
	int size_;

public:
	Inventory(int capacity = 10)
		: pItems_(nullptr), capacity_(capacity), size_(0)
	{
		if (capacity_ > 0) {
			pItems_ = new T[capacity_];
		}
		else
			size_ = 1;
	}

	// 복사 생성자
	Inventory(const Inventory<T>& other) {
		capacity_ = other.capacity_;
		size_ = other.size_;
		pItems_ = new T[capacity_];
		for (int i = 0; i < size_; ++i) {
			pItems_[i] = other.pItems_[i];
		}

		cout << "인벤토리 복사 완료" << '\n';
	}

	

	~Inventory() {
		delete[] pItems_;
		pItems_ = nullptr;
	}

	int GetSize() const { return size_; }
	int GetCapacity() const { return capacity_; }

	void Resize(int newCapacity);
	void Assign(const Inventory<T>& other);
	void AddItem(const T& item);
	void RemoveLastItem();
	void PrintAllItems() const;
	void SortItems();

};


