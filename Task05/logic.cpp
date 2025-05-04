// Последний локальный минимум
// [The last local minimum]
// 
// Дана математическая прямоугольная матрица размером N на M.
// Необходимо разработать эффективную функцию (или программу), которая 
// находит и возвращает местоположение последнего локального минимума. 

#include "logic.h"

void get_last_local_minimum(int** matrix, int n, int m, int* ii, int* jj) {

	if (n <= 1 || m <= 1 || matrix == nullptr) {
		return;
	}

	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = m - 1; j >= 0; j--)
		{
			if (j == m - 1) {
				if (matrix[i][j] < matrix[i][j - 1]) {
					*ii = i;
					*jj = j;
					return;
				}
			}
			else if (j < m - 1 && j > 0) {
				if (matrix[i][j] < matrix[i][j - 1] && matrix[i][j] < matrix[i][j + 1]) {
					*ii = i;
					*jj = j;
					return;
				}
			}
			else if (j == 0) {
				if (matrix[i][j] < matrix[i][j + 1]) {
					*ii = i;
					*jj = j;
					return;
				}
			}
		}
	}
}