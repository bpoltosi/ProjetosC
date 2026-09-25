/* Crie um algoritmo para contar quantos espacos em branco existem em uma frase.
Depois o programa deve contar quantos caracteres sao diferentes do caractere espaco em uma frase. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main (void)
{

    char frase[100];
    printf("Digite uma frase: ");
    fgets(frase, 100, stdin);

    strlwr(frase);
    puts(frase);

    int quantosEspacos = 0;
    int quantosCaracteres = 0;
    char *p1 = frase;
    char *p2 = frase;

    int tam = (int) strlen(frase);
    if (tam > 0 && frase[tam-1] == '\n')
    {
        frase[tam-1] = '\0';
    }

    for(int i=0; i<tam; i++)
    {
        if(*p1 == ' ')
        {
            quantosEspacos++;
        }
        if(*p2 != ' ')
        {
            quantosCaracteres++;
        }
        p1++;
        p2++;
    }
    printf("\nEspacos em branco: %d", quantosEspacos);
    printf("\nCaracteres diferentes do caractere espaco: %d", quantosCaracteres-1);


    return 0;
}
