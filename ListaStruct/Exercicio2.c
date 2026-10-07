/* Faça um algoritmo para realizar cadastro e consulta de informações sobre automóveis usados na concessionária FastCar,
onde é apresentado o seguinte menu:
1. Cadastrar automóvel -> cadastra a placa, modelo, fabricante, cor, ano de fabricação e preço (escreve no .csv)
2. Consultar automóvel -> usuário informa uma placa e o algoritmo deve exibir as informações sobre o veículo
(Caso não encontre, deve exibir uma mensagem informando isso)
3. Gerar relatório -> relatório contendo todos os dados dos automóveis cadastrados
4. Sair do programa
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	char placa[8];
	char modelo[30];
	char fabricante[30];
	char cor[30];
	int anoFabricacao;
	float preco;
} Carro;

int main(void)
{
	FILE *arquivo = fopen("automoveis.csv", "r");

	// verifica se o arquivo foi aberto com sucesso
	if (arquivo == NULL)
	{
		printf("Erro ao abrir o arquivo 'automoveis.csv'.\n");
		return 1;
	}

	int quantidadeCarros = 0;
	char linha[200];

	fgets(linha, sizeof(linha), arquivo); //	Pula o cabeçalho

	// Conta quantos carros existem
	while (fgets(linha, sizeof(linha), arquivo) != NULL)
	{
		quantidadeCarros++;
	}

	// verifica se o arquivo não esta vazio (apenas cabeçalho)
	if (quantidadeCarros == 0)
	{
		printf("Nenhum carro encontrado no arquivo.\n");
		fclose(arquivo);
		return 0;
	}

	// 1. Aloca dinamicamente na HEAP
	if (quantidadeCarros > 0)
	{
		Carro *carro = malloc(quantidadeCarros * sizeof(Carro));

		// 2. Verifica se o sistema operacional concedeu a memória
		if (carro == NULL)
		{
			printf("Erro: Memoria insuficiente!\n");
			fclose(arquivo);
			return 1;
		}

		// ==================================
		// 		Interpreta linhas do CSV
		// ==================================

		rewind(arquivo);					  //	Volta para o início do arquivo
		fgets(linha, sizeof(linha), arquivo); //	Pula novamente o cabeçalho

		for (int i = 0; i < quantidadeCarros; i++)
		{
			fgets(linha, sizeof(linha), arquivo);

			sscanf(
				linha,
				"%7[^,],%29[^,],%29[^,],%29[^,],%d,%f",
				carro[i].placa,
				carro[i].modelo,
				carro[i].fabricante,
				carro[i].cor,
				&carro[i].anoFabricacao,
				&carro[i].preco);
		}
	}
	fclose(arquivo); // Fechamos a leitura inicial para liberar o arquivo para possíveis gravações (Case 1)

	int opcaoSelecionada = 0;
	char placaBuscada[30];
	int verificador = 0;

	do
	{
		printf("------ Menu de Opções: ------\n");
		printf("1) cadastrar automóvel\n");
		printf("2) consultar automóvel\n");
		printf("3) gerar relatório do estoque\n");
		printf("4) sair do programa\n");
		printf("-----------------------------\n");
		printf("Selecionar opção: ");
		scanf("%d", &opcaoSelecionada);

		switch (opcaoSelecionada)
		{
		case 1:

			// Expande a memória dinamicamente para caber o novo carro
			carro = realloc(carro, (quantidadeCarros + 1) * sizeof(Carro));
			if (carro == NULL)
			{
				printf("\nErro de alocação de memória ao cadastrar!\n");
				break;
			}

			printf("\nInforme a placa a ser cadastrada: ");
			scanf(" %7s", carro[quantidadeCarros].placa);

			// %[^\n] permite ler nomes compostos com espaços em branco
			printf("Informe o modelo: ");
			scanf(" %[^\n]", carro[quantidadeCarros].modelo);

			printf("Informe o fabricante: ");
			scanf(" %[^\n]", carro[quantidadeCarros].fabricante);

			printf("Informe a cor: ");
			scanf(" %[^\n]", carro[quantidadeCarros].cor);

			printf("Informe o ano de fabricação: ");
			scanf("%d", &carro[quantidadeCarros].anoFabricacao);

			printf("Informe o preço: ");
			scanf("%f", &carro[quantidadeCarros].preco);

			// Abre o arquivo em modo append para adicionar no final
			FILE *arqAppend = fopen("automoveis.csv", "a");
			if (arqAppend != NULL)
			{
				fprintf(arqAppend, "%s,%s,%s,%s,%d,%.2f\n",
						carro[quantidadeCarros].placa,
						carro[quantidadeCarros].modelo,
						carro[quantidadeCarros].fabricante,
						carro[quantidadeCarros].cor,
						carro[quantidadeCarros].anoFabricacao,
						carro[quantidadeCarros].preco);
				fclose(arqAppend);
			}
			else
			{
				printf("\nErro ao gravar no arquivo CSV!\n");
			}

			quantidadeCarros++;
			printf("\nVeiculo cadastrado com sucesso!\n");
			break;

		case 2:
			verificador = 0; // para sempre resetar a cada busca
			printf("\nInforme a placa do carro que deseja buscar: ");
			scanf("%s", &placaBuscada); // valida os 7 digitos(StrUpperCase), depois ve se existe

			for (int i = 0; i < quantidadeCarros; i++)
			{
				if (strcmp(placaBuscada, carro[i].placa) == 0)
				{
					printf("\n---- Veiculo Encontrado! ----\n");
					printf("Modelo: %s\n", carro[i].modelo);
					printf("Fabricante: %s\n", carro[i].fabricante);
					printf("Cor: %s\n", carro[i].cor);
					printf("Ano de Fabricação: %d\n", carro[i].anoFabricacao);
					printf("Preço: %.2f\n", carro[i].preco);
					verificador = 1;
					break;
				}
			}
			if (verificador == 0)
			{
				printf("\nCarro não encontrado!\n");
			}

			break;

		case 3:
			printf("---- Relatorio dos Carros em Estoque: ----\n");
			for (int i = 0; i < quantidadeCarros; i++)
			{
				printf("Placa: %s\n", carro[i].placa);
				printf("Modelo: %s\n", carro[i].modelo);
				printf("Fabricante: %s\n", carro[i].fabricante);
				printf("Cor: %s\n", carro[i].cor);
				printf("Ano de Fabricação: %d\n", carro[i].anoFabricacao);
				printf("Preço: %.2f\n", carro[i].preco);
				printf("--------------------\n");
			}
			break;

		case 4:
			printf("\nSaindo do programa...\n");
			break;

		default:
			printf("\nOpção inválida! Tente novamente.\n");
			break;
		}

	} while (opcaoSelecionada != 4);

	// Libera a memória HEAP antes de encerrar o programa
	if (carro != NULL)
	{
		free(carro);
	}
	return 0;
}