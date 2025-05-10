// Минимальный максимум среди всех локальных максимумов
// [The minimum maximum among all local maxima].
// 
// Дана математическая прямоугольная матрица размером N на M.
// Необходимо разработать функцию (или программу), которая 
// находит значение локального максимума, который является
// минимальным среди всех локальных максимумов. 

#include "logic.h"
#include <iostream>

int get_min_maximum(int** matrix, int n, int m) {

	if (n <= 0 || m <= 0 || matrix == nullptr) {
		return 0;
	}

	int minMaximum = matrix[0][0];
	int localMaximum = matrix[0][0];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			if (j == 0) {
				if (matrix[i][j] > matrix[i][j + 1]) {
					localMaximum = matrix[i][j];
				}
			}
			else if (j > 0 && j < m - 1) {
				if (matrix[i][j] > matrix[i][j + 1] && matrix[i][j] > matrix[i][j - 1]) {
					localMaximum = matrix[i][j];
				}
			}
			else if (j == m - 1) {
				if (matrix[i][j] > matrix[i][j - 1]) {
					localMaximum = matrix[i][j];
				}
			}
		}
		if (minMaximum > localMaximum) {
			int t = localMaximum;
			localMaximum = minMaximum;
			minMaximum = t;
		}

	}


	return minMaximum;
}