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

class Matrix
{
private:
    inline void Set(int row, int col, int value)
    {
        assert(row >= 0 && row < this->GetMatrixRows());
        assert(col >= 0 && col < this->GetMatrixCols());
        this->ePtr[row * this->GetMatrixCols() + col] = value;
    }

    inline void Set(int index, int value)
    {
        assert(index >= 0 && index < this->GetMatrixSize());
        this->ePtr[index] = value;

    }

public:
	// default constructor
	Matrix()
		:mRows(2), mCols(2)
	{
		// calculate the mSize of the matrix array
		int mSize = mRows * mCols;

		// set the mSize of the matrix array
		this->ePtr = new int[mSize];

		// set the elements of the matrix array to zero
		for (int index = 0; index < mSize; index++)
		{
			//this->SetMatrixElement(index, 0);
			ePtr[index] = 0;
		}

		cout << "Default Constructor Called .... and ePtr is " << ePtr << endl;
	}

	// constructor
	Matrix(int rows, int cols)
	{
		// validate the row and column dimensions
		// row dimesnion
		if (rows < 1 || rows > maxrows)
		{
			cout << " Matrix Row dimension must be between 1 and 1000... " << endl;
			mRows = 2;
		}
		else
		{
			mRows = rows;
		}

		// column dimesnion
		if (cols <1 || cols > maxcols)
		{
			mCols = 2;
		}
		else
		{
			mCols = cols;
		}
		int mSize = mRows * mCols;

		// allocate space in memory for the element array of matrix
		ePtr = new int[mSize];

		// set all the elements of the martix array to zero
		for (int index = 0; index < mSize; index++)
		{
			ePtr[index] = 0;
		}

		cout << " First Constructor Called ...  and ePtr is " << ePtr << endl;
	}

	// destructor
	~Matrix()
	{
		cout << " Destructor Called... and ePtr points to address  " << this->ePtr << endl;
		delete[] this->ePtr;
		this->ePtr = nullptr;
		cout << " Destructor Complete... and ePtr points to address  " << this->ePtr << endl;
	}

	// copy constructor
	Matrix(const Matrix & matrixToCopy)
		:mRows(matrixToCopy.mRows), mCols(matrixToCopy.mCols)
	{
		/// calculate the mSize of the array to hold the matrix elements
		//int mSize = matrixToCopy.GetMatrixRows() * matrixToCopy.GetMatrixCols();

		/// allocate memory for the new matrix
		this->ePtr = new int[matrixToCopy.GetMatrixSize()];

		/// copy the elements into the new matrix
		for (int index = 0; index < matrixToCopy.GetMatrixSize(); index++)
		{
			this->Set(index, matrixToCopy.GetMatrixElement(index));
		}

		cout << " Copy Contructor Called . ..  and ePtr is " << ePtr << endl;
	}

	// assignment operator
	Matrix &operator=(const Matrix &rhside)
	{
        cout << " Assignment Operator Called... " << endl;
//	    cout << " Assignment Operator Called... the address of this->ePtr is " << (this->ePtr) << endl;
//        cout << " this matrix dimensions rows = " << this->GetMatrixRows() << "  cols = " << this->GetMatrixCols() << endl;
//	    cout << " Assignment Operator Called... the address of rhside.ePtr is " << (rhside.ePtr) << endl;
//	    cout << " rhside matrix dimensions rows = " << rhside.GetMatrixRows() << "  cols = " << rhside.GetMatrixCols() << endl;

		/// check that we arent attempting self assignment
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
				this->ePtr = new int[rhside.GetMatrixSize()];
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

//		cout << " Assignment Operator Complete... the address of this->ePtr is " << this->ePtr << endl;
		return *this;
	}

	// print the matrix in row column format
	void Mprint(void) const
	{
		for (int i = 0; i < this->GetMatrixRows(); i++)
		{
			for (int j = 0; j < this->GetMatrixCols(); j++)
			{
//				cout << ePtr[mCols*i + j] << "    ";
				cout << this->GetMatrixRCElement(i+1, j+1) << "    ";
			}
			cout << endl;
		}
		cout << endl << endl;
	}

	// Set Matrix Rows
	void SetMatrixRows(const int rows)
	{
		/// validate row range set to default if out of range
		// to do

		/// set the row dimesnion
		this->mRows = rows;
	}

	// Set Matrix Columns
	void SetMatrixCols(const int cols)
	{
		/// validate column range - set to default if out of range
        // to do

		/// set the column dimension
		this->mCols = cols;
	}

	// set the elements of the matrix array
	void SetMatrixElement(int index, int val)
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

