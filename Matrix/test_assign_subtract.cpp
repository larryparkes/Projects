//
// Matrix class test program.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Matrix.h"

int testAssignSubtract()
{

	// attempt to subtract non square matrices m x n + m x y, m x y + n x y & m x y + n x z
	// a is a m x n, b is a m x y, c n x y, d is a n x z

	cout << " Matrix Assign Subtraction a -= d Test..." << endl;
	LOG_DEBUG(" Matrix Assign Subtraction Test a -= b; ...","\n");
	Matrix a(4, 2), b(4, 5), c(2, 5), d(2, 3), e;

	//set up the a matrix,
	for (int i = 0; i < a.GetMatrixSize(); i++)
	{
		a.SetMatrixElement(i, i + 11);
	}

	//set up the b matrix,
	for (int i = 0; i < b.GetMatrixSize(); i++)
	{
		b.SetMatrixElement(i, i + 11);
	}

	//set up the c matrix,
	for (int i = 0; i < c.GetMatrixSize(); i++)
	{
		c.SetMatrixElement(i, i + 11);
	}

	//set up the d matrix,
	for (int i = 0; i < d.GetMatrixSize(); i++)
	{
		d.SetMatrixElement(i, i + 11);
	}

	//set up the e matrix,
	for (int i = 0; i < e.GetMatrixSize(); i++)
	{
		e.SetMatrixElement(i, i + 11);
	}
//	cout << "e is " << endl;
//	e.Mprint();


	//illegal inconsistent matrix dimensions
//	a.Mprint();
//	b.Mprint();
    int test = 0;
    try
    {
        test++;
        a -= b;
    }
    catch(std::runtime_error(e))
    {
        --test;
        LOG_DEBUG(e.what());
//        cout << e.what() << endl;
    }

	if(test)
    {
        cout << " failed 1st group test at the first subtract function test..." << endl;
        return 1;
    }

    try
    {
        test++;
        a -= c;
    }
    catch(std::runtime_error(e))
    {
        --test;
        LOG_DEBUG(e.what());
//        cout << e.what() << endl;
    }
    if(test)
    {
        cout << " failed 1st group test at the second subtract function test..." << endl;
        return 1;
    }

    try
    {
        test++;
        a -= d;
    }
    catch(std::runtime_error(e))
    {
        --test;
        LOG_DEBUG(e.what());
//        cout << e.what() << endl;
    }
	if(test)
    {
        cout << " failed 1st group test at the third subtract function test..." << endl;
        return 1;
    }


	a = d;
	e = a;

		// assignment operator set "e" to "a" and subtract

    a -= e;

	if ( a != 0*e)
    {
        cout << " failed 2nd group test at the first subtract function test..." << endl;
        return 1;

    }
    // assignment operator set "e" to "b" and subtract
	a = b;
	a -= b;
	if ( a != 0*b)
    {
        cout << " failed 2nd group test at the second subtract function test..." << endl;
        return 1;

    }
	// assignment operator set "e" to "c" and subtract
	a = c;
	a -= c;
	if ( a == c || a != 0*c)
    {
        cout << " failed 2nd group test at the third subtract function test..." << endl;
        return 1;

    }
	// assignment operator set "e" to "d" and subtract
	a = d;
	a -= d;
	if ( a == d || a != 0*d)
    {
        cout << " failed 2nd group test at the fourth subtract function test..." << endl;
        return 1;

    }
    cout << " Matrix Assign Subtract Passed!" << endl << endl;
    LOG_DEBUG(" Matrix Assign Subtraction Test Passed!", "\n", "\n");
	return 0;
}

