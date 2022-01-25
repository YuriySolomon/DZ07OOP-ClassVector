#include "MyVector.h"

MyVector::MyVector() : MyVector(10)
{
}
MyVector::MyVector(int capacity)
{
	SetCapacity(capacity);
}
MyVector::MyVector(const MyVector& original)
{
	cout << "Copy C-TOR P\n";
	size = original.size;
	SetCapacity(original.capacity);
	for (int i = 0; i < size; i++)
	{
		ar[i] = original.ar[i];
	}
}
MyVector::~MyVector()
{
	if (ar != nullptr) delete[] ar;
}

void MyVector::SetCapacity(int capacity)
{
	if (capacity < 10)
	{
		throw "Invalid number entered";
	}
	this->capacity = capacity;
	ar = new int[capacity];
}
int MyVector::GetCapacity() const
{
	return capacity;
}
int MyVector::GetSize() const
{
	return size;
}

void MyVector::EnsureCapacity(int size)
{
	if (size < capacity) return;
	this->capacity = this->capacity * 1.5 + 1;
	int* temp = new int[this->capacity];
	for (int i = 0; i < size; i++)
	{
		temp[i] = ar[i];
	}
	delete[] ar;
	ar = temp;
}

void MyVector::Print() const
{
	if (IsEmpty())
	{
		cout << "Vector is empty.\n";
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			cout << ar[i] << " ";
		}
		cout << endl;
	}
}

bool MyVector::IsEmpty() const
{
	return size == 0;
}

void MyVector::PushBack(int value)
{
	EnsureCapacity(size + 1);
	ar[size++] = value;
}

void MyVector::PushFront(int value)
{
	EnsureCapacity(size + 1);
	size++;
	int* temp = new int[capacity];
	temp[0] = value;
	for (int i = 0; i < size; i++)
	{
		temp[i + 1] = ar[i];
	}
	delete[] ar;
	ar = temp;
}

void MyVector::Clear()
{
	for (int i = 0; i < size; i++)
	{
		ar[i] = 0;
	}
	size = 0;
}

void MyVector::PopBack()
{
	if (IsEmpty())
	{
		cout << "Vector is empty.\n";
	}
	else
	{
		ar[--size] = 0;
	}	
}

void MyVector::PopFront()
{
	if (IsEmpty())
	{
		cout << "Vector is empty.\n";
	}
	else
	{
		for (int i = 0; i < size - 1; i++)
		{
			ar[i] = ar[i + 1];
		}
		size--;
	}
}

void MyVector::TrimToSize()
{
	if (size < capacity / 2)
	{
		capacity = size;
		int* temp = new int[capacity];
		for (int i = 0; i < size; i++)
		{
			temp[i] = ar[i];
		}
		delete[] ar;
		ar = temp;
	}
}

void MyVector::Insert(int index)
{
	if (index < 0 || index >= size)
	{
		throw "index is out of range";
	}
	EnsureCapacity(size + 1);
	size++;
	int* temp = new int[capacity];
	for (int i = 0; i < size; i++)
	{
		if (i < index)
		{
			temp[i] = ar[i];
		}
		else if (i == index)
		{
			temp[i] = rand() % 100;
		}
		else
		{
			temp[i] = ar[i - 1];
		}
	}
	delete[] ar;
	ar = temp;
}

void MyVector::RemoveAt(int index)
{
	if (index < 0 || index >= size)
	{
		throw "index is out of range";
	}
	size--;
	int* temp = new int[capacity];
	for (int i = 0; i < size; i++)
	{
		if (i < index)
		{
			temp[i] = ar[i];
		}
		else if (i == index)
		{
			temp[i] = ar[i + 1];
		}
		else
		{
			temp[i] = ar[i + 1];
		}
	}
	delete[] ar;
	ar = temp;
}

void MyVector::Remove(int value)
{
	for (int i = 0; i < size; i++)
	{
		if (ar[i] == value)
		{
			RemoveAt(i);
		}
	}
}

void MyVector::SortAsc()
{
	int temp;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			if (ar[j] < ar[j + 1])
			{
				temp = ar[j];
				ar[j] = ar[j + 1];
				ar[j + 1] = temp;
			}
		}
	}
}

void MyVector::SortDesc()
{
	int temp;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			if (ar[j] > ar[j + 1])
			{
				temp = ar[j];
				ar[j] = ar[j + 1];
				ar[j + 1] = temp;
			}
		}
	}
}

void MyVector::Shuffle()
{
	int temp;
	int j;
	int k;
	for (int i = 0; i < size - 1; i++)
	{
		j = rand() % size;
		k = rand() % size;
		temp = ar[j];
		ar[j] = ar[k];
		ar[k] = temp;
	}
}

void MyVector::RandomFill()
{
	for (int i = 0; i < size - 1; i++)
	{
		ar[i] = rand() % 100;
	}
}

int MyVector::IndexOf(int value)
{
	for (int i = 0; i < size; i++)
	{
		if (ar[i] == value)
		{
			return i;
		}
	}
	return -1;
}

int MyVector::LastIndexOf(int value)
{
	for (int i = size - 1; i >= 0; i--)
	{
		if (ar[i] == value)
		{
			return i;
		}
	}
	return -1;
}

void MyVector::Reverse()
{
	for (int i = 0; i < size / 2; i++)
	{
		swap(ar[i], ar[size - i - 1]);
	}
}

int MyVector::GetElementAt(int index) const
{
	if (index < 0 || index >= size)
	{
		throw "index is out of range";
	}
	return ar[index];
}

MyVector& MyVector::operator = (const MyVector& v1)
{
	delete[] ar;
	size = v1.size;
	capacity = v1.capacity;
	ar = new int[capacity];
	for (int i = 0; i < v1.size; i++)
	{
		ar[i] = v1.ar[i];
	}
	return *this;
}

bool operator == (const MyVector& v1, const MyVector& v2)
{
	if (v1.size != v2.size)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < v1.size; i++)
		{
			if (v1.ar[i] != v2.ar[i])
			{
				return false;
			}
		}
	}
	return true;
}

ostream& operator << (ostream& os, const MyVector& v)
{
	for (int i = 0; i < v.size; i++)
	{
		os << v.ar[i] << " ";
	}
	return os;
}

istream& operator >> (istream& os, MyVector& v)
{
	cout << "Enter the number of array elements: ";
	os >> v.size;
	return os;
}
