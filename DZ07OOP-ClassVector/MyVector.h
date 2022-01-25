#pragma once
#include "AllLibraries.h"

class MyVector
{
	int* ar = nullptr;
	int size = 0;
	int capacity;

	void EnsureCapacity(int size); // memory check

public:
	MyVector();
	MyVector(int capacity);
	MyVector(const MyVector& original);
	~MyVector();

	void SetCapacity(int capacity);
	int GetCapacity() const;
	int GetSize() const;
	void Print() const;
	bool IsEmpty() const;
	void PushBack(int value); // add element in back
	void PushFront(int value); // add element in front
	void Clear();
	void PopBack(); // delete element in back
	void PopFront(); // delete element in front
	void TrimToSize(); // adjusts capacity to fit size
	void Insert(int index); // insert element by index
	void RemoveAt(int index); // delete element by index
	void Remove(int value); // delete element by value
	void SortAsc(); // sort array element values in ascending order
	void SortDesc(); // sort array element values in descending order
	void Shuffle(); // random shuffling of array elements
	void RandomFill(); // filling an array with random values
	int IndexOf(int value); //linear search from left to right first
	int LastIndexOf(int value); //linear search from right to left first
	void Reverse(); //reversing the order of elements in an array
	int GetElementAt(int index) const; // return a copy of the array element at the specified index
	
	MyVector& operator = (const MyVector& v1);
	friend bool operator == (const MyVector& v1, const MyVector& v2);
	friend ostream& operator << (ostream& os, const MyVector& v);
	friend istream& operator >> (istream& os, MyVector& v);
};

bool operator == (const MyVector& v1, const MyVector& v2);
ostream& operator << (ostream& os, const MyVector& v);
istream& operator >> (istream& os, MyVector& v);
