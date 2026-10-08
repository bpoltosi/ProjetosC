/* Uma loja de calçados possui um cadastro (csv) de até 1000 peças de reposição em seu estoque. - (use 30 para exemplo)
Para cada peça são armazenados os seguintes dados: código da peça; preço unitário; descrição da peça; e quantidade disponível em estoque.
Você deve elaborar um programa para:
a. Ler certa quantidade de peças para o cadastro. Considere que o código -999 encerra a entrada de dados;
b. Exibir uma listagem das peças que possuem menos de X unidades, onde X é uma quantidade fornecida pelo usuário. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int codigoPeca;
    float precoUnitario;
    char descricao[50];
    int quantidadeEstoque;
} Produto;

// Função void não retorna nada, apenas imprime os dados desejados na tela
void printaInformacoes(Produto p)
{
    printf("Codigo: %d | Descricao: %s | Preco: R$ %.2f | Estoque: %d\n", 
           p.codigoPeca, p.descricao, p.precoUnitario, p.quantidadeEstoque);
}

int main(void)
{
    FILE *arquivo = fopen("estoque.csv", "r");

    // Caso o arquivo não exista, vamos criá-lo automaticamente com o cabeçalho
    if (arquivo == NULL)
    {
        printf("Arquivo 'estoque.csv' nao encontrado. Criando um novo...\n");
        arquivo = fopen("estoque.csv", "w");
        fprintf(arquivo, "codigo,preco,descricao,quantidade\n");
        fclose(arquivo);
        
        // Reabre em modo leitura
        arquivo = fopen("estoque.csv", "r");
    }

    int quantidadePecas = 0;
    char linha[200];

    fgets(linha, sizeof(linha), arquivo); // Pula o cabeçalho

    // Conta quantas pecas existem
    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        quantidadePecas++;
    }

    // Inicializa o ponteiro como NULL
    Produto *produto = NULL;

    // Alocação dinâmica de memória na heap para o tamanho do estoque
    if (quantidadePecas > 0)
    {
        produto = (Produto *)malloc(quantidadePecas * sizeof(Produto));
        if (produto == NULL)
        {
            printf("Erro de alocacao de memoria.\n");
            fclose(arquivo);
            return 1;
        }
    }

    // ==================================
    //      Interpreta linhas do CSV
    // ==================================

    rewind(arquivo);                      // Volta para o início do arquivo
    fgets(linha, sizeof(linha), arquivo); // Pula novamente o cabeçalho

    for (int i = 0; i < quantidadePecas; i++)
    {
        fgets(linha, sizeof(linha), arquivo);

        sscanf(
            linha,
            "%d,%f,%49[^,],%d",
            &produto[i].codigoPeca,
            &produto[i].precoUnitario,
            produto[i].descricao,
            &produto[i].quantidadeEstoque);
    }
    fclose(arquivo); // Fechamos a leitura inicial para liberar o arquivo para possíveis gravações

    int opcaoSelecionada = 0;
    int numeroBuscado;
    int verificador = 0;

    do
    {
        printf("\n------ Menu de Opcoes: ------\n");
        printf("1) Inserir novas pecas\n");
        printf("2) Exibir listagem das pecas que possuem menos de X unidades\n");
        printf("3) Sair do programa\n");
        printf("-----------------------------\n");
        printf("Selecionar opcao: ");
        scanf("%d", &opcaoSelecionada);

        switch (opcaoSelecionada)
        {
        case 1:
            // Expande a memória dinamicamente para caber a nova peça
            produto = realloc(produto, (quantidadePecas + 1) * sizeof(Produto));
            if (produto == NULL)
            {
                printf("\nErro de alocacao de memoria ao cadastrar!\n");
                break;
            }

            printf("\nInforme o codigo da peca a ser cadastrada: ");
            scanf(" %d", &produto[quantidadePecas].codigoPeca);

            printf("Informe o preco unitario: ");
            scanf(" %f", &produto[quantidadePecas].precoUnitario);

            printf("Informe a descricao da peca: ");
            scanf(" %[^\n]", produto[quantidadePecas].descricao);

            printf("Informe a quantidade em estoque: ");
            scanf(" %d", &produto[quantidadePecas].quantidadeEstoque);

            // Abre o arquivo em modo append para adicionar no final
            FILE *arqAppend = fopen("estoque.csv", "a");
            if (arqAppend != NULL)
            {
                fprintf(arqAppend, "%d,%.2f,%s,%d\n",
                    produto[quantidadePecas].codigoPeca,
                    produto[quantidadePecas].precoUnitario,
                    produto[quantidadePecas].descricao,
                    produto[quantidadePecas].quantidadeEstoque);
                fclose(arqAppend);
            }
            else
            {
                printf("\nErro ao gravar no arquivo CSV!\n");
            }

            quantidadePecas++;
            printf("\nPeca cadastrada com sucesso!\n");
            break;

        case 2:
            printf("Informe o valor de X (quantidade minima): ");
            scanf("%d", &numeroBuscado);

            verificador = 0; // para sempre resetar a cada busca
            printf("\n---- Pecas com menos de %d unidades ----\n", numeroBuscado);

            for (int i = 0; i < quantidadePecas; i++)
            {
                if (produto[i].quantidadeEstoque < numeroBuscado)
                {
                    printaInformacoes(produto[i]);
                    verificador = 1;
                }
            }
            if (verificador == 0)
            {
                printf("Nenhuma peca encontrada abaixo dessa quantidade!\n");
            }
            break;

        case 3:
            printf("\nSaindo do programa...\n");
            break;

        default:
            printf("\nOpcao invalida! Tente novamente.\n");
            break;
        }

    } while (opcaoSelecionada != 3);

    // Libera a memória HEAP antes de encerrar o programa
    if (produto != NULL)
    {
        free(produto);
    }
    return 0;
}