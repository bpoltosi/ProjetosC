/* Modele um pedido de compra usando as structs:
Data, Endereco, Produto, ItemPedido (que contém um Produto)
Cliente (que contém um CPF e Endereco)
Pedido (que contém Cliente, Data e um vetor de ItemPedido)

cliente (ler de clientes.csv) - cpf,endereco (supondo que ele esta "identificado", mas vamos criar alguns cliente fixos e usar a funcao rand() para aleatorizar o uso desses clientes para compras)
produto (ler de 'produtos.csv') - codigo,nome,preco
escrever em 'pedidos.csv' - cpf,endereco,codigoDosProdutoComprados (podem ser varios produtos) * quantidade [usar a funcao rand() para aleatorizar o uso desses produtos para pedidos]

O programa deve:
Calcular o subtotal e aplicar 10% de desconto se ele passar de R$500,00;
Imprimir um cupom fiscal. (data da compra / nome do produto(s) -  quantidade * valor = preco(s) [sem e com o desconto] / cpf do cliente / endereço entrega) 

Obs: tive que usar IA pra parte de escrita dos pedidos ;(
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
	int dia, mes, ano;
} Data;

typedef struct
{
	char cidade[50], rua[50];
	int numero;
} Endereco;

typedef struct
{
	int codigo;
	char nome[50];
	float preco;
} Produto;

typedef struct
{
	Produto produto;
	int quantidade;
} ItemPedido;

typedef struct
{
	int cpf;
	Endereco endereco;
} Cliente;

typedef struct
{
	Cliente id;
	Data dataPedido;
	ItemPedido itens[20];
	int qtdDiferentesItens;
} Pedido;

// Função para calcular o preço já aplicando a regra de desconto
float calculaPrecoTotal(Pedido p)
{
	float total = 0.0;
	for (int i = 0; i < p.qtdDiferentesItens; i++)
	{
		total += p.itens[i].produto.preco * p.itens[i].quantidade;
	}

	if (total > 500.0)
	{
		total = total * 0.90; // Aplica 10% de desconto
	}

	return total;
}

int main(void)
{
	Cliente clientes[15];
	int qtdClientes = 0;

	Produto produtos[20];
	int qtdProdutos = 0;
	char cabecalho[200]; // Buffer temporário para ler a linha do cabeçalho

	// le o arquivo clientes
	FILE *fc = fopen("clientes.csv", "r");
	if (fc)
	{
		fgets(cabecalho, sizeof(cabecalho), fc); // Pula o cabeçalho

		while (fscanf(fc, "%d,%[^,],%[^,],%d\n",
					  &clientes[qtdClientes].cpf,
					  clientes[qtdClientes].endereco.cidade,
					  clientes[qtdClientes].endereco.rua,
					  &clientes[qtdClientes].endereco.numero) != EOF)
		{
			qtdClientes++;
		}
		fclose(fc);
	}

	// le o arquivo produtos
	FILE *fp = fopen("produtos.csv", "r");
	if (fp)
	{
		fgets(cabecalho, sizeof(cabecalho), fp); // Pula o cabeçalho

		while (fscanf(fp, "%d,%[^,],%f\n",
					  &produtos[qtdProdutos].codigo,
					  produtos[qtdProdutos].nome,
					  &produtos[qtdProdutos].preco) != EOF)
		{
			qtdProdutos++;
		}
		fclose(fp);
	}

	if (qtdClientes == 0){
		printf("Erro: Não foi possível carregar os dados dos arquivos CSV (ou o arquivo 'clientes.csv' nao tem clientes).\n");
		return 1;

	if (qtdProdutos == 0)
	{
		printf("Erro: Não foi possível carregar os dados dos arquivos CSV (ou o arquivo nao tem produtos).\n");
		return 1;
	}

	// usa rand() para sortera cliente e produtos
	srand(time(NULL));

	Pedido pedido;
	pedido.id = clientes[rand() % qtdClientes];

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	pedido.dataPedido.dia = tm.tm_mday;
	pedido.dataPedido.mes = tm.tm_mon + 1;
	pedido.dataPedido.ano = tm.tm_year + 1900;

	pedido.qtdDiferentesItens = (rand() % 4) + 1; // gera aleatoriamente
	for (int i = 0; i < pedido.qtdDiferentesItens; i++)
	{
		pedido.itens[i].produto = produtos[rand() % qtdProdutos];
		pedido.itens[i].quantidade = (rand() % 3) + 1;
	}

	// calcula o total e imprime o cupom fisal
	float subTotal = 0.0;
	printf("\n=================== CUPOM FISCAL ===================\n");
	printf("DATA DA COMPRA: %02d/%02d/%04d\n", pedido.dataPedido.dia, pedido.dataPedido.mes, pedido.dataPedido.ano);
	printf("CLIENTE (CPF): %d\n", pedido.id.cpf);
	printf("ENDERECO DE ENTREGA: %s, %s, %d\n", pedido.id.endereco.cidade, pedido.id.endereco.rua, pedido.id.endereco.numero);
	printf("----------------------------------------------------\n");
	printf("ITENS DO PEDIDO:\n");

	for (int i = 0; i < pedido.qtdDiferentesItens; i++)
	{
		float valorItem = pedido.itens[i].produto.preco * pedido.itens[i].quantidade;
		subTotal += valorItem;
		printf("- %s | Qtd: %d x R$ %.2f = R$ %.2f\n",
			   pedido.itens[i].produto.nome,
			   pedido.itens[i].quantidade,
			   pedido.itens[i].produto.preco,
			   valorItem);
	}
	float totalComDesconto = calculaPrecoTotal(pedido);
	printf("----------------------------------------------------\n");
	printf("SUBTOTAL: R$ %.2f\n", subTotal);
	if (subTotal > 500.0)
	{
		printf("DESCONTO (10%%): R$ -%.2f\n", subTotal * 0.10);
	}
	printf("TOTAL A PAGAR: R$ %.2f\n", totalComDesconto);
	printf("====================================================\n\n");

	// Tenta abrir o arquivo como leitura ("r") para ver se ele existe e verificar o tamanho
	int precisaCabecalho = 0;
	FILE *fped_check = fopen("pedidos.csv", "r");
	if (fped_check == NULL)
	{
		// O arquivo não existe ainda
		precisaCabecalho = 1;
	}
	else
	{
		// O arquivo existe. Movemos o cursor para o final e checamos o tamanho
		fseek(fped_check, 0, SEEK_END);
		if (ftell(fped_check) == 0)
		{
			precisaCabecalho = 1; // O arquivo existe, mas está vazio
		}
		fclose(fped_check); // Fecha o modo de leitura
	}

	// Agora abre em modo de adição para gravar
	FILE *fped = fopen("pedidos.csv", "a");
	if (fped)
	{

		// Escreve o cabeçalho se a verificação anterior sinalizou que é necessário
		if (precisaCabecalho)
		{
			fprintf(fped, "CPF,Endereco_Entrega,Itens(Cod*Qtd|...)\n");
		}

		// Escreve os dados do pedido (CPF, Endereço...)
		fprintf(fped, "%d,%s-%s-%d,",
				pedido.id.cpf,
				pedido.id.endereco.cidade,
				pedido.id.endereco.rua,
				pedido.id.endereco.numero);

		// Escreve a lista de itens
		for (int i = 0; i < pedido.qtdDiferentesItens; i++)
		{
			fprintf(fped, "%d*%d", pedido.itens[i].produto.codigo, pedido.itens[i].quantidade);
			if (i < pedido.qtdDiferentesItens - 1)
			{
				fprintf(fped, "|"); // Separa os itens com |
			}
		}
		fprintf(fped, "\n"); // Pula linha para o próximo pedido
		fclose(fped);
		printf(">>> Pedido registrado com sucesso em 'pedidos.csv'.\n");
	}
	else
	{
		printf("Erro ao gravar 'pedidos.csv'.\n");
	}
	return 0;
}