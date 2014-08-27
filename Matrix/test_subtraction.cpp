//
// Matrix class test program.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Matrix.h"

int testSubtraction()
{

	// attempt to subtract non square matrices m x n + m x y, m x y + n x y & m x y + n x z
	// a is a m x n, b is a m x y, c n x y, d is a n x z

	cout << " Matrix Subtraction a = c - d Test..." << endl;
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

    int test = 0;
	//illegal inconsistent matrix dimensions
	try
	{
	    test++;
	    e = a - b;
//        e.Mprint();
//        a.Mprint();
//        b.Mprint();
	}
	catch(std::runtime_error(e))
	{
	    --test;
	    LOG_DEBUG(e.what());
//	    cout << e.what() << endl;
	}
	if(test)
    {
        cout << " failed 1st group test at the first subtract function test..." << endl;
        return 1;
    }

    try
    {
        test++;
        e = b - c;
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
        e = c - b;
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
    try
    {
        test++;
        e = e - d;
    }
    catch(std::runtime_error(e))
    {
        --test;
        LOG_DEBUG(e.what());
//        cout << e.what() << endl;
    }
	if(test)
    {
        cout << " failed 1st group test at the forth subtract function test..." << endl;
        return 1;
    }

	// assignment operator set "e" to "a" and subtract

	e = a;


	e = a - a;
	if ( e == a || e != 0*a)
    {
        cout << " failed 2nd group test at the first subtract function test..." << endl;
        return 1;

    }
    // assignment operator set "e" to "b" and subtract
	e = b;
	e = b - b;
	if ( e == b || e != 0*b)
    {
        cout << " failed 2nd group test at the second subtract function test..." << endl;
        return 1;

    }
	// assignment operator set "e" to "c" and subtract
	e = c;
	e = c - c;
	if ( e == c || e != 0*c)
    {
        cout << " failed 2nd group test at the third subtract function test..." << endl;
        return 1;

    }
	// assignment operator set "e" to "d" and subtract
	e = d;
	e = d - d;
	if ( e == d || e != 0*d)
    {
        cout << " failed 2nd group test at the fourth subtract function test..." << endl;
        return 1;

    }
    cout << " Matrix Subtract Passed!" << endl << endl;
	return 0;
}
