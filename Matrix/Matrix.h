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
//const int mylong = 1;


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
    /// check the range of the rows variable
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
    /// check the range of the cols variable
        if(cols >= 1 || cols <= maxcols)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

/// Absolute value function
    inline static long double Abs( long double a)
    {
        // get the absolute value of a and return that.
        if( a < 0 )
        {
            a = -a;
        }
        return a;
    }

/// Absolute value function
    inline static int Abs( int a)
    {
        // get the absolute value of a and return that.
        if( a < 0 )
        {
            a = -a;
        }
        return a;
    }

/// round function
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

/// Swap Rows in Matrix a & I function, swaps rows swap1 and swap2
    inline void SwapRows(Matrix &a, Matrix &I, int swap1, int swap2)
    {
    /// swap rows - swap1 with swap2 in both matrices - iterate along the column
//      cout << " in the swap block"  << endl;
        long double tempVar_1;
        long double tempVar_2;
        for( int x = 0; x < a.GetMatrixCols(); x++)
        {
            tempVar_1 = a.GetMatrixRCElement(swap2+1, x+1);
            tempVar_2 = I.GetMatrixRCElement(swap2+1, x+1);
            a.Set(swap2, x, a.GetMatrixRCElement(swap1+1, x+1) );
            I.Set(swap2, x, I.GetMatrixRCElement(swap1+1, x+1) );
            a.Set(swap1, x, tempVar_1);
            I.Set(swap1, x, tempVar_2);
        }
    }

/// Swap Rows in Matrix a function, swaps rows swap1 and swap2
    inline void SwapRows(Matrix &a, int swap1, int swap2)
    {
/// swap rows - swap1 with swap2 in the Copy Matrix - iterate along the column
//      cout << " in the swap block"  << endl;
        long double tempVar_1;
        for( int x = 0; x < a.GetMatrixCols(); x++)
        {
            tempVar_1 = a.GetMatrixRCElement(swap2+1, x+1);
            a.Set(swap2, x, a.GetMatrixRCElement(swap1+1, x+1) );
            a.Set(swap1, x, tempVar_1);
        }
    }

/// Matrix upper and lower decomposition
    inline void UnLMatrixDecomp( Matrix &a, Matrix &I, int rowcount)
    {
        for(int k = 0; k < a.GetMatrixRows(); k++)
        {
            long double tempVar_1 = a.GetMatrixRCElement(k+1, rowcount+1);
            for( int l = 0; l < a.GetMatrixCols(); l++)
            {
                if(rowcount != k)
                {
    /// subtracts the row count row of the this matrix from all the other rows - should make all the other
    /// elements in the pivot column zero
                    if(Abs(a.GetMatrixRCElement(k+1, l+1) - a.GetMatrixRCElement(rowcount+1, l+1) * tempVar_1) <= epsilon)
                    {
                        a.Set(k, l, 0);
                        I.Set(k, l, (I.GetMatrixRCElement(k+1, l+1) - I.GetMatrixRCElement(rowcount+1, l+1) * tempVar_1));
                    }
                    else
                    {
                        a.Set(k, l, (a.GetMatrixRCElement(k+1, l+1) - a.GetMatrixRCElement(rowcount+1, l+1) * tempVar_1));
                        I.Set(k, l, (I.GetMatrixRCElement(k+1, l+1) - I.GetMatrixRCElement(rowcount+1, l+1) * tempVar_1));
                    }
                }
            }
        }
        if(mdbug)
        {
            a.Mprint();
            I.Mprint();
        }
    }

/// Upper and Lower matrix decomposition routine manipulates all the off diagonal elements to zero
    inline void UnLMatrixDecomp( Matrix &a, int rowcount)
    {
        for(int k = 0; k < a.GetMatrixRows(); k++)
        {
            long double tempVar_1 = (a.GetMatrixRCElement(k+1, rowcount+1))/ a.GetMatrixRCElement(rowcount+1, rowcount+1);
            for( int l = 0; l < a.GetMatrixCols(); l++)
            {
                if(rowcount != k)
                {
                    if(Abs(a.GetMatrixRCElement(k+1, l+1) - a.GetMatrixRCElement(rowcount+1, l+1) * tempVar_1) <= epsilon)
                    {
                        a.Set(k, l, 0);
                    }
                    else
                    {
                        a.Set(k, l, (a.GetMatrixRCElement(k+1, l+1) - a.GetMatrixRCElement(rowcount+1, l+1) * tempVar_1));
                    }
                }
            }
        }
        if(mdbug)
        {
            a.Mprint();
        }
    }

