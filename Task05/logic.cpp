// Последний локальный минимум
// [The last local minimum]
// 
// Дана математическая прямоугольная матрица размером N на M.
// Необходимо разработать эффективную функцию (или программу), которая 
// находит и возвращает местоположение последнего локального минимума. 

#include "logic.h"

void get_last_local_minimum(int** matrix, int n, int m, int* ii, int* jj) {

	if (n < 1 || m < 1 || matrix == nullptr) {
		return;
	}

	if (n > 1 && m > 1) {

		// 1:
		if (matrix[n - 1][m - 1] < matrix[n - 1][m - 2]
			&& matrix[n - 1][m - 1] < matrix[n - 2][m - 1]) {
			*ii = n;
			*jj = m;
			return;
		}
		// 2:
		for (int j = m - 2; j > 0; j--)
		{
			if (matrix[n - 1][j] < matrix[n - 1][j - 1]
				&& matrix[n - 1][j] < matrix[n - 1][j + 1]
				&& matrix[n - 1][j] < matrix[n - 2][j]) {
				*ii = n;
				*jj = j + 1;
				return;
			}
		}
		// 3:
		if (matrix[n - 1][0] < matrix[n - 1][1]
			&& matrix[n - 1][0] < matrix[n - 2][0]) {
			*ii = n;
			*jj = 1;
			return;
		}

		for (int i = n - 2; i > 0; i--)
		{
			// 4:
			if (matrix[i][m - 1] < matrix[i][m - 2]
				&& matrix[i][m - 1] < matrix[i - 1][m - 1]
				&& matrix[i][m - 1] < matrix[i + 1][m - 1]) {
				*ii = i + 1;
				*jj = m;
				return;
			}
			// 5:
			for (int j = m - 2; j > 0; j--)
			{
				if (matrix[i][j] < matrix[i][j - 1] && matrix[i][j] < matrix[i][j + 1]
					&& matrix[i][j] < matrix[i - 1][j] && matrix[i][j] < matrix[i + 1][j]) {
					*ii = i + 1;
					*jj = j + 1;
					return;
				}
			}
			// 6:	
			if (matrix[i][0] < matrix[i][1]
				&& matrix[i][0] < matrix[i - 1][0]
				&& matrix[i][0] < matrix[i + 1][0]) {
				*ii = i + 1;
				*jj = 1;
				return;
			}
		}
		// 7:
		if (matrix[0][m - 1] < matrix[0][m - 2]
			&& matrix[0][m - 1] < matrix[1][m - 1]) {
			*ii = 1;
			*jj = m;
			return;
		}
		// 8:
		for (int j = m - 2; j > 0; j--)
		{
			if (matrix[0][j] < matrix[0][j - 1]
				&& matrix[0][j] < matrix[0][j + 1]
				&& matrix[0][j] < matrix[1][j]) {
				*ii = 1;
				*jj = j + 1;
				return;
			}
		}
		// 9:
		if (matrix[0][0] < matrix[0][1]
			&& matrix[0][0] < matrix[1][0]) {
			*ii = 1;
			*jj = 1;
			return;
		}
	}
	else {
		if (n == 1) {
			for (int j = m - 1; j >= 0; j--)
			{
				if (j == m - 1) {
					if (matrix[0][j] < matrix[0][j - 1]) {
						*ii = 1;
						*jj = j + 1;
						return;
					}
				}
				else if (j > 0 && j < m - 1) {
					if (matrix[0][j] < matrix[0][j - 1]
						&& matrix[0][j] < matrix[0][j + 1]) {
						*ii = 1;
						*jj = j + 1;
						return;
					}
				}
				else if (j == 0){
					if (matrix[0][0] < matrix[0][j + 1]) {
						*ii = 1;
						*jj = 1;
						return;
					}
				}
			}
		}
		else if (m == 1) {
			for (int i = n - 1; i >= 0; i--)
			{
				if (i == n - 1) {
					if (matrix[i][0] < matrix[i - 1][0]) {
						*ii = i + 1;
						*jj = 1;
						return;
					}
				}
				else if (i > 0 && i < n - 1) {
					if (matrix[i][0] < matrix[i - 1][0]
						&& matrix[i][0] < matrix[i + 1][0]) {
						*ii = i + 1;
						*jj = 1;
						return;
					}
				}
				else if (i == 0) {
					if (matrix[0][0] < matrix[i + 1][0]) {
						*ii = 1;
						*jj = 1;
						return;
					}
				}
			}
		}
	}
}