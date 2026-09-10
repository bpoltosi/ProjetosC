/* Crie um programa que leia duas strings (A e B) e mostre uma terceira string (C)
formada pelos caracteres contidos em A e B de forma intercalada.
Exemplo: Se A = “quarta” e B = “segunda”, a resposta obtida deverá ser “qsueagrutnada”. */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    // Recebe entrada da StringA
    char stringA[100];
    printf("Informe a primeira frase: ");
    fgets(stringA, 100, stdin);

    // Recebe entrada da StringB
    char stringB[100];
    printf("Informe a segunda frase: ");
    fgets(stringB, 100, stdin);

    // Tira o "espaco final"
    int tam1 = strlen(stringA);
    if (tam1 > 0 && stringA[tam1 - 1] == '\n')
    {
        stringA[tam1 - 1] = '\0';
        tam1--;
    }
    int tam2 = strlen(stringB);
    if (tam2 > 0 && stringB[tam2 - 1] == '\n')
    {
        stringB[tam2 - 1] = '\0';
        tam2--;
    }

    // Valida as entradas
    if (tam1 <= 0 || tam2 <= 0)
    {
        printf("Uma das frases esta vazia\n");
        return 0;
    }

    // Intercala Strings A e B para C
    char stringC[tam1 + tam2 + 1];
    char *pA = stringA;
    char *pB = stringB;
    char *pC = stringC;

    while (*pA != '\0' || *pB != '\0') // Enquanto ao menos uma das strings ainda tiver caracteres
    {
        if (*pA != '\0') // Se A ainda tem letras, copia para C e avança os ponteiros
        {
            *pC = *pA;
            pC++;
            pA++;
        }

        if (*pB != '\0') // Se B ainda tem letras, copia para C e avança os ponteiros
        {
            *pC = *pB;
            pC++;
            pB++;
        }
    }

    *pC = '\0'; // Adiciona o caractere de término da string C

    printf("\nResultado das strings intercaladas: %s\n", stringC);

    return 0;
}