#pragma once
#include<iostream>

class matr
{
private:
	int cols;
	int rows;
	double* elems;
public:
	matr();
	matr(int i, int j);
	matr(int i, int j, const double* arr);
	~matr();

	void input();
	void input(int i, int j);
	void input(int i, int j, const double* arr);
	void print();

	double get_elem(int i, int j);
	int get_cols();
	int get_rows();

	void mult_by_num(double num);
	bool mult(const matr* matr2);
	//перегрузка умножения
	bool mult(const double* arr, int lrows, int lcols);
	bool sum(const matr* matr2);
	//перегрузка суммы
	bool sum(const double* arr, int lrows, int lcols);

	double trace();
	void copy(const matr* mat2);
	//double det();

};