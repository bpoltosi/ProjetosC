/*
 * Trabalho Bingo - Linguagem de Programacao
 * Compilacao: gcc -std=c11 -Wall -Wextra -Wpedantic -O2 TrabalhoBingo.c -o bingo
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM_CARTELA 15
#define MAX_NUMERO 60
#define MAX_NOME 50
#define MAX_JOGADORES 100

typedef struct {
    int numeros[TAM_CARTELA];
    unsigned char marcados[TAM_CARTELA];
} Cartela;

typedef struct {
    int id;
    char nome[MAX_NOME];
    Cartela cartela;
    int venceu;
    int rodada_vitoria;
} Jogador;

static void descartar_linha(void);
static int ler_inteiro_intervalo(const char *mensagem, int minimo, int maximo);
static void limpar_tela(void);
static Cartela gerar_cartela(void);
static void cadastrar_jogadores(Jogador jogadores[], int quantidade);
static void exibir_cartela(const Cartela *cartela);
static int sortear_numero(int sorteados[], int quantidade);
static void marcar_numero(Jogador jogadores[], int quantidade, int numero);
static int cartela_completa(const Cartela *cartela);
static int registrar_vitorias(Jogador jogadores[], int quantidade, int rodada);
static void exibir_resultado_final(const Jogador jogadores[], int quantidade,
                                   int total_vencedores);
static int processar_rodada(Jogador jogadores[], int quantidade,
                            int sorteados[], int *total_sorteados,
                            int *rodada, int *total_vencedores);
static void pular_ate_proximo_ganhador(Jogador jogadores[], int quantidade,
                                       int sorteados[], int *total_sorteados,
                                       int *rodada, int *total_vencedores);
static void executar_partida(Jogador jogadores[], int quantidade);

static void descartar_linha(void)
{
    int caractere;
    while ((caractere = getchar()) != '\n' && caractere != EOF) {
    }
}

static int ler_inteiro_intervalo(const char *mensagem, int minimo, int maximo)
{
    char linha[128];
    char *fim;
    long valor;

    for (;;) {
        printf("%s", mensagem);
        if (fgets(linha, sizeof linha, stdin) == NULL) {
            puts("\nEntrada encerrada.");
            exit(EXIT_SUCCESS);
        }

        valor = strtol(linha, &fim, 10);
        while (isspace((unsigned char)*fim)) {
            fim++;
        }

        if (fim != linha && *fim == '\0' && valor >= minimo && valor <= maximo) {
            return (int)valor;
        }
        printf("Digite um numero entre %d e %d.\n", minimo, maximo);
    }
}

static void limpar_tela(void)
{
    /* Sequencia ANSI: funciona nos terminais modernos e evita comandos do sistema. */
    printf("\033[2J\033[H");
}

static Cartela gerar_cartela(void)
{
    Cartela cartela = {{0}, {0}};
    int usados[MAX_NUMERO + 1] = {0};
    int i;

    for (i = 0; i < TAM_CARTELA; i++) {
        int numero;
        do {
            numero = rand() % MAX_NUMERO + 1;
        } while (usados[numero]);

        usados[numero] = 1;
        cartela.numeros[i] = numero;
    }
    return cartela;
}

static void cadastrar_jogadores(Jogador jogadores[], int quantidade)
{
    int i, j;

    for (i = 0; i < quantidade; i++) {
        char nome[MAX_NOME];
        printf("Nome do jogador %d: ", i + 1);
        if (fgets(nome, sizeof nome, stdin) == NULL) {
            strcpy(nome, "Jogador");
        } else {
            size_t tamanho = strcspn(nome, "\r\n");
            nome[tamanho] = '\0';
            if (tamanho == sizeof nome - 1) {
                descartar_linha();
            }
        }

        if (nome[0] == '\0') {
            snprintf(nome, sizeof nome, "Jogador %d", i + 1);
        }

        snprintf(jogadores[i].nome, sizeof jogadores[i].nome, "%s", nome);
        for (j = 0; j < i; j++) {
            if (strcmp(jogadores[i].nome, jogadores[j].nome) == 0) {
                snprintf(jogadores[i].nome, sizeof jogadores[i].nome,
                         "%s (%d)", nome, i + 1);
                break;
            }
        }

        jogadores[i].id = i + 1;
        jogadores[i].cartela = gerar_cartela();
        jogadores[i].venceu = 0;
        jogadores[i].rodada_vitoria = 0;
    }
}

