/* Leia uma matriz nXn de números inteiros, calcule e imprima a soma de cada linha e a soma de cada coluna
Informe qual linha e qual coluna têm a maior soma.*/

#include <stdio.h>

int main(void) {

	int somaPrincipal = 0;
	int somaMaiorLinha = 0;
	int somaMaiorColuna = 0;
	int qualMaiorLinha;
	int qualMaiorColuna;

  //recebe o valor de 'n'
  printf("Informe o valor de 'n' para uma matriz quadrática: ");
  scanf("%d", &n);
  int matriz[n][n];
  
	//recebe os valores de Linha/Coluna
	int n;
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			printf("Informe os valores da %d linha, coluna %d: ", (i+1), (j+1));
			scanf("%d", &matriz[i][j]);
		}
	}
	*/

	//soma valores da linha
	for (int i = 0; i < 4; i++) {
		int soma_linha = 0;
		for (int j = 0; j < 4; j++) {
			soma_linha += matriz[i][j];
		}
		printf("Soma da linha %d: %d\n", (i+1), soma_linha);
		//verifica maior linha
		if (i == 0 || somaMaiorLinha < soma_linha) {
			somaMaiorLinha = soma_linha;
			qualMaiorLinha = i;
		}
	}

	//soma valores da coluna
	for (int j = 0; j < 4; j++) {
		int soma_coluna = 0;
		for (int i = 0; i < 4; i++) {
			soma_coluna += matriz[i][j];
		}
		printf("Soma da coluna %d: %d\n", (j+1), soma_coluna);
		//verifica maior coluna
		if (j == 0 || somaMaiorColuna < soma_coluna) {
			somaMaiorColuna = soma_coluna;
			qualMaiorColuna = j;
		}
	}
	printf("Maior linha: %d \n", (qualMaiorLinha+1));
	printf("Maior coluna: %d \n", (qualMaiorColuna+1));

	return 0;
}
