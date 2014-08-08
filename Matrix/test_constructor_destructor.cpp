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
		Matrix a;
		cout << " Matrix a is " << endl;
		a.Mprint();

		Matrix b(10, 10), c(5,5);
		cout << " Matrix b is " << endl;
		b.Mprint();

		cout << " Matrix c is " << endl;
		c.Mprint();

//		system("pause");

	}
//	system("pause");
	return 0;
}
