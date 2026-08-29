/* Escreva um programa que declare uma matriz 3x3 de inteiros, leia os 9
valores digitados pelo usuário (usando dois laços aninhados) e, em seguida, imprima
a matriz em forma de grade (uma linha da matriz por linha de tela). */

#include <stdio.h>

int main(void)
{

	int matriz[3][3];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("Informe os valores da %d linha, coluna %d: ", (i + 1), (j + 1));
			scanf("%d", &matriz[i][j]);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d, ", matriz[i][j]);
		}
		printf("\n");
	}
	return 0;
}