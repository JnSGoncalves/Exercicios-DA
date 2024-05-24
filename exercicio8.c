#include <stdio.h>
#include <stdlib.h>

#define Total 5

int* inverter_array(int *array, int tamanho) {
    int *array2 = (int *)malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++) {
        array2[i] = array[tamanho - 1 - i];
    }

    return array2;
}

int main() {
    int array[Total] = {-5, 5, 7, 7, 9};
    int tamanho = Total;

    int *array_inv = inverter_array(array, tamanho);

    printf("Array invertido: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array_inv[i]);
    }
}