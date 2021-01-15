#pragma once
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Matrix {
private:
	int** _array;
	int _rows;
	int _cols;

public:
	Matrix(int rows, int cols) {
		this->_rows = rows;
		this->_cols = cols;

		_array = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			_array[i] = new int[cols] { 0 };
		}
	}

	~Matrix() {
		for (int i = 0; i < _rows; i++) {
			delete[] _array[i];
		}

		delete[] _array;
	}


	void input();
	void print();
	static Matrix sum(const Matrix& m1, const Matrix& m2) { //метод класса
		if (m1._rows == m2._rows && m1._cols == m2._cols) {
			Matrix* res = new Matrix(m1._rows, m1._cols);

			for (int i = 0; i < res->_rows; i++) {
				for (int j = 0; j < res->_cols; j++) {
					res->_array[i][j] = m1._array[i][j] + m2._array[i][j];
				}
			}

			return *res;
		}
	}
	void sum(const Matrix& m1); 
		
	int GetRows();
	
	int GetCols();
	
	friend Matrix operator- (const Matrix& m1, const Matrix& m2)// бинар  
	{
		Matrix* res = new Matrix(m1._rows, m1._cols);
		for (int i = 0; i < res->_rows; i++) {
			for (int j = 0; j < res->_cols; j++) {
				res->_array[i][j] = m1._array[i][j] - m2._array[i][j];
			}
		}
		return *res;
	}
	friend Matrix  operator+ (const Matrix& m1, const Matrix& m2)// бинар  
	{
		Matrix* res = new Matrix(m1._rows, m1._cols);
		for (int i = 0; i < res->_rows; i++) {
			for (int j = 0; j < res->_cols; j++) {
				res->_array[i][j] = m1._array[i][j] + m2._array[i][j];
			}
		}
		return *res;
	}
	friend Matrix operator* (const Matrix& m1, const Matrix& m2)// бинар  
	{
		Matrix* res = new Matrix(m1._rows, m1._cols);
		for (int i = 0; i < res->_rows; i++) {
			for (int j = 0; j < res->_cols; j++) {
				res->_array[i][j] = m1._array[i][j] * m2._array[i][j];
			}
		}
		return *res;
	}
	friend Matrix  operator* (const Matrix& m1, const int m2)// унар
	{
		Matrix* res = new Matrix(m1._rows, m1._cols);
		for (int i = 0; i < res->_rows; i++) {
			for (int j = 0; j < res->_cols; j++) {
				res->_array[i][j] = m1._array[i][j] * m2;
			}
		}
		return *res;
	}
	Matrix  operator<< (const Matrix& m1)
	{
		print();
		return m1;
	}
	Matrix  operator>> (const Matrix& m1)
	{
		input();
		return m1;
	}
};


