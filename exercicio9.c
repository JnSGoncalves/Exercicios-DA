#include <stdio.h>
#include <stdlib.h>

int compara(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

float calc_media(int array[], int tamanho){
    int soma = 0;
    for(int i = 0; i < tamanho; i++){
        soma += array[i];
    }

    float media = soma / tamanho;

    return media;
}

int calc_mediana(int array[], int tamanho){
    qsort(array, tamanho, sizeof(int), compara);

    if (tamanho % 2 == 0) {
        return (array[tamanho/2 - 1] + array[tamanho/2]) / 2;
    } else {
        return array[tamanho/2];
    }
}

int calc_moda(int array[], int tamanho) {
    qsort(array, tamanho, sizeof(int), compara);

    int moda = array[0];
    int frequencia = 1;
    int max_frequencia = 1;

    for (int i = 1; i < tamanho; i++) {
        if (array[i] == array[i - 1]) {
            frequencia++;
        } else {
            if (frequencia > max_frequencia) {
                moda = array[i - 1];
                max_frequencia = frequencia;
            }
            frequencia = 1;
        }
    } if (frequencia > max_frequencia) {
        moda = array[tamanho - 1];
    }

    return moda;
}

int main(){
    int tamanho;

    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    int *array = (int *)malloc(tamanho * sizeof(int));

    printf("Digite os elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &array[i]);
    }

    printf("Média: %.2f\n", calc_media(array, tamanho));

    printf("Mediana: %d\n", calc_mediana(array, tamanho));

    printf("Moda: %d\n", calc_moda(array, tamanho));
}