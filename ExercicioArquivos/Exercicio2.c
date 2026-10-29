/* Escreva um programa em C que:
1) Leia o arquivo alunos.txt (nome e nota em cada linha) para um vetor de registros
2) Grave, em um novo arquivo aprovados.txt, apenas os alunos com nota maior ou igual a 6.0
3) Ao final, informe na tela quantos alunos foram aprovados e quantos reprovados */

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    float nota;
} Aluno;

int main (void)
{
    Aluno turma[30];
    int n = 0;
    int aprovados = 0, reprovados = 0;

    FILE *arquivo = fopen("alunos.txt","r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    while (n < 30 && fscanf(arquivo, "%49s %f", turma[n].nome, &turma[n].nota)== 2)
    {
        n++;
    }
    fclose(arquivo);

    FILE *arq_aprovados = fopen ("aprovados.txt","w");
    if (arq_aprovados == NULL)
    {
        printf("Erro ao criar o arquivo aprovados.txt!\n");
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (turma[i].nota >= 6)
        {
            fprintf(arq_aprovados, "%s %.2f\n", turma[i].nome, turma[i].nota);
            aprovados++;
        }
        else
        {
            reprovados++;
        }
    }
    fclose(arq_aprovados);

    printf("Total de alunos aprovados: %d\n", aprovados);
    printf("Total de alunos reprovados: %d\n", reprovados);

    return 0;
}
