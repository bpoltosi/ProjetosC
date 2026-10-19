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

/* Prototipos */
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

int processaProximaRodada(
    Jogador players[],
    int qtdJogadores,
    int numerosSorteados[],
    int *qtsNumerosSorteados,
    int *rodada,
    int *jogadoresVencedores
);

void exibeListaVencedores(
    Jogador players[],
    int qtdJogadores,
    int rodadaAtual,
    int jogadoresVencedores
);

void exibeEstadoPartida(
    Jogador players[],
    int qtdJogadores,
    int rodada,
    int numeroSorteado,
    int jogadoresVencedores
);

void pularAteProximoGanhador(
    Jogador players[],
    int qtdJogadores,
    int numerosSorteados[],
    int *qtsNumerosSorteados,
    int *rodada,
    int *jogadoresVencedores
);

void executaPartida(Jogador players[], int qtdJogadores);
void exibeResultadoFinal(Jogador players[], int qtdJogadores, int jogadoresVencedores);

/* Funcoes auxiliares */
void descartarRestanteLinha(void)
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
    {
        // Descarta os caracteres restantes da entrada
    }
}

int lerQuantidadeJogadores(void)
{
    int qtdJogadores;

    while (1)
    {
        printf("Informe a quantidade de jogadores (2 a 5): ");

        if (scanf("%d", &qtdJogadores) != 1)
        {
            printf("Entrada invalida. Digite um numero.\n");
            descartarRestanteLinha();
            continue;
        }

        descartarRestanteLinha();

        if (qtdJogadores >= 2 && qtdJogadores <= 5)
        {
            return qtdJogadores;
        }

        printf("Numero invalido. Escolha entre 2 e 5.\n\n");
    }
}

/* ENTER avanca uma rodada; P pula ate surgir um novo vencedor. */
char aguardaEnter(void)
{
    int c;

    printf("\nENTER = proxima rodada | P = pular ate proximo ganhador: ");
    c = getchar();

    if (c == EOF)
    {
        return 'n';
    }

    if (c != '\n')
    {
        descartarRestanteLinha();
    }

    if (c == 'p' || c == 'P')
    {
        return 'p';
    }

    return 'n';
}

void limparTela(void)
{
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#else
    system("clear");
#endif
}

/* Sorteio dos numeros */
int sortearNumero(int numerosSorteados[], int qtsNumerosSorteados)
{
    if (qtsNumerosSorteados >= 60)
    {
        return 0;
    }

    int n;
    int repetido;

    do
    {
        n = rand() % 60 + 1;
        repetido = 0;

        for (int i = 0; i < qtsNumerosSorteados; i++)
        {
            if (n == numerosSorteados[i])
            {
                repetido = 1;
                break;
            }
        }
    } while (repetido);

    return n;
}

void armazenaNumeroSorteado(int numerosSorteados[], int *qtsNumerosSorteados)
{
    if (*qtsNumerosSorteados >= 60)
    {
        return;
    }

    int n = sortearNumero(numerosSorteados, *qtsNumerosSorteados);

    if (n == 0)
    {
        return;
    }

    numerosSorteados[*qtsNumerosSorteados] = n;
    (*qtsNumerosSorteados)++;
}

/* Geracao e cadastro das cartelas */
Cartela geraCartela(void)
{
    Cartela cartela;

    for (int z = 0; z < 15; z++)
    {
        int n;
        int repetido;

        do
        {
            n = rand() % 60 + 1;
            repetido = 0;

            for (int i = 0; i < z; i++)
            {
                if (n == cartela.numero[i] ||
                    n == cartela.numero[i] - 1 ||
                    n == cartela.numero[i] + 1)
                {
                    repetido = 1;
                    break;
                }
            }
        } while (repetido);

        cartela.numero[z] = n;
        cartela.marcado[z] = 0;
    }

    return cartela;
}

