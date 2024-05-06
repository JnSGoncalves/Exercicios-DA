#include <stdio.h>
#include <string.h>
#define Total 255

typedef struct{
    char nome[Total];
    int quantidade;
    float preco;
} Produto;

void ClearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int add_prod(Produto produtos[], int *pos){
    printf("\nDigite o nome do produto: ");
    fgets(produtos[*pos].nome, Total, stdin);
    produtos[*pos].nome[strcspn(produtos[*pos].nome, "\n")] = '\0';

    printf("Digite o a quantidade em estoque: ");
    scanf("%d", &produtos[*pos].quantidade);

    ClearBuffer();

    printf("Digite o valor unitário do produto: ");
    scanf("%f", &produtos[*pos].preco);

    ClearBuffer();

    *pos = *pos + 1;

    printf("Produto Adicionado!\n");
}

int list_prod(Produto produtos[], int *pos){
    printf("\nLista de todos os produtos cadastrados:\n");

    for(int i = 0; i < *pos; i++){
        printf("\nNome: %s\n", produtos[i].nome);
        printf("Quantidade: %d\n", produtos[i].quantidade);
        printf("Preço: R$ %.2f\n", produtos[i].preco);
    }
}

int cont_val(Produto produtos[], int *pos){
    float valor_total = 0;
    
    for(int i = 0; i < *pos; i++){
        valor_total += produtos[i].quantidade * produtos[i].preco;
    }

    printf("Valor total de produtos em estoque: R$ %.2f\n\n", valor_total);
}

int main(){
    Produto produtos[Total];
    int pos = 0;
    int opcao;

    do{
        printf("\n1. Adicionar produto.\n");
        printf("2. Listar produtos.\n");
        printf("3. Verificar valor total dos produtos.\n");
        printf("0. Sair.\n\n");

        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);
        ClearBuffer();

        if(opcao == 1){
            add_prod(produtos, &pos);
        }else if(opcao == 2){
            list_prod(produtos, &pos);
        }else if(opcao == 3){
            cont_val(produtos, &pos);
        }
    }while(opcao != 0);

    printf("Saindo..");
}