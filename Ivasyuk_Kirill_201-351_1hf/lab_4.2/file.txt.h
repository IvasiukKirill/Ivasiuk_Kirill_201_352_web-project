#pragma once
class Matrix
{
private:
	int** matr;
	int rows;
	int cols;


	int Opred(int** matr, int n)
	{
		if (n == 1)
			return matr[0][0];
		else if (n == 2)
			return matr[0][0] * matr[1][1] - matr[0][1] * matr[1][0];
		else {
			int d = 0;
			for (int k = 0; k < n; k++) {
				int** b = new int* [n - 1];
				for (int i = 0; i < n - 1; i++) {
					b[i] = new int[n - 1];
				}
				for (int i = 1; i < n; i++) {
					for (int j = 0; j < n; j++) {
						if (j == k)
							continue;
						else if (j < k)
							b[i - 1][j] = matr[i][j];
						else
							b[i - 1][j - 1] = matr[i][j];
					}
				}
				d += pow(-1, k + 2) * matr[0][k] * Opred(b, n - 1);
			}
			return d;
		}
	}
public:
	Matrix(int rows, int cols)
	{
		this->rows = rows;
		this->cols = cols;

		matr = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			matr[i] = new int[cols];
		}
	}

	~Matrix()
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] matr[i];
		}
		delete[] matr;
	}

	void Input()
	{
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->cols; j++)
			{
				cin >> this->matr[i][j];
			}
		}
	}
	void PrintMatrix()
	{
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->cols; j++)
			{
				cout << matr[i][j] << ' ';
			}
			cout << endl;
		}
	}

	Matrix Sum(Matrix& m1)
	{
		if (m1.rows == this->rows && m1.cols == this->cols)
		{
			Matrix* res = new Matrix(m1.rows, m1.cols);

			for (int i = 0; i < res->rows; i++)
			{
				for (int j = 0; j < res->cols; j++)
				{
					res->matr[i][j] = m1.matr[i][j] + this->matr[i][j];
				}
			}

			return *res;
		}
	}

	Matrix Mult(Matrix& m1, Matrix& m2)
	{
		if (m1.rows == m2.cols)
		{
			Matrix* res = new Matrix(m1.rows, m2.cols);
			for (int i = 0; i < res->rows; i++)
			{
				for (int j = 0; j < res->cols; j++)
				{
					res->matr[i][j] = 0;
					for (int k = 0; k < m1.cols; k++)
					{
						res->matr[i][j] += m1.matr[i][k] * m2.matr[k][j];
					}
				}
			}
			return *res;
		}
	}

	double Trace()
	{
		double Sum = 0;

		if (this->cols == this->rows)
		{
			for (int i = 0; i < this->rows; i++)
			{
				Sum += this->matr[i][i];
			}
			return Sum;
		}
	}

	double Det()
	{
		double x = Opred(matr, this->cols);
		return x;
	}


	void MultByNum(double num)
	{
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->cols; j++)
			{
				matr[i][j] *= num;
			}
		}
	}

	int GetCols()
	{
		return this->cols;
	}

	int GetRows()
	{
		return this->rows;
	}

	double GetElem(int i, int j)
	{
		return matr[i][j];
	}

};

