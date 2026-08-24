/* Escreva um programa que leia uma matriz M x N de inteiros, calcule a sua
transposta (uma matriz N x M) e imprima o resultado.  */

#include <stdio.h>

int main(){

int n;
int m;

printf("Digite o valor de N: ");			//leitura de N
	scanf("%d", &n);

printf("Digite o valor de M: ");			//leitura de M
	scanf("%d", &m);

int matriz[n][m];
int matrizTransposta[m][n];
int simetrico = 1;

	for(int i=0; i<n; i++) {					//leitura da matriz
		for(int j=0; j<m; j++) {
			printf("Informe os valores da %d linha, coluna %d: ", (i+1), (j+1));
			scanf("%d", &matriz[i][j]);
		}
	}

	for(int i=0; i<n; i++) {					//calculo da Matriz Transposta
		for(int j=0; j<m; j++) {
			matrizTransposta[j][i] = matriz[i][j];
		}
	}

printf("\n Matriz Transposta: \n");			//exibicao da Matriz Transposta
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			printf("%d ", matrizTransposta[j][i]);
		}
		printf("\n");
	}
return 0;
}
