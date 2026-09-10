/* Fazer um programa para ler uma string e um caractere.
Sempre que o caractere lido aparecer na frase, ele deverá ser substituído por asterisco. */

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

    // Recebe a escolha
    char escolhido;
    printf("Informe o caracter a ser encontrado e substituido: ");
    scanf("%c", &escolhido);

    // Encontra e Substitui
    char *p = frase;
    for (int i = 0; i < tam; i++)
    {
        if (tolower(*p) == tolower(escolhido))
        {
            *p = '*';
        }
        p++;
    }

    printf("\nResultado da frase substituida: %s", frase);

    return 0;
}