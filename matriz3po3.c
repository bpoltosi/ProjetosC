/* Leia uma matriz 3x3 de números inteiros, usando dois laços aninhados;
2 Imprima a matriz em forma de grade, uma linha da matriz por linha de tela */

#include <stdio.h>

int main(void) {

	int matriz[3][3] = {0};

	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			printf("Informe os valores da %d linha, coluna %d: ", (i+1), (j+1));
			scanf("%d", &matriz[i][j]);
		}
	}
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			printf("%d, ", matriz[i][j]);
			printf("\n");
		}
	}
	return 0;
}

//nao terminei!
