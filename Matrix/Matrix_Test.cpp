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
int testMatrixInverse();
int testScalarMultiply();
int testMatrixDeterminant();

bool Matrix::mdbug = 0;


int main()
{
	{
	    /// test the constructors and destructor
		testConstructorDestructor();

		/// test the getters and setters
//		testGetnSetters();

		/// test assignment operator
		testAssignment();

		/// test the get and set to update matrix elements
		testGetandSet();

		// test matrix equality
		/// relational operator == equality operator works correctl
		testEquality();

		/// test matrix, inequality
		testInequality();

		/// assign add funcion a += b works correctly
		testAssignAdd();

	    // test assignment add operator
	    /// add funcion a = a + b works correctly
		testAdd();

		/// assign subtract funcion a -= b works correctly
		testAssignSubtract();

		// test subtraction c = c - b
        /// subtraction funcion a = a - b works correctly
		testSubtraction();

		// test matrix assign and multiply a *= b;
		/// assign multiply funcion a *= b works correctly
		testAssignMultiply();

		 //test matrix multiplication c = a x b;
		/// multiply funcion a = a * b works correctly
		testMMltiplication();

		/// scalar multiplication a = 2 * b or a = b * 2
		testScalarMultiply();

		// test matrix transpose
		/// transpose funcion a.transpose() works correctly
		testTranspose();

		/// large matrix multiply funcion a = a * a works correctly
//		testMatrixMultiply();

        ///test matrix inverse function
        testMatrixInverse();

        /// test matrix determinant function
        testMatrixDeterminant();

	}


	return 0;
}
