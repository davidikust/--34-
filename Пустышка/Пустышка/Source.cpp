#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void take_size(int num, int* row, int* col)
{
	do
	{
		cout << "Введите размеры матрицы #" << num << endl;
		cin >> *row >> *col;
	} while (row <= 0 || col <= 0);
}

int** new_matrix(int row, int col)
{
	int** Matrix = new int* [row];
	for (int i = 0; i < row; i++)
		Matrix[i] = new int[col];
	return Matrix;
}




void show_matrix(int** Matrix, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << Matrix[i][j] << " ";
		cout << endl;
	}
}

void fill_matrix_manualy(int** Matrix, int row, int col)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> Matrix[i][j];
}

void matrix_autofill(int** Matrix, int row, int col)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			Matrix[i][j] = rand() % 10;
}

void set_zeros(int** Matrix, int length)
{
	for (int i = 0; i < length; i++)
		for (int j = 0; j < length; j++)
			Matrix[i][j] = 0;
}

void flow_matrix(int** Getter, int** Setter, int row, int col)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			Getter[i][j] = Setter[i][j];
}



void align_matrix(int length, int** Matrix, int* indx)
{
	int x;
	for (int i = 0; i < length; i++)
	{
		x = 0;
		for (int j = 0; j < length; j++)
		{
			if (Matrix[i][j] != 0)
			{
				x++;
				*indx = 100;
			}
		}
		if (x == 0 && i < *indx)
		{
			*indx = i;
		}
	}
}


