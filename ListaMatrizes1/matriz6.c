/* Escreva um programa que leia uma matriz quadrada N x N e verifique se ela é
simétrica, ou seja, se matriz[i][j] é igual a matriz[j][i] para todo i e j. Imprima
"Simétrica" ou "Assimétrica". */

#include <stdio.h>

int main(){

int n;

printf("Digite o valor de N: ");		//leitura de N
	scanf("%d", &n);

int matriz[n][n];
int simetrico = 1;

	for(int i=0; i<n; i++) {				//leitura da matriz
		for(int j=0; j<n; j++) {
			printf("Informe os valores da %d linha, coluna %d: ", (i+1), (j+1));
			scanf("%d", &matriz[i][j]);
		}
	}

	for(int i=0; i<n; i++) {			// valida simetria
		for(int j=0; j<n; j++) {
			if(matriz[i][j] != matriz[j][i]) {
				simetrico = 0;
			}
		}
	}
	if (simetrico) {
		printf("Matriz Simetrica!");	// printa simetria

	} else {
		printf("Matriz Assimetrica!");	//printa assimetria
	}
return 0;
}
