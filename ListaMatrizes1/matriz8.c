/* Escreva um programa que leia duas matrizes M x N de inteiros e calcule a
matriz soma, somando elemento a elemento. Imprima a matriz resultado. */

#include <stdio.h>

int main(){

int n;
int m;

printf("Digite o valor de N: ");	//leitura de N
	scanf("%d", &n);

printf("Digite o valor de M: ");	//leitura de M
	scanf("%d", &m);

int matriz1[n][m];
int matriz2[n][m];
int matrizSoma[n][m];

	for(int i=0; i<n; i++) {			//leitura da Matriz 1
		for(int j=0; j<m; j++) {
			printf("Informe os valores da %d linha, coluna %d: ", (i+1), (j+1));
			scanf("%d", &matriz1[i][j]);
		}
	}

	for(int i=0; i<n; i++) {			//primeiro calculo da Matriz Soma
		for(int j=0; j<m; j++) {
			matrizSoma[i][j] = matriz1[i][j];
		}
	}

	for(int i=0; i<n; i++) {			//leitura da Matriz 2
		for(int j=0; j<m; j++) {
			printf("Informe os valores da %d linha, coluna %d: ", (i+1), (j+1));
			scanf("%d", &matriz2[i][j]);
		}
	}

	for(int i=0; i<n; i++) {			//segundo calculo da Matriz Soma
		for(int j=0; j<m; j++) {
			matrizSoma[i][j] += matriz2[i][j];
		}
	}

printf("\n Matriz Soma: \n");		//exibicao da Matriz Soma
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			printf("%d ", matrizSoma[i][j]);
		}
		printf("\n");
	}
return 0;
}
