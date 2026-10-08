/* Usando estas structs:
1) Data: dia, mês e ano.
2) Endereço: rua, número e cidade.
3) Aluno: nome, matrícula, data de nascimento (Data), endereço(Endereço) e 3 notas.
O programa deve ler os dados dos alunos e mostrar:
a ficha de cada um com sua média, se a media >= 7 exibir "Aprovado", se nao "Reprovado"
aluno com a maior nota e qual aluno é o mais velho e novo */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
	char nome[50];
	int matricula;
	float nota1, nota2, nota3, mediaNotas;
	Endereco endereco;
	Data dataNascimento;
} Aluno;

float calculaMedia(float x, float y, float z)
{
	return (x + y + z) / 3.0;
}

// Função para comparar datas de nascimento
// Retorna negativo se d1 nasceu ANTES de d2 (d1 é mais velho)
// Retorna positivo se d1 nasceu DEPOIS de d2 (d1 é mais novo)
int comparaDataNascimento(Data d1, Data d2)
{
	if (d1.ano != d2.ano)
		return d1.ano - d2.ano;
	if (d1.mes != d2.mes)
		return d1.mes - d2.mes;
	return d1.dia - d2.dia;
}

int main(void)
{
	FILE *arquivoAlunos = fopen("alunos.csv", "r");
	if (arquivoAlunos == NULL)
	{
		printf("Erro ao abrir alunos.csv\n");
		return 1;
	}

	int quantidadeAlunos = 0;
	char linha[200]; // Buffer temporário para ler a linha do cabeçalho

	fgets(linha, sizeof(linha), arquivoAlunos); // Pula o cabeçalho

	// Conta quantos alunos existem
	while (fgets(linha, sizeof(linha), arquivoAlunos) != NULL)
	{
		quantidadeAlunos++;
	}

	if (quantidadeAlunos == 0)
	{
		printf("Nenhum aluno encontrado.\n");
		fclose(arquivoAlunos);
		return 1;
	}

	// Alocação dinâmica de memória na heap para a quantidade de alunos
	Aluno *aluno = (Aluno *)malloc(quantidadeAlunos * sizeof(Aluno));
	if (aluno == NULL)
	{
		printf("Erro de alocacao de memoria.\n");
		fclose(arquivoAlunos);
		return 1;
	}

	rewind(arquivoAlunos);						// Volta para o início do arquivo
	fgets(linha, sizeof(linha), arquivoAlunos); // Pula novamente o cabeçalho

	// le arquivo alunos.csv
	for (int i = 0; i < quantidadeAlunos; i++)
	{
		fgets(linha, sizeof(linha), arquivoAlunos);

		// nome,matricula,dd-mm-aaaa,cidade,rua,numero
		sscanf(linha, "%49[^,],%d,%d-%d-%d,%49[^,],%49[^,],%d",
			   aluno[i].nome,
			   &aluno[i].matricula,
			   &aluno[i].dataNascimento.dia,
			   &aluno[i].dataNascimento.mes,
			   &aluno[i].dataNascimento.ano,
			   aluno[i].endereco.cidade,
			   aluno[i].endereco.rua,
			   &aluno[i].endereco.numero);

		// Inicializa notas com zero por segurança
		aluno[i].nota1 = aluno[i].nota2 = aluno[i].nota3 = aluno[i].mediaNotas = 0.0;
	}
	fclose(arquivoAlunos);

	// le notas e cruza pela matricula
	FILE *arquivoNotas = fopen("notas.csv", "r");
	if (arquivoNotas == NULL)
	{
		printf("Erro ao abrir notas.csv\n");
		free(aluno);
		return 1;
	}

	fgets(linha, sizeof(linha), arquivoNotas); // Pula cabeçalho de notas.csv
	while (fgets(linha, sizeof(linha), arquivoNotas) != NULL)
	{
		int matriculaBusca;
		float n1, n2, n3;

		// 		matricula,nota1,nota2,nota3
		sscanf(linha, "%d,%f,%f,%f", &matriculaBusca, &n1, &n2, &n3);

		// Procura o aluno com essa matrícula e insere as notas
		for (int i = 0; i < quantidadeAlunos; i++)
		{
			if (aluno[i].matricula == matriculaBusca)
			{
				aluno[i].nota1 = n1;
				aluno[i].nota2 = n2;
				aluno[i].nota3 = n3;
				aluno[i].mediaNotas = calculaMedia(n1, n2, n3);
				break;
			}
		}
	}
	fclose(arquivoNotas);

	// Exibição
	int indiceMaisVelho = 0;
	int indiceMaisNovo = 0;
	int indiceMaiorNota = 0;

	printf("\n------- FICHAS DOS ALUNOS -------\n");
	for (int i = 0; i < quantidadeAlunos; i++)
	{
		printf("Nome: %s | Matricula: %d\n", aluno[i].nome, aluno[i].matricula);
		printf("Media: %.2f -> Situacao: %s\n",
			   aluno[i].mediaNotas,
			   aluno[i].mediaNotas >= 7.0 ? "Aprovado" : "Reprovado");
		printf("---------------------------------\n");

		// verifica se é o mais velho (data de nascimento menor)
		if (comparaDataNascimento(aluno[i].dataNascimento, aluno[indiceMaisVelho].dataNascimento) < 0)
		{
			indiceMaisVelho = i;
		}
		// verifica se é o mais novo (data de nascimento maior)
		if (comparaDataNascimento(aluno[i].dataNascimento, aluno[indiceMaisNovo].dataNascimento) > 0)
		{
			indiceMaisNovo = i;
		}

		// verifica se a média atual é maior que a maior média registrada até agora
		if (aluno[i].mediaNotas > aluno[indiceMaiorNota].mediaNotas)
		{
			indiceMaiorNota = i;
		}
	}

	printf("\nAluno(a) com maior media: %s (Media: %.2f)\n",
		   aluno[indiceMaiorNota].nome,
		   aluno[indiceMaiorNota].mediaNotas);

	printf("\n------- RESULTADOS DE IDADE -------\n");
	printf("Aluno mais velho: %s (Nascido em %02d/%02d/%04d)\n",
		   aluno[indiceMaisVelho].nome,
		   aluno[indiceMaisVelho].dataNascimento.dia,
		   aluno[indiceMaisVelho].dataNascimento.mes,
		   aluno[indiceMaisVelho].dataNascimento.ano);

	printf("Aluno mais novo: %s (Nascido em %02d/%02d/%04d)\n\n",
		   aluno[indiceMaisNovo].nome,
		   aluno[indiceMaisNovo].dataNascimento.dia,
		   aluno[indiceMaisNovo].dataNascimento.mes,
		   aluno[indiceMaisNovo].dataNascimento.ano);

	// Libera a memória alocada
	free(aluno);

	return 0;
}