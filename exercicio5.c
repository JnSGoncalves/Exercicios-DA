#include <stdio.h>
#include <string.h>
#include <ctype.h>

char ret_maiuscula(char *string){
    char *ptr = string;

    while (*ptr != '\0') {
        *ptr = toupper(*ptr);
        ptr++;
    }
}

int main(){
    char string[255];

    printf("Digite uma frase: ");
    fgets(string, 255, stdin);

    ret_maiuscula(string);
    printf("%s", string);
}