
//
// Matrix class test program.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Matrix.h"

int testAssignMultiply()
{
    cout << " Matrix Assign Multiply a *= c Test...." << endl;
	Matrix b(2, 3);
	Matrix c(3, 2);
	Matrix d(4, 5);
	Matrix x, y(3, 3), z;


    //multiply matrices of different dimensions 2, 3 x 4, 5 & 3, 2 x 4, 5


	int val = 1;
	for (int i = 1; i <= b.GetMatrixSize(); i++, val++)
	{
		b.SetMatrixElement(i - 1, val);

	}

//	cout << "set up of the c matrix -  non zero values" << endl;
	val = 1;
	for (int i = 1; i <= c.GetMatrixSize(); i++, val++)
	{
		c.SetMatrixElement(i - 1, val);

	}
	x = c;
//	cout << " b matrix set" << endl;
//	cout << "b is " << endl;
//	b.Mprint();

//	cout << "set up of the d matrix -  non zero values" << endl;
	val = 1;
	for (int i = 1; i <= d.GetMatrixSize(); i++, val++)
	{
		d.SetMatrixElement(i - 1, val+2);
	}

    int test = 0;
	try
	{
	    test++;
	    b *= d;
	}
	catch(std::runtime_error(e))
	{
	    --test;
	    LOG_DEBUG(e.what())
//	    cout << e.what() << endl;
	}

	if(test)
    {
        cout << " Matrix Assign Multiply first test failed" << endl;
        return 1;
    }
//    cout << "b" << endl;
//    b.Mprint();

    try
    {
        test++;
        c *= d;
    }
    catch(std::runtime_error(e))
    {
        --test;
        LOG_DEBUG(e.what());
//        cout << e.what() << endl;
    }
    if(test)
    {
        cout << " Matrix Assign Multiply second test failed" << endl;
        return 1;
    }
//    cout << " c" << endl;
//    c.Mprint();


	c *= b;
	y.SetMatrixRCElement(1, 1, 9);
    y.SetMatrixRCElement(1, 2, 12);
    y.SetMatrixRCElement(1, 3, 15);
    y.SetMatrixRCElement(2, 1, 19);
    y.SetMatrixRCElement(2, 2, 26);
    y.SetMatrixRCElement(2, 3, 33);
    y.SetMatrixRCElement(3, 1, 29);
    y.SetMatrixRCElement(3, 2, 40);
    y.SetMatrixRCElement(3, 3, 51);

	if( c != y)
    {
        cout << " Matrix Assign Multiply third test failed" << endl;
        return 1;
    }

	b *= x;
	z.SetMatrixRCElement(1, 1, 22);
    z.SetMatrixRCElement(1, 2, 28);
    z.SetMatrixRCElement(2, 1, 49);
    z.SetMatrixRCElement(2, 2, 64);
	if( b != z)
    {
        cout << " Matrix Assign Multiply fourth test failed" << endl;
        return 1;
    }
    cout << " Matrix Assign Multiply Passed!" << endl << endl;

	return 0;
}
