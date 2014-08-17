//
// Matrix class test program.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Matrix.h"

int testGetandSet()
{
	{

		cout << " Matrix Get and Set function test..." << endl;
		Matrix a;
        Matrix d(2, 2);

        if( a != d)
        {
            cout << " Matrix 1st Get & Set Function, first test failed..." << endl;
            return 1;
        }

		Matrix b(10, 10), c(10, 10);

		c = b;
		if( a != d)
        {
            cout << " Matrix 1st Get & Set Function, second test failed..." << endl;
            return 1;
        }


		// set into 0 to 3 in the matrix row 1 0, 1
		int k = 1;
		for (int i = 0; i < a.GetMatrixRows(); i++)
		{
			for (int j = 0; j < a.GetMatrixCols(); j++)
			{
				a.SetMatrixRCElement(i+1, j+1, k);
				k++;
			}
		}

        d = a;
         if( a != d)
        {
            cout << " Matrix 2nd Get & Set Function, first test failed..." << endl;
            return 1;
        }


		// set the b matrix elements
		for (int i = 0; i < b.GetMatrixRows(); i++)
		{
			for (int j = 0; j < b.GetMatrixCols(); j++)
			{
				b.SetMatrixRCElement(i+1, j+1, (i + j) % 11 + 10);
			}
		}
        d = b;
        if( b != d)
        {
            cout << " Matrix 2nd Get & Set Function, second test failed..." << endl;
            return 1;
        }

		for (int i = 0; i < b.GetMatrixRows(); i++)
		{
			for (int j = 0; j < b.GetMatrixCols(); j++)
			{
				c.SetMatrixRCElement(i+1, j+1, b.GetMatrixRCElement(i+1, j+1));
			}
		}

		if( c != b)
        {
            cout << " Matrix 3rd Get & Set Function, first test failed..." << endl;
            return 1;
        }

        cout << " Matrix Get and Set function passed!" << endl << endl;

	}

	return 0;
}
