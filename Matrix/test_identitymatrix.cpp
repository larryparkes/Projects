//
// Matrix class test program.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Matrix.h"
int matrixTest();


int testIdentity()
{
	/// Matrix Identity Test function

	cout << " Matrix Identity test function " << endl;
    Matrix a, b;
    for(int i = 2; i < 10; i++)
    {
        Matrix b(i, i);
        for( int j = 0; j < i; j++)
        {
            b.SetMatrixRCElement(j+1, j+1, 1);
        }
        a = a.GetMatrixIdentity(i, i);

        if( a != b)
        {
            cout << " failed 1st Matrix Identity Test function" << endl;
        }
    }

    for(int i = 1; i < 10; i++)
    {
        Matrix b(i, i);
        for( int j = 0; j < i; j++)
        {
            b.SetMatrixRCElement(j+1, j+1, 1);
        }
        a = a.GetMatrixIdentity(i, i+1);

        if( a == b)
        {
            cout << " failed 2nd Matrix Identity Test function" << endl;
        }
    }

    cout << " Matrix Identity Test Passed!" << endl << endl;

	return 0;
}
