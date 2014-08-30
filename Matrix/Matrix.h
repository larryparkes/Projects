#ifndef MATRIX_H
#define MATRIX_H

#include "utils.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <stdexcept>
#include <sstream>

using std::iostream;
using std::ostream;
using std::cout;
using std::cin;
using std::endl;

const int maxrows = 1000;
const int maxcols = 1000;
const long double epsilon = 1e-12;



class Matrix
{
    private:
    inline void Set(int row, int col, long double value)
    {
        LOG_DEBUG(" private Set Matrix RC Value function Called....");
        assert(row >= 0 && row < this->GetMatrixRows());
        assert(col >= 0 && col < this->GetMatrixCols());
        this->ePtr[row * this->GetMatrixCols() + col] = value;
    }

    inline void Set(int index, long double value)
    {
        LOG_DEBUG(" private Set Matrix Value function Called....");
        assert(index >= 0 && index < this->GetMatrixSize());
        this->ePtr[index] = value;

    }

    inline bool ValidateRows(int rows)
    {
        LOG_DEBUG(" ValidateRows function Called....");
    /// check the range of the rows variable
        if(rows >= 1 && rows <= maxrows)
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
        LOG_DEBUG(" ValidateCols function Called....");
    /// check the range of the cols variable
        if(cols >= 1 && cols <= maxcols)
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
        LOG_DEBUG(" double Absolute function Called....");
        /// get the absolute value of a and return that.
        if( a < 0 )
        {
            a = -a;
        }
        return a;
    }

/// Absolute value function
    inline static int Abs( int a)
    {
        LOG_DEBUG(" integer Absolute function Called....");
        /// get the absolute value of a and return that.
        if( a < 0 )
        {
            a = -a;
        }
        return a;
    }

/// round function
    inline Matrix Round()
    {
        LOG_DEBUG(" Round Matrix function Called....");
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
        LOG_DEBUG(" Dual Matrix SwapRows function Called....");
    /// swap rows - swap1 with swap2 in both matrices - iterate along the column
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
        LOG_DEBUG(" Single Matrix SwapRows function Called....");
/// swap rows - swap1 with swap2 in the Copy Matrix - iterate along the column
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
        LOG_DEBUG(" Dual Matrix Upper&Lower Matrix Decomposition function Called....");
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
    }

/// Upper and Lower matrix decomposition routine manipulates all the off diagonal elements to zero
    inline void UnLMatrixDecomp(Matrix &a, int rowcount)
    {
        LOG_DEBUG(" Single Upper&Lower Matrix Decomposition function Called....");
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
    }

/// Normalise the row - iterate over the row count row and divide each element by the pivot
/// this will make the pivot elements  unity
    inline void NormaliseMatrixRow( Matrix &a, Matrix &I, int rowcount, long double pivot)
    {
        LOG_DEBUG(" NormaliseMatrixRow function Called....");
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
        LOG_DEBUG(" SelectPivot function Called....");
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

	int mRows;		    // row dimension of the matrix array
	int mCols;		    // column dimension of the matrix array
	long double *ePtr;	// the location of the first element of the matrix



    public:
    static bool mdbug;

/// default constructor
	Matrix()
		:mRows(2), mCols(2)
	{
	    LOG_DEBUG(" Default Constructor Called....")
    /// calculate the mSize of the matrix array
		int mSize = mRows * mCols;

    /// set the mSize of the matrix array
		this->ePtr = new long double[mSize];
		if(this->ePtr == nullptr)
        {
            std::stringstream ss;
            ss << "Function " << __FUNCTION__ << " line " << __LINE__ <<
                " Can't allocate memory for matrix elements...." ;
            throw std::runtime_error(ss.str());

        }

    /// set the elements of the matrix array to zero
		for (int index = 0; index < mSize; index++)
		{
			ePtr[index] = 0;
		}
	}

/// constructor
	Matrix(int rows, int cols)
	{
	    LOG_DEBUG(" Constructor Called....");

    /// validate the row dimensions
        if (!ValidateRows(rows))
        {
 //           rows = 2;
            std::stringstream ss;
            ss << "Function " << __FUNCTION__ << " line " << __LINE__ <<
                " Matrix Row must be between 1 and "<< maxrows <<
                "...\n" <<  " Rows = " << rows ;
            throw std::runtime_error(ss.str());
        }
        mRows = rows;

    /// validate the column dimensions
        if (!ValidateCols(cols))
        {
 //           cols = 2;
            std::stringstream ss;
            ss << "Function " << __FUNCTION__ << " line " << __LINE__ <<
                " Matrix Column must be between 1 and "<< maxcols <<
                "...\n" <<  " Columns = " << cols ;
            throw std::runtime_error(ss.str());
        }
        mCols = cols;


    /// allocate space in memory for the element array of matrix
		int mSize = this->mRows * this->mCols;
		this->ePtr = new long double[mSize];
		if(this->ePtr == nullptr)
        {
            std::stringstream ss;
            ss << "Function " << __FUNCTION__ << " line " << __LINE__ <<
                " Can't allocate memory for matrix elements...." ;
            throw std::runtime_error(ss.str());

        }

    /// set all the elements of the matrix array to zero
		for (int index = 0; index < mSize; index++)
		{
			this->ePtr[index] = 0;
		}

        LOG_DEBUG(" Constructor Called ...  and the address of ePtr is ", &(this->ePtr));
        LOG_DEBUG(" Constructor Called ...  and the ePtr points to address ", (this->ePtr));
//        LOG_DEBUG(" First Constructor Called ...  and the value of ePtr is ", *(this->ePtr));
	}

/// destructor
	~Matrix()
	{
	    LOG_DEBUG(" Destructor Called....");
	    LOG_DEBUG(" Destructor Called... and the address of ePtr is ", &(this->ePtr));
  		LOG_DEBUG(" Destructor Called... and the ePtr points to address ", (this->ePtr));
//  		LOG_DEBUG(" Destructor Called... and the value of Ptr is ", *(this->ePtr));

		delete[] this->ePtr;
		this->ePtr = nullptr;
		LOG_DEBUG(" Destructor Complete... and the address of ePtr is  ", &(this->ePtr));
  		LOG_DEBUG(" Destructor Complete... and ePtr points to address  ", (this->ePtr));


	}

/// copy constructor
	Matrix(const Matrix & matrixToCopy)
		:mRows(matrixToCopy.mRows), mCols(matrixToCopy.mCols)
	{
	    LOG_DEBUG(" Copy Constructor Called....");
    /// allocate memory for the new matrix

		this->ePtr = new long double[matrixToCopy.GetMatrixSize()];
		if(this->ePtr == nullptr)
        {
            std::stringstream ss;
            ss << "Function " << __FUNCTION__ << " line " << __LINE__ <<
                " Can't allocate memory for matrix elements...." ;
            throw std::runtime_error(ss.str());
        }

    /// copy the elements into the new matrix
		for (int index = 0; index < matrixToCopy.GetMatrixSize(); index++)
		{
			this->Set(index, matrixToCopy.GetMatrixElement(index));
		}
//		LOG_DEBUG(" Copy Constructor Called . ..  and ePtr is " << &(this->ePtr));
//        LOG_DEBUG(" Copy Constructor Called . ..  and ePtr is " << (this->ePtr));
//        LOG_DEBUG(" Copy Constructor Called . ..  and ePtr is " << *(this->ePtr));
	}

/// assignment operator
	Matrix &operator=(const Matrix &rhside)
	{
	    LOG_DEBUG(" Assignment Operator Called....");
//        if(mdbug)
//        {
//            cout << " Assignment Operator Called... " << endl;
////	        cout << " Assignment Operator Called... the address of this->ePtr is " << (this->ePtr) << endl;
////          cout << " this matrix dimensions rows = " << this->GetMatrixRows() << "  cols = " << this->GetMatrixCols() << endl;
////	        cout << " Assignment Operator Called... the address of rhside.ePtr is " << (rhside.ePtr) << endl;
////	        cout << " rhside matrix dimensions rows = " << rhside.GetMatrixRows() << "  cols = " << rhside.GetMatrixCols() << endl;
//
//        }

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
				if(this->ePtr == nullptr)
                {
                    std::stringstream ss;
                    ss << "Function " << __FUNCTION__ << " line " << __LINE__ <<
                        " Can't allocate memory for matrix elements...." ;
                    throw std::runtime_error(ss.str());
                }
			}

    /// set the this matrix dimensions to that of the rhside
			this->mRows = rhside.GetMatrixRows();
			this->mCols = rhside.GetMatrixCols();

    /// copy the rhs elements into the this matrix
			for (int index = 0; index < rhside.GetMatrixSize(); index++)
            {
                this->SetMatrixElement(index, rhside.GetMatrixElement(index));
            }
		}
//        if(mdbug)
//        {
//		    cout << " Assignment Operator Complete... the address of this->ePtr is " << &(this->ePtr) << endl;
//		    cout << " Assignment Operator Complete... the address of this->ePtr is " << (this->ePtr) << endl;
//		    cout << " Assignment Operator Complete... the address of this->ePtr is " << *(this->ePtr) << endl;
//        }
		return *this;
	}

