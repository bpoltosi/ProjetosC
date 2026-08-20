/* Escreva um programa que leia uma matriz M x N de inteiros, calcule a sua
transposta (uma matriz N x M) e imprima o resultado.  */

#include <stdio.h>

int main()
{

	int n;
	int m;

	//leitura de N
	printf("Digite o valor de N: ");
	scanf("%d", &n);

	//leitura de M
	printf("Digite o valor de M: ");
	scanf("%d", &m);

	int matriz[n][m];
	int matrizTransposta[m][n];
	int simetrico = 1;

	//leitura da matriz
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			printf("Informe os valores da %d linha, coluna %d: ", (i+1), (j+1));
			scanf("%d", &matriz[i][j]);
		}
	}

	//calculo da Matriz Transposta
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			matrizTransposta[j][i] = matriz[i][j];
		}
	}

	//exibicao da Matriz Transposta
	printf("\n Matriz Transposta: \n");
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			printf("%d ", matrizTransposta[j][i]);
		}
		printf("\n");
	}
	return 0;
}
