#include <stdio.h>
#include <stdlib.h>

int* inverter_array(int *array, int tamanho) {
    int *array2 = (int *)malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++) {
        array2[i] = array[tamanho - 1 - i];
    }

    return array2;
}

int main() {
    int tamanho;

    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    int *array = (int *)malloc(tamanho * sizeof(int));

    printf("Digite os elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &array[i]);
    }

    int *array_inv = inverter_array(array, tamanho);

    printf("Array invertido: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array_inv[i]);
    }
    printf("\n");

    return 0;
}