#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    float salario;
} Pessoa;

// Função de comparação para idade
int compara_idade(const void *a, const void *b) {
    Pessoa *pessoaA = (Pessoa *)a;
    Pessoa *pessoaB = (Pessoa *)b;
    return (pessoaA->idade - pessoaB->idade);
}

// Função de comparação para salário
int compara_salario(const void *a, const void *b) {
    Pessoa *pessoaA = (Pessoa *)a;
    Pessoa *pessoaB = (Pessoa *)b;
    if (pessoaA->salario < pessoaB->salario) return -1;
    else if (pessoaA->salario > pessoaB->salario) return 1;
    else return 0;
}

int main() {
    // Criação e inicialização do array de structs
    Pessoa pessoas[] = {
        {"Alice", 30, 2500.65},
        {"Bob", 18, 1356.98},
        {"Carlos", 28, 980.68},
        {"Diana", 22, 1850.80}
    };
    
    int n = sizeof(pessoas) / sizeof(pessoas[0]);

    printf("Original:\n\n");
    for(int i = 0; i < n; i++) {
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Idade: %d\n", pessoas[i].idade);
        printf("Salário: %.2f\n\n", pessoas[i].salario);
    }

    // Ordenando por idade
    qsort(pessoas, n, sizeof(Pessoa), compara_idade);

    printf("\nApós a ordenação por idade:\n");
    for(int i = 0; i < n; i++) {
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Idade: %d\n", pessoas[i].idade);
        printf("Salário: %.2f\n\n", pessoas[i].salario);
    }

    // Ordenando por salário
    qsort(pessoas, n, sizeof(Pessoa), compara_salario);

    printf("\nApós a ordenação por salário:\n");
    for(int i = 0; i < n; i++) {
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Idade: %d\n", pessoas[i].idade);
        printf("Salário: %.2f\n\n", pessoas[i].salario);
    }

    return 0;
}