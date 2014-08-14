//
// Matrix class test program.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Matrix.h"

int testInequality()
{
	cout << " Matrix Inequality a != b Test... " << endl;
	Matrix a(5, 5), b(5, 5), c(4, 5);

	//set up the a matrix,

	int mSize = a.GetMatrixSize();
	for (int i = 0; i < mSize; i++)
	{
		a.SetMatrixElement(i, i + 1);
	}

	b = a;

	// check if b != a
//	cout << "Check if b != a" << endl;
	if (b != a)
	{
		cout << " Failed the first matrix inequaity test" << endl;
		return 1;
	}


//	cout << "Check if c != a" << endl;
	if (c == a)
	{
		cout << " Failed the second matrix inequaity test" << endl;
		return 1;
	}

	cout << " Matrix Inequality Test Passed!" << endl << endl;
	return 0;
}