/// Normalise the row - iterate over the row count row and divide each element by the pivot
/// this will make the pivot elements  unity
    inline void NormaliseMatrixRow( Matrix &a, Matrix &I, int rowcount, long double pivot)
    {
        for(int j = 0; j < a.GetMatrixCols(); j++)
        {
            if(j >= rowcount)
            {
                a.Set(rowcount, j, (a.GetMatrixRCElement(rowcount+1, j+1))/pivot);
            }
            I.Set(rowcount, j, (I.GetMatrixRCElement(rowcount+1, j+1))/pivot);
        }

    }

/// partial pivot routine - row pivot
    inline void SelectPivot( Matrix &a, int &swapRow, int &rowcount, long double &pivot)
    {
        for (int j = rowcount; j < a.GetMatrixRows(); j++)
        {
    /// scan the j-th column and select the largest element this will be the pivot
            if ( Abs(pivot) < Abs(a.GetMatrixRCElement(j+1, rowcount+1)))
            {
    /// if we find a pivot larger than the a[rc, rc] update swapRow so we
    /// we can swap the rowcount row with swapRow.
                pivot =  a.GetMatrixRCElement(j+1, rowcount+1);
                swapRow = j;
            }
        }

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
		this->ePtr = new long double[mSize];


    /// set the elements of the matrix array to zero
		for (int index = 0; index < mSize; index++)
		{
			ePtr[index] = 0;
		}

        if( Matrix::mdbug )
        {
            cout << "Default Constructor Called ... Rows variable address is "<< &(this->mRows) << endl;
            cout << "Default Constructor Called ... Rows variable address is "<< &(this->mCols) << endl;
            cout << "Default Constructor Called ... and the address of ePtr is " << &(this->ePtr) << endl;
            cout << "Default Constructor Called ... and ePtr points to " << (this->ePtr) << endl;
        }
	}

/// constructor
	Matrix(int rows, int cols)
	{
    /// validate the row and column dimensions
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

		int mSize = this->mRows * this->mCols;
		this->ePtr = new long double[mSize];

    /// set all the elements of the matrix array to zero
		for (int index = 0; index < mSize; index++)
		{
			this->ePtr[index] = 0;
		}
        if (mdbug)
        {
            cout << " First Constructor Called ...  and the address of ePtr is " << &(this->ePtr) << endl;
            cout << " First Constructor Called ...  and the ePtr points to address " << (this->ePtr) << endl;
            cout << " First Constructor Called ...  and the value of ePtr is " << *(this->ePtr) << endl;
        }

	}

