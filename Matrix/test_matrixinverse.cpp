//
// Matrix class test program.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Matrix.h"

int testMatrixInverse()
{
	{
		/*Matrix x;*/
		cout << "Set up for x" << endl;
		Matrix a(2, 2), b, c;

		a.SetMatrixRCElement(1, 1, 1);
		a.SetMatrixRCElement(1, 2,-1);
		a.SetMatrixRCElement(2, 1, 2);
		a.SetMatrixRCElement(2, 2, 1);



		cout << " a matrix set" << endl;
		cout << "a is " << endl;
		a.Mprint();

		b = a.MatrixInvert();
		cout << endl <<" the inverse of a is" << endl;
		b.Mprint();

        cout << "Check I = a * a^-1"  <<endl;
        c = a * b;
        c.Mprint();

        cout << "next" << endl;


        cout << "a is " << endl;
        a.Mprint();
        cout << " a inverse is " << endl;
		b.Mprint();
		a *= b;

		cout << " a * a^-1 is" << endl;
		a.Mprint();

//		c= a * b;
//        cout << "a is " << endl;
//        a.Mprint();
//        cout << " a inverse is " << endl;
//		c.Mprint();
//		system("pause");


//		cout << "set up of the b matrix -  non zero values" << endl;
//		mSize = b.GetMatrixSize();
//		val = 1;
//		for (int i = 1; i <= mSize; i++, val++)
//		{
//			b.SetMatrixElement(i - 1, val + 2);
//		}
//
//		cout << "b is " << endl;
//		b.Mprint();
//
//		b.MatrixTranspose();
//		cout << "b now is " << endl;
//		b.Mprint();
//
////		system("pause");
//
//		cout << "set up of the c matrix -  non zero values" << endl;
//		mSize = c.GetMatrixSize();
//		val = 1;
//		for (int i = 1; i <= mSize; i++, val++)
//		{
//
//			c.SetMatrixElement(i - 1, val + 2);
//		}
//
//		cout << " c is " << endl;
//		c.Mprint();
//		c.MatrixTranspose();
//		cout << "c now is " << endl;
//		c.Mprint();

	}
//	system("pause");
	return 0;
}