void cadastraJogador(Jogador players[], int qtdJogadores)
{
    for (int i = 0; i < qtdJogadores; i++)
    {
        printf("Digite o nome do jogador %d: ", i + 1);

        if (scanf(" %49[^\n]", players[i].nome) != 1)
        {
            printf("Nao foi possivel ler o nome.\n");
            players[i].nome[0] = '\0';
        }

        descartarRestanteLinha();

        players[i].id = i + 1;
        players[i].cartela = geraCartela();
        players[i].venceu = 0;
        players[i].rodadaVitoria = 0;
    }
}

/* Exibicao das cartelas */
void exibeCartela(Jogador jogador)
{
    printf("\nCartela de Bingo - %s (ID: %d)\n", jogador.nome, jogador.id);

    for (int i = 0; i < 15; i++)
    {
        if (i % 5 == 0)
        {
            printf("|----|----|----|----|----|\n");
        }

        if (jogador.cartela.marcado[i])
        {
            printf("|%2d* ", jogador.cartela.numero[i]);
        }
        else
        {
            printf("|%2d  ", jogador.cartela.numero[i]);
        }

        if ((i + 1) % 5 == 0)
        {
            printf("|\n");
        }
    }

    printf("|----|----|----|----|----|\n");
}

/* Marcacao e verificacao de vitoria */
void marcaNumero(Jogador players[], int qtdJogadores, int numeroSorteado)
{
    for (int i = 0; i < qtdJogadores; i++)
    {
        if (players[i].venceu == 1)
        {
            continue;
        }

        for (int j = 0; j < 15; j++)
        {
            if (players[i].cartela.numero[j] == numeroSorteado)
            {
                players[i].cartela.marcado[j] = 1;
            }
        }
    }
}

int verificaVitoria(Jogador jogador)
{
    for (int i = 0; i < 15; i++)
    {
        if (jogador.cartela.marcado[i] == 0)
        {
            return 0;
        }
    }

    return 1;
}

int verificaVencedores(Jogador players[], int qtdJogadores, int rodada)
{
    int novosVencedores = 0;

    for (int i = 0; i < qtdJogadores; i++)
    {
        if (players[i].venceu == 0 && verificaVitoria(players[i]))
        {
            players[i].venceu = 1;
            players[i].rodadaVitoria = rodada;
            novosVencedores++;
        }
    }

    return novosVencedores;
}

/* Executa uma rodada e devolve o numero sorteado. */
int processaProximaRodada(
    Jogador players[],
    int qtdJogadores,
    int numerosSorteados[],
    int *qtsNumerosSorteados,
    int *rodada,
    int *jogadoresVencedores
)
{
    if (*rodada >= 60 || *jogadoresVencedores >= qtdJogadores)
    {
        return 0;
    }

    armazenaNumeroSorteado(numerosSorteados, qtsNumerosSorteados);

    if (*qtsNumerosSorteados == 0)
    {
        return 0;
    }

    (*rodada)++;
    int numeroSorteado = numerosSorteados[*qtsNumerosSorteados - 1];

    marcaNumero(players, qtdJogadores, numeroSorteado);

    *jogadoresVencedores += verificaVencedores(
        players,
        qtdJogadores,
        *rodada
    );

    return numeroSorteado;
}

/* Lista os vencedores ordenados pela rodada em que venceram.
   Em caso de empate na mesma rodada, segue a ordem de cadastro. */
void exibeListaVencedores(
    Jogador players[],
    int qtdJogadores,
    int rodadaAtual,
    int jogadoresVencedores
)
{
    printf("\nJogadores que venceram: %d de %d\n",
           jogadoresVencedores, qtdJogadores);
    printf("Vencedores (ordem de vitoria):\n");

    if (jogadoresVencedores == 0)
    {
        printf("Nenhum vencedor ainda.\n");
        return;
    }

    int posicao = 1;

    for (int rodada = 1; rodada <= rodadaAtual; rodada++)
    {
        for (int i = 0; i < qtdJogadores; i++)
        {
            if (players[i].venceu == 1 &&
                players[i].rodadaVitoria == rodada)
            {
                printf("%d. %s - rodada %d\n",
                       posicao, players[i].nome, players[i].rodadaVitoria);
                posicao++;
            }
        }
    }
}

