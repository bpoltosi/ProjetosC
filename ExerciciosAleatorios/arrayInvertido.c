/* algoritmo le 8 números inputados via laço de repetição e, em seguida,
utiliza um segundo laço para exibir todos os elementos do vetor na ordem inversa à que foram digitados */

#include <stdio.h>

int main(void)
{

	int valores[8];
	int valoresInvertidos[8];

	for (int i = 0; i < 8; i++)
	{
		printf("Informe os valores inteiros: ");
		scanf("%d", &valores[i]);
	}

	for (int i = 0; i < 8; i++)
	{
		valoresInvertidos[i] = valores[8 - i];
	}

	printf("Sequencia inversa dos numeros informados:\n");

	for (int i = 1; i < 9; i++)
	{
		printf("%d, ", valoresInvertidos[i]);
	}
	return 0;
}