static void exibir_cartela(const Cartela *cartela)
{
    int linha, coluna;

    for (linha = 0; linha < 3; linha++) {
        printf("  ");
        for (coluna = 0; coluna < 5; coluna++) {
            int indice = linha * 5 + coluna;
            if (cartela->marcados[indice]) {
                printf("[%02d] ", cartela->numeros[indice]);
            } else {
                printf(" %02d  ", cartela->numeros[indice]);
            }
        }
        putchar('\n');
    }
}

static int sortear_numero(int sorteados[], int quantidade)
{
    int disponiveis[MAX_NUMERO];
    int total = 0;
    int numero, i;

    for (numero = 1; numero <= MAX_NUMERO; numero++) {
        int ja_sorteado = 0;
        for (i = 0; i < quantidade; i++) {
            if (sorteados[i] == numero) {
                ja_sorteado = 1;
                break;
            }
        }
        if (!ja_sorteado) {
            disponiveis[total++] = numero;
        }
    }

    if (total == 0) {
        return 0;
    }
    return disponiveis[rand() % total];
}

static void marcar_numero(Jogador jogadores[], int quantidade, int numero)
{
    int i, j;

    for (i = 0; i < quantidade; i++) {
        if (jogadores[i].venceu) {
            continue;
        }
        for (j = 0; j < TAM_CARTELA; j++) {
            if (jogadores[i].cartela.numeros[j] == numero) {
                jogadores[i].cartela.marcados[j] = 1;
                break;
            }
        }
    }
}

static int cartela_completa(const Cartela *cartela)
{
    int i;
    for (i = 0; i < TAM_CARTELA; i++) {
        if (!cartela->marcados[i]) {
            return 0;
        }
    }
    return 1;
}

static int registrar_vitorias(Jogador jogadores[], int quantidade, int rodada)
{
    int i, novas_vitorias = 0;

    for (i = 0; i < quantidade; i++) {
        if (!jogadores[i].venceu && cartela_completa(&jogadores[i].cartela)) {
            jogadores[i].venceu = 1;
            jogadores[i].rodada_vitoria = rodada;
            novas_vitorias++;
            printf("\nBINGO! %s venceu na rodada %d!\n",
                   jogadores[i].nome, rodada);
        }
    }
    return novas_vitorias;
}

static int processar_rodada(Jogador jogadores[], int quantidade,
                            int sorteados[], int *total_sorteados,
                            int *rodada, int *total_vencedores)
{
    int numero;

    if (*rodada >= MAX_NUMERO || *total_vencedores >= quantidade) {
        return 0;
    }

    numero = sortear_numero(sorteados, *total_sorteados);
    if (numero == 0) {
        return 0;
    }

    sorteados[(*total_sorteados)++] = numero;
    (*rodada)++;
    marcar_numero(jogadores, quantidade, numero);
    *total_vencedores += registrar_vitorias(jogadores, quantidade, *rodada);
    return numero;
}

static void pular_ate_proximo_ganhador(Jogador jogadores[], int quantidade,
                                       int sorteados[], int *total_sorteados,
                                       int *rodada, int *total_vencedores)
{
    int vencedores_antes = *total_vencedores;
    int numero = 0;

    while (*rodada < MAX_NUMERO && *total_vencedores < quantidade) {
        numero = processar_rodada(jogadores, quantidade, sorteados,
                                  total_sorteados, rodada, total_vencedores);
        if (numero == 0 || *total_vencedores > vencedores_antes) {
            break;
        }
    }


}

