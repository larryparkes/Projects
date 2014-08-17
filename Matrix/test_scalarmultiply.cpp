//
// Matrix class test program.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Matrix.h"

int testScalarMultiply()
{
	{

		/*Matrix x;*/
		cout << " Matrix Scalar Multiply a = c * 2 or 2 * c Test" << endl;
		Matrix a(4, 4), b, c, I(4, 4), d;

		a.SetMatrixRCElement(1, 1, 0);
		a.SetMatrixRCElement(1, 2, 1);
		a.SetMatrixRCElement(1, 3, 2);
		a.SetMatrixRCElement(1, 4, 3);
		a.SetMatrixRCElement(2, 1, 1);
		a.SetMatrixRCElement(2, 2, 1);
		a.SetMatrixRCElement(2, 3, 2);
		a.SetMatrixRCElement(2, 4, 3);
		a.SetMatrixRCElement(3, 1, 2);
		a.SetMatrixRCElement(3, 2, 2);
		a.SetMatrixRCElement(3, 3, 2);
		a.SetMatrixRCElement(3, 4, 3);
		a.SetMatrixRCElement(4, 1, 3);
		a.SetMatrixRCElement(4, 2, 3);
		a.SetMatrixRCElement(4, 3, 3);
		a.SetMatrixRCElement(4, 4, 3);


		d = a;
		a = 2 * d;
		b = d * 2;
		if( a != b)
        {
            cout << " failed scalar multiply first function test"  << endl;
            return 1;
        }

        a = d;
        d = 2 * d;
        b = d * 0.5;
        if( a != b)
        {
            cout << " failed scalar multiply second function test" << endl;
            return 1;
        }

        cout << " Matrix Scalar Multiply Passed!" << endl << endl;
	}
	return 0;
}

