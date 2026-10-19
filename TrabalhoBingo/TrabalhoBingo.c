#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int numero[15];
    int marcado[15]; // 1 para sorteado ; 0 para disponivel
} Cartela;

typedef struct
{
    int id;
    char nome[50];
    Cartela cartela;
    int venceu; // 0 se ainda esta jogando, 1 se ja "ganhou"
    int rodadaVitoria;
} Jogador;

//assinatura das funcoes (prototipo)
void descartarRestanteLinha(void);
int lerQuantidadeJogadores(void);
void aguardaEnter(void);
void limparTela(void);
void exibeCartela(Jogador jogador);
void exibeEstadoPartida(Jogador players[],int qtdJogadores,int rodada,int numeroSorteado,int jogadoresVencedores);
void executaPartida(Jogador players[], int qtdJogadores);
int sortearNumero(int numerosSorteados[], int qtsNumerosSorteados);
void armazenaNumeroSorteado(int numerosSorteados[],int *qtsNumerosSorteados);
Cartela geraCartela(void);
void cadastraJogador(Jogador players[], int qtdJogadores);
void marcaNumero(Jogador players[],int qtdJogadores,int numeroSorteado);
int verificaVitoria(Jogador jogador);
int verificaVencedores(Jogador players[],int qtdJogadores,int rodada);
void exibeResultadoFinal(Jogador players[],int qtdJogadores,int jogadoresVencedores);

void descartarRestanteLinha(void)
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
    {
        // Descarta o restante da entrada
    }
}

int lerQuantidadeJogadores(void)
{
    int qtdJogadores;

    printf("Informe a quantidade de jogadores (2 a 5): "); // recebe a quantidade de jogadores
    scanf("%d", &qtdJogadores);
    descartarRestanteLinha();

    while (qtdJogadores < 2 || qtdJogadores > 5) // valida quantidade de jogadores
    {
        printf("\nNumero inválido, fora do intervalo (2-5)\n");
        printf("Informe a quantidade de jogadores (2 a 5): ");
        scanf("%d", &qtdJogadores);
        descartarRestanteLinha();
    }
    return qtdJogadores;
}

void aguardaEnter(void)
{
    printf("\nPressione ENTER para a proxima rodada...");

    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        // Descarta caracteres restantes da entrada
    }
}

void limparTela()
{
#if defined(_WIN32) || defined(_WIN64)
    system("cls"); // Executa no Windows antigo/padrão
#else
    system("clear"); // Executa no Linux e macOS
#endif
}

void exibeEstadoPartida(Jogador players[], int qtdJogadores, int rodada, int numeroSorteado, int jogadoresVencedores)
{
    printf("========== BINGO ==========\n");
    printf("Rodada: %d/60\n", rodada);
    printf("Numero sorteado: %d\n", numeroSorteado);

    printf("\n---- Cartelas em jogo ----\n");

    for (int i = 0; i < qtdJogadores; i++)
    {
        if (players[i].venceu == 0)
        {
            exibeCartela(players[i]);
        }
    }

    printf("\nJogadores que venceram: %d de %d\n",
           jogadoresVencedores, qtdJogadores);
}

void executaPartida(Jogador players[], int qtdJogadores)
{
    int qtsNumerosSorteados = 0;
    int numerosSorteados[60];
    int jogadoresVencedores = 0;

    for (int rodada = 1;
         rodada <= 60 && jogadoresVencedores < qtdJogadores;
         rodada++)
    {
        armazenaNumeroSorteado(
            numerosSorteados,
            &qtsNumerosSorteados
        );

        int numeroSorteado = numerosSorteados[rodada - 1];

        marcaNumero(
            players,
            qtdJogadores,
            numeroSorteado
        );

        limparTela();

        jogadoresVencedores += verificaVencedores(
            players,
            qtdJogadores,
            rodada
        );

        exibeEstadoPartida(
            players,
            qtdJogadores,
            rodada,
            numeroSorteado,
            jogadoresVencedores
        );

        if (jogadoresVencedores < qtdJogadores && rodada < 60)
        {
            aguardaEnter();
        }
    }

    exibeResultadoFinal(
        players,
        qtdJogadores,
        jogadoresVencedores
    );
}

int sortearNumero(int numerosSorteados[], int qtsNumerosSorteados)
{
    if (qtsNumerosSorteados >= 60)
    { // verifica se ja nao foram sorteados os 60 numeros
        return 0;
    }

    int n = rand() % 60 + 1;
    int repetido = 1; // da a TAG inicialmente, para cair na validacao

    while (repetido)
    {
        repetido = 0; // retira momentaneamente a TAG, pois nem todo numero que entra no loop é repetido

        for (int i = 0; i < qtsNumerosSorteados; i++)
        {
            if (n == numerosSorteados[i])
            {                        // valida o numero
                repetido = 1;        // se for repetido, volta novamente a dar a TAG
                n = rand() % 60 + 1; // gera um novo numero
                break;               // interrompe o for completo, reiniciando a validacao
            }
        }
    }
    return n;
}

