#include <stdio.h>
#include <string.h>
#include "aluno.h"

int carregar_alunos(Aluno alunos[], int max) {
    FILE *arquivo = fopen("alunos.txt", "r");

    if (arquivo == NULL)
        return 0;

    int total = 0;

    while (total < max) {
        if (fscanf(arquivo, "%d\n", &alunos[total].matricula) != 1)
            break;

        if (fgets(alunos[total].nome, MAX_NOME, arquivo) == NULL)
            break;

        alunos[total].nome[strcspn(alunos[total].nome, "\r\n")] = '\0';

        if (fscanf(arquivo, "%f\n", &alunos[total].nota) != 1)
            break;

        total++;
    }

    fclose(arquivo);
    return total;
}

void salvar_alunos(Aluno alunos[], int total) {
    FILE *arquivo = fopen("alunos.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao salvar os dados!\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        fprintf(arquivo, "%d\n%s\n%.2f\n",
                alunos[i].matricula,
                alunos[i].nome,
                alunos[i].nota);
    }

    fclose(arquivo);
}

void listar_alunos(Aluno alunos[], int total) {
    if (total == 0) {
        printf("\nNenhum aluno cadastrado.\n");
        return;
    }

    printf("\n--- Lista de Alunos ---\n");

    for (int i = 0; i < total; i++) {
        printf("Matricula: %d | Nome: %s | Nota: %.2f\n",
               alunos[i].matricula,
               alunos[i].nome,
               alunos[i].nota);
    }
}

int cadastrar_aluno(Aluno alunos[], int *total, int max) {
    if (*total >= max)
        return 1;

    printf("\n--- Cadastro de Aluno ---\n");

    printf("Digite a matricula: ");
    if (scanf("%d", &alunos[*total].matricula) != 1)
        return 1;

    getchar();

    printf("Digite o nome: ");
    if (fgets(alunos[*total].nome, MAX_NOME, stdin) == NULL)
        return 1;

    alunos[*total].nome[strcspn(alunos[*total].nome, "\r\n")] = '\0';

    printf("Digite a nota: ");
    if (scanf("%f", &alunos[*total].nota) != 1)
        return 1;

    (*total)++;

    return 0;
}

void mostrar_media_turma(Aluno alunos[], int total) {
    if (total == 0) {
        printf("\nNenhum aluno cadastrado.\n");
        return;
    }

    float soma = 0;

    for (int i = 0; i < total; i++) {
        soma += alunos[i].nota;
    }

    printf("\nMedia da turma: %.2f\n", soma / total);
}
