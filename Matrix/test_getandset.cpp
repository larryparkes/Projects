//
// Matrix class test program.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Matrix.h"

int testGetandSet()
{
	{
		Matrix a;
		cout << " Matrix a is " << endl;
		a.Mprint();
		cout << " Matrix a rows = " << a.GetMatrixRows() << " Matrix a columns = " << a.GetMatrixCols() << endl;

		Matrix b(10, 10), c(5, 5);
		cout << " Matrix b is " << endl;
		b.Mprint();
		cout << " Matrix b rows = " << b.GetMatrixRows() << " Matrix b columns = " << b.GetMatrixCols() << endl;

		cout << " Matrix c is " << endl;
		c.Mprint();
		cout << " Matrix c rows = " << c.GetMatrixRows() << " Matrix c columns = " << c.GetMatrixCols() << endl;
//		system("pause");

		// set into 0 to 3 in the matrix row 1 0, 1
		int k = 1;
		for (int i = 0; i < a.GetMatrixRows(); i++)
		{
			for (int j = 0; j < a.GetMatrixCols(); j++)
			{
				a.SetRCMatrixElement(i+1, j+1, k);
				k++;
			}
		}

		cout << " Matrix a is " << endl;
		a.Mprint();
		cout << " Matrix a rows = " << a.GetMatrixRows() << " Matrix a columns = " << a.GetMatrixCols() << endl;


		// set the b matrix elements
		for (int i = 0; i < b.GetMatrixRows(); i++)
		{
			for (int j = 0; j < b.GetMatrixCols(); j++)
			{
				b.SetRCMatrixElement(i+1, j+1, (i + j) % 11 + 10);
			}
		}

		cout << " Matrix b is " << endl;
		b.Mprint();
		cout << " Matrix b rows = " << b.GetMatrixRows() << " Matrix b columns = " << b.GetMatrixCols() << endl;

//		system("pause");




	}
//	system("pause");
	return 0;
}
