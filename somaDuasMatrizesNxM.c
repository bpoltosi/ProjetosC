/* Le duas matrizes N x M de inteiros e calcula a matriz soma, somando elemento a elemento.
Imprime a matriz resultante. */

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

	int matriz1[n][m];
	int matriz2[n][m];
	int matrizSoma[n][m];

	//leitura da Matriz 1
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			printf("Informe os valores da %d linha, coluna %d: ", (i+1), (j+1));
			scanf("%d", &matriz1[i][j]);
		}
	}

	//primeiro calculo da Matriz Soma
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			matrizSoma[i][j] = matriz1[i][j];
		}
	}

	//leitura da Matriz 2
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			printf("Informe os valores da %d linha, coluna %d: ", (i+1), (j+1));
			scanf("%d", &matriz2[i][j]);
		}
	}

	//segundo calculo da Matriz Soma
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			matrizSoma[i][j] += matriz2[i][j];
		}
	}

	//exibicao da Matriz Transposta
	printf("\n Matriz Soma: \n");
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			printf("%d ", matrizSoma[i][j]);
		}
		printf("\n");
	}
	return 0;
}
