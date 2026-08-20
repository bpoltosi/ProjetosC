/* Le uma matriz quadrada N x N e verifica se ela é simétrica (matriz[i][j] == matriz[j][i]) para todo i e j.
Imprime "Simétrica" ou "Assimétrica" para os resultados. */

#include <stdio.h>

int main()
{

	int n;

	//leitura de N
	printf("Digite o valor de N: ");
	scanf("%d", &n);

	int matriz[n][n];
	int simetrico = 1;

	//leitura da matriz
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			printf("Informe os valores da %d linha, coluna %d: ", (i+1), (j+1));
			scanf("%d", &matriz[i][j]);
		}
	}

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(matriz[i][j] != matriz[j][i]) {
				simetrico = 0;
			}
		}
	}
	if (simetrico) {
		printf("Matriz Simetrica!");

	} else {
		printf("Matriz Assimetrica!");
	}
	return 0;
}
