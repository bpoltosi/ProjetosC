/* Escreva um programa de cadastro de alunos organizado em bibliotecas próprias:
1 Uma biblioteca aluno (aluno.h / aluno.c) com o typedef do registro Aluno e as funções carregar_alunos (lê de alunos.txt), salvar_alunos (grava no arquivo) e listar_alunos;
2 Na main, um menu que permita listar os alunos, cadastrar um novo aluno e mostrar a média da turma;
3 Ao sair, os dados devem ser gravados de volta em alunos.txt — na próxima execução, o cadastro deve continuar lá. */

#include <stdio.h>
#include "aluno.h"

int main(void) {
    Aluno alunos[MAX_ALUNOS];

    int total = carregar_alunos(alunos, MAX_ALUNOS);
    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Listar alunos\n");
        printf("2 - Cadastrar aluno\n");
        printf("3 - Mostrar media da turma\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida!\n");

            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            continue;
        }

        switch (opcao) {
            case 1:
                listar_alunos(alunos, total);
                break;

            case 2:
                if (cadastrar_aluno(alunos, &total, MAX_ALUNOS) == 0) {
                    printf("\nAluno cadastrado com sucesso!\n");
                } else {
                    printf("\nErro ao cadastrar aluno!\n");
                }
                break;

            case 3:
                mostrar_media_turma(alunos, total);
                break;

            case 4:
                salvar_alunos(alunos, total);
                printf("\nDados salvos com sucesso!\n");
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 4);

    return 0;
}
