/* 
Uma matriz de notas guarda, em cada linha, as notas de um aluno em várias avaliações (linha = aluno, coluna = avaliação).
Escreva um programa que:
a) Leia uma matriz de notas com A alunos e V avaliações (float);
b) Calcule e imprima a média de cada aluno (média da linha);
c) Ao final, informe quantos alunos foram aprovados (media >= 7.0) e quantos foram reprovados.
*/

#include <stdio.h>

int main (void) {

float notaAluno = 0;
int alunosAprovados = 0;
int alunosReprovados = 0;
float mediaAlunos;
float notas [100];
float somaNotas = 0;
int quantidadeAlunos = 0;

	while (notaAluno != -1) {
		printf("Digite a nota do Aluno: ");
		scanf("%f", &notaAluno);


		if (notaAluno == -1) {
			break;
		}

		notas[quantidadeAlunos] = notaAluno;
		quantidadeAlunos++;

		if (notaAluno >= 6)
		{
			printf("Aluno APROVADO!\n");
			alunosAprovados++;
		}
		else
		{
			printf("Aluno REPROVADO!\n");
			alunosReprovados++;
		}
	}

	for (int i = 0; i < quantidadeAlunos; i++) {
		somaNotas += notas[i];
	}

	if (quantidadeAlunos > 0) {
		mediaAlunos = somaNotas / quantidadeAlunos;
	} else {
		mediaAlunos = 0;
	}

printf("Quantidade de Alunos Aprovados: %d e Reprovados: %d", alunosAprovados, alunosReprovados);
printf("\nMedia dos Alunos: %.2f", mediaAlunos);

return 0;
}
