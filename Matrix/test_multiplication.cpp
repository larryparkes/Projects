//
// Matrix class test program.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Matrix.h"

int testMMltiplication()
{
	{
		Matrix b(2, 3);

		Matrix c(3, 2);

		Matrix d;

		cout << "set up of the b matrix -  non zero values" << endl;
		int mSize = b.GetMatrixSize();
		int val = 1;
		for (int i = 0; i < mSize; i++, val++)
		{
			b.SetMatrixElement(i, val);

		}
		cout << " b matrix set" << endl;
		cout << "b is " << endl;
		b.Mprint();

		cout << "set up of the c matrix -  non zero values" << endl;
		mSize = c.GetMatrixSize();
		val = 1;
		for (int i = 1; i <= mSize; i++, val++)
		{
			c.SetMatrixElement(i - 1, val + 2);
		}

		cout << "c is " << endl;
		c.Mprint();
		d = c;
		c = c * b;

		cout << "c now is " << endl;
		c.Mprint();

		c = c * d;
		cout << "c now is " << endl;
		c.Mprint();

	}
//	system("pause");
	return 0;
}
