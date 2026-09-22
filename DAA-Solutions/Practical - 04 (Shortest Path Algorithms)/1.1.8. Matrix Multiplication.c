/**
 * @file 1.1.8. Matrix Multiplication.c
 * @brief 1.1.8. Matrix Multiplication
 * @strategy Basic Matrix Operations / Divide and Conquer
 * @complexity
 *   - Time Complexity: O(m * n * p)
 *   - Space Complexity: O(m * n + n * p + m * p)
 */

#include <stdio.h>

int main() {
    int m, n, p, n2;

    if (scanf("%d %d", &m, &n) != 2) return 0;

    int A[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    if (scanf("%d %d", &n2, &p) != 2) return 0;

    if (n != n2) {
        printf("Invalid input");
        return 0;
    }

    int B[n2][p];

    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < p; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    int C[m][p];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
