//
// Matrix class test program.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Matrix.h"

int testEquality()
{
	Matrix a(5, 5), b(5, 5), c(4, 5);

	//set up the a matrix,

	int mSize = a.GetMatrixSize();
	for (int i = 0; i < mSize; i++)
	{
		a.SetMatrixElement(i, i + 1);
	}

	b = a;

	// check if b = a
	cout << "Check if b = a" << endl;
	cout << " a is" << endl;
	a.Mprint();
	cout << endl << " b is " << endl;
	b.Mprint();

	if (b == a)
	{
		cout << "Success b is equal to a" << endl<< endl;
	}
	else
	{
		cout << " nope they are different" << endl << endl;
	}

	// check if b = a
	b.SetMatrixElement(24, 1);
	cout << " a is" << endl;
	a.Mprint();
	cout << endl << " b is " << endl;
	b.Mprint();

	cout << "Check if b = a" << endl;
	if (b == a)
	{
		cout << "Success b is equal to a" << endl;
	}
	else
	{
		cout << " nope they are different" << endl;
	}

	cout << endl << "Check if c = a" << endl;
	cout << " a is" << endl;
	a.Mprint();
	cout << endl << " c is " << endl;
	c.Mprint();


	if (c == a)
	{
		cout << "Success c is equal to a" << endl << endl;
	}
	else
	{
		cout << " nope they are different" << endl << endl;
	}
	return 0;
}
