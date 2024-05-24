#include <stdio.h>
#include <string.h>

enum {OK, Erro};

typedef struct{
    char nome[50];
    int idade;
    float salario;
} Funcionario;

void ClearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int adicionar(Funcionario lista[], int *pos){
    char nome[50];
    int idade;
    float salario;

    printf("Digite os dados do funcionário\n");
    
    printf("Nome: ");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("Idade: ");
    scanf("%d", &idade);
    ClearBuffer();

    printf("Salario: ");
    scanf("%f", &salario);
    ClearBuffer();

    strcpy(lista[*pos].nome, nome);
    lista[*pos].idade = idade;
    lista[*pos].salario = salario;

    *pos = *pos + 1;  

    printf("Funcionário adicionado!\n");

    return OK;
}

int listar(Funcionario lista[], int *pos){
    if (*pos == 0){
        printf("Nenhum funcionário cadastrado!\n");
        return Erro;
    }

    for(int i = 0; i < *pos; i++){
        printf("Nome: %s\n", lista[i].nome);
        printf("Idade: %d anos\n", lista[i].idade);
        printf("Salário: R$ %.2f\n\n", lista[i].salario);
        printf("\n");
    }
    printf("\n");
    
    return OK;
}

int proc_funcionario(Funcionario lista[], int *pos){
    if (*pos == 0){
        printf("Nenhum funcionário cadastrado!\n");
        return Erro;
    }

    char nome[50];
    printf("Digite o nome do funcionário a ser pesquisado: ");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    int verifi = 0;
    for (int i = 0; i < *pos; i++){
        if (strcmp(lista[i].nome, nome) == 0){
            printf("Nome: %s\n", lista[i].nome);
            printf("Idade: %d\n", lista[i].idade);
            printf("Salário: R$ %.2f\n", lista[i].salario);

            verifi = 1;
        }
    }
    if (verifi != 1){
        printf("Funcionario não encontrado.\n");
        return Erro;
    }

    return OK;
}

int carregar(Funcionario lista[], int *pos){
    FILE *f = fopen("ex6_save.bin", "rb");
    if (f == NULL){
        return Erro;
    }

    Funcionario func;

	int pos_load = 0;
    while (fread(&func, sizeof(Funcionario), 1, f) == 1) {
        lista[pos_load] = func;
        (pos_load)++;
    }
	*pos = pos_load;

    fclose(f);

    return OK;
}

int salvar(Funcionario lista[], int *pos){
    FILE *f = fopen("ex6_save.bin", "wb");
    if (f == NULL){
        printf("Erro ao salvar.\n");
        return Erro;
    }

    for (int i = 0; i < *pos; i++){
        
        if (fwrite(&lista[i], sizeof(Funcionario), 1, f) != 1) {
            fclose(f);
            printf("Erro ao salvar.\n");
            return Erro;
        }
    }

    fclose(f);

    printf("Funcionarios salvos.\n");

    return OK;
}

int main(){
    Funcionario lista[255];
    int pos;
    int erro = carregar(lista, &pos);
    if (erro != OK)
        pos = 0;

    int opcao;
    do{
        printf("1. Adicionar funcionário.\n");
        printf("2. Listar funcionários.\n");
        printf("3. Procurar funcionário.\n");
        printf("0. Sair.\n");

        printf("Digite a opção: ");
        scanf("%d", &opcao);
        ClearBuffer();

        switch (opcao) {
            case 1:
                adicionar(lista, &pos);
                break;
            case 2:
                listar(lista, &pos);
                break;
            case 3:
                proc_funcionario(lista, &pos);
                break;
            default:
                break;
        }
    } while (opcao != 0);
    salvar(lista, &pos);
    printf("Saindo...");
}