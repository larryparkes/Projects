//
// Matrix class test program.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Matrix.h"

int testAssignAdd()
{
	// attempt to add non square matricies m x n + m x y, m x y + n x y & m x y + n x z
	// a is a m x n, b is a m x y, c n x y, d is a n x z

	Matrix a(4, 2), b(4, 5), c(2, 5), d(2, 3), e;

	//set up the a matrix,

	int mSize = a.GetMatrixSize();
	for (int i = 0; i < mSize; i++)
	{
		a.SetMatrixElement(i, i + 1);
	}

	//set up the b matrix,

	mSize = b.GetMatrixSize();
	for (int i = 0; i < mSize; i++)
	{
		b.SetMatrixElement(i, i + 1);
	}

	//set up the c matrix,

	mSize = c.GetMatrixSize();
	for (int i = 0; i < mSize; i++)
	{
		c.SetMatrixElement(i, i + 1);
	}

	//set up the d matrix,

	mSize = d.GetMatrixSize();
	for (int i = 0; i < mSize; i++)
	{
		d.SetMatrixElement(i, i + 1);
	}

	//set up the e matrix,

	mSize = e.GetMatrixSize();
	for (int i = 0; i < mSize; i++)
	{
		e.SetMatrixElement(i, i+1 );
	}
	cout << "e is " << endl;
	e.Mprint();

	cout << "a is " << endl;
	a.Mprint();

//	system("pause");
	//illegal inconsistent matrix dimensions
	e += a;
	cout << "e is " << endl;
	e.Mprint();

	e += b;
	cout << "e is " << endl;
	e.Mprint();

	e += c;
	cout << "e is " << endl;
	e.Mprint();

	e += d;
	cout << "e is " << endl;
	e.Mprint();

	// assignment operator set "e" to "a" and add

	e = a;
	cout << "e is = a " << endl;
	e.Mprint();

	e += a;
	cout << "now e is " << endl;
	e.Mprint();

	// assignment operator set "e" to "b" and add
	e = b;
	cout << "e is = b " << endl;
	e.Mprint();

	e += b;
	cout << "now e is " << endl;
	e.Mprint();

	// assignment operator set "e" to "c" and add
	e = c;
	cout << "e is = c " << endl;
	e.Mprint();

	e += c;
	cout << "now e is " << endl;
	e.Mprint();

	// assignment operator set "e" to "d" and add
	e = d;
	cout << "e is = d " << endl;
	e.Mprint();

	e += d;
	cout << "now e is " << endl;
	e.Mprint();

	cout << " end of test.." << endl;

	return 1;
}
