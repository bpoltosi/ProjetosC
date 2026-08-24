#include <stdio.h>

int main(void) {

    int n;
    int somaMaiorLinha = 0;
    int somaMaiorColuna = 0;
    int qualMaiorLinha;
    int qualMaiorColuna;

    printf("Informe o valor de 'n' para uma matriz quadratica: ");	// recebe o valor de 'n'
    scanf("%d", &n);

    int matriz[n][n];

    for (int i = 0; i < n; i++) {		// recebe os valores da matriz
        for (int j = 0; j < n; j++) {
            printf("Informe o valor da linha %d, coluna %d: ",
                   i + 1, j + 1);

            scanf("%d", &matriz[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {		// soma os valores de cada linha

        int soma_linha = 0;

        for (int j = 0; j < n; j++) {
            soma_linha += matriz[i][j];
        }

        printf("Soma da linha %d: %d\n", i + 1, soma_linha);
        
        if (i == 0 || somaMaiorLinha < soma_linha) {			// verifica maior linha
            somaMaiorLinha = soma_linha;
            qualMaiorLinha = i;
        }
    }

    for (int j = 0; j < n; j++) {			// soma os valores de cada coluna

        int soma_coluna = 0;

        for (int i = 0; i < n; i++) {
            soma_coluna += matriz[i][j];
        }

        printf("Soma da coluna %d: %d\n", j + 1, soma_coluna);

        if (j == 0 || somaMaiorColuna < soma_coluna) { 			// verifica maior coluna
            somaMaiorColuna = soma_coluna;
            qualMaiorColuna = j;
        }
    }

    printf("\nMaior linha: %d (soma = %d)\n", qualMaiorLinha + 1, somaMaiorLinha);
    printf("Maior coluna: %d (soma = %d)\n", qualMaiorColuna + 1, somaMaiorColuna);

return 0;
}