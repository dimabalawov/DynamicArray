#pragma once
#include "DynamicArray.h"



DynamicArray GetObj() //возврат по значению
{
	DynamicArray obj(3);
	obj.Input();

	return obj;
}
void main()
{
	srand(time(0));
	//DynamicArray a(5); // constructor 1 param
	//a.Input();
	//a.Output();
	//DynamicArray b = a; // copy constructor
	//b.Output();

	//DynamicArray rezult = GetObj();"
	DynamicArray a(5);
	a.Input();
	a.Output();
	a.ReSize(2);
	a.Output();
	a.Sort();
	a.Output();
	a.Reverse();
	a.Output();
	cout << "Search: " << a.Search(0) << endl;


	system("pause");
}