/// print the matrix in row column format
	void Mprint(void)
	{
	    LOG_DEBUG(" Called Matrix Print function....");
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
	    LOG_DEBUG(" Called SetMatrixRows function....");
    /// validate row range set to default if out of range

        if(!ValidateRows(rows))
        {
            std::stringstream ss;
            ss << "Function " << __FUNCTION__ << " line " << __LINE__ << " Row Value out of range...\n"
                << "row must be between 1 and " << maxcols;
            throw std::runtime_error(ss.str());
        }
    /// set the row dimension
        this->mRows = rows;

	}

/// Set Matrix Columns
	void SetMatrixCols(const int cols)
	{
	    LOG_DEBUG(" Called SetMatrixCols function....");

    /// validate column range - set to default if out of range
        if(!ValidateCols(cols))
        {
            std::stringstream ss;
            ss << "Function " << __FUNCTION__ << " line " << __LINE__ << " Column Value out of range...\n"
                << "cols must be between 1 and " << maxcols;
            throw std::runtime_error(ss.str());
        }
        this->mCols = cols;
	}

/// set the elements of the matrix array
	void SetMatrixElement(int index, long double val)
	{
	    LOG_DEBUG( " Called SetMatrixElement function....");
    /// check that we are setting an element within the range of the matrix array space
        if (index < 0 || index >= this->GetMatrixSize())
        {
            std::stringstream ss;
            ss << "Function " << __FUNCTION__ << " line " << __LINE__ << " index out of range...\n"
                << "Index = " << index << " Range for Index is 0 to " << this->GetMatrixSize();
            throw std::runtime_error(ss.str());
        }
    /// set the element value
        this->Set(index, val);
        return;
 	}

