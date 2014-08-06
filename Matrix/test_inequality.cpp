// 
// Matrix class test program.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Matrix.h"

int testInequality()
{
	Matrix a(5, 5), b(5, 5), c(4, 5);

	//set up the a matrix,

	int size = a.GetMatrixSize();
	for (int i = 0; i < size; i++)
	{
		a.SetMatrixElement(i, i + 1);
	}

	b = a;

	// check if b != a
	cout << "Check if b != a" << endl;
	if (b != a)
	{
		cout << "Yes b != a, so they are different" << endl;
	}
	else
	{
		cout << " No they are equal, b = a" << endl;
	}

	cout << "Check if c != a" << endl;
	if (c != a)
	{
		cout << "Yes c != a, they are different." << endl;
	}
	else
	{
		cout << " No they are equal c = a " << endl;
	}
	return 0;
}
