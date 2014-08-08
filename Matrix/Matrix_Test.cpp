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
//		testConstructorDestructor();
//		system("pause");*/

		// test the getters and setters
//		testGetnSetters();
//		system("pause");*/

		// test assignment operator
//		testAssignment();
//		system("pause");*/

		// test the get and set to update matrix elements
//		testGetandSet();
//		system("pause");*/

		// test assignment add operator
		/// assign add funcion a += b works correctly
//		testAssignAdd();
//		system("pause");*/

        /// add funcion a = a + b works correctly
//		testAdd();
//		system("pause");*/

		// test matrix assign and multiply a *= b;
		/// assign multiply funcion a *= b works correctly
//		testAssignMultiply();
//		system("pause");*/

		 //test matrix multiplication c = a x b;
		/// multiply funcion a = a * b works correctly
//		testMMltiplication();
//		system("pause");*/

		//test assignment subtract c -= b
        /// assign subtract funcion a -= b works correctly
//		testAssignSubtract();
//		system("pause");*/

		// test subtraction c = c - b
        /// subtraction funcion a = a - b works correctly
		testSubtraction();
//		system("pause");

		// test matrix transpose
		/// transpose funcion a.transpose() works correctly
//		testTranspose();
//		system("pause");

		// test matrix equality
		/// relational operator == equality operator works correctly
//		testEquality();
//		system("pause");*/

		// test matrix, inequality
//		testInequality();
//		system("pause");*/

		//test random matrix
		/// large matrix multiply funcion a = a * a works correctly
//		testMatrixMultiply();
//		system("pause");



	}

	//system("pause");
	return 0;
}
