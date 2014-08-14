//
// Matrix class test program.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Matrix.h"

int testEquality()
{
	cout << " Matrix Equality a == b Test..." << endl;
	Matrix a(5, 5), b(5, 5), c(4, 5);

	//set up the a matrix,

	int mSize = a.GetMatrixSize();
	for (int i = 0; i < mSize; i++)
	{
		a.SetMatrixElement(i, i + 1);
	}

	b = a;

	// check if b = a
	if (b != a)
	{
		cout << "Failed the first equality test" << endl;
		return 1;
	}

	// check if b = a
	b.SetMatrixElement(24, 1);


//	cout << "Check if b = a" << endl;
	if (b == a)
	{
		cout << "Failed the second equality test" << endl;
		return 1;
	}


//  check if c = a
	if (c == a)
	{
		cout << "Failed the third equality test" << endl;
	}

	cout << " Matrix Equality Passed!" << endl << endl;

	return 0;
}
