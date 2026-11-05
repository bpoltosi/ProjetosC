#ifndef ALUNO_H
#define ALUNO_H

#define MAX_ALUNOS 100
#define MAX_NOME 100

typedef struct {
    int matricula;
    char nome[MAX_NOME];
    float nota;
} Aluno;

int carregar_alunos(Aluno alunos[], int max);
void salvar_alunos(Aluno alunos[], int total);
void listar_alunos(Aluno alunos[], int total);
int cadastrar_aluno(Aluno alunos[], int *total, int max);
void mostrar_media_turma(Aluno alunos[], int total);

#endif
