#include "Matrix.h"
#include <iostream>
using namespace std;

	void Matrix:: input() {
		if (this->_cols == this->_rows)
		{
			for (int i = 0, j = 0; i < this->_rows; i++, j++)
			{
				cin >> this->_array[i][j];
			}
			for (int i = 0, j = 1; j < this->_cols; i++, j++)
			{
				cin >> this->_array[i][j];
			}
			for (int i = 1, j = 0; i < this->_rows; i++, j++)
			{
				cin >> this->_array[i][j];
			}

		}


	}
	void Matrix::print() {
		for (int i = 0; i < _rows; i++) {
			for (int j = 0; j < _cols; j++) {
				std::cout << _array[i][j] << " ";
			}
			std::cout << "\n";
		}
	}
	
	
	void Matrix:: sum(const Matrix& m1) { // метод экз класса
		if (m1._rows == this->_rows && m1._cols == this->_cols) {

			for (int i = 0; i < this->_rows; i++) {
				for (int j = 0; j < this->_cols; j++) {
					this->_array[i][j] += m1._array[i][j];
				}
			}
		}
	}
	int Matrix:: GetRows()
	{
		return _rows;
	}
	int Matrix::GetCols()
	{
		return _cols;
	}