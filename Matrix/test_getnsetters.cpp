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

		Matrix a;
		cout << " Matrix a is " << endl;

		Matrix d(2, 2);

        if ( a != d)
        {
            cout << " " << endl;
        }
		cout << " Matrix a rows = " << a.GetMatrixRows() << " Matrix a columns = " << a.GetMatrixCols() << endl;

		Matrix b(10, 10), c(5, 5);
		cout << " Matrix b is " << endl;
		b.Mprint();
		cout << " Matrix b rows = " << b.GetMatrixRows() << " Matrix b columns = " << b.GetMatrixCols() << endl;

		cout << " Matrix c is " << endl;
		c.Mprint();
		cout << " Matrix c rows = " << c.GetMatrixRows() << " Matrix c columns = " << c.GetMatrixCols() << endl;
//		system("pause");

	}
//	system("pause");
	return 0;
}
