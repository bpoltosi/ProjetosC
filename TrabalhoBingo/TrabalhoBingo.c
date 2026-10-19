#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int numero[15];
    int marcado[15]; // 1 = sorteado; 0 = disponivel
} Cartela;

typedef struct
{
    int id;
    char nome[50];
    Cartela cartela;
    int venceu; // 0 = jogando; 1 = venceu
    int rodadaVitoria;
} Jogador;

/* declaracao dos prototipos */
void descartarRestanteLinha(void);
int lerQuantidadeJogadores(void);
char aguardaEnter(void);
void limparTela(void);
Cartela geraCartela(void);
void cadastraJogador(Jogador players[], int qtdJogadores);
void exibeCartela(Jogador jogador);
int sortearNumero(int numerosSorteados[], int qtsNumerosSorteados);
void armazenaNumeroSorteado(int numerosSorteados[], int *qtsNumerosSorteados);
void marcaNumero(Jogador players[], int qtdJogadores, int numeroSorteado);
int verificaVitoria(Jogador jogador);
int verificaVencedores(Jogador players[], int qtdJogadores, int rodada);
int processaProximaRodada(Jogador players[],int qtdJogadores,int numerosSorteados[],int *qtsNumerosSorteados,int *rodada,int *jogadoresVencedores);
void exibeListaVencedores(Jogador players[],int qtdJogadores,int rodadaAtual,int jogadoresVencedores);
void exibeEstadoPartida(Jogador players[],int qtdJogadores,int rodada,int numeroSorteado,int jogadoresVencedores);
void pularAteProximoGanhador(Jogador players[], int qtdJogadores, int numerosSorteados[], int *qtsNumerosSorteados, int *rodada, int *jogadoresVencedores)
{
    int vencedoresAntes = *jogadoresVencedores;
    int numeroSorteado = 0;

    /*
     * Processa uma rodada por vez e para imediatamente assim que o
     * contador de vencedores aumentar. So chega ao fim se nenhum outro
     * jogador completar a cartela antes do limite de sorteios.
     */
    while (*rodada < 60 && *jogadoresVencedores < qtdJogadores)
    {
        numeroSorteado = processaProximaRodada(
            players,
            qtdJogadores,
            numerosSorteados,
            qtsNumerosSorteados,
            rodada,
            jogadoresVencedores);

        if (numeroSorteado == 0 || *jogadoresVencedores > vencedoresAntes)
        {
            break;
        }
    }

    limparTela();

    if (*rodada > 0)
    {
        exibeEstadoPartida(players, qtdJogadores, *rodada, numeroSorteado, *jogadoresVencedores);
    }

    if (*jogadoresVencedores == vencedoresAntes &&
        *jogadoresVencedores < qtdJogadores &&
        *rodada >= 60)
    {
        printf("\nNao houve outro vencedor antes do fim dos 60 sorteios.\n");
    }
}

/* Execucao da partida - usa limparTela() exibeEstadoPartida() - exibeResultadoFinal*/
void executaPartida(Jogador players[], int qtdJogadores)
{
    int qtsNumerosSorteados = 0;
    int numerosSorteados[60];
    int jogadoresVencedores = 0;
    int rodada = 0;
    int numeroSorteado = 0;

    while (rodada < 60 && jogadoresVencedores < qtdJogadores)
    {
        numeroSorteado = processaProximaRodada(players,qtdJogadores,numerosSorteados,&qtsNumerosSorteados,&rodada,&jogadoresVencedores);

        limparTela();
        exibeEstadoPartida(players,qtdJogadores,rodada,numeroSorteado,jogadoresVencedores);

        if (rodada < 60 && jogadoresVencedores < qtdJogadores)
        {
            char opcao = aguardaEnter();

            if (opcao == 'p')
            {
                pularAteProximoGanhador(players,qtdJogadores,numerosSorteados,&qtsNumerosSorteados,&rodada,&jogadoresVencedores);
            }
        }
    }

    exibeResultadoFinal(players, qtdJogadores, jogadoresVencedores);
}

/* Resultado final - usa exibeListaVencedores() */
void exibeResultadoFinal(Jogador players[], int qtdJogadores, int jogadoresVencedores)
{
    printf("\n========== RESULTADO FINAL ==========\n");

    if (jogadoresVencedores == qtdJogadores)
    {
        printf("Todos os jogadores completaram suas cartelas!\n");
    }
    else
    {
        printf("Limite de 60 sorteios atingido.\n");
        printf("Nem todos os jogadores completaram suas cartelas.\n");
    }

    /* Cada vencedor aparece uma unica vez, em ordem de vitoria. */
    exibeListaVencedores(players, qtdJogadores, 60, jogadoresVencedores);

    /* Evita repetir os vencedores: lista aqui somente quem nao venceu. */
    int existemNaoVencedores = 0;
    for (int i = 0; i < qtdJogadores; i++)
    {
        if (players[i].venceu == 0)
        {
            if (!existemNaoVencedores)
            {
                printf("\n--- Jogadores que nao completaram a cartela ---\n");
                existemNaoVencedores = 1;
            }

            printf("%s\n", players[i].nome);
        }
    }
}

int main(void)
{
    srand((unsigned int)time(NULL));

    int qtdJogadores = lerQuantidadeJogadores();
    Jogador players[qtdJogadores];

    cadastraJogador(players, qtdJogadores);
    executaPartida(players, qtdJogadores);

    return 0;
}
