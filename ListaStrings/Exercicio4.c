/* Crie um algoritmo para contar quantos espaços em branco existem em uma frase.
Depois o programa deve contar quantos caracteres são diferentes do caractere espaço em uma frase. */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    // Recebe entrada da frase
    char frase[100];
    printf("Informe uma frase: ");
    fgets(frase, 100, stdin);

    // Tira o "espaco final"
    int tam = strlen(frase);
    if (tam > 0 && frase[tam - 1] == '\n')
    {
        frase[tam - 1] = '\0';
        tam--;
    }

    // Valida entrada
    if (tam <= 0)
    {
        printf("Nenhuma frase informada.\n");
        return 0;
    }

    // Conta vazios -> espaços
    int contadorDeVazios = 0;
    char *ponteiroContadorVazios = frase;
    for (int i = 0; i < tam; i++)
    {
        if (*ponteiroContadorVazios == ' ')
        {
            contadorDeVazios++;
        }
        ponteiroContadorVazios++;
    }

    // Conta não vazios -> letras
    int contadorDeNaoVazios = 0;
    char *ponteiroContadorDeNaoVazios = frase;
    for (int i = 0; i < tam; i++)
    {
        if (*ponteiroContadorDeNaoVazios != ' ')
        {
            contadorDeNaoVazios++;
        }
        ponteiroContadorDeNaoVazios++;
    }

    printf("\nQuantas vezes os 'espaços em branco' foram encontrados: %i", contadorDeVazios);                       // Quantos espaços
    printf("\nQuantos caracteres diferentes do 'espaço em branco' foram encontrados: %i", contadorDeNaoVazios);     // Quantas letras

    return 0;
}