/// set matrix element using RC format
	void SetMatrixRCElement(int row, int col, long double val)
	{
        LOG_DEBUG(" Called SetMatrixRCElement function....");

    /// check the validity of the RC format
        if (((row < 1 || row > this->GetMatrixRows()) || (col < 1 || col > this->GetMatrixCols())))
        {
            std::stringstream ss;
            ss << "Function " << __FUNCTION__ << " line " << __LINE__ << " row or col specification out of range...\n"
                << "Row = " << row << " Columns = " << col;
            throw std::runtime_error(ss.str());
        }

///convert row col format to array index and set array element to val
        int index = (row - 1)*this->GetMatrixCols() + (col - 1);
        this->Set(index, val);
//        this->Set(row - 1, col - 1, val);
        return;
	}

/// get the number of rows in the matrix array
	int GetMatrixRows() const
	{
	    LOG_DEBUG(" Called GetMatrixRows function ....");
		return this->mRows;
	}

/// get the number of columns in the matrix array
	int GetMatrixCols() const
	{
	    LOG_DEBUG(" Called GetMatrixCols function ....");
		return this->mCols;
	}

/// get the mSize of the matrix array
	int GetMatrixSize() const
	{
	    LOG_DEBUG(" Called GetMatrixSize function ....");
		return this->GetMatrixCols() * this->GetMatrixRows();
	}

/// get a matrix element from the matrix array
	long double GetMatrixElement(const int index) const
	{
	    LOG_DEBUG(" Called GetMatrixElement function ....");
	    if(!(index >= 0 && index <= this->GetMatrixSize()))
        {
            std::stringstream ss;
            ss << "Function " << __FUNCTION__ << " line " << __LINE__ << " index specification out of range...\n"
                << "index = " << index << " must be between 0 and " << this->GetMatrixSize();
            throw std::runtime_error(ss.str());

        }
		return this->ePtr[index];
	}

/// get matrix element RC format from the matrix array
	long double GetMatrixRCElement(const int row, const int col) const
	{
	    LOG_DEBUG(" Called GetMatrixRCElement function ....");

    /// convert RC format to an index
		int index = (row - 1) * (this->GetMatrixCols()) + col - 1;

    ///look up the index and return the element
		return this->GetMatrixElement(index);
	}

