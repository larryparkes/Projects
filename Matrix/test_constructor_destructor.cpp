//
// Matrix class test program.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Matrix.h"

int testConstructorDestructor()
{
	{

	    cout << " Matrix Constructors test..."<< endl;
		Matrix a;
        if(a.GetMatrixCols() != a.GetMatrixRows())
        {
           cout << " Matrix Constructor  first test failed" << endl;
           return 1;
        }

		Matrix b(10, 5);
		if(b.GetMatrixCols()!= 5 || b.GetMatrixRows() != 10)
        {
            cout << " Matrix Constructor  second test failed" << endl;
            return 1;
        }

        cout << " Matrix Constructor Passed!" << endl << endl;


	}

	return 0;
}
