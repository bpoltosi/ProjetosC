/* codigo que exibe quantos/quais numeros dão resto "n1" quando divididos por "n2"
no intervalo "n3", validando requisitos (Exceto Negativos ainda) */

#include <stdio.h>

int main(void)
{

    int valorResto;
    int valorDivisor;
    int valorInicialIntervalo;
    int valorFinalIntervalo;
    int quantosNumerosAceitos = 0;

    printf("Qual o valor deseja encontrar para o resto da divisao? ");
    scanf("%d", &valorResto);

    printf("Qual o valor do divisor? ");
    scanf("%d", &valorDivisor);

    // Validar divisor diferente de 0
    while (valorDivisor == 0)
    {
        printf("Valor invalido para divisor! Tente novamente.\n");

        printf("Qual o valor do divisor? ");
        scanf("%d", &valorDivisor);
    }

    // Validar resto menor que divisor
    if (valorResto >= valorDivisor)
    {

        printf("Valor invalido para Divisor e Resto (Resto >= Divisor).\n");

        while (valorResto >= valorDivisor)
        {

            printf("Qual o valor deseja encontrar para o resto da divisao? ");
            scanf("%d", &valorResto);

            printf("Qual o valor do divisor? ");
            scanf("%d", &valorDivisor);

            // Validar divisor diferente de 0
            while (valorDivisor == 0)
            {
                printf("Valor invalido para divisor! Tente novamente.\n");

                printf("Qual o valor do divisor? ");
                scanf("%d", &valorDivisor);
            }
        }
    }

    printf("Qual o valor inicial do intervalo desejado? ");
    scanf("%d", &valorInicialIntervalo);

    printf("Qual o valor final do intervalo desejado? ");
    scanf("%d", &valorFinalIntervalo);

    // Validar valor inicial menor que valor final
    while (valorInicialIntervalo > valorFinalIntervalo)
    {

        printf("Valor Inicial do intervalo MAIOR que Valor Final do intervalo! Tente novamente.\n");

        printf("Qual o valor inicial do intervalo desejado? ");
        scanf("%d", &valorInicialIntervalo);

        printf("Qual o valor final do intervalo desejado? ");
        scanf("%d", &valorFinalIntervalo);
    }

    // Procurar numeros que possuem o resto desejado
    for (int i = valorInicialIntervalo; i <= valorFinalIntervalo; i++)
    {

        if (i % valorDivisor == valorResto)
        {

            quantosNumerosAceitos++;

            printf("%d\n", i);
        }
    }

    // Validar saida de 0 numeros
    if (quantosNumerosAceitos == 0)
    {

        printf("Nenhum numero atende aos requisitos.\n");
    }
    else
    {

        printf("Foram descobertos %d numeros que atendem aos requisitos!\n",
               quantosNumerosAceitos);
    }

    return 0;
}
