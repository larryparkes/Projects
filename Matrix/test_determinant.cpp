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
            cout << " failed the second determinant function test"  << endl;
            return 1;
        }
		cout << " Matrix Determinant Passed!" << endl << endl;

    }

	return 0;
}

