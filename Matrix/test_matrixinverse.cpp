//
// Matrix class test program.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Matrix.h"

int testMatrixInverse()
{
	{
        cout << " Matrix Inversion a^(-1) Test...." << endl;
//		cout << "Set up for x" << endl;
		Matrix a(4, 4), b, c, I(4, 4);

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


        /// identity Matrix

        for( int i = 0; i < a.GetMatrixRows(); i++)
        {
            for( int j = 0; j < a.GetMatrixCols(); j++)
            {
                if( i == j)
                {
                    I.SetMatrixRCElement(i+1, j+1, 1);
                }
            }
        }

		b = a.MatrixInvert();
        c = a * b;
//        c.Mprint();

        if( c != I)
        {
            cout << " First Matrix Inversion test failed!  exit" << endl;
            return 1;
        }
//        b.Mprint();
        a *= b;

//            cout << " a * a^-1 is" << endl;
//            a.Mprint();

        if(a != I)
        {
            cout << " Second Matrix Inversion Test failed! exit" << endl;
            return 1;
        }

//        cout << endl << " 3rd & 4th tests...." << endl << endl;

        a = I;
        b = a.MatrixInvert();
        c = a * b;
//        c.Mprint();

        if( c != I)
        {
            cout << " Third Matrix Inversion test failed!  exit" << endl;
            return 1;
        }
//           b.Mprint();
        a *= b;

//            cout << " a * a^-1 is" << endl;
//            a.Mprint();

        if(a != I)
        {
            cout << " Fourth Matrix Inversion Test failed! exit" << endl;
            return 1;
        }




    }

    Matrix e(7, 7), f, I(7, 7);
//    cout << "set up of the e matrix -  non zero values" << endl;
//	mSize = c.GetMatrixSize();
	double val = 1;
	for (int i = 0; i < e.GetMatrixSize(); i++, val++)
	{
		srand(i);
		val = (int)rand() % 7 +1 ;
		e.SetMatrixElement(i, val);
	}

//  set up the identity matrix I
    for(int j = 0; j < I.GetMatrixRows(); j++)
    {
        I.SetMatrixRCElement(j+1, j+1, 1);
    }

	f = e;
    double z = e.Determinant();
	e = e.MatrixInvert();
    f = f * e;
    if( f !=I && z != 11319)
    {
        cout << " Fifth Matrix Inversion Test failed! " << endl;
        return 1;
    }


    for (int i = 0; i < e.GetMatrixSize(); i++, val++)
	{
		srand(i);
		val = (int)rand() % 7 + 1;
		val = 1/val;
		e.SetMatrixElement(i, val);
	}

	f = e;
    z = e.Determinant();
	e = e.MatrixInvert();
    f = f * e;

    z=f.Determinant();

    if(f != I && z != 1)
    {
        cout << " Sixth Matrix Inversion Test failed! " << endl;
        return 1;
    }
    cout << " Matrix Inversion Passed!" << endl << endl;

	return 0;
}

