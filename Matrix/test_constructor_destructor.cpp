//
// Matrix class test program.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Matrix.h"

int testConstructorDestructor()
{
	{
        int test = 0;
	    cout << " Matrix Constructors Test..."<< endl;
	    LOG_DEBUG(" Matrix Constructor Test....", "\n");
        try
        {
            test++;
            Matrix a(0, 10);
        }
        catch(std::runtime_error(e))
        {
            --test;
//            std::cout << e.what() << std::endl;
        }

        if(test != 0)
        {
            cout << " Matrix Constructor first test failed.." << endl;
        }

        try
        {
            test++;
            Matrix b(10, 0);
        }
        catch(std::runtime_error(e))
        {
            --test;
 //           std::cout << e.what() << std::endl;

        }
        if(test != 0)
        {
            cout << " Matrix Constructor seconds test failed.." << endl;
        }

        try
        {
            test++;
            Matrix c(10001, 10);
        }
        catch(std::runtime_error(e))
        {
            --test;
//            std::cout << e.what() << std::endl;
        }

        if(test != 0)
        {
            cout << " Matrix Constructor third test failed.." << endl;
        }

        try
        {
            test++;
            Matrix d(10, 10001);
        }
        catch(std::runtime_error(e))
        {
            --test;
//            std::cout << e.what() << std::endl;
        }

        if(test != 0)
        {
            cout << " Matrix Constructor fourth test failed.." << endl;
        }


//        try
//        {
//            test++;
//            Matrix a(10000, 10000);
//            Matrix b(10000, 10000);
////            Matrix c(10000, 10000);
////            Matrix d(10000, 10000);
////            Matrix e(10000, 10000);
//        }
//        catch(std::runtime_error(e))
//        {
//            --test;
//            std::cout << e.what() << std::endl;
//            cout << " Matrix Constructor fifth test failed.." << endl;
//        }

        cout << " Matrix Constructor Passed!" << endl << endl;
        LOG_DEBUG(" Matrix Constructor Tests Passed!", "\n", "\n");

	}

	return 0;
}
