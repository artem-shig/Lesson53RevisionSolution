// Сумма элементов столбцов с экстремальными элементами
// [The Sum of elements of columns with extreme elements]
// 
// Дана математическая прямоугольная матрица размером N на M.
// Необходимо разработать функцию (или программу), которая 
// высчитывает сумму элементов в тех столбцах заданной матрицы,
// которые содержат хотя бы один экстремальный элемент.

#include "logic.h"

int get_max_value(int** matrix, int n, int m) {

	int max = matrix[0][0];

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (max < matrix[i][j]) {
				max = matrix[i][j];
			}
		}
	}
	return max;
}

int get_min_value(int** matrix, int n, int m) {

	int min = matrix[0][0];

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (min > matrix[i][j]) {
				min = matrix[i][j];
			}
		}
	}
	return min;
}

int sum_elements_of_columns_with_extreme_value(int** matrix, int n, int m) {

	if (n <= 0 || m <= 0 || matrix == nullptr) {
		return 0;
	}

	int sumAll = 0;
	int sumСolumn;
	int countExtremeValue;
	int maxValue = get_max_value(matrix, n, m);
	int minValue = get_min_value(matrix, n, m);


	for (int j = 0; j < m; j++)
	{
		countExtremeValue = 0;
		sumСolumn = 0;

		for (int i = 0; i < n; i++)
		{
			sumСolumn += matrix[i][j];
			if (matrix[i][j] == maxValue || matrix[i][j] == minValue) {
				countExtremeValue++;
			}
		}

		if (countExtremeValue == 0) {
			sumСolumn = 0;
		}
		sumAll += sumСolumn;
	}

	return sumAll;
}