void armazenaNumeroSorteado(int numerosSorteados[], int *qtsNumerosSorteados)
{
    if (*qtsNumerosSorteados >= 60)
    { // valida se ja nao foram sorteados os 60 numeros (60 sorteios)
        return;
    }

    int n = sortearNumero(numerosSorteados, *qtsNumerosSorteados);

    if (n == 0)
    { // valida se a funcao nao returnou zero, do caso de validacao da funcao para quando nao ha mais numeros disponiveis para sortear
        return;
    }

    numerosSorteados[*qtsNumerosSorteados] = n;
    (*qtsNumerosSorteados)++;
}

Cartela geraCartela(void)
{
    Cartela cartela; // inicializa a cartela

    for (int z = 0; z < 15; z++) // FOR para gerar os 15 numeros da cartela
    {
        int repetido = 1;          // da a TAG inicialmente, para cair na validacao
        int n = (rand() % 60 + 1); // gera um novo numero (ainda nao validado)

        while (repetido)
        {
            repetido = 0; // retira momentaneamente a TAG, pois nem todo numero que entra no loop é repetido

            for (int i = 0; i < z; i++) // 'z' seria == qtsNumerosGerados
            {
                if (n == cartela.numero[i]                                           // valida repeticao exata
                    || n == (cartela.numero[i] - 1) || n == (cartela.numero[i] + 1)) // valida repeticao consecutiva
                {
                    repetido = 1;        // se for repetido, volta novamente a ter a TAG, para reiniciar a validacao
                    n = rand() % 60 + 1; // gera um novo numero (ainda nao validado)
                    break;               // interrompe o FOR completo
                }
            }
        }
        cartela.numero[z] = n;  // atribui o numero a cartela
        cartela.marcado[z] = 0; // marca os numeros como "nao marcados"
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

void exibeCartela(Jogador jogador)
{
    printf("\nCartela de Bingo - %s (ID: %d)\n", jogador.nome, jogador.id);

    for (int i = 0; i < 15; i++)
    {
        if (i % 5 == 0)
            printf("|----|----|----|----|----|\n");

        if (jogador.cartela.marcado[i])
        {
            printf("|%2d* ", jogador.cartela.numero[i]); // o asterisco '*' indica que o numero foi marcado (preciso melhorar - nao sei como)
        }
        else
        {
            printf("|%2d  ", jogador.cartela.numero[i]); // sem o asterisco (nao é um numero ja sorteado)
        }

        if ((i + 1) % 5 == 0)
            printf("|\n");
    }
    printf("|----|----|----|----|----|\n");
}

void marcaNumero(Jogador players[], int qtdJogadores, int numeroSorteado)
{
    for (int i = 0; i < qtdJogadores; i++)
    {
        if (players[i].venceu == 1) // skipa os players que ja venceram
        {
            continue; // comando para "pular" (!= do break, que para)
        }

        for (int j = 0; j < 15; j++)
        {
            if (players[i].cartela.numero[j] == numeroSorteado)
            {
                players[i].cartela.marcado[j] = 1; // marca o da tabela da pessoa se o numeroTabela == numeroSorteado
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
        if (players[i].venceu == 0 &&
            verificaVitoria(players[i]))
        {
            players[i].venceu = 1;
            players[i].rodadaVitoria = rodada;
            novosVencedores++;

            printf(
                "\n*** BINGO! %s venceu na rodada %d! ***\n",
                players[i].nome,
                rodada
            );
        }
    }

    return novosVencedores;
}

void exibeResultadoFinal(Jogador players[], int qtdJogadores, int jogadoresVencedores)
{
    printf("\n========== RESULTADO FINAL ==========\n");

    if (jogadoresVencedores == qtdJogadores)
    {
        printf("Todos os jogadores venceram!\n");
    }
    else
    {
        printf("Limite de 60 sorteios atingido.\n");
        printf("Nem todos completaram a cartela.\n");
    }

    printf(
        "\nTotal de vencedores: %d de %d\n",
        jogadoresVencedores,
        qtdJogadores
    );

    printf("\n--- Classificacao dos jogadores ---\n");

    for (int i = 0; i < qtdJogadores; i++)
    {
        printf("%d. %s - ", i + 1, players[i].nome);

        if (players[i].venceu == 1)
        {
            printf(
                "Venceu na rodada %d!\n",
                players[i].rodadaVitoria
            );
        }
        else
        {
            printf("Nao completou a cartela.\n");
        }
    }
}

int main(void)
{
    srand(time(NULL));

    int qtdJogadores = lerQuantidadeJogadores();

    Jogador players[qtdJogadores];

    cadastraJogador(players, qtdJogadores);

    executaPartida(players, qtdJogadores);

    return 0;
}