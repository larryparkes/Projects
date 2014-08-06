//
// Matrix class test program.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Matrix.h"

int testTranspose()
{
	{
		/*Matrix x;*/
		cout << "Set up for x" << endl;
		Matrix a(5, 5), b(3, 5), c(4, 1);

		/*x = a;
		cout << " x is " << endl;
		x.Mprint();*/

		// set up the matricies

		cout << "set up of the a matrix -  non zero values" << endl;
		int size = a.GetMatrixSize();
		int val = 1;
		for (int i = 0; i < size; i++, val++)
		{
			a.SetMatrixElement(i, val);

		}
		cout << " a matrix set" << endl;
		cout << "a is " << endl;
		a.Mprint();
		a.MatrixTranspose();
		cout << " a transpose is " << endl;


		a.Mprint();
//		system("pause");


		cout << "set up of the b matrix -  non zero values" << endl;
		size = b.GetMatrixSize();
		val = 1;
		for (int i = 1; i <= size; i++, val++)
		{
			b.SetMatrixElement(i - 1, val + 2);
		}

		cout << "b is " << endl;
		b.Mprint();

		b.MatrixTranspose();
		cout << "b now is " << endl;
		b.Mprint();

//		system("pause");

		cout << "set up of the c matrix -  non zero values" << endl;
		size = c.GetMatrixSize();
		val = 1;
		for (int i = 1; i <= size; i++, val++)
		{

			c.SetMatrixElement(i - 1, val + 2);
		}

		cout << " c is " << endl;
		c.Mprint();
		c.MatrixTranspose();
		cout << "c now is " << endl;
		c.Mprint();

	}
//	system("pause");
	return 0;
}
