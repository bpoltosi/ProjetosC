/* Escreva um programa que leia uma matriz quadrada N x N de inteiros e
calcule a soma dos elementos da diagonal principal e a soma dos elementos da
diagonal secundária. */

#include <stdio.h>

int main(void)
{

	int n = 0;
	int somaPrincipal = 0;

	printf("Informe o valor de 'n': ");
	scanf("%d", &n);

	while (n <= 0)
	{ // valida N
		printf("Valor inválido!\n");
		printf("Informe o valor de 'n' para Matriz NxN: ");
		scanf("%d", &n);
	}

	int matriz[n][n];

	for (int j = 0; j < n; j++)
	{ // recebe os valores
		for (int i = 0; i < n; i++)
		{
			printf("Informe os valores da %d linha, coluna %d: ", (i + 1), (j + 1));
			scanf("%d", &matriz[i][j]);
		}
	}

	// printa os valores
	// Diagonal principal: elementos onde o índice da linha é igual ao da coluna (i == j)
	for (int i = 0; i < n; i++)
	{
		somaPrincipal += matriz[i][i];
	}
	printf("Soma dos valores da diagonal principal: %d\n", somaPrincipal);
	return 0;
}
