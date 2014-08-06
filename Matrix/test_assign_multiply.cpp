
//
// Matrix class test program.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Matrix.h"

int testAssignMultiply()
{
	Matrix b(2, 3);
	Matrix c(3, 2);

	Matrix d;
	cout << " d matrix is " << endl;
	d.Mprint();


	cout << "set up of the b matrix -  non zero values" << endl;
	int size = b.GetMatrixSize();
	int val = 1;
	for (int i = 1; i <= size; i++, val++)
	{
		b.SetMatrixElement(i - 1, val);

	}
	cout << " b matrix set" << endl;
	cout << "b is " << endl;
	b.Mprint();

	cout << "set up of the c matrix -  non zero values" << endl;
	size = c.GetMatrixSize();
	val = 1;
	for (int i = 1; i <= size; i++, val++)
	{
		c.SetMatrixElement(i - 1, val+2);
	}

	cout << "c is " << endl;
	c.Mprint();

	d = c;
	/*cout << " d matrix is " << endl;
	d.Mprint();*/

	c *= b;

	cout << "c is now the product c * b " << endl;
	c.Mprint();
//	system("pause");

	c *= d;
	cout << "c is now the product c * d " << endl;
//	system("pause");
	c.Mprint();

	return 0;
}