	// set matrix element using RC format
	void SetMatrixRCElement(int row, int col, int val)
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

	// get the number of rows in the matrix array
	int GetMatrixRows() const
	{
		return this->mRows;
	}

	//get the number of columns in the matrix array
	int GetMatrixCols() const
	{
		return this->mCols;
	}

	// get the mSize of the mtrix array
	int GetMatrixSize() const
	{
		return this->mRows * this->mCols;
	}

	// get a matrix element from the matrix array
	int GetMatrixElement(const int index) const
	{
		return this->ePtr[index];
	}

	// get matrix element RC format from the matrix array
	int GetMatrixRCElement(const int row, const int col) const
	{
		/// convert RC format to an index
		int index = (row - 1) * (this->GetMatrixCols()) + col - 1;

		///look up the index and return the element
//		return this->ePtr[index];
		return this->GetMatrixElement(index);
	}

	// asssign add matrices
	const Matrix &operator+=(const Matrix &rhside)
	{
		/// check the this and the rhs dimensions, must be the same

		if ((this->GetMatrixRows() == rhside.GetMatrixRows()) &&
			(this->GetMatrixCols() == rhside.GetMatrixCols()))
		{
//			int mSize = rhside.GetMatrixSize();
            /// iterate over the array and add elements
			for (int index = 0; index < rhside.GetMatrixSize(); index++)
			{
				this->Set(index, (this->GetMatrixElement(index)
					+ rhside.GetMatrixElement(index)));
			}
			cout << "adding done!" << endl;
			return *this;
		}
		else
		{
			cout << "Function assign add matrices c += b " << endl;
			cout << " addition not possible... inconsistent matrix dimensions..." << endl;
			return *this;
		}

	}

	// assign subtract matrices
	const Matrix &operator-=(const Matrix &rhside)
	{
		/// check the this and the rhs dimensions, must be the same
		if ((this->GetMatrixRows() == rhside.GetMatrixRows()) &&
			(this->GetMatrixCols() == rhside.GetMatrixCols()))
		{
//			int mSize = rhside.GetMatrixSize();
            /// iterate over the array and subtract
			for (int index = 0; index < rhside.GetMatrixSize(); index++)
			{
				this->Set(index, (this->GetMatrixElement(index) - rhside.GetMatrixElement(index)));
			}
			return *this;
		}
		else
		{
			cout << " Function assign subtract matrices c -= b " << endl;
			cout << " subtraction not possible inconsistent matrix dimensions..." << endl;
			return *this;
		}
	}
/*
//	 assign multiply matrices c *= b;
	const Matrix &operator*=(const Matrix &rhside)
	{
		if (this->GetMatrixCols() != rhside.GetMatrixRows())
		{
			cout << "assign multiply matrices c *= b " << endl;
			cout << "Multiplication not possible inconsistent matrix dimension" << endl;
			return *this;
		}
		int mSize = this->GetMatrixRows() * rhside.GetMatrixCols();
		int index = rhside.GetMatrixRows();

		 set up a temporary matrix to hold the contents of the matrix product
		Matrix temp(this->GetMatrixRows(), rhside.GetMatrixCols());

		for (int i = 0; i < mSize; i++)
		{
			int result = 0;
			for (int j = 0; j < index; j++)
			{
			 	temp.ePtr[i] += this->ePtr[(i / temp.mCols)*index + j]
					* rhside.ePtr[j*temp.mCols + i%temp.mCols];
				result += this->GetMatrixRCElement(i, j) * rhside.GetMatrixRCElement(j, i)

			}
		}
		cout << " Temp is" << endl;
		temp.Mprint();

		 need adjust the mSize of the this matrix to hold the contents of the product
		 set the row and column dimesions to agree with the product results
		this->mRows = temp.mRows;
		this->mCols = temp.mCols;

		detele the element pointer and create a new one large enough to hold all the
		 elemets of the matrix product

		delete[] ePtr;
		this->ePtr = nullptr;
		this->ePtr = new int[mSize];

		 copy the prodct results into the this matrix array elements
		for (int i = 0; i < mSize; i++)
		{
			this->ePtr[i] = temp.ePtr[i];
		}

		cout << "multiplication called... " << endl;
		return *this;
	}*/

