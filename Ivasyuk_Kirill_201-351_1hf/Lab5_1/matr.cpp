#include "matr.h"
using std::cout;
matr::matr()
{
	cols = 0;
	rows = 0;
	elems = nullptr;
}

matr::matr(int i, int j)
{
	rows = i;
	cols = j;
	elems = new double[i * j]{ 0 };
}

matr::matr(int i, int j, const double* arr)
{
	rows = i;
	cols = j;
	elems = new double[i * j]{ 0 };
	for (int k = 0; k < i * j; k++)
	{
		elems[k] = arr[k];
	}
}



matr::~matr()
{
	if (elems != nullptr)
		delete[] elems;
}

void matr::input()
{
	std::cout << "Input number of rows:";
	std::cin >> rows;
	std::cout << "Input number of columns:";
	std::cin >> cols;
	if (elems != nullptr)
		delete[] elems;
	elems = new double[this->rows * this->cols]{ 0 };
	for (int i = 0; i < rows * cols; i++)
		std::cin >> elems[i];
}

void matr::input(int i, int j)
{
	if (elems != nullptr)
		delete[] elems;
	this->elems = new double[i * j]{ 0 };
	std::cout << "Enter matrix: \n";
	for (int k = 0; k < i * j; k++)
		std::cin >> elems[k];
}

void matr::input(int i, int j, const double* arr)
{
	if (this->elems != nullptr)
		delete[] this->elems;
	this->elems = new double[i * j]{ 0 };
	for (int k = 0; k < i * j; k++)
		this->elems[k] = arr[k];
}

void matr::print()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cout << get_elem(i, j) << "\t";
		cout << std::endl;
	}
}

double matr::get_elem(int i, int j)
{
	return elems[i * cols + j];
}

int matr::get_rows()
{
	return rows;
}

int matr::get_cols()
{
	return cols;
}

void matr::mult_by_num(double num)
{
	for (int i = 0; i < rows * cols; i++)
		this->elems[i] *= num;
}


bool matr::sum(const matr* matr2)
{
	if (rows != matr2->rows || cols != matr2->cols)
		return false;
	for (int i = 0; i < cols * rows; i++)
	{
		this->elems[i] += matr2->elems[i];

	}
	return true;
}

bool matr::sum(const double* arr, int lrows, int lcols)
{
	if (rows != lrows && cols != lcols)
		return false;
	for (int i = 0; i < cols * rows; i++)
	{
		this->elems[i] += arr[i];

	}
	return true;
}


bool matr::mult(const matr* matr2)
{
	if (this->cols == matr2->rows)
	{
		matr Buf;
		Buf.copy(this);

		delete[] this->elems;
		this->cols = matr2->cols;
		this->elems = new double[double(this->cols) * this->rows]{ 0 };

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				for (int k = 0; k < Buf.cols; k++)
					this->elems[i * cols + j] += Buf.get_elem(i, k) * matr2->elems[k * matr2->cols];
		return true;
	}
	else
	{
		cout << "error \n";
		return false;
	}
}

bool matr::mult(const double* arr, int lrows, int lcols)
{
	if (this->cols == lrows)
	{
		matr MatrBuf(this->rows, this->cols, this->elems);

		delete[] this->elems;
		this->cols = lcols;
		this->elems = new double[double(this->cols) * this->rows]{ 0 };

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				for (int k = 0; k < MatrBuf.cols; k++)
					this->elems[i * cols + j] += MatrBuf.get_elem(i, k) * arr[k * lcols + j];
		return true;
	}
	else
	{
		std::cout << "error \n";
		return false;
	}
}

double matr::trace()
{
	if (cols == rows)
	{
		double s = 0.0;
		for (int i = 0; i < rows; i++)
		{
			s += this->get_elem(i, i);
		}
		return s;
	}
	else
		cout << "error \n";
	return -1;
}

void matr::copy(const matr* matr2)
{
	this->cols = matr2->cols;
	this->rows = matr2->rows;
	this->elems = new double[double(this->cols) * this->rows]{ 0 };
	for (int i = 0; i < cols * rows; i++)
		this->elems[i] = matr2->elems[i];
}