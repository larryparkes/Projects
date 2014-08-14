//
// Matrix class test program.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Matrix.h"

int testAssignment()
{
	cout << " Matrix Assignment test a = b...." << endl;
	Matrix a(5, 5), b(3, 3), c (5, 5);

	//set up the a matrix,
	for (int i = 0; i < a.GetMatrixSize(); i++)
	{
		a.SetMatrixElement(i, i + 1);
	}

    b = c = a;

    if( b != a)
    {
        cout << " Matrix Assignment first test failed"  << endl;
        return 1;
    }

    if( c != a)
    {
        cout << " Matrix Assignment second test failed"  << endl;
        return 1;
    }

    cout << " Matrix Assigment Passed!" << endl << endl;
	return 0;
}
