//
// Matrix class test program.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Matrix.h"

int testAdd();
int testAssignAdd();
int testAssignMultiply();
int testAssignment();
int testConstructorDestructor();
int testAssignSubtract();
int testEquality();
int testGetnSetters();
int testGetandSet();
int testInequality();
int testMMltiplication();
int testSubtraction();
int testTranspose();
int testMatrixMultiply();




int main()
{
	{
		// test the constructors and destructor
		/*testConstructorDestructor();
		system("pause");*/

		// test the getters and setters
		/*testGetnSetters();
		system("pause");*/

		// test assignment operator
		/*testAssignment();
		system("pause");*/

		// test the get and set to update matrix elements
		/*testGetandSet();
		system("pause");*/

		// test assignment add operator
		/*testAssignAdd();
		system("pause");*/

		/*testAdd();
		system("pause");*/

		// test matrix assign and multiply a *= b;
		/*testAssignMultiply();
		system("pause");*/

		 //test matrix multiplication c = a x b;
		/*testMMltiplication();
		system("pause");*/

		//test assignment subtract c -= b
		/*testAssignSubtract();
		system("pause");*/

		// test subtraction c = c - b
		/*testSubtraction();
		system("pause");*/

		// test matrix transpose
		/*testTranspose();
		system("pause");*/



		// test matrix equality
	/*	testEquality();
		system("pause");*/

		// test matrix, inequality
		/*testInequality();
		system("pause");*/

		//test random matrix
		testMatrixMultiply();
//		system("pause");



	}

	//system("pause");
	return 0;
}
