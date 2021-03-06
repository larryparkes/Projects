//
// Matrix class test program.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Matrix.h"

int testMatrixMultiply()
{
	{

		/* Test matrix multiply of very large matrices;*/
		cout << " Large Matrix Multiply Test ..." << endl;
		LOG_DEBUG( " Large Matrix Multiply Test ...", "   ");

		Matrix a(7, 7), b(7, 7), c(7, 7), I(7, 7);
        for(int i = 0; i < I.GetMatrixRows(); i++)
        {
            I.SetMatrixRCElement(i+1, i+1, 1);
        }

		// set up the matrices


		int val = 1;
		for (int i = 0; i < a.GetMatrixSize(); i++, val++)
		{
			srand(i);
			val = (int)rand() % 10 - 2;
			a.SetMatrixElement(i, val);

		}


        double z = a.Determinant();

		b = a.MatrixTranspose();
		a *= b;


		for (int i = 0; i < b.GetMatrixSize(); i++, val++)
		{
			srand(i);
			val = (int)rand() % 10 -2;
			b.SetMatrixElement(i, val);

		}

		c = b.MatrixTranspose();
        z = b.Determinant();
//        cout << " det(b) is = " << z << endl;
		b = b * c;

        if (a != b && z != 1000)
        {
            cout << " failed first large Matrix Multiply tests" << endl;
            return 1;
        }


		for (int i = 0; i < c.GetMatrixSize(); i++, val++)
		{
			srand(i);
			val = (int)rand() % 7 ;
			c.SetMatrixElement(i, val);
		}

        Matrix d;

		d = c.MatrixTranspose();
		c = c * d;
		d = c.MatrixInvert();
		c *= d;
		z = c.Determinant();
//		cout << " det(c) is = " << z << endl;
		if(c != I && z != 1)
        {
            cout << " failed second large Matrix Multiply tests" << endl;
            return 1;
        }

        cout << " Large Matrix Multiply Passed!" << endl << endl;
        LOG_DEBUG(" Large Matrix Multiply Passed!", "\n", "\n");
	}

	return 0;
}