/// assign add matrices
	const Matrix &operator+=(const Matrix &rhside)
	{
	    LOG_DEBUG(" Called Assign Add operator  a += b; ....");

    /// initialisation
        long double sum;

    /// check the this and the rhside dimensions, must be the same
//        try
//        {
            if ((this->GetMatrixRows() != rhside.GetMatrixRows()) ||
			(this->GetMatrixCols() != rhside.GetMatrixCols()))
			{
			    std::stringstream ss;
                ss << "Function " << __FUNCTION__ << " line " << __LINE__
                    << " addition not possible,inconsistent matrix dimensions...\n"
                    << " matrices are " << this->GetMatrixRows() << "x" << this->GetMatrixCols()
                    << " and " << rhside.GetMatrixRows() << "x" << rhside.GetMatrixCols();
                throw std::runtime_error(ss.str());
			}

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

/// assign subtract matrices
	const Matrix &operator-=(const Matrix &rhside)
	{
	    LOG_DEBUG(" Called assign subtract operator a -= b; ....");

    /// initialisation
        long double sum;

    /// check the this and the rhside dimensions, must be the same
		if ((this->GetMatrixRows() != rhside.GetMatrixRows()) ||
			(this->GetMatrixCols() != rhside.GetMatrixCols()))
		{
		    std::stringstream ss;
            ss << "Function " << __FUNCTION__ << " line " << __LINE__
                << " addition not possible,inconsistent matrix dimensions...\n"
                << " matrices are " << this->GetMatrixRows() << "x" << this->GetMatrixCols()
                << " and " << rhside.GetMatrixRows() << "x" << rhside.GetMatrixCols();
            throw std::runtime_error(ss.str());
		}

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


/// assign multiply matrices c *= b;
	const Matrix &operator*=(const Matrix &rhside)
	{
	    LOG_DEBUG(" Called assign multiply operator a *= b;....");

	/// Check Matrix dimensions if dimensions are inconsistent throw exception
		if (this->GetMatrixCols() != rhside.GetMatrixRows())
		{
			std::stringstream ss;
            ss << "Function " << __FUNCTION__ << " line " << __LINE__
                << " Multiplication not possible, inconsistent matrix dimensions...\n"
                << " matrices are " << this->GetMatrixRows() << "x" << this->GetMatrixCols()
                << " and " << rhside.GetMatrixRows() << "x" << rhside.GetMatrixCols();
            throw std::runtime_error(ss.str());
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
		this->ePtr = new long double[result.GetMatrixSize()];
//       this->ePtr = new long double[this->GetMatrixSize()];
		if(this->ePtr == nullptr)
        {
            std::stringstream ss;
            ss << "Function " << __FUNCTION__ << " line " << __LINE__ <<
                " Can't allocate memory for matrix elements...." ;
            throw std::runtime_error(ss.str());
        }

    /// set the this object = the results object
        *this = result;
		return *this;
	}


/// matrix transpose a^t
	const Matrix MatrixTranspose()
	{
	    LOG_DEBUG(" Called Matrix Transpose function....");

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
    LOG_DEBUG(" Called Matrix Invert function....");

    /// Initialisation
    Matrix Copy = *this;
    Matrix I;

    /// check matrix dimensions -  must be square
    if (Copy.GetMatrixRows() != Copy.GetMatrixCols())
    {
        std::stringstream ss;
        ss << "Function " << __FUNCTION__ << " line " << __LINE__
            << " Matrix must be square...\n"
            << " matrix is a " << this->GetMatrixRows() << "x" << this->GetMatrixCols();
        throw std::runtime_error(ss.str());
    }

    /// set up the identity matrix
    I = I.GetMatrixIdentity(Copy.GetMatrixRows());

    /// transform process - manipulate the Copy Matrix and the Identity Matrix
    /// the aim is to reduce the Copy matrix to the identity matrix, the
    /// Identity Matrix become the inverse of the copy Matrix
    for(int i = 0; i < Copy.GetMatrixRows(); i++)
    {
    /// initialisations
        int swapRow = 0;
        long double pivot = Copy.GetMatrixRCElement(i+1, i+1);

    /// partial pivot routine
        SelectPivot(Copy, swapRow, i, pivot);
        if(pivot == 0)
        {
            std::stringstream ss;
            ss << "Function " << __FUNCTION__ << " line " << __LINE__
                << " Matrix is singular, so the determinant is undefined ";
            throw std::runtime_error(ss.str());
        }

        if(swapRow > i)
        {
    /// if swapRow = i -> means we could not find a row with a pivot value greater than the ith row
    /// if swapRow = j > i then the pivot is i, j and we swap the j row with the ith row.
            SwapRows(Copy, I, swapRow, i);
        }

    /// Normalise the current row of both the Copy and Identity Matrix divide each element by the pivot
    /// this will make the pivot element  unity
        NormaliseMatrixRow(Copy, I, i, pivot);
        if(mdbug)
        {
            cout << " after the normalise row " << i+1 << " - the Copy matrix is "<< endl << endl;
            Copy.Mprint();
        }

    /// Matrix upper and lower decomposition - manipulates the Copy Matrix and Identity Matrix
        UnLMatrixDecomp(Copy, I, i);

    }
    LOG_DEBUG(" Matrix Inversion is complete");
    return I;

}

/// calculate the determinant of a matrix.
long double Determinant()
{
    LOG_DEBUG(" Called Matrix Determinant function....")

    /// initialisation
    Matrix Copy = *this;
    int numberSwaps = 0;
    long double det = 1;

    /// check matrix dimensions -  must be square
    if (Copy.GetMatrixRows() != Copy.GetMatrixCols())
    {
        std::stringstream ss;
        ss << "Function " << __FUNCTION__ << " line " << __LINE__
            << " Matrix must be square...\n"
            << " matrix is a " << this->GetMatrixRows() << "x" << this->GetMatrixCols();
        throw std::runtime_error(ss.str());
    }


    /// transform process - manipulate the Copy Matrix to reduce it to
    /// a diagonal matrix.  the determinant is the product of the diagonal terms.

    for (int i = 0; i < Copy.GetMatrixRows(); i++)
    {
    /// loop initialisations
        int swapRow = 0;
        long double pivot = Copy.GetMatrixRCElement(i+1, i+1);

    /// partial pivot routine
        SelectPivot(Copy, swapRow, i, pivot);
        if(pivot == 0)
        {
            return det = 0;
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


/// Hilbert Matrix set up
const Matrix GetMatrixHilbert(int dimension) const
{
    LOG_DEBUG(" Called Hilbert Matrix order ", dimension, " function....");

    /// initialisations
    Matrix Hilbert(dimension, dimension);
    long double val;

    if(!Hilbert.ValidateRows(dimension))
    {
        std::stringstream ss;
        ss << "Function " << __FUNCTION__ << " line " << __LINE__
            << " Dimensions must be greater than 1 and less than " << maxrows << " ...\n";
        throw std::runtime_error(ss.str());
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
    LOG_DEBUG(" Called Identity Matrix set up function....")

/// Set up the Identity Matrix given rows and columns
    if(this->GetMatrixRows() != this->GetMatrixCols())
    {
        std::stringstream ss;
        ss << "Function " << __FUNCTION__ << " line " << __LINE__
            << " Matrix must be square...\n"
            << " matrix is a " << this->GetMatrixRows() << "x" << this->GetMatrixCols();
        throw std::runtime_error(ss.str());

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
    LOG_DEBUG(" Called Identity Matrix setup, rows specified");

/// set up the identity matrix
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
	    LOG_DEBUG(" Called Matrix Addition, a = b + c; ....");

        Matrix result  = lhside;
        result += rhside;
        return result;
	}

/// subtraction of matrices c = a - b;
	friend const Matrix operator-(const Matrix &lhside, const Matrix &rhside)
	{
	    LOG_DEBUG(" Called Matrix Subtraction, a = b - c; ....");

        Matrix results = lhside;
        results -= rhside;
        return results;
	}

/// multiplication of matrices c = a x b
	friend const Matrix operator *(const Matrix &lhside, const Matrix &rhside)
	{
	    LOG_DEBUG(" Called Matrix Multiply a = b * c; ....");

    /// set up the result matrix to hold the contents of the matrix product
        Matrix result = lhside;
        result *= rhside;
		return result;
	}

/// scalar multiplication
    friend const Matrix operator *(const Matrix &lhside, const double rhside)
    {
        LOG_DEBUG(" Called Scalar Matrix Multiplication a = b * x; x is a double....");
/// set up a matrix to hold the result of the calculation
        Matrix result = lhside;
        for(int index = 0; index < result.GetMatrixSize(); index++)
        {
            result.Set(index, rhside * result.GetMatrixElement(index));
        }

/// if we have very small elements < epsilon set them to zero
        result.Round();
        return result;
    }
/// scalar multiplication
    friend const Matrix operator *(const double lhside, const Matrix &rhside)
    {
        return (rhside * lhside);
    }

/// equality operator  a == b
	friend bool operator==(const Matrix &lhside, const Matrix &rhside)
	{
	    LOG_DEBUG(" Called Equality Operator function a == c; ....");

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
