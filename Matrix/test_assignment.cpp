//
// Matrix class test program.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Matrix.h"

int testAssignment()
{
	Matrix a(5, 5), b(5, 5), c(4, 5);

	//set up the a matrix,

	int mSize = a.GetMatrixSize();
	for (int i = 0; i < mSize; i++)
	{
		a.SetMatrixElement(i, i + 1);
	}


	cout << "a is" << endl;
	a.Mprint();
	cout << " b is" << endl;
	b.Mprint();
	cout << " Assignment b = a " << endl;
	b = a;
	cout << "b is now" << endl;
	b.Mprint();


	cout << "c is" << endl;
	c.Mprint();
	cout << " b is" << endl;
	b.Mprint();
	cout << " Assignment b = c " << endl;
	b = c;
	cout << " b is now" << endl;
	b.Mprint();


	return 0;
}
