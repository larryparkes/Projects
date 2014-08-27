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
        a = b;

        for( int j = 0; j < i; j++)
        {
            b.SetMatrixRCElement(j+1, j+1, 1);
        }
        a = a.GetMatrixIdentity();
//        cout << " a is = " << endl;
//        a.Mprint();
//        cout << " b is = " << endl;
//        b.Mprint();

        if( a != b)
        {
            cout << " failed 1st Matrix Identity Test function" << endl;
        }
    }
    int test = 0;
    for(int i = 2; i < 10; i++)
    {
        Matrix b(i, i);
        Matrix a(i, i+1);


        for( int j = 0; j < i; j++)
        {
            b.SetMatrixRCElement(j+1, j+1, 1);
        }
        try
        {
            test++;
            a = a.GetMatrixIdentity();
        }
        catch(std::runtime_error(e))
        {
            --test;
            LOG_DEBUG(e.what());
//            cout << e.what() << endl;
        }

//        cout << " a is = " << endl;
//        a.Mprint();
//        cout << " b is = " << endl;
//        b.Mprint();

        if(test)
        {
            cout << " failed 2nd Matrix Identity Test function" << endl;
        }
    }

    cout << " Matrix Identity Test Passed!" << endl << endl;

	return 0;
}
