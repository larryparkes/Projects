//
// Matrix class test program.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Matrix.h"

int testGetnSetters()
{
	{
        cout << " Matrix Get and Set function Tests..." << endl;
        int test = 0;

		Matrix a(20, 10);
		long double val  = 50;
		for ( int i = 0; i < a.GetMatrixSize(); i++)
        {
            a.SetMatrixElement(i, val - 2*i);
        }


		Matrix d(20, 10);
		for(int j = a.GetMatrixRows(); j > 0; j--)
        {
            for(int k = 0; k < a.GetMatrixCols(); k++)
            {
                d.SetMatrixRCElement(j, k+1, a.GetMatrixRCElement(j, k+1));
            }
        }

        if(a != d)
        {
            LOG_DEBUG(" 1st Get and Set Test failed..." );
            cout << " 1st Get and Set Test failed..." << endl;
            return 1;
        }

/// attempting to set a value outside a valid index range
        try
        {
            test++;
            a.SetMatrixElement(201, 10);
        }
        catch(std::runtime_error(e))
        {
            --test;
 //           cout << e.what() << endl;
            LOG_DEBUG(e.what());
        }
        if(test)
        {
            cout << " 2nd Get and Set Test failed" << endl;
            return 1;
        }

/// attempting to set a value outside a valid row value
        try
        {
            test++;
            a.SetMatrixRCElement(0, 10, 2);
        }
        catch(std::runtime_error(e))
        {
            --test;
 //           cout << e.what() << endl;
            LOG_DEBUG(e.what());
        }
        if(test)
        {
            cout << " 3nd Get and Set Test failed" << endl;
            return 1;
        }

/// attempting to set a value outside a valid column value

        try
        {
            test++;
            a.SetMatrixRCElement(20, 0, 2);
        }
        catch(std::runtime_error(e))
        {
            --test;
//            cout << e.what() << endl;
            LOG_DEBUG(e.what());
        }
        if(test)
        {
            cout << " 4th Get and Set Test failed" << endl;
            return 1;
        }

/// attempting to set a value outside a valid index range

        try
        {
            test++;
            a.SetMatrixElement(-2, 2);
        }
        catch(std::runtime_error(e))
        {
            --test;
 //           cout << e.what() << endl;
            LOG_DEBUG(e.what());
        }
        if(test)
        {
            cout << " 5th Get and Set Test failed" << endl;
            return 1;
        }


        cout << " Matrix Get and Set Functions Passed!" << endl << endl;
	}

	return 0;
}