static void exibir_resultado_final(const Jogador jogadores[], int quantidade,
                                   int total_vencedores)
{
    int i, nao_venceram = 0;

    puts("\n========== RESULTADO FINAL ==========");
    printf("Jogadores vencedores: %d de %d\n", total_vencedores, quantidade);
    if (total_vencedores == quantidade) {
        puts("Todos os jogadores completaram suas cartelas!");
    } else {
        puts("Limite de sorteios atingido; nem todos completaram a cartela.");
    }

    if (total_vencedores > 0) {
        puts("\nVencedores (em ordem de rodada):");
        for (i = 1; i <= MAX_NUMERO; i++) {
            int j;
            for (j = 0; j < quantidade; j++) {
                if (jogadores[j].venceu && jogadores[j].rodada_vitoria == i) {
                    printf("- %s — rodada %d\n", jogadores[j].nome,
                           jogadores[j].rodada_vitoria);
                }
            }
        }
    }

    for (i = 0; i < quantidade; i++) {
        if (!jogadores[i].venceu) {
            if (!nao_venceram) {
                puts("\nJogadores que nao completaram a cartela:");
                nao_venceram = 1;
            }
            printf("- %s\n", jogadores[i].nome);
        }
    }
}

static void executar_partida(Jogador jogadores[], int quantidade)
{
    int sorteados[MAX_NUMERO] = {0};
    int total_sorteados = 0;
    int total_vencedores = 0;
    int rodada = 0;
    int numero = 0;
    int estado_ja_processado = 0;

    while (rodada < MAX_NUMERO && total_vencedores < quantidade) {
        char linha[64];

        if (estado_ja_processado) {
            estado_ja_processado = 0;
            if (total_sorteados > 0) {
                numero = sorteados[total_sorteados - 1];
            }
        } else {
            numero = processar_rodada(jogadores, quantidade, sorteados,
                                      &total_sorteados, &rodada, &total_vencedores);
            if (numero == 0) {
                break;
            }
        }

        limpar_tela();
        printf("========== BINGO LDP ==========\n");
        printf("Rodada %d/%d | Numero sorteado: %d\n", rodada, MAX_NUMERO, numero);
        printf("Historico: ");
        {
            int i;
            for (i = 0; i < total_sorteados; i++) {
                printf("%d%s", sorteados[i], i + 1 == total_sorteados ? "" : ", ");
            }
            putchar('\n');
        }
        printf("Vencedores: %d/%d\n", total_vencedores, quantidade);

        {
            int i;
            for (i = 0; i < quantidade; i++) {
                printf("\n%s%s\n", jogadores[i].nome,
                       jogadores[i].venceu ? " - VENCEDOR" : "");
                exibir_cartela(&jogadores[i].cartela);
            }
        }
        if (total_vencedores > 0) {
            /* O resumo final e mostrado uma unica vez ao terminar a partida. */
            puts("\nHa vencedor(es)! Continue para buscar os demais.");
        }

        if (rodada < MAX_NUMERO && total_vencedores < quantidade) {
            int pular = 0;
            printf("\n[Enter] proxima rodada | [p + Enter] proximo vencedor: ");
            if (fgets(linha, sizeof linha, stdin) == NULL) {
                break;
            }
            pular = tolower((unsigned char)linha[0]) == 'p';
            if (pular) {
                pular_ate_proximo_ganhador(jogadores, quantidade, sorteados,
                                            &total_sorteados, &rodada,
                                            &total_vencedores);
                estado_ja_processado = 1;
            }
        }
    }

    exibir_resultado_final(jogadores, quantidade, total_vencedores);
}

int main(void)
{
    int quantidade;
    Jogador jogadores[MAX_JOGADORES];

    srand((unsigned int)time(NULL));
    puts("========== BINGO LDP ==========");
    quantidade = ler_inteiro_intervalo("Quantidade de jogadores (1-100): ",
                                        1, MAX_JOGADORES);
    cadastrar_jogadores(jogadores, quantidade);
    executar_partida(jogadores, quantidade);
    return EXIT_SUCCESS;
}
