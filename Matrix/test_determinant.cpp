//
// Matrix class test program.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Matrix.h"

int testMatrixDeterminant()
{
	{

        cout << " Matrix Determinant det(a) Test...." << endl;
        LOG_DEBUG(" Matrix Determinant Test det(a)  ...", "\n");
//		cout << "Set up for x" << endl;
		Matrix a(4, 4), b, c, I(4, 4);
		double z = 0;

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

//        cout<< " I Matrix is" << endl;
//        I.Mprint();


		z = a.Determinant();
		if ( (z + 3)*(z + 3) >= epsilon*epsilon)
        {
            cout << " failed the first determinant function test"  << endl;
            return 1;
        }


		z = I.Determinant();
		if( (z - 1) * (z - 1) >= epsilon*epsilon)
        {
            cout << " failed the 2nd determinant function test"  << endl;
            return 1;
        }

        int x = 12;
        int y = 2160;
        int w = 6048000;
        for(int i = 2; i < 5; i++)
        {
            a = a.GetMatrixHilbert(i);
            a = a.MatrixInvert();
//            a.Mprint();
            z = a.Determinant();
            long long int p = z;
            if( i == 2 && p != x)
            {
                cout << " failed the 3rd determinant function test " << endl;
                return 1;
            }
            if( i == 3 && p != y)
            {
                cout << " failed the 4th determinant function test " << endl;
                return 1;
            }
            if( i == 4 && p != w)
            {
                cout << " failed the 5th determinant function test " << endl;
                return 1;
            }
 //        cout << " determinant of a is " << (long long int)z << endl << endl;

        }

		cout << " Matrix Determinant Passed!" << endl << endl;
		LOG_DEBUG(" Matrix Determinant Test Passed!","\n", "\n");

    }

	return 0;
}

