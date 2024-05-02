#include <stdio.h>

void ClearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Soma de números em um array
int main(){
    float array[255];

    int tamanho;
    printf("Digite o número de elementos do array: ");
    scanf("%d", &tamanho);


    float n;
    for(int i = 0; i < tamanho; i++){
        ClearBuffer();
        
        printf("Digite o %d° número: ", (i + 1));
        scanf("%f", &n);

        array[i] = n;
    }

    float soma = 0;
    for(int i = 0; i < tamanho; i++){
        soma += array[i];
    }

    printf("%.1f", soma);

}