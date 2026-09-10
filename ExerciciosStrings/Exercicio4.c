/* Leia uma string (com fgets);
Usando apenas um ponteiro (sem colchetes e sem strlen), calcule e imprima o seu tamanho;
Percorra a string novamente, também por ponteiro, e conte quantas vogais ela possui */

#include <stdio.h>
#include <ctype.h>

int main()
{
    char frase[99];
    int quantasVogais = 0;
    int tamanhoFrase = 0;
    char vogais[] = {'a', 'e', 'i', 'o', 'u'};

    printf("Informe uma frase: ");
    fgets(frase, 99, stdin);

    char *p = frase;

    while (*p != '\0' && *p != '\n') {      // Calcula o tamanho da frase
        tamanhoFrase++;
        p++;
    }

    p = frase;  // "Reseta" o ponteiro

    while (*p != '\0' && *p != '\n') {
        char atual = tolower(*p);           // Converte para minusculas
        for (int j = 0; j < 5; j++) {
            if (atual == vogais[j]) {
                quantasVogais++;            // Conta vogais
            }
        }
        p++;
    }

    printf("Tamanho da frase: %i caracteres\n", tamanhoFrase);
    printf("Quantas Vogais: %i\n", quantasVogais);

    return 0;
}
