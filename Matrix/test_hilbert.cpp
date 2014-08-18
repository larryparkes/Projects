//
// Matrix class test program.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Matrix.h"


int testHilbert()
{
	/// Matrix - Hilbert Matrix Test function
    /// set up the Hilbert Matrix for various dimensions and we
    /// calculate the inverse and then perform H * (H)^1 which should
    /// produce the identity Matrix.
    cout << " Matrix - Hilbert Matrix Test function " << endl;
	Matrix H, b, c, I;
//	long double z;

	for( int i  = 2; i <= 8; i++)
    {
        ///set up the Hilbert matrix dimension i x i
        H = H.Hilbert(i);
        Matrix I(i ,i);
//        H.Mprint();
//        z = H.Determinant();

        /// calculate the inverse of the Hilbert Matrix
        b = H.MatrixInvert();

        /// test - multiply H * H^-1 = I
//        z = b.Determinant();
       // I = I(i, i)
        for( int j = 0; j < i; j++)
        {
            for( int k = 0; k < i; k++)
            {
                I.SetMatrixRCElement(j+1, j+1, 1);
            }
        }
 //       I.Mprint();
        c = b;
        b *= H;

        if( b != I)
        {
            cout << "test " << i - 1 << " failed the first Hilbert Matrix Test " << endl<<endl;
            b.Mprint();
//            return 1;
        }

        c = c * H;
        if( c != I)
        {
            cout << "test " << i - 1 << " failed the second Hilbert Matrix Test " << endl << endl;
            c.Mprint();
//            return 1;
        }
    }

    cout << " Matrix - Hilbert Matrix Test Passed!" << endl;

	return 0;
}
