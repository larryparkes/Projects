//
// Matrix class test program.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Matrix.h"

int testAdd()
{
	// attempt to add non square matricies m x n + m x y, m x y + n x y & m x y + n x z
	// a is a m x n, b is a m x y, c n x y, d is a n x z

	Matrix a(4, 2), b(4, 5), c(2, 5), d(2, 3), e;

	//set up the a matrix,

	int size = a.GetMatrixSize();
	for (int i = 0; i < size; i++)
	{
		a.SetMatrixElement(i, i + 1);
	}

	//set up the b matrix,

	size = b.GetMatrixSize();
	for (int i = 0; i < size; i++)
	{
		b.SetMatrixElement(i, i + 1);
	}

	//set up the c matrix,

	size = c.GetMatrixSize();
	for (int i = 0; i < size; i++)
	{
		c.SetMatrixElement(i, i + 1);
	}

	//set up the d matrix,

	size = d.GetMatrixSize();
	for (int i = 0; i < size; i++)
	{
		d.SetMatrixElement(i, i + 1);
	}

	//set up the e matrix,

	size = e.GetMatrixSize();
	for (int i = 0; i < size; i++)
	{
		e.SetMatrixElement(i, i + 1);
	}
	cout << "e is " << endl;
	e.Mprint();
//	system("pause");

	//illegal inconsistent matrix dimensions
	e = a + b;
	cout << "e is a + b" << endl;
	e.Mprint();

	e = b + c;
	cout << "e is b + c" << endl;
	e.Mprint();

	e = c + b;
	cout << "e is c + b" << endl;
	e.Mprint();

	e += d;
	cout << "e is " << endl;
	e.Mprint();

	// assignment operator set "e" to "a" and add

	e = a;
	cout << "e is = a " << endl;
	e.Mprint();

	e = a + a;
	cout << "now e is a + a " << endl;
	e.Mprint();

	// assignment operator set "e" to "b" and add
	e = b;
	cout << "e is = b " << endl;
	e.Mprint();

	e = b + b;
	cout << "now e is b + b" << endl;
	e.Mprint();

	// assignment operator set "e" to "c" and add
	e = c;
	cout << "e is = c " << endl;
	e.Mprint();

	e = c + c;
	cout << "now e is c + c " << endl;
	e.Mprint();

	// assignment operator set "e" to "d" and add
	e = d;
	cout << "e is = d " << endl;
	e.Mprint();

	e = d + d;
	cout << "now e is d + d" << endl;
	e.Mprint();

	return 0;
}
