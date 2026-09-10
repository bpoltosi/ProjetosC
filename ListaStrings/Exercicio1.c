/* Fazer um programa que leia uma string de caracteres maiúsculos e troque 
todos os caracteres por letras minúsculas. */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char palavra[100];

    // Recebe entrada da palavra
    printf("Informe uma palavra: ");
    fgets(palavra, 100, stdin);

    int tam = strlen(palavra);

    // Tira o espaco final
    if (tam > 0 && palavra[tam - 1] == '\n') {
        palavra[tam - 1] = '\0';
        tam--;
    }

    // Valida entrada
    if (tam <= 0) {
        printf("Nenhuma palavra informada.\n");
        return 0;
    }

    // Coloca em minusculas usando ponteiro
    char *p = palavra;
    while (*p != '\0') {
        *p = tolower(*p);
        p++;
    }

    // Exibe o resultado
    printf("Resultado: %s\n", palavra);

    return 0;
}
