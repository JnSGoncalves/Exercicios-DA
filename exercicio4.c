#include <stdio.h>

#define linha_matriz1 3
#define coluna_matriz1 3
#define linha_matriz2 3
#define coluna_matriz2 3

int mult_matriz(int matriz1[][coluna_matriz1], int matriz2[][coluna_matriz2], int mat_result[linha_matriz1][coluna_matriz2]){
    if (linha_matriz1 != coluna_matriz2){
        printf("Multplicação impossível.\n");
        return 0;
    }

    for(int linha = 0; linha < linha_matriz1; linha++){
        for (int coluna = 0; coluna < coluna_matriz2; coluna++){
            mat_result[linha][coluna] = 0;
        }
    }

    for(int linha = 0; linha < linha_matriz1; linha++){
        for (int coluna = 0; coluna < coluna_matriz2; coluna++){
            for (int linha_coluna = 0; linha_coluna < linha_matriz1; linha_coluna++){
                mat_result[linha][coluna] += matriz1[linha][linha_coluna] * matriz2[linha_coluna][coluna];
            }
        }
    }
}

int main(){
    int matriz1[linha_matriz1][coluna_matriz1] = {
        {2, -4, 4},
        {3, 6, -1},
        {3, 4, 1}
    };

    int matriz2[linha_matriz2][coluna_matriz2] = {
        {1, 2, 4},
        {-3, -1, 2},
        {2, -2, 3}
    };

    int mat_result[linha_matriz1][coluna_matriz2];

    mult_matriz(matriz1, matriz2, mat_result);
    
    printf("Matriz multiplicada.\n");
    for (int linha = 0; linha < linha_matriz1; linha++){
        for (int coluna = 0; coluna < coluna_matriz2; coluna++){
            printf("%d ", mat_result[linha][coluna]);
        }
        printf("\n");
    }
}