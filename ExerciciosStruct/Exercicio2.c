/* Escreva um programa em C que:
1 Leia os dados (nome, matrícula e nota) de N alunos em um vetor de registros;
2 Calcule a média da turma;
3 Imprima o nome de todos os alunos com nota acima da média. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	char nome[50];
	int matricula;
	float nota1;
	float nota2;
} Aluno;

int main(void)
{
	FILE *arquivo = fopen("alunos.csv", "r");

	// verifica se o arquivo foi aberto com sucesso
	if (arquivo == NULL)
	{
		printf("Erro ao abrir o arquivo 'alunos.csv'.\n");
		return 1;
	}

	int quantidadeAlunos = 0;
	char linha[200];

	fgets(linha, sizeof(linha), arquivo); //	Pula o cabeçalho

	// Conta quantos alunos existem
	while (fgets(linha, sizeof(linha), arquivo) != NULL)
	{
		quantidadeAlunos++;
	}

	// verifica se o arquivo não esta vazio (apenas cabeçalho)
	if (quantidadeAlunos == 0)
	{
		printf("Nenhum aluno encontrado no arquivo.\n");
		fclose(arquivo);
		return 0;
	}

	// 1. Aloca dinamicamente na HEAP
	Aluno *aluno = malloc(quantidadeAlunos * sizeof(Aluno));

	// 2. Verifica se o sistema operacional concedeu a memória
	if (aluno == NULL)
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

	for (int i = 0; i < quantidadeAlunos; i++)
	{
		fgets(linha, sizeof(linha), arquivo);

		sscanf(
			linha,
			"%49[^,],%d,%f,%f",
			aluno[i].nome,
			&aluno[i].matricula,
			&aluno[i].nota1,
			&aluno[i].nota2);
	}

	float maiorMediaIndividual = (aluno[0].nota1 + aluno[0].nota2) / 2.0;
	char nomeMaiorMediaIndividual[50];
	strcpy(nomeMaiorMediaIndividual, aluno[0].nome);

	// Calcula Media da Turma
	float mediaTurma = 0;
	for (int i = 0; i < quantidadeAlunos; i++)
	{
		float mediaAluno = ((aluno[i].nota1 + aluno[i].nota2) / 2.0);
		mediaTurma += mediaAluno;

		// procura aluno com maior media individual
		if (mediaAluno > maiorMediaIndividual)
		{
			maiorMediaIndividual = mediaAluno;
			strcpy(nomeMaiorMediaIndividual, aluno[i].nome);
		}
	}
	mediaTurma = mediaTurma / quantidadeAlunos;

	// Exibição
	printf("Média geral da turma: %.2f\n", mediaTurma);
	printf("Nome do aluno com a Maior Média Individual: '%s' com %.2f pontos\n", nomeMaiorMediaIndividual, maiorMediaIndividual);
	printf("\nNome dos alunos acima da média geral, e suas notas:\n");
	for (int i = 0; i < quantidadeAlunos; i++)
	{
		float mediaAluno = (aluno[i].nota1 + aluno[i].nota2) / 2.0;

		if (mediaAluno > mediaTurma)
		{
			printf("'%s' - %.2f \n", aluno[i].nome, mediaAluno);
		}
	}

	fclose(arquivo);
	free(aluno);
	return 0;
}