	// assign multiply matrices c *= b;
	const Matrix &operator*=(const Matrix &rhside)
	{
		if (this->GetMatrixCols() != rhside.GetMatrixRows())
		{
			cout << "assign multiply matrices c *= b " << endl;
			cout << "Multiplication not possible inconsistent matrix dimension" << endl;
			return *this;
		}
		/// determine the number of elements in the matrix product
//		int mSize = this->GetMatrixSize();

		/// get the row index - this is the number of rows in the this matrix
//		int rowIndex = this->GetMatrixRows();

		/// get the column index - this is the number of columns in the rhside matrix
//		int colIndex = rhside.GetMatrixCols();

		/// set up a temporary matrix to hold the contents of the matrix product
		Matrix temp(this->GetMatrixRows(), rhside.GetMatrixCols());

		/// the final Aij element is given by sum( Bik * Ckj) where k correspond to the
		/// this cols or the rhside rows. k is the number of products to be summed o get the Aij term.
//		int sumIndex = this->GetMatrixCols();

//		for (int i = 0; i < rowIndex; i++)
		for (int i = 0; i < this->GetMatrixRows(); i++)
		{
//			for (int j = 0; j < colIndex; j++)
			for (int j = 0; j < rhside.GetMatrixCols(); j++)
			{
				int result = 0;
//				for (int k = 0; k < sumIndex; k++)
				for (int k = 0; k < this->GetMatrixCols(); k++)
				{
  				temp.Set(i, j, result += this->GetMatrixRCElement(i + 1, k + 1)
						* rhside.GetMatrixRCElement(k + 1, j + 1));
					//temp.SetMatrixRCElement(i + 1, j + 1, result
					//	+= this->GetMatrixRCElement(i + 1, k + 1)
					//	* rhside.GetMatrixRCElement(k + 1, j + 1));
//					temp.ePtr[i*colIndex + j] += this->ePtr[i*colIndex + k] * rhside.ePtr[k*rowIndex + j];
//					temp.ePtr[i*rhside.GetMatrixCols() + j] += this->ePtr[i*rhside.GetMatrixCols() + k] * rhside.ePtr[k*this->GetMatrixRows() + j];
				}
			}
		}
		/// need adjust the mSize of the this matrix to hold the contents of the product
		/// set the row and column dimesions to agree with the product results

		this->SetMatrixRows(temp.GetMatrixRows());
		this->SetMatrixCols(temp.GetMatrixCols());

		/// detele the element pointer and create a new one large enough to hold all the
		/// elemets of the matrix product

		delete[] this->ePtr;
		this->ePtr = nullptr;
		this->ePtr = new int[this->GetMatrixSize()];

		/// copy the prodct results into the this matrix array elements
		for (int i = 0; i < this->GetMatrixSize(); i++)
		{
			this->Set(i, temp.GetMatrixElement(i));
		}

		cout << "multiplication called... " << endl;
		return *this;
	}

	// addition of matrices c = a + b;
	friend const Matrix operator+(const Matrix &lhside, const Matrix &rhside)
	{
		/// check the lhs and rhs dimensions, must be the same

		if ((lhside.GetMatrixRows() == rhside.GetMatrixRows()) &&
			(lhside.GetMatrixCols() == rhside.GetMatrixCols()))
		{
			Matrix temp(rhside.GetMatrixRows(), rhside.GetMatrixCols());
//			int mSize = rhside.GetMatrixSize();
			for (int index = 0; index < rhside.GetMatrixSize(); index++)
			{
				temp.SetMatrixElement(index, (lhside.GetMatrixElement(index) + rhside.GetMatrixElement(index)));
			}
			cout << "adding done! \n" << endl;
			return temp;
		}
		else
		{
			cout << " Function assign multiply matrices c *= b  " << endl;
			cout << " addition not possible... inconsistent matrix dimensions..." << endl;
			// what should we return?????
			return lhside;
		}

	}

	// subrtaction of matrices c = a - b;
	friend const Matrix operator-(const Matrix &lhside, const Matrix &rhside)
	{
		/// check the lhs and rhs dimensions, must be the same

		if ((lhside.GetMatrixRows() == rhside.GetMatrixRows()) &&
			(lhside.GetMatrixCols() == rhside.GetMatrixCols()))
		{
			Matrix temp(rhside.GetMatrixRows(), rhside.GetMatrixCols());
//			int mSize = rhside.GetMatrixSize();
			for (int index = 0; index < rhside.GetMatrixSize(); index++)
			{
//				temp.Set(index,
//					(lhside.GetMatrixElement(index) - rhside.GetMatrixElement(index)));
//                temp.Set(index, 10);
//                temp.SetMatrixElement(index, (lhside.GetMatrixElement(index)-rhside.GetMatrixElement(index)));
                temp.Set(index, (lhside.GetMatrixElement(index) - rhside.GetMatrixElement(index)));

			}
			cout << "subtraction done! \n" << endl;
			return temp;
		}
		else
		{
			cout << " Function subrtaction of matrices c = a - b  " << endl;
			cout << " Subtraction not possible... inconsistent matrix dimensions..." << endl;
			// what should we return?????
			return lhside;
		}
	}

