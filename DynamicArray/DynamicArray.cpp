#include "DynamicArray.h"
#include<Windows.h>

DynamicArray::DynamicArray():ptr(nullptr),size(0)
{}
DynamicArray::DynamicArray(int S)
{
	cout << "Construct by 1 param\n";
	size = S;
	ptr = new int[S];	
}

DynamicArray::DynamicArray(const DynamicArray & a)// copy constructor
{
	cout << "Copy construct\n";
	size = a.size;
	ptr = new int[size];
	for (int i = 0; i < size; i++)
	{
		ptr[i] = a.ptr[i];
	}
}
DynamicArray::~DynamicArray()
{
	cout << "Destruct\n";
	delete[] ptr;
}
void DynamicArray::Input()
{
	for (int i = 0; i < size; i++)
	{
		ptr[i] = rand() % 20;
	}
}
void DynamicArray::Output()const
{
	for (int i = 0; i < size; i++)
	{
		cout<<ptr[i] <<"\t";
	}
	cout << "\n---------------------------------\n";
}
void DynamicArray::ReSize(int size)
{
	int* newptr = new int[this->size + size];
	for (size_t i = 0; i < this->size + size; i++)
	{
		if (i < this->size)
			newptr[i] = ptr[i];
		else
			newptr[i] = 0;
	}
	this->size += size;
	delete[] ptr;
	ptr = newptr;
}
void DynamicArray::Sort()
{
	int i, j;
	for (i = 0; i < size - 1; i++)
		for (j = 0; j < size - i - 1; j++)
			if (ptr[j] > ptr[j + 1])
				swap(ptr[j], ptr[j + 1]);
}
int DynamicArray::Search(int a) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (ptr[i] == a)
			return i;
	}
	return -1;
}
void DynamicArray::Reverse()
{
	for (size_t i = 0; i < size/2; i++)
	{
		swap(ptr[i], ptr[size - i - 1]);
	}
}
int * DynamicArray::GetPointer() const
{
	return ptr;
}
int DynamicArray::GetSize()const
{
	return size;
}