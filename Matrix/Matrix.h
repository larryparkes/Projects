#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using std::iostream;
using std::ostream;
using std::cout;
using std::cin;
using std::endl;

const int maxrows = 10000;
const int maxcols = 10000;
const long double epsilon = 1e-12;
const int mylong = 1;


class Matrix
{
    private:
    inline void Set(int row, int col, long double value)
    {
        assert(row >= 0 && row < this->GetMatrixRows());
        assert(col >= 0 && col < this->GetMatrixCols());
        this->ePtr[row * this->GetMatrixCols() + col] = value;
    }

    inline void Set(int index, long double value)
    {
        assert(index >= 0 && index < this->GetMatrixSize());
        this->ePtr[index] = value;

    }

    inline bool ValidateRows(int rows)
    {
        // check the range of the rows variable
        if(rows >= 1 || rows <= maxrows)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    inline bool ValidateCols(int cols)
    {
        // check the range of the cols variable
        if(cols >= 1 || cols <= maxcols)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    inline static long double Abs( long double a)
    {
        // get the absolute value of a and return that.
        if( a < 0 )
        {
            a = -a;
        }
        return a;
    }

    inline static int Abs( int a)
    {
        // get the absolute value of a and return that.
        if( a < 0 )
        {
            a = -a;
        }
        return a;
    }

    inline Matrix Round()
    {
        // often at the completion of an operation the results of some elements is residuals
        // as a result of truncation in the representation of double, in which case we should
        // set these to zero.  This routine does this.
        for( int i = 0; i < this->GetMatrixSize(); i++)
        {
            if(Abs(this->GetMatrixElement(i)) <= 1e06*epsilon)
            {
                this->Set(i, 0);
            }
        }
        return *this;
    }



	/// class members variables


	int mRows;		// row dimension of the matrix array
	int mCols;		// column dimension of the matrix array
	long double *ePtr;	// the location of the first element of the matrix


    public:
    static bool mdbug;

	/// default constructor
	Matrix()
		:mRows(2), mCols(2)
	{
		/// calculate the mSize of the matrix array
		int mSize = mRows * mCols;

		/// set the mSize of the matrix array
//		this->ePtr = new double[mSize];
		this->ePtr = new long double[mSize];


		/// set the elements of the matrix array to zero
		for (int index = 0; index < mSize; index++)
		{
			ePtr[index] = 0;
		}

        if( Matrix::mdbug )
        {
//  		cout << "Default Constructor Called .... and ePtr is " << ePtr << endl;
            cout << " Default Constructor Called ..." << endl;
        }

	}

	// constructor
	Matrix(int rows, int cols)
	{
		/// validate the row and column dimensions
		/// row dimension
		if (!ValidateRows(rows))
		{
			cout << " Matrix Row dimension must be between 1 and "<< maxrows << "..." << endl;
			cout << " Rows = " << rows << endl;
			mRows = 2;
		}
		else
		{
			mRows = rows;
		}

		/// column dimension
		if (!ValidateCols(cols))
		{
			cout << " Matrix Column dimension must be between 1 and "<< maxcols << "..." << endl;
			cout << " Columns = " << cols << endl;
			mCols = 2;
		}
		else
		{
			mCols = cols;
		}

		/// allocate space in memory for the element array of matrix
		//  calculate the size of the memory required
		int mSize = mRows * mCols;
//		ePtr = new double[mSize];
		ePtr = new long double[mSize];

		/// set all the elements of the matrix array to zero
		for (int index = 0; index < mSize; index++)
		{
			ePtr[index] = 0;
		}
        if (mdbug)
        {
//  		cout << " First Constructor Called ...  and ePtr is " << ePtr << endl;
            cout << " First Constructor Called ...." << endl;
        }

	}

	/// destructor
	~Matrix()
	{
	    if(mdbug)
        {
//  		cout << " Destructor Called... and ePtr points to address  " << this->ePtr << endl;
            cout << " Destructor Called....  "<< endl;

        }

		delete[] this->ePtr;
		this->ePtr = nullptr;
		if(mdbug)
        {
//  		cout << " Destructor Complete... and ePtr points to address  " << this->ePtr << endl;
        }

	}

	/// copy constructor
	Matrix(const Matrix & matrixToCopy)
		:mRows(matrixToCopy.mRows), mCols(matrixToCopy.mCols)
	{
		/// calculate the mSize of the array to hold the matrix elements
		/// allocate memory for the new matrix
//		this->ePtr = new double[matrixToCopy.GetMatrixSize()];
		this->ePtr = new long double[matrixToCopy.GetMatrixSize()];

		/// copy the elements into the new matrix
		for (int index = 0; index < matrixToCopy.GetMatrixSize(); index++)
		{
			this->Set(index, matrixToCopy.GetMatrixElement(index));
		}

        if(mdbug)
        {
//		    cout << " Copy Constructor Called . ..  and ePtr is " << ePtr << endl;
            cout << " Copy Constructor Called . .. " << endl;
        }

	}

	/// assignment operator
	Matrix &operator=(const Matrix &rhside)
	{
        if(mdbug)
        {
            cout << " Assignment Operator Called... " << endl;
//	        cout << " Assignment Operator Called... the address of this->ePtr is " << (this->ePtr) << endl;
//          cout << " this matrix dimensions rows = " << this->GetMatrixRows() << "  cols = " << this->GetMatrixCols() << endl;
//	        cout << " Assignment Operator Called... the address of rhside.ePtr is " << (rhside.ePtr) << endl;
//	        cout << " rhside matrix dimensions rows = " << rhside.GetMatrixRows() << "  cols = " << rhside.GetMatrixCols() << endl;

        }

		/// check that we are not attempting self assignment
		if (&rhside != this)
		{
			/// check to see if the memory allocated for the this matrix is the same as rhs
			if (this->GetMatrixSize() != rhside.GetMatrixSize())
			{
				/// release the memory space for the this matrix array
//				cout << " 1 Assignment Operator... the address of this->ePtr is " << (this->ePtr) << endl;
				delete[] this->ePtr;
				this->ePtr = nullptr;
//				cout << " 2 Assignment Operator... the address of this->ePtr is " << (this->ePtr) << endl;

				/// allocate the required space for the new this matrix
//				this->ePtr = new double[rhside.GetMatrixSize()];
				this->ePtr = new long double[rhside.GetMatrixSize()];
//				cout << " 3 Assignment Operator allocation... the address of this->ePtr is " << this->ePtr << endl;
//              cout << " Assignment Operator Called... the address of rhside.ePtr is " << (rhside.ePtr) << endl;
			}
			/// set the this matrix dimensions to that of the rhside
			this->mRows = rhside.GetMatrixRows();
			this->mCols = rhside.GetMatrixCols();

			/// copy the rhs elements into the this matrix

			for (int index = 0; index < rhside.GetMatrixSize(); index++)
				this->SetMatrixElement(index, rhside.GetMatrixElement(index));
		}
        if(mdbug)
        {
		    cout << " Assignment Operator Complete... the address of this->ePtr is " << this->ePtr << endl;
        }

		return *this;
	}

	/// print the matrix in row column format
	void Mprint(void)
	{
		for (int i = 0; i < this->GetMatrixRows(); i++)
		{
			for (int j = 0; j < this->GetMatrixCols(); j++)
			{
			    cout << this->GetMatrixRCElement(i+1, j+1) << "    ";
			}
			cout << endl;
		}
		cout << endl << endl;
	}

	/// Set Matrix Rows
	void SetMatrixRows(const int rows)
	{
		/// validate row range set to default if out of range
		if(!ValidateRows(rows))
        {
            cout << " Rows value out of range.. must be between 1 and " << maxrows << endl;
        }
        else
        {
            /// set the row dimension
            this->mRows = rows;
        }
	}

	/// Set Matrix Columns
	void SetMatrixCols(const int cols)
	{
		/// validate column range - set to default if out of range
        if(!ValidateCols(cols))
        {
            cout << " Cols value out of range.. must be between 1 and " << maxcols << endl;
        }
        else
        {
            /// set the column dimension
            this->mCols = cols;
        }
	}

	// set the elements of the matrix array
	void SetMatrixElement(int index, long double val)
	{
		/// check that we are setting an element within the range of the matrix array space
//		int mSize = this->GetMatrixSize();
		if (index < 0 || index >= this->GetMatrixSize())
		{
			/// issue an error message
			cout << "Element out of range..." << endl;
			return;
		}

		/// set the element value
		//this->ePtr[index] = val;
        Set(index, val);
 	}

	/// set matrix element using RC format
	void SetMatrixRCElement(int row, int col, long double val)
	{
		/// check the validity of the RC format
		if (((row >= 1 && row <= this->GetMatrixRows()) && (col >= 1 && col <= this->GetMatrixCols())))
		{
            ///convert row col format to array index and set array element to val
            Set(row - 1, col - 1, val);
		}
		else
		{
			cout << " row = " << row << " col = " << col << endl;
			cout << "row or col specification out of range" << endl;
		}
	}

	/// get the number of rows in the matrix array
	int GetMatrixRows() const
	{
		return this->mRows;
	}

	/// get the number of columns in the matrix array
	int GetMatrixCols() const
	{
		return this->mCols;
	}

	/// get the mSize of the matrix array
	int GetMatrixSize() const
	{
		return this->GetMatrixCols() * this->GetMatrixRows();
	}

	/// get a matrix element from the matrix array
	long double GetMatrixElement(const int index) const
	{
		return this->ePtr[index];
	}

	/// get matrix element RC format from the matrix array
	long double GetMatrixRCElement(const int row, const int col) const
	{
		/// convert RC format to an index
		int index = (row - 1) * (this->GetMatrixCols()) + col - 1;

		///look up the index and return the element
//		return this->ePtr[index];
		return this->GetMatrixElement(index);
	}

	/// assign add matrices
	const Matrix &operator+=(const Matrix &rhside)
	{
	    long double sum;
		/// check the this and the rhside dimensions, must be the same
		if(mdbug)
        {
            cout << " Called assign add operator...." << endl;
        }

		if ((this->GetMatrixRows() == rhside.GetMatrixRows()) &&
			(this->GetMatrixCols() == rhside.GetMatrixCols()))
		{
            /// iterate over the array and add elements

			for (int index = 0; index < rhside.GetMatrixSize(); index++)
			{
			    sum = this->GetMatrixElement(index) + rhside.GetMatrixElement(index);
			    if(Abs(sum) <= epsilon)
                {
                    sum = 0;
                }
                this->Set(index, sum);
//				this->Set(index, (this->GetMatrixElement(index)
//					+ rhside.GetMatrixElement(index)));
			}
//			cout << "adding done!" << endl;

            /// if we have very small elements < epsilon set them to zero
            this->Round();
			return *this;
		}
		else
		{
			if(!mdbug)
            {
                return rhside;
            }
			cout << "Function assign add matrices c += b " << endl;
			cout << " addition not possible... inconsistent matrix dimensions..." << endl;
/* to do - what do we or should we return here */
			return rhside;
		}

	}

	/// assign subtract matrices
	const Matrix &operator-=(const Matrix &rhside)
	{
		/// check the this and the rhside dimensions, must be the same
		long double sum;
		if(mdbug)
        {
            cout << " Called assign subtract operator...." << endl;
        }

		if ((this->GetMatrixRows() == rhside.GetMatrixRows()) &&
			(this->GetMatrixCols() == rhside.GetMatrixCols()))
		{
            /// iterate over the array and subtract
			for (int index = 0; index < rhside.GetMatrixSize(); index++)
			{
			    sum = this->GetMatrixElement(index) - rhside.GetMatrixElement(index);
			    if(Abs(sum) <= epsilon)
                {
                    sum = 0;
                }
                this->Set(index, sum);
//				this->Set(index, (this->GetMatrixElement(index) - rhside.GetMatrixElement(index)));
			}

			/// if we have very small elements < epsilon set them to zero
			this->Round();
			return *this;
		}
		else
		{
			cout << " Function assign subtract matrices c -= b " << endl;
			cout << " subtraction not possible inconsistent matrix dimensions..." << endl;
/* to do - what do we or should we return here */
			return *this;
		}
	}


	/// assign multiply matrices c *= b;
	const Matrix &operator*=(const Matrix &rhside)
	{
	    if(mdbug)
        {
            cout << " Called assign multiply operator *= ...." << endl;
        }

		if (this->GetMatrixCols() != rhside.GetMatrixRows())
		{
			if(!mdbug)
			{
			    return *this;
			}
            cout << "assign multiply matrices c *= b " << endl;
			cout << "Multiplication not possible inconsistent matrix dimension" << endl;
/* to do - what do we or should we return here */
			return *this;
		}

		/// determine the number of elements in the matrix product
		/// get the row index - this is the number of rows in the this matrix
		/// get the column index - this is the number of columns in the rhside matrix
		/// set up a temporary matrix to hold the contents of the matrix product

		Matrix result(this->GetMatrixRows(), rhside.GetMatrixCols());

		/// the final Aij element is given by sum( Bik * Ckj) where k correspond to the
		/// this cols or the rhside rows. k is the number of products to be summed to get the Aij term.

		for (int i = 0; i < this->GetMatrixRows(); i++)
		{
			for (int j = 0; j < rhside.GetMatrixCols(); j++)
			{
				long double sum = 0;
				for (int k = 0; k < this->GetMatrixCols(); k++)
				{
				    sum += this->GetMatrixRCElement(i + 1, k + 1)
						* rhside.GetMatrixRCElement(k + 1, j + 1);
				}

                /// if we have very small elements < epsilon set them to zero
				if(Abs(sum) <= epsilon)
                {
                    sum = 0;
                }
                result.Set(i, j, sum );
			}
		}
		/// need adjust the mSize of the this matrix to hold the contents of the product
		/// set the row and column dimensions to agree with the product results

		this->SetMatrixRows(result.GetMatrixRows());
		this->SetMatrixCols(result.GetMatrixCols());

		/// delete the element pointer and create a new one large enough to hold all the
		/// elements of the matrix product

		delete[] this->ePtr;
		this->ePtr = nullptr;
//		this->ePtr = new double[this->GetMatrixSize()];
		this->ePtr = new long double[this->GetMatrixSize()];


		/// copy the product results into the this matrix array elements
		for (int i = 0; i < this->GetMatrixSize(); i++)
		{
			this->Set(i, result.GetMatrixElement(i));
		}

		if(mdbug)
        {
            cout << "multiplication called... " << endl;
        }
        /// if we have very small elements < epsilon set them to zero
        this->Round();
		return *this;
	}


    /// matrix transpose a^t
	const Matrix MatrixTranspose()
	{
	    if(mdbug)
        {
            cout << " Called Transpose...." << endl;
        }

		/// set up a temporary matrix transpose - set the transpose matrix rows and cols equal to
		/// the cols and rows of the this matrix

		Matrix transpose(this->GetMatrixCols(), this->GetMatrixRows());

		/// iterate over the this matrix and set transpose Aij = this Aji

		for (int i = 0; i < this->GetMatrixCols(); ++i)
		{
			for (int j = 0; j < this->GetMatrixRows(); ++j)
			{
                transpose.Set(i, j, this->GetMatrixRCElement(j + 1, i + 1));

			}

		}
		/// iterate over the array and copy to the this array.
		int mSize = this->GetMatrixCols() * this->GetMatrixRows();
		for (int index = 0; index < mSize; ++index)
		{
//			this->SetMatrixElement(index, transpose.GetMatrixElement(index));
			this->Set(index, transpose.GetMatrixElement(index));
		}

		/// set the this->mCols and the this->mRows the same as the transpose matrix
		this->SetMatrixCols(transpose.GetMatrixCols());
		this->SetMatrixRows(transpose.GetMatrixRows());
		return *this;
	}

    /// matrix invert a^-1
const Matrix MatrixInvert()
{
    /// set up identity matrix I and a Copy matrix
    Matrix I(this->GetMatrixRows(), this->GetMatrixCols());
    Matrix Copy = *this;
    int elsecount  = 0;
    int rescount = 0;

    if(mdbug)
    {
        cout << " Matrix Invert Function called..." << endl;

    }

    /// check matrix dimensions -  must be square
    if (Copy.GetMatrixRows() == Copy.GetMatrixCols())
    {
        /// set up the identity matrix
        for( int m = 0; m < Copy.GetMatrixRows(); m++)
        {
            I.Set(m, m, 1);
        }

        /// partial pivot routine
        /// scan 1st column and select the largest element, if its "a11" zero all the a1i-n elements
        /// otherwise swap the row with the largest element for the 1st row.

        for ( int i = 0; i < Copy.GetMatrixRows(); i++)
        {
            /// initialisations
            int swapRow = 0;
            long double pivot = Copy.GetMatrixRCElement(i+1, i+1);
            long double tempVar_1 = 0;
            long double tempVar_2 = 0;

            /// iterate over the ith column to find the largest entry - this will
            /// become the pivot for the ith row. Set the swapRow to j the row that
            /// has to be swapped with ith.

            for (int j = i; j < Copy.GetMatrixCols(); j++)
            {
//                cout << " iterate  - the Pivot is " << pivot << " and the swaprow is " << swapRow << " and i is " << i <<endl;
                if ( Abs(pivot) < Abs(Copy.GetMatrixRCElement(j+1, i+1)))
                {
                   pivot =  Copy.GetMatrixRCElement(j+1, i+1);
                   swapRow = j;
//                   cout << " Set the Pivot " << pivot << " and the swaprow is " << swapRow << " and i is " << i <<endl;
                }
            }


            if(pivot == 0)
            {
                cout << "Matrix is singular...  \n" << endl;
/* to do - what do we or should we return here */
                return *this;
            }

            if(mdbug)
            {
                cout << " Pivot = " << pivot << " and swapRow = " << swapRow << "  and i = " << i << endl;
            }

            /// if swapRow = i -> means we could not find a row with a pivot value greater than the ith row
            /// if swapRow = j > i then the pivot is i, j and we swap the j row with the ith row.

            if(swapRow > i)
            {
                /// swap the 2 rows of the this matrix - iterate along the column
//                cout << " in the swap block"  << endl;
                for( int x = 0; x < Copy.GetMatrixCols(); x++)
                {
                    tempVar_1 = Copy.GetMatrixRCElement(i+1, x+1);
                    tempVar_2 = I.GetMatrixRCElement(i+1, x+1);
                    Copy.Set(i, x, Copy.GetMatrixRCElement(swapRow+1, x+1) );
                    I.Set(i, x, I.GetMatrixRCElement(swapRow+1, x+1) );
                    Copy.Set(swapRow, x, tempVar_1);
                    I.Set(swapRow, x, tempVar_2);
                }
            }

            /// Normalise the row - iterate over the ith row and divide each element by the pivot
            /// this will make the pivot element  unity

            for(int j = 0; j < Copy.GetMatrixCols(); j++)
            {
                if(j >= i)
                {
                    Copy.Set(i, j, (Copy.GetMatrixRCElement(i+1, j+1))/pivot);
                }
                I.Set(i,j, (I.GetMatrixRCElement(i+1, j+1))/pivot);
            }
            if(mdbug)
            {
                cout << " after the normalise row " << i+1 << " - the Copy matrix is "<< endl << endl;
                Copy.Mprint();

            }

            /// Matrix upper and lower decomposition
            /// subtracts the ith row of the this matrix from all the other rows - should make all the other
            /// elements in the pivot column zero

            for(int k = 0; k < Copy.GetMatrixRows(); k++)
            {
                tempVar_1 = Copy.GetMatrixRCElement(k+1, i+1);
                for( int l = 0; l < Copy.GetMatrixCols(); l++)
                {
                    if(i != k)
                    {
//                        cout << "beginning of the loop, temp is = " << temp << " and  k = "<< k+1 << ", l = "<< l+1 << endl;
//                        cout << " temp is = Copy[ " << k+1 << " , " << i+1 << " ]" << endl;
                        if(Abs(Copy.GetMatrixRCElement(k+1, l+1) - Copy.GetMatrixRCElement(i+1, l+1) * tempVar_1) <= epsilon)
                        {
 //                           rescount++;
                            Copy.Set(k, l, 0);
                            I.Set(k, l, (I.GetMatrixRCElement(k+1, l+1) - I.GetMatrixRCElement(i+1, l+1) * tempVar_1));

                        }
                        else
                        {
 //                           elsecount++;
                            Copy.Set(k, l, (Copy.GetMatrixRCElement(k+1, l+1) - Copy.GetMatrixRCElement(i+1, l+1) * tempVar_1));
                            I.Set(k, l, (I.GetMatrixRCElement(k+1, l+1) - I.GetMatrixRCElement(i+1, l+1) * tempVar_1));

                        }
                    }
                }
            }

            if(mdbug)
            {
                cout << " the Copy matrix is and the res and else counts are "<<  rescount << "  " << elsecount << endl << endl;
                Copy.Mprint();
                I.Mprint();
            }

        }
        if(mdbug)
        {
            cout << " Matrix Invert complete..."  << endl;
        }
        return I;
    }
    cout << " Matrix is not invertible.. must be square" << endl;
    return *this;
}

long double Determinant()
{
    /// initialisation and a Copy matrix

    Matrix Copy = *this;
    long double tempVar_1 = 0;
    int numberSwaps = 0;
    long double det = 1;

    if(mdbug)
    {
        cout << " Matrix Determinant Function called..." << endl;
    }

    /// check matrix dimensions -  must be square
    if (Copy.GetMatrixRows() == Copy.GetMatrixCols())
    {
        /// partial pivot routine
        /// scan 1st column and select the largest element, if its "a11" zero all the a1i-n elements
        /// otherwise swap the row with the largest element for the 1st row.

        for ( int i = 0; i < Copy.GetMatrixRows(); i++)
        {
            /// initialisations
            int swapRow = 0;
            long double pivot = Copy.GetMatrixRCElement(i+1, i+1);

            /// iterate over the ith column to find the largest entry - this will
            /// become the pivot for the ith row. Set the swapRow to j the row that
            /// has to be swapped with ith.

            for (int j = i; j < Copy.GetMatrixCols(); j++)
            {
//                cout << " iterate  - the Pivot is " << pivot << " and the swaprow is " << swapRow << " and i is " << i << endl;
                if ( Abs(pivot) < Abs(Copy.GetMatrixRCElement(j+1, i+1)))
                {
                   pivot =  Copy.GetMatrixRCElement(j+1, i+1);
                   swapRow = j;
//                   cout << " Set the Pivot " << pivot << " and the swaprow is " << swapRow << "and i is " << i << endl;
                }

            }


            if(pivot == 0)
            {
                cout << "Matrix is singular...  \n" << endl;
                return (det = 0);
            }

            if(mdbug)
            {
                cout << " Pivot = " << pivot << " and swapRow = " << swapRow << "  and i = " << i << endl;
            }

            /// if swapRow = i -> means we could not find a row with a pivot value greater than the ith row
            /// if swapRow = j > i then the pivot is i, j and we swap the j row with the ith row.

            if(swapRow > i)
            {
                /// swap the 2 rows of the Copy matrix - iterate along the column
//                cout << " in the swap block"  << endl;
                for( int x = 0; x < Copy.GetMatrixCols(); x++)
                {
                    tempVar_1 = Copy.GetMatrixRCElement(i+1, x+1);
                    Copy.Set(i, x, Copy.GetMatrixRCElement(swapRow+1, x+1) );
                    Copy.Set(swapRow, x, tempVar_1);

                }

                /// keep track of track of the number of swaps we do
                numberSwaps++;
//
//                cout << "after the row swaps" << endl;
//                cout << " the Copy matrix is "<< endl << endl;
//                Copy.Mprint();;
            }

            /// subtracts the ith row of the this matrix from all the other rows - should make all the other
            /// elements in the pivot column zero
            for(int k = 0; k < Copy.GetMatrixRows(); k++)
            {
                tempVar_1 = (Copy.GetMatrixRCElement(k+1, i+1))/ Copy.GetMatrixRCElement(i+1, i+1);
                for( int l = 0; l < Copy.GetMatrixCols(); l++)
                {

                    if(i != k)
                    {
                        if(Abs(Copy.GetMatrixRCElement(k+1, l+1) - Copy.GetMatrixRCElement(i+1, l+1) * tempVar_1) <= epsilon)
                        {
                            Copy.Set(k, l, 0);
                        }
                        else
                        {
                            Copy.Set(k, l, (Copy.GetMatrixRCElement(k+1, l+1) - Copy.GetMatrixRCElement(i+1, l+1) * tempVar_1));
                        }
                    }
                }
            }
//            cout << "Swaps = " << numberSwaps << endl;
//            cout << " the Copy matrix is "<< endl << endl;
//            Copy.Mprint();
        }

//        Copy.Mprint();
        /// evaluate the determinant
        for (int i = 0; i < Copy.GetMatrixRows(); i++)
        {
            det *= Copy.GetMatrixRCElement(i+1, i+1);
        }

        /// depending on the number of row swaps we need adjust the result polarity
        /// odd number of row swaps multiply by -1
        if( (numberSwaps % 2))
        {
            det = -1 * det;
        }
        if(mdbug)
        {
            cout << " Matrix Determinant complete..."  << endl;
        }
        return det;
    }
    cout << " Matrix must be square" << endl;
    return 0;
}

const Matrix GetMatrixHilbert(int n) const
{
    Matrix Hilbert(n, n);
    long double val;
    if(mdbug)
    {
        cout << " Generate a Hilbert Matrix order = " << n << endl;
    }

    if( !Hilbert.ValidateRows(n))
    {
        cout << "Error"  << endl;
/* to do what do we return here */
        return Hilbert;
    }

    for(int i = 0; i < n; i++)
    {
        for( int j = 0; j < n; j++)
        {
            val = (long double)1/(i+1 + j);
//            cout << " Element Value is " << val << endl;
            Hilbert.SetMatrixRCElement(i+1, j+1, val);
        }
    }

    return Hilbert;
}

const Matrix GetMatrixIdentity( int rows, int cols)
{
    if(mdbug)
    {
        cout << " Set up the Identity Matrix given rows and columns" << endl;
    }
    if(!ValidateRows(rows) || rows != cols)
    {
        cout << " Rows and Columns must be equal and in the range 1, " << maxrows << endl;
/* to do what do we return here */
//        return 1;
    }
    Matrix I(rows, cols);
    for( int i = 0; i < rows; i++)
    {
        I.SetMatrixRCElement( i+1, i+1, 1.0);
    }
    return I;
}

/// addition of matrices c = a + b;
	friend const Matrix operator+(const Matrix &lhside, const Matrix &rhside)
	{
		/// check the lhside and rhside dimensions, must be the same
		long double sum;
        if(mdbug)
        {
            cout << " Called add operator a = b + c ...." << endl;
        }

		if ((lhside.GetMatrixRows() == rhside.GetMatrixRows()) &&
			(lhside.GetMatrixCols() == rhside.GetMatrixCols()))
		{
			Matrix result(rhside.GetMatrixRows(), rhside.GetMatrixCols());

			for (int index = 0; index < rhside.GetMatrixSize(); index++)
			{
			    /// if we have very small elements < epsilon set them to zero
			    sum = lhside.GetMatrixElement(index) + rhside.GetMatrixElement(index);
			    if(Abs(sum) <= epsilon)
                {
                    sum = 0;
                }
                result.SetMatrixElement(index, sum);
//				result.SetMatrixElement(index, (lhside.GetMatrixElement(index) + rhside.GetMatrixElement(index)));
			}
//			cout << "adding done! \n" << endl;

            /// if we have very small elements < epsilon set them to zero
//            result.Round();
			return result;
		}
		else
		{
			if(!mdbug)
            {
                return rhside;
            }
            else
            {
                cout << " Function add matrices c = a + b  " << endl;
                cout << " addition not possible... inconsistent matrix dimensions..." << endl;
                /* to do - what should we return????? */
                return lhside;
            }

		}

	}

	/// subtraction of matrices c = a - b;
	friend const Matrix operator-(const Matrix &lhside, const Matrix &rhside)
	{
        long double sum;
		if(mdbug)
        {
            cout << " Called subtraction operator c = a - b ...." << endl;
        }

        /// check the lhside and rhside dimensions, must be the same
		if ((lhside.GetMatrixRows() == rhside.GetMatrixRows()) &&
			(lhside.GetMatrixCols() == rhside.GetMatrixCols()))
		{
            /// create a matrix to hold the results of the operation
			Matrix results(rhside.GetMatrixRows(), rhside.GetMatrixCols());

			for (int index = 0; index < rhside.GetMatrixSize(); index++)
			{
			    /// if we have very small sum elements < epsilon set them to zero
			    sum = lhside.GetMatrixElement(index) - rhside.GetMatrixElement(index);
			    if(Abs(sum) <= epsilon)
                {
                    sum = 0;
                }
                results.Set(index, sum);
			}
//			cout << "subtraction done! \n" << endl;


			results.Round();
			return results;
		}
		else
		{
			if(!mdbug)
            {
                return lhside;
            }
			cout << " Function subtraction of matrices c = a - b  " << endl;
			cout << " Subtraction not possible... inconsistent matrix dimensions..." << endl;
			 /* to do - what should we return????? */
			return lhside;
		}
	}

	/// multiplication of matrices c = a x b
	friend const Matrix operator *(const Matrix &lhside, const Matrix &rhside)
	{
	    if(mdbug)
        {
            cout << " Called multiply operator a =  b * c...." << endl;
        }

		if (lhside.GetMatrixCols() != rhside.GetMatrixRows())
		{
			if(!mdbug)
            {
                return lhside;
            }
			cout << " Function multiplication of matrices c = a x b  " << endl;
			cout << "Multiplication not possible inconsistent matrix dimension" << endl;
			 /* to do - what should we return????? */

			return lhside;
		}

		/// determine the number of elements in the matrix
		/// get the row index - this is the number of rows in the this matrix
		/// get the column index - this is the number of columns in the rhside matrix
		/// set up the results matrix to hold the contents of the matrix product

		Matrix results(lhside.GetMatrixRows(), rhside.GetMatrixCols());

        /// the final Aij element is given by sum( Bik * Ckj) where k correspond to the
		/// lhside cols or the rhside rows. k is the number of products to be summed to get the Aij term.

		for (int i = 0; i < lhside.GetMatrixRows(); i++)
		{
			for (int j = 0; j < rhside.GetMatrixCols(); j++)
			{
				long double sum = 0;
				for (int k = 0; k < lhside.GetMatrixCols(); k++)
				{
                    sum += lhside.GetMatrixRCElement(i + 1, k + 1)
						* rhside.GetMatrixRCElement(k + 1, j + 1);
                }
                /// if we have very small elements < epsilon set them to zero
                if(Abs(sum) <= epsilon)
                {
                    sum = 0;
                }
                results.Set(i, j, sum );
			}
		}

//		cout << "multiplication 'a * b' called... " << endl;
        results.Round();
		return results;
	}

    /// scalar multiplication
    friend const Matrix operator *( const Matrix &lhside, const double rhside)
    {
        if(mdbug)
        {
            cout << " Called scalar multiplication..."<< endl;
        }
        Matrix Copy = lhside;
        for(int index = 0; index < Copy.GetMatrixSize(); index++)
        {
            Copy.Set(index, rhside * Copy.GetMatrixElement(index));
        }

        /// if we have very small elements < epsilon set them to zero
        Copy.Round();
        return Copy;
    }
    /// scalar multiplication
    friend const Matrix operator *( const double lhside, const Matrix &rhside)
    {
        return (rhside * lhside);
    }

	/// equality operator  a == b
	friend bool operator==(const Matrix &lhside, const Matrix &rhside)
	{
		if(mdbug)
        {
            cout << " called equality of Matrices c == a   " << endl;
        }

		/// initialisations
		int index = 0;
		bool test = false;

		/// check if the row and column dimensions are equal if they are check
		/// then check each element in the matrix to see if they are also equal
		if ((lhside.GetMatrixRows() == rhside.GetMatrixRows()) &&
			(lhside.GetMatrixCols() == rhside.GetMatrixCols()))
		{
			while (index < rhside.GetMatrixSize())
			{
			    /// index is used to step through the elements in the matrix array,
			    /// since elements are double need to check that the difference is very small
                /// if that difference is less than epsilon then they are equal.
				if (Matrix::Abs( lhside.GetMatrixElement(index) - rhside.GetMatrixElement(index) ) <= 1000*epsilon)
				{
					test = true;
					index++;
				}
				else
				{
				    /// if any element comparison is not true return false
					return false;
				}
			}
		}
		return test;
	}

	/// equality operator  a != b;
	friend bool operator!=(const Matrix &lhside, const Matrix &rhside)
	{
		return !(lhside == rhside);
	}


};
#endif
