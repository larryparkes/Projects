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
 //       bool test = false;
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
        b.Mprint();
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
        c.Mprint();

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


        cout << " Matrix Inversion Passed!" << endl << endl;

    }

	return 0;
}

