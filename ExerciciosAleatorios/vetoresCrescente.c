/* Le N valores inteiros e os ordena em um vetor na ordem crescente.
A cada valor capturado, o programa encontra sua posição correta no vetor e ajusta os demais elementos. */
#include <stdio.h>

int main()
{
	int tamanho;

	printf("Informe o tamanho do vetor: ");
	scanf("%d", &tamanho);

	int V1[tamanho];
	int valor;

	for (int i = 0; i < tamanho; i++)
	{

		printf("Informe um valor: ");
		scanf("%d", &valor);

		int posicao = i;

		for (int n = i - 1; n >= 0; n--)
		{

			if (V1[n] > valor)
			{
				V1[n + 1] = V1[n];
				posicao = n;
			}

			if (valor < V1[n])
			{
				V1[n - 1] = V1[n];
			}
		}
		V1[posicao] = valor;
	}

	printf("\nVetor em ordem crescente:\n");

	for (int i = 0; i < tamanho; i++)
	{
		printf("%d, ", V1[i]);
	}

	return 0;
}