	// multiplication of matrices c = a x b;
	friend const Matrix operator *(const Matrix &lhside, const Matrix &rhside)
	{
		if (lhside.GetMatrixCols() != rhside.GetMatrixRows())
		{
			cout << " Function multiplication of matrices c = a x b  " << endl;
			cout << "Multiplication not possible inconsistent matrix dimension" << endl;
			//what should we return5.00
			return lhside;
		}

		///determine the number of elements in the matrix
//		int mSize = lhside.GetMatrixRows() * rhside.GetMatrixCols();

		/// get the row index - this is the number of rows in the this matrix
//		int rowIndex = lhside.GetMatrixRows();

		/// get the column index - this is the number of columns in the rhside matrix
//		int colIndex = rhside.GetMatrixCols();


		/// set up a temporary matrix to hold the contents of the matrix product
		Matrix temp(lhside.GetMatrixRows(), rhside.GetMatrixCols());

        /// the final Aij element is given by sum( Bik * Ckj) where k correspond to the
		/// this cols or the rhside rows. k is the number of products to be summed o get the Aij term.
//		int sumIndex = lhside.GetMatrixCols();

		for (int i = 0; i < lhside.GetMatrixRows(); i++)
		{
			for (int j = 0; j < rhside.GetMatrixCols(); j++)
			{
				int result = 0;
				for (int k = 0; k < lhside.GetMatrixCols(); k++)
				{

                        temp.Set(i, j, result += lhside.GetMatrixRCElement(i + 1, k + 1)
						* rhside.GetMatrixRCElement(k + 1, j + 1));
                }
			}
		}

		cout << "multiplication 'a * b' called... " << endl;
		return temp;
	}

	/*equality operator  a == b;*/
	friend bool operator==(const Matrix &lhside, const Matrix &rhside)
	{
		cout << " Function  equality of Matrices c = a   " << endl;
		/// index is used to step through the elements in the matrix array,
//		/// mSize is the number of elements in the matrix array
		int index = 0;
		bool test = false;
//		int mSize = rhside.GetMatrixSize();

		/// check if the row and column are equal if they are check
		if ((lhside.GetMatrixRows() == rhside.GetMatrixRows()) &&
			(lhside.GetMatrixCols() == rhside.GetMatrixCols()))
		{
			while (index < rhside.GetMatrixSize())
			{
				if (lhside.GetMatrixElement(index) == rhside.GetMatrixElement(index))
				{
					test = true;
	/*				cout << "lhs[ " << index << " ] = " <<
						lhside.GetMatrixElement(index) <<
						" and rhs[ " << index << " ] = " <<
						rhside.GetMatrixElement(index) << endl;*/
					index++;
				}
				else
				{
					test = false;
					index = rhside.GetMatrixSize();
				}
			}
			return test;
		}

		return test;
	}

		// equality operator  a != b;
	friend bool operator!=(const Matrix &lhside, const Matrix &rhside)
	{
		return !(lhside == rhside);
	}


	const Matrix MatrixTranspose()
	{
		// set up a temporary matrix - set the temp matrix rows and cols equal to
		// the cols and rows of the this matrix
//		int cols = this->GetMatrixRows();
//		int rows = this->GetMatrixCols();
		Matrix temp(this->GetMatrixCols(), this->GetMatrixRows());

		// iterate over the this matrix and set temp Aij = this Aji

		for (int i = 0; i < this->GetMatrixCols(); ++i)
		{
			for (int j = 0; j < this->GetMatrixRows(); ++j)
			{
                temp.Set(i, j, this->GetMatrixRCElement(j + 1, i + 1));

				//temp.SetMatrixRCElement(iIndex + 1, jIndex + 1,
				//	this->GetMatrixRCElement(jIndex + 1, iIndex + 1));
			}

		}
		// iterate over the array and copy to the this array.
		int mSize = this->GetMatrixCols() * this->GetMatrixRows();
		for (int index = 0; index < mSize; ++index)
		{
//			this->SetMatrixElement(index, temp.GetMatrixElement(index));
			this->Set(index, temp.GetMatrixElement(index));
		}

		// set the this->mCols and the this->mRows the same as the temp matrix
		this->SetMatrixCols(temp.GetMatrixCols());
		this->SetMatrixRows(temp.GetMatrixRows());
		return *this;
	}



	//
private:
	int mRows;		// row dmension of the matrix array
	int mCols;		// column dimension of the matrix array
	int *ePtr;		// the location of the first element of the matrix

};
#endif
