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
int testHilbert();
int testIdentity();

bool Matrix::mdbug = false;


int matrixTest()
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
		/// relational operator == equality operator works correctly
		testEquality();

		/// test matrix, inequality
		testInequality();

		/// assign add function a += b works correctly
		testAssignAdd();

        ///test assignment add operator
	    // add function a = a + b works correctly
		testAdd();

		/// assign subtract function a -= b works correctly
		testAssignSubtract();

		/// test subtraction c = c - b
        // subtraction function a = a - b works correctly
		testSubtraction();

		/// test matrix assign and multiply a *= b;
		/// assign multiply function a *= b works correctly
		testAssignMultiply();

		/// test matrix multiplication c = a x b;
		testMMltiplication();

		/// scalar multiplication a = 2 * b or a = b * 2
		testScalarMultiply();

		/// test matrix transpose
		testTranspose();

		/// large matrix multiply function a = a * a works correctly
		testMatrixMultiply();

        ///test matrix inverse function
        testMatrixInverse();

        /// test matrix determinant function
        testMatrixDeterminant();

        /// test Hilbert Matrix function
        testHilbert();

//        /// test matrix identity function
//        //testIdentity();


	}


	return 0;
}