void exibeEstadoPartida(
    Jogador players[],
    int qtdJogadores,
    int rodada,
    int numeroSorteado,
    int jogadoresVencedores
)
{
    printf("========== BINGO ==========\n");
    printf("Rodada: %d/60\n", rodada);
    printf("Numero sorteado: %d\n", numeroSorteado);
    printf("\nLegenda: * = numero sorteado\n");
    printf("\n---- Cartelas em jogo ----\n");

    for (int i = 0; i < qtdJogadores; i++)
    {
        if (players[i].venceu == 0)
        {
            exibeCartela(players[i]);
        }
    }

    exibeListaVencedores(
        players,
        qtdJogadores,
        rodada,
        jogadoresVencedores
    );
}

/* Avanca varias rodadas, sem exibi-las, ate aparecer um novo vencedor.
   A tela mostra o estado da rodada em que houve a nova vitoria (ou a rodada 60). */
void pularAteProximoGanhador(
    Jogador players[],
    int qtdJogadores,
    int numerosSorteados[],
    int *qtsNumerosSorteados,
    int *rodada,
    int *jogadoresVencedores
)
{
    int vencedoresAntes = *jogadoresVencedores;
    int numeroSorteado = 0;

    while (*rodada < 60 &&
           *jogadoresVencedores < qtdJogadores &&
           *jogadoresVencedores == vencedoresAntes)
    {
        numeroSorteado = processaProximaRodada(
            players,
            qtdJogadores,
            numerosSorteados,
            qtsNumerosSorteados,
            rodada,
            jogadoresVencedores
        );
    }

    limparTela();

    if (*rodada > 0)
    {
        exibeEstadoPartida(
            players,
            qtdJogadores,
            *rodada,
            numeroSorteado,
            *jogadoresVencedores
        );
    }
}

/* Execucao da partida */
void executaPartida(Jogador players[], int qtdJogadores)
{
    int qtsNumerosSorteados = 0;
    int numerosSorteados[60];
    int jogadoresVencedores = 0;
    int rodada = 0;
    int numeroSorteado = 0;

    while (rodada < 60 && jogadoresVencedores < qtdJogadores)
    {
        numeroSorteado = processaProximaRodada(
            players,
            qtdJogadores,
            numerosSorteados,
            &qtsNumerosSorteados,
            &rodada,
            &jogadoresVencedores
        );

        limparTela();
        exibeEstadoPartida(
            players,
            qtdJogadores,
            rodada,
            numeroSorteado,
            jogadoresVencedores
        );

        if (rodada < 60 && jogadoresVencedores < qtdJogadores)
        {
            char opcao = aguardaEnter();

            if (opcao == 'p')
            {
                pularAteProximoGanhador(
                    players,
                    qtdJogadores,
                    numerosSorteados,
                    &qtsNumerosSorteados,
                    &rodada,
                    &jogadoresVencedores
                );
            }
        }
    }

    exibeResultadoFinal(players, qtdJogadores, jogadoresVencedores);
}

/* Resultado final */
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

    exibeListaVencedores(
        players,
        qtdJogadores,
        60,
        jogadoresVencedores
    );

    printf("\n--- Situacao final dos jogadores ---\n");

    for (int i = 0; i < qtdJogadores; i++)
    {
        if (players[i].venceu == 1)
        {
            printf("%s - venceu na rodada %d.\n",
                   players[i].nome, players[i].rodadaVitoria);
        }
        else
        {
            printf("%s - nao completou a cartela.\n", players[i].nome);
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