/// destructor
	~Matrix()
	{
	    if(mdbug)
        {
  		cout << " Destructor Called... and the address of ePtr is " << &(this->ePtr) << endl;
  		cout << " Destructor Called... and the ePtr points to address " << (this->ePtr) << endl;
  		cout << " Destructor Called... and the value of Ptr is " << *(this->ePtr) << endl;
//            cout << " Destructor Called....  "<< endl;
        }

		delete[] this->ePtr;
		this->ePtr = nullptr;
		if(mdbug)
        {
  		cout << " Destructor Complete... and the address of ePtr is " << &(this->ePtr) << endl;
  		cout << " Destructor Complete... and ePtr points to address  " << (this->ePtr) << endl;
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
		    cout << " Copy Constructor Called . ..  and ePtr is " << &(this->ePtr) << endl;
		    cout << " Copy Constructor Called . ..  and ePtr is " << (this->ePtr) << endl;
		    cout << " Copy Constructor Called . ..  and ePtr is " << *(this->ePtr) << endl;
//            cout << " Copy Constructor Called . .. " << endl;
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
				delete[] this->ePtr;
				this->ePtr = nullptr;

    /// allocate the required space for the new this matrix
				this->ePtr = new long double[rhside.GetMatrixSize()];
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
		    cout << " Assignment Operator Complete... the address of this->ePtr is " << &(this->ePtr) << endl;
		    cout << " Assignment Operator Complete... the address of this->ePtr is " << (this->ePtr) << endl;
		    cout << " Assignment Operator Complete... the address of this->ePtr is " << *(this->ePtr) << endl;
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

/// set the elements of the matrix array
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
		return this->GetMatrixElement(index);
	}

/// assign add matrices
	const Matrix &operator+=(const Matrix &rhside)
	{
    /// check the this and the rhside dimensions, must be the same
		if(mdbug)
        {
            cout << " Called assign add operator...." << endl;
        }

    /// initialisation
        long double sum;

		if ((this->GetMatrixRows() == rhside.GetMatrixRows()) &&
			(this->GetMatrixCols() == rhside.GetMatrixCols()))
		{
    /// iterate over the array and add elements

			for (int index = 0; index < rhside.GetMatrixSize(); index++)
			{
			    sum = this->GetMatrixElement(index) + rhside.GetMatrixElement(index);
    /// if we have very small elements < epsilon set them to zero
			    if(Abs(sum) <= epsilon)
                {
                    sum = 0;
                }
                this->Set(index, sum);
			}
			return *this;
		}
		else
		{
			if(mdbug)
            {
                cout << "Function assign add matrices c += b " << endl;
                cout << " addition not possible... inconsistent matrix dimensions..." << endl;
                return *this;
            }
// TODO (Larry#1#): what should we return here
/* to do - what do we or should we return here */
			return *this;
		}
	}

/// assign subtract matrices
	const Matrix &operator-=(const Matrix &rhside)
	{
        if(mdbug)
        {
            cout << " Called assign subtract operator...." << endl;
        }
    /// initialisation
        long double sum;

    /// check the this and the rhside dimensions, must be the same
		if ((this->GetMatrixRows() == rhside.GetMatrixRows()) &&
			(this->GetMatrixCols() == rhside.GetMatrixCols()))
		{
    /// iterate over the array and subtract
			for (int index = 0; index < rhside.GetMatrixSize(); index++)
			{
			    sum = this->GetMatrixElement(index) - rhside.GetMatrixElement(index);

    /// if we have very small elements < epsilon set them to zero
			    if(Abs(sum) <= epsilon)
                {
                    sum = 0;
                }
                this->Set(index, sum);
			}

			return *this;
		}
		else
		{
			if(mdbug)
            {
                cout << " Function assign subtract matrices c -= b " << endl;
                cout << " subtraction not possible inconsistent matrix dimensions..." << endl;
// TODO (Larry#1#): what should we return here
/* to do - what do we or should we return here */
                return *this;
            }
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
// TODO (Larry#1#): what do we return here
/* to do - what do we or should we return here */
			return *this;
		}
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

    /// delete the element pointer and create a new one large enough to hold all the
    /// elements of the matrix product
		delete[] this->ePtr;
		this->ePtr = nullptr;
		this->ePtr = new long double[this->GetMatrixSize()];

    /// set the this object = the results object
        *this = result;

		if(mdbug)
        {
            cout << "multiplication called... " << endl;
        }
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
    /// set this = transpose.
        *this = transpose;
		return *this;
	}

/// matrix invert a^-1
const Matrix MatrixInvert()
{
    if(mdbug)
    {
        cout << " Matrix Invert Function called..." << endl;

    }
    /// Initialisation
    Matrix Copy = *this;
    Matrix I;

    /// check matrix dimensions -  must be square
    if (Copy.GetMatrixRows() == Copy.GetMatrixCols())
    {
    /// set up the identity matrix
        I = I.GetMatrixIdentity(Copy.GetMatrixRows());

    /// transform process - manipulate the Copy Matrix and the Identity Matrix
    /// the aim is to reduce the Copy matrix to the identity matrix, the
    /// Identity Matrix become the inverse of the copy Matrix
        for ( int i = 0; i < Copy.GetMatrixRows(); i++)
        {
    /// initialisations
            int swapRow = 0;
            long double pivot = Copy.GetMatrixRCElement(i+1, i+1);

    /// partial pivot routine
            SelectPivot( Copy, swapRow, i, pivot);
            if(pivot == 0)
            {
                cout << "Matrix is singular...  \n" << endl;
// TODO (Larry#1#): what should we return here
/* to do - what do we or should we return here */
                return *this;
            }

            if(mdbug)
            {
                cout << " Pivot = " << pivot << " and swapRow = " << swapRow << "  and i = " << i << endl;
            }

            if(swapRow > i)
            {
    /// if swapRow = i -> means we could not find a row with a pivot value greater than the ith row
    /// if swapRow = j > i then the pivot is i, j and we swap the j row with the ith row.
                SwapRows(Copy, I, swapRow, i);
            }

    /// Normalise the current row of both the Copy and Identity Matrix divide each element by the pivot
    /// this will make the pivot element  unity
            NormaliseMatrixRow( Copy, I, i, pivot);
            if(mdbug)
            {
                cout << " after the normalise row " << i+1 << " - the Copy matrix is "<< endl << endl;
                Copy.Mprint();
            }

    /// Matrix upper and lower decomposition - manipulates the Copy Matrix and Identity Matrix
            UnLMatrixDecomp(Copy, I, i);

            if(mdbug)
            {
                cout << " the Copy matrix is and Identity Matrix are "<< endl << endl;
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
// TODO (Larry#1#): what should we return here
/* what should we return ???? */
    return *this;
}

/// calculate the determinant of a matrix.
long double Determinant()
{
    if(mdbug)
    {
        cout << " Matrix Determinant Function called..." << endl;
    }

    /// initialisation
    Matrix Copy = *this;
    int numberSwaps = 0;
    long double det = 1;

    /// check matrix dimensions -  must be square
    if (Copy.GetMatrixRows() == Copy.GetMatrixCols())
    {
    /// transform process - manipulate the Copy Matrix to reduce it to
    /// a diagonal matrix.  the determinant is the product of the diagonal terms.

        for ( int i = 0; i < Copy.GetMatrixRows(); i++)
        {
    /// loop initialisations
            int swapRow = 0;
            long double pivot = Copy.GetMatrixRCElement(i+1, i+1);
    /// partial pivot routine
    /// iterate over the ith column to find the largest entry - this will
    /// become the pivot for the ith row. Set the swapRow to j the row that
    /// has to be swapped with ith.
            SelectPivot(Copy, swapRow, i, pivot);
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
    /// keep track of track of the number of swaps we do
                SwapRows(Copy, swapRow, i);
                numberSwaps++;
            }

    /// subtracts the ith row of the this matrix from all the other rows - should make all the other
    /// elements in the pivot column zero
            UnLMatrixDecomp(Copy, i);
        }

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
// TODO (Larry#1#): what should we return here
    return 0;
}

/// Hilbert Matrix set up
const Matrix GetMatrixHilbert(int dimension) const
{
    if(mdbug)
    {
        cout << " Generate a Hilbert Matrix order = " << dimension << endl;
    }
    /// initialisations
    Matrix Hilbert(dimension, dimension);
    long double val;

    if( !Hilbert.ValidateRows(dimension))
    {
        cout << "Error"  << endl;
// TODO (Larry#1#): what should we return
/* to do what do we return here */
        return Hilbert;
    }
    /// set up the Hilbert Matrix
    for(int i = 0; i < dimension; i++)
    {
        for( int j = 0; j < dimension; j++)
        {
            val = (long double)1/(i+1 + j);
            Hilbert.Set(i, j, val);
        }
    }

    return Hilbert;
}

/// identity matrix set up
const Matrix GetMatrixIdentity()
{
    if(mdbug)
    {
        cout << " Set up the Identity Matrix given rows and columns" << endl;
    }
    if(this->GetMatrixRows() != this->GetMatrixCols())
    {
        cout << " Rows and Columns must be equal "<< endl;
// TODO (Larry#1#): what should we return
/* to do what do we return here */
        return *this;
    }

    for( int i = 0; i < this->GetMatrixRows(); i++)
    {
        for(int j = 0; j < this->GetMatrixCols(); j++)
        {
            if( i != j)
            {
                this->Set( i, j, 0);
            }
            this->Set( i, i, 1.0);
        }

    }
    return *this;
}

/// identity matrix set up
const Matrix GetMatrixIdentity(int rows)
{
    if(mdbug)
    {
        cout << " Set up the Identity Matrix given rows" << endl;
    }
    Matrix I(rows, rows);

    for( int i = 0; i < rows; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            if( i != j)
            {
                I.Set( i, j, 0);
            }
            I.Set( i, i, 1.0);
        }

    }
    return I;
}

/// addition of matrices c = a + b;
	friend const Matrix operator+(const Matrix &lhside, const Matrix &rhside)
	{
    /// check the lhside and rhside dimensions, must be the same
        if(mdbug)
        {
            cout << " Called add operator a = b + c ...." << endl;
        }
        Matrix result  = lhside;
        result += rhside;
        return result;
	}

/// subtraction of matrices c = a - b;
	friend const Matrix operator-(const Matrix &lhside, const Matrix &rhside)
	{
		if(mdbug)
        {
            cout << " Called subtraction operator c = a - b ...." << endl;
        }
        Matrix results = lhside;
        results -= rhside;
        return results;
	}

/// multiplication of matrices c = a x b
	friend const Matrix operator *(const Matrix &lhside, const Matrix &rhside)
	{
	    if(mdbug)
        {
            cout << " Called multiply operator a =  b * c...." << endl;
        }
    /// set up the results matrix to hold the contents of the matrix product
        Matrix results = lhside;
        results *= rhside;
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
		if ((lhside.GetMatrixRows() == rhside.GetMatrixRows()) &&
			(lhside.GetMatrixCols() == rhside.GetMatrixCols()))
		{
    /// then check each element in the matrix to see if they are also equal
			while (index < rhside.GetMatrixSize())
			{
    /// if that difference is less than epsilon then they are equal.
				if (Matrix::Abs( lhside.GetMatrixElement(index) - rhside.GetMatrixElement(index) ) > 1000*epsilon)
				{
    /// if any element comparison is not true return false
					test = false;
					return test;
				}
				test = true;
				index++;
			}
		}
		return test;
	}

/// inequality operator  a != b;
	friend bool operator!=(const Matrix &lhside, const Matrix &rhside)
	{
		return !(lhside == rhside);
	}


};
#endif
