#include "MyVector.h"

int main()
{
	MyVector v1;
	v1.Print();

	v1.PushBack(10);
	v1.Print();
	
	v1.PushFront(15);
	v1.Print();

	MyVector v2;
	v2 = v1;
	v2.Print();

	cout << (v2 == v1) << "\n";

	system("pause >> NULL");
}
