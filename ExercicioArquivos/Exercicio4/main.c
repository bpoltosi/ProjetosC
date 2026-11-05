
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