void main()
{
	srand(time(NULL));
	int row1 = -1, col1 = -1, row2 = -1, col2 = -1, length = 2;
	system("chcp 1251");
	cout << "Вас приветствует программа" << endl <<
		"быстрого перемножения матриц методом Штрассена\n\n";




	///////////////////////////////////////////////////////////////////////////////
	////////////////////Ввод размеров матрицы пользователем////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	take_size(1, &row1, &col1);
	int** Matrix1 = new_matrix(row1, col1);

	take_size(2, &row2, &col2);
	int** Matrix2 = new_matrix(row2, col2);




	///////////////////////////////////////////////////////////////////////////////
	////////////////Выбор способа заполнения и заполнение матриц///////////////////
	///////////////////////////////////////////////////////////////////////////////

	short k;
	do
	{
		cout << "Выберите способ заполнения матриц\n" <<
			"1 - Вручную\n2 - Случайным образом\n";
		cin >> k;
	} while (k < 1 || k > 2);
	
	switch (k)
	{
	case 1:
		fill_matrix_manualy(Matrix1, row1, col1);
		fill_matrix_manualy(Matrix2, row2, col2);

		cout << "\nМатрица 1" << "\n\n";
		show_matrix(Matrix1, row1, col1);
		
		cout << "\nМатрица 2" << "\n\n";
		show_matrix(Matrix2, row2, col2);
		break;


	case 2:
		matrix_autofill(Matrix1, row1, col1);
		matrix_autofill(Matrix2, row2, col2);

		cout << "\nМатрица 1" << "\n\n";
		show_matrix(Matrix1, row1, col1);

		cout << "\nМатрица 2" << "\n\n";
		show_matrix(Matrix2, row2, col2);
		break;
	}




	///////////////////////////////////////////////////////////////////////////////
	/////////////////Приведение матриц к требуемому размеру////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	while (length < row1 || length < row2 || length < col1 || length < col2)
		length *= 2;

	int** givenMatrix1 = new_matrix(length, length);
	set_zeros(givenMatrix1, length);

	int** givenMatrix2 = new_matrix(length, length);
	set_zeros(givenMatrix2, length);

	flow_matrix(givenMatrix1, Matrix1, row1, col1);
	flow_matrix(givenMatrix2, Matrix2, row2, col2);

	cout << "Приведенные матрицы\n";

	cout << "\nМатрица 1" << "\n\n";
	show_matrix(Matrix1, row1, col1);

	cout << "\nМатрица 2" << "\n\n";
	show_matrix(Matrix2, row2, col2);




	///////////////////////////////////////////////////////////////////////////////
	///////////////Разбиение матриц на подматрицы и их заполнение//////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** mat1 = new int* [length / 2];
	int** mat2 = new int* [length / 2];
	int** mat3 = new int* [length / 2];
	int** mat4 = new int* [length / 2];
	int** mat5 = new int* [length / 2];
	int** mat6 = new int* [length / 2];
	int** mat7 = new int* [length / 2];
	int** mat8 = new int* [length / 2];
	
	for (int i = 0; i < length / 2; i++)
	{
		mat1[i] = new int[length / 2];
		mat2[i] = new int[length / 2];
		mat3[i] = new int[length / 2];
		mat4[i] = new int[length / 2];
		mat5[i] = new int[length / 2];
		mat6[i] = new int[length / 2];
		mat7[i] = new int[length / 2];
		mat8[i] = new int[length / 2];

		for (int j = 0; j < length / 2; j++)
		{
			mat1[i][j] = givenMatrix1[i][j];
			mat2[i][j] = givenMatrix1[i][j + length / 2];
			mat3[i][j] = givenMatrix1[i + length / 2][j];
			mat4[i][j] = givenMatrix1[i + length / 2][j + length / 2];
			mat5[i][j] = givenMatrix2[i][j];
			mat6[i][j] = givenMatrix2[i][j + length / 2];
			mat7[i][j] = givenMatrix2[i + length / 2][j];
			mat8[i][j] = givenMatrix2[i + length / 2][j + length / 2];
		}
	}




	///////////////////////////////////////////////////////////////////////////////
	////////////////////////Создание промежуточных матриц//////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	// p - промежуточная матрица
	int** p1 = new int* [length / 2];
	int** p2 = new int* [length / 2];
	int** p4 = new int* [length / 2];
	int** p3 = new int* [length / 2];
	int** p5 = new int* [length / 2];
	int** p6 = new int* [length / 2];
	int** p7 = new int* [length / 2];

	for (int i = 0; i < length / 2; i++)
	{
		p1[i] = new int[length / 2];	
		p2[i] = new int[length / 2];	
		p3[i] = new int[length / 2];
		p4[i] = new int[length / 2];
		p5[i] = new int[length / 2];
		p6[i] = new int[length / 2];
		p7[i] = new int[length / 2];
	}




	///////////////////////////////////////////////////////////////////////////////
	////////////////////Вычисление значений промежуточных матриц///////////////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < length / 2; i++)
	{
		for (int j = 0; j < length / 2; j++)
		{
			p1[i][j] = 0;
			p2[i][j] = 0;
			p3[i][j] = 0;
			p4[i][j] = 0;
			p5[i][j] = 0;
			p6[i][j] = 0;
			p7[i][j] = 0;

			for (int z = 0; z < length / 2; z++)
			{
				p1[i][j] += (mat1[i][z] + mat4[i][z]) * (mat5[z][j] + mat8[z][j]);			
				p2[i][j] += (mat3[i][z] + mat4[i][z]) * mat5[z][j];			
				p3[i][j] += mat1[i][z] * (mat6[z][j] - mat8[z][j]);			
				p4[i][j] += mat4[i][z] * (mat7[z][j] - mat5[z][j]);			
				p5[i][j] += (mat1[i][z] + mat2[i][z]) * mat8[z][j];			
				p6[i][j] += (mat3[i][z] - mat1[i][z]) * (mat5[z][j] + mat6[z][j]);		
				p7[i][j] += (mat2[i][z] - mat4[i][z]) * (mat7[z][j] + mat8[z][j]);
			}
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////////Создание вспомогательных матриц/////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** mat9 = new int* [length / 2];
	int** mat10 = new int* [length / 2];
	int** mat11 = new int* [length / 2];
	int** mat12 = new int* [length / 2];

	for (int i = 0; i < length / 2; i++)
	{
		mat9[i] = new int[length / 2];
		mat10[i] = new int[length / 2];
		mat11[i] = new int[length / 2];
		mat12[i] = new int[length / 2];
	}

	///////////////////////////////////////////////////////////////////////////////
	////////////Подсчет значений вспомогательных матриц из промежуточных///////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < length / 2; i++)
	{
		for (int j = 0; j < length / 2; j++)
		{
			mat9[i][j] = p1[i][j] + p4[i][j] - p5[i][j] + p7[i][j];
			mat10[i][j] = p3[i][j] + p5[i][j];
			mat11[i][j] = p2[i][j] + p4[i][j];
			mat12[i][j] = p1[i][j] - p2[i][j] + p3[i][j] + p6[i][j];
		}
	}




	///////////////////////////////////////////////////////////////////////////////
	///////////////////Создание результирующей матрицы/////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** M5 = new int* [length];
	for (int i = 0; i < length; i++)
	{
		M5[i] = new int[length];
	}




	///////////////////////////////////////////////////////////////////////////////
	///////Занесение информации из вспомогательных матриц в результирующую/////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < length / 2; i++)
	{
		for (int j = 0; j < length / 2; j++)
		{
			M5[i][j] = mat9[i][j];
			M5[i][j + length / 2] = mat10[i][j];
			M5[i + length / 2][j] = mat11[i][j];
			M5[i + length / 2][j + length / 2] = mat12[i][j];
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	////////////////Выравнивание границ результирующей матрицы/////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int f = 100, s = 100;
	align_matrix(length, M5, &f);
	align_matrix(length, M5, &s);

	int** M6 = new int* [f];
	for (int i = 0; i < f; i++)
	{
		M6[i] = new int[s];
		for (int j = 0; j < s; j++)
			M6[i][j] = M5[i][j];
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////Вывод результирующей матрицы////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	cout << "\nРезультирующая матрица\n\n";
	for (int i = 0; i < f; i++)
	{
		for (int j = 0; j < s; j++)
			cout << M6[i][j] << " ";
		cout << endl;
	}

	system("pause");

	///////////////////////////////////////////////////////////////////////////////
	/////////////////////Очистка динамической памяти///////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < row1; i++)
		delete[] Matrix1[i];
	for (int i = 0; i < row2; i++)
		delete[] Matrix2[i];
	for (int i = 0; i < length; i++)
	{
		delete[] givenMatrix1[i];
		delete[] givenMatrix2[i];
		delete[] M5[i];
	}
	for (int i = 0; i < f; i++)
		delete[] M6[i];
	for (int i = 0; i < length / 2; i++)
	{
		delete[] mat1[i];
		delete[] mat2[i];
		delete[] mat3[i];
		delete[] mat4[i];
		delete[] mat5[i];
		delete[] mat6[i];
		delete[] mat7[i];
		delete[] mat8[i];
		delete[] mat9[i];
		delete[] mat10[i];
		delete[] mat11[i];
		delete[] mat12[i];
		delete[] p1[i];
		delete[] p2[i];
		delete[] p3[i];
		delete[] p4[i];
		delete[] p5[i];
		delete[] p6[i];
		delete[] p7[i];
	}
	delete[] Matrix1, Matrix2, givenMatrix1, givenMatrix2, M5, M6;
	delete[] mat1, mat2, mat3, mat4, mat5, mat6, mat7, mat8, mat9, mat10, mat11, mat12;
	delete[] p1, p2, p3, p4, p5, p6, p7;
}