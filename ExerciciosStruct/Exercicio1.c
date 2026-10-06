/* Escreva um programa em C que:
1 Defina um registro Produto com os campos nome, preco e quantidade;
2 Leia os dados de dois produtos digitado pelo usuário;
3 Imprima os dados lidos e o valor total em estoque (preco * quantidade). */

#include <stdio.h>
#include <string.h>

typedef struct {
	char nome[50];
	float preco;
	int quantidade;
} Produto;


int main (void)
{

	Produto p[2];


	for (int i=0; i<2; i++)
	{
		// Limpa o buffer deixado pelo scanf anterior, se nao for a primeira interacao
		if (i > 0) {
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
		}
		// recebe os nomes
		printf("Informe o nome do Produto %d: ", (i+1));
		fgets(p[i].nome,50,stdin);

		// Remove o '\n' do final gerado pelo fgets
		int tam = strlen(p[i].nome);
		if (tam > 0 && p[i].nome[tam - 1] == '\n') {
			p[i].nome[tam - 1] = '\0';
		}

		// recebe os precos
		printf("Informe o preço do Produto %d: ", (i+1));
		scanf("%f", &p[i].preco);

		// recebe as quantidades
		printf("Informe a quantidade do Produto %d: ", (i+1));
		scanf("%i", &p[i].quantidade);
	}
	float valorEstoque = (p[0].preco * p[0].quantidade) + (p[1].preco * p[1].quantidade);

	// exibe os dados lidos corretamente com
	printf("\n--- Dados dos Produtos ---");
	printf("\nNome dos produtos: %s, %s", p[0].nome, p[1].nome);
	printf("\nPreço dos produtos: %.2f, %.2f", p[0].preco, p[1].preco);
	printf("\nQuantidade dos produtos: %i, %i", p[0].quantidade, p[1].quantidade);
	printf("\nValor total em estoque: %.2f", valorEstoque);

	return 0;
}
