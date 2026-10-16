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
} Jogador;

void descartarRestanteLinha(void)
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
    {
        // Descarta o restante da entrada
    }
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
        printf("Digite o nome do jogador: ");
        scanf(" %49[^\n]", players[i].nome);
        descartarRestanteLinha();

        players[i].id = i + 1;              // da IDs sequenciais para os players
        players[i].cartela = geraCartela(); // gera cartela para o player
        players[i].venceu = 0;              // inicializa como "não ganhadores"
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
            continue;   // comando para "pular" (!= do break, que para)
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

int main(void)
{
    int qtsNumerosSorteados = 0;
    int numerosSorteados[60];
    int qtdJogadores;
    int jogadoresVencedores = 0;

    srand(time(NULL));

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

    Jogador players[qtdJogadores];
    cadastraJogador(players, qtdJogadores);

    for (int z = 1; z <= 60 && jogadoresVencedores < qtdJogadores; z++) // FOR pra se nao ocorreram as 60 rodadas e nem todos jogadores "venceram"
    {
        armazenaNumeroSorteado(numerosSorteados, &qtsNumerosSorteados); 
        int numeroSorteado = numerosSorteados[z - 1];

        marcaNumero(players, qtdJogadores, numeroSorteado);
        limparTela(); // limpa tela para iniciar a proxima rodada

        printf("========== BINGO ==========\n");
        printf("Rodada: %d/60\n", z);
        printf("Numero sorteado: %d\n", numeroSorteado);

        for (int i = 0; i < qtdJogadores; i++) // verifica se algum jogador ganhou na rodada atual
        {
            if (players[i].venceu == 0 && verificaVitoria(players[i]))
            {
                players[i].venceu = 1;
                jogadoresVencedores++;

                printf("\n*** BINGO! %s venceu! ***\n",
                       players[i].nome);
            }
        }

        // EXibe as cartelas de quem ainda esta em jogo
        printf("\n--- Cartelas em jogo ---\n");

        for (int i = 0; i < qtdJogadores; i++)
        {
            if (players[i].venceu == 0) // condicao de apenas os "nao ganhadores"
            {
                exibeCartela(players[i]);
            }
        }

        printf("\nJogadores que venceram: %d de %d\n", jogadoresVencedores, qtdJogadores); // print dos jogadores que ja venceram (nao sei se deveria aparecer em toda rodada)

        if (jogadoresVencedores < qtdJogadores && z < 60) // validacao de espera para a proxima rodada
        {
            aguardaEnter();
        }
    }

    if (jogadoresVencedores == qtdJogadores) // se todos os jogadores "ja ganharam"
    {
        printf("\nTodos os jogadores venceram!\n");
    }
    return 0;
}