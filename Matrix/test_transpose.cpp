//
// Matrix class test program.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Matrix.h"

int testTranspose()
{
	{

		cout << " Matrix Transpose a^t Test" << endl;
		LOG_DEBUG(" Matrix Transpose function Test a^t ...", "\n");
//		cout << "Set up for x" << endl;
		Matrix a(5, 5), b(3, 5), c(4, 1);
        Matrix x, y, z;
		// set up the matricies

//		cout << "set up of the a matrix -  non zero values" << endl;

		int val = 11;
		for (int i = 0; i < a.GetMatrixSize(); i++, val++)
		{
			a.SetMatrixElement(i, val);

		}

//		cout << "set up of the b matrix -  non zero values" << endl;

		val = 11;
		for (int i = 1; i <= b.GetMatrixSize(); i++, val++)
		{
			b.SetMatrixElement(i - 1, val + 2);
		}


//		cout << "set up of the c matrix -  non zero values" << endl;

		val = 11;
		for (int i = 1; i <= c.GetMatrixSize(); i++, val++)
		{

			c.SetMatrixElement(i - 1, val + 2);
		}

        z = a;
        x = z.MatrixTranspose();
		y = x.MatrixTranspose();

		if(a != y)
        {
            cout << " failed the first transpose function test..." << endl;
            return 1;
        }

        z = b;
		x = z.MatrixTranspose();
		y = x.MatrixTranspose();

		if(b != y)
        {
            cout << " failed the second transpose function test..." << endl;
            return 1;
        }

        z = c;
		x = z.MatrixTranspose();
		y = x.MatrixTranspose();
		if(c != y)
        {
            cout << " failed the third transpose function test..." << endl;
            return 1;
        }
		 cout << " Matrix Transpose Passed!" << endl << endl;
		 LOG_DEBUG(" Matrix Transpose function Test Passed!", "\n", "\n");

	}

	return 0;
}
