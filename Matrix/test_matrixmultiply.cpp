//
// Matrix class test program.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Matrix.h"

int testMatrixMultiply()
{
	{
		/* Test matrix multiply of very large matricies;*/
		cout << "Set up for x" << endl;
		Matrix a(5, 5), b(5, 5), c(1000, 1000);


		// set up the matricies

		cout << "set up of the a matrix -  non zero values" << endl;
		int mSize = a.GetMatrixSize();
		int val = 1;
		for (int i = 0; i < mSize; i++, val++)
		{
			srand(i);
			val = (int)rand() % 5;
			a.SetMatrixElement(i, val);

		}
		cout << " a matrix set" << endl;
		cout << "a is " << endl;
		a.Mprint();
//		system("pause");

		a *= a;
		cout << "a is now a * a" << endl;
		a.Mprint();
//		system("pause");


		cout << "set up of the b matrix -  non zero values" << endl;
		mSize = b.GetMatrixSize();
		//int val = 1;
		for (int i = 0; i < mSize; i++, val++)
		{
			srand(i);
			val = (int)rand() % 5;
			b.SetMatrixElement(i, val);

		}
		cout << "b is " << endl;
		b.Mprint();
//		system("pause");

		b = b * b;
		cout << "b is now b * b" << endl;
		b.Mprint();
//		system("pause");

        cout << " Check a should be equal to b" << endl << endl;
        if (a == b)
        {
            cout << " Success a = b \n" << endl;

        }
        else
        {
            cout << " Problem .... a != b"  << endl;
        }

		cout << "set up of the c matrix -  non zero values" << endl;
		mSize = c.GetMatrixSize();
//		int val = 1;
		for (int i = 0; i < mSize; i++, val++)
		{
			srand(i);
			val = (int)rand() % 3;
			c.SetMatrixElement(i, val);

		}

		cout << " c is " << endl;
		//c.Mprint();

//		system("pause");

		c = c * c;
		cout << "c is now c = c * c" << endl;
//		system("pause");
		//c.Mprint();
//		system("pause");
	}
//	system("pause");
	return 0;
}
