/* calculo de valor do fatorial de 'n', validando entrada de negativos */

#include <stdio.h>

int main(void) {
    int valorN;
    int valorTotalFatorial = 1;

    printf("Digite o valor de 'n': ");
    scanf("%d", &valorN);

    if (valorN < 0) {
        printf("Nao existe fatorial de numero negativo.");
    }
    else {
        if (valorN > 1) {
            do {
                valorTotalFatorial *= valorN;
                valorN--;
            } while (valorN != 1);
        }

        printf("Valor do fatorial: %d", valorTotalFatorial);
    }

    return 0;
}
