/* Desenvolva um algoritmo para ler o nome, gênero e idade de 10 pessoas.
Em seguida, solicitar ao usuário que digite/selecione um gênero.
Exiba o nome e idade das pessoas que possuem o sexo procurado. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct
{
	char nome[50];
	char genero; // 'm' ou 'f'
	int idade;
} Pessoa;

int main(void)
{

	FILE *arquivo = fopen("pessoas.csv", "r");

	// verifica se o arquivo foi aberto com sucesso
	if (arquivo == NULL)
	{
		printf("Erro ao abrir o arquivo 'pessoas.csv'.\n");
		return 1;
	}

	int quantidadePessoas = 0;
	char linha[200];

	fgets(linha, sizeof(linha), arquivo); //	Pula o cabeçalho

	// Conta quantas pessoas existem
	while (fgets(linha, sizeof(linha), arquivo) != NULL)
	{
		quantidadePessoas++;
	}

	// verifica se o arquivo não esta vazio (apenas cabeçalho)
	if (quantidadePessoas == 0)
	{
		printf("Nenhuma pessoa encontrada no arquivo.\n");
		fclose(arquivo);
		return 0;
	}

	// 1. Aloca dinamicamente na HEAP
	Pessoa *pessoa = malloc(quantidadePessoas * sizeof(Pessoa));

	// 2. Verifica se o sistema operacional concedeu a memória
	if (pessoa == NULL)
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

	for (int i = 0; i < quantidadePessoas; i++)
	{
		fgets(linha, sizeof(linha), arquivo);

		sscanf(
			linha,
			"%49[^,],%c,%d",
			pessoa[i].nome,
			&pessoa[i].genero,
			&pessoa[i].idade);
	}

	char generoBusca = ' ';
	int generoValido = 0;
	char entradaBusca[50];

	while (!generoValido){

		// Usuario solicita genero da busca
		printf("Informe o genero que deseja buscar: ");
		scanf("%49s", entradaBusca);

        // Converte o que o usuário digitou para minúsculas
        for (int i = 0; entradaBusca[i]; i++) {
            entradaBusca[i] = tolower(entradaBusca[i]);
        }

        // Verifica qual genero o usuário digitou usando strcmp (comparando as strings)
        if (strcmp(entradaBusca, "m") == 0 || strcmp(entradaBusca, "masculino") == 0 || strcmp(entradaBusca, "homem") == 0)
        {
            generoBusca = 'm';
            generoValido = 1;
        }
        else if (strcmp(entradaBusca, "f") == 0 || strcmp(entradaBusca, "feminino") == 0 || strcmp(entradaBusca, "mulher") == 0)
        {
            generoBusca = 'f';
            generoValido = 1;
        }
        else
        {
            printf("\nGenero '%s' nao compreendido! Tente novamente.\n", entradaBusca);
        }
	}

	printf("\n---- Lista de Nomes correspondentes a busca: -----\n");
	int encontrados = 0;

	for(int i=0; i<quantidadePessoas; i++){
		if (pessoa[i].genero == generoBusca){
			printf("'%s' - %d anos\n", pessoa[i].nome, pessoa[i].idade);
			encontrados++;
		}
	}
	
	if (encontrados == 0) {
        printf("Nenhum registro encontrado para este genero.\n");
    }

	free(pessoa);
	fclose(arquivo);
	return 0;
}