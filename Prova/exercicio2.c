/* Faca um programa que le uma matriz NxN, e apos extrai uma submatriz MxM
da matriz original. E ao final, mostre as duas matrizes para comparacao. Repare que
para ser possivel, M deve ser menor que N, e o programa deve validar isso. */

#include <stdio.h>

int main(void)
{

    int n;
    printf("Informe o valor de N: ");
    scanf("%d", &n);

    while(n<=0)
    {
        printf( "Valor invalido para N!");
        printf ("\nInforme novamente o valor de N: ");
        scanf("%d", &n);
    }

    int matriz[n][n];
    printf("\nInforme os %d elementos da Matriz Original: ", (n*n));
    for(int i=0; i<n; i++)
    {
        printf("\nLinha %d: ", i+1);
        for(int j=0; j<n; j++)
        {
            scanf("%d,", &matriz[i][j]);
        }
    }

    int m=1;
    printf("Informe o valor de M: ");
    scanf("%d", &m);

    while(m<=0 || m<0 || m>n || m==n)
    {
        printf("\nValor invalido para M!");
        printf("\nInforme novamente o valor de M: ");
        scanf("%d", &m);
    }

    int subMatriz[m][m];

    for (int i=0; i<m; i++)
    {
        for(int j=0; j<m; j++)
        {
            subMatriz[i][j] = matriz[i][j];
        }
    }

    printf("\nMatriz Original: ");
    for(int j=0; j<n; j++)
    {
        printf("\nLinha %d: ", j+1);
        for(int i=0; i<n; i++)
        {
            printf("%d, ", matriz[i][j]);
        }
    }

    printf("\n\nSubmatriz: ");
    for(int j=0; j<m; j++)
    {
        printf("\nLinha %d: ", j+1);
        for(int i=0; i<m; i++)
        {
            printf("%d, ", subMatriz[i][j]);
        }
    }

    return 0;
}
