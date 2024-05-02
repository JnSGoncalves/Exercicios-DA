#include <stdio.h>
#include <string.h>


int main(){
    char string[255];

    printf("Digite uma frase: ");
    fgets(string, 255, stdin);
    string[strcspn(string, "\n")] = '\0';

    int cont = 0;
    for(int i = 0; string[i] != '\0'; i++){
        if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u')
            cont++;
        if (string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U')
            cont++;
    }

    printf("Número de vogais digitadas: %d", cont);
}