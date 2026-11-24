#include <stdio.h>

int main(void) {
    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int B[2][3] = {{10, 20, 30}, {40, 50, 60}};
    int C[2][3];

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            C[i][j] = A[i][j] + B[i][j];

    printf("Matriz A + Matriz B:\\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) printf("%d\\t", C[i][j]);
        printf("\\n");
    }

    return 0;
}
