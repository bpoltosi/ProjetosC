/* Tenha uma função int eh_primo(int n), que retorna 1 se n for primo e 0 caso contrário
Na main, leia um número N e, usando a função, imprima todos os números primos de 1 até N */

#include <stdio.h>

int eh_primo(int n)
{
	// Dividir por 1 e por ele mesmo
	if (n <= 1)
	{
		return 0; // 1 e numeros menores nao sao primos
	}

	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			return 0; // se encontrou um divisor, logo nao é primo
		}
	}
	return 1; // se não encontrou divisores, é primo
}

int eh_par(int n)
{
	return n % 2 == 0; // 1 se for par, 0 se for impar
}

void mostra_primos(int n){

	// imprime os numeros primos de 1 até N
	printf("\nNúmeros primos de 1 até %d:\n", n);

	// laço para testar e imprimir todos os numeros
	for (int i = 1; i <= n; i++)
	{
		if (eh_primo(i))
		{
			printf("%d ", i);
		}
	}
	printf("\n");

	return;
}

int main(void)
{
	int n;

	// recebe o valor de N
	printf("Informe o valor desejado: ");
	scanf("%d", &n);

	// verifica Par ou Impar
	if (eh_par(n))
	{
		printf("\nÉ Par\n");
	}
	else
	{
		printf("\nÉ Impar\n");
	}

    // chama a função para imprimir os primos de 1 até N
    mostra_primos(n);

    return 0;
}