//
// Matrix class test program.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Matrix.h"

int testSubtraction()
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

	cout << " the a matrix is " << endl;
	a.Mprint();
	cout << "e is " << endl;
	e.Mprint();
//	system("pause");



	//illegal inconsistent matrix dimensions
	//
	e = e - a;
	cout << "e = e - a, and e is " << endl;
	e.Mprint();

	// next test
	cout << " the b matrix is " << endl;
	b.Mprint();
	e = e - b;
	cout << "e = e - b, and e is " << endl;
	e.Mprint();

	// Next test
	cout << " the c matrix is " << endl;
	c.Mprint();
	e = e - c;
	cout << "e = e - c, and e is " << endl;
	e.Mprint();


	// next test
	cout << " the d matrix is " << endl;
	d.Mprint();
	e = e - d;
	cout << "e = e - d, and e is " << endl;
	e.Mprint();

//	system("pause");
	// assignment operator set "e" to "a" and add
	cout << " set e = a" << endl;
	e = a;
	cout << "e is = a " << endl;
	e.Mprint();

	e = e - a;
	cout << "e = e - a, and now e is " << endl;
	e.Mprint();

	// assignment operator set "e" to "b" and add
	e = b;
	cout << "set e = b " << endl;
	e.Mprint();

	e = e - b;
	cout << "e = e - b and now e is " << endl;
	e.Mprint();

	// assignment operator set "e" to "c" and add
	e = c;
	cout << "set e = c " << endl;
	e.Mprint();

	e = e - c;
	cout << " e = e - c and now e is " << endl;
	e.Mprint();

	// assignment operator set "e" to "d" and add
	e = d;
	cout << "e = d, " << endl;
	e.Mprint();

	e = e - d;
	cout << "e = e - d, and now e is " << endl;
	e.Mprint();

	return 0;
}