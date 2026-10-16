#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int numero[15];
} Cartela;

typedef struct
{
    int id;
    char nome[50];
    Cartela cartela;
} Jogador;

int sortearNumero(int numerosSorteados[], int qtsNumerosSorteados)
{ // ja valida o numero sorteado
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

    int n = sortearNumero(numerosSorteados, *qtsNumerosSorteados);

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
        cartela.numero[z] = n; // atribui o numero a cartela
    }
    return cartela;
}

void cadastraJogador(Jogador players[], int qtdJogadores)
{
    for (int i = 0; i < qtdJogadores; i++)
    {
        printf("Digite o nome do jogador: ");
        scanf(" %49[^\n]", players[i].nome);

        players[i].id = i + 1;
        players[i].cartela = geraCartela();
    }
}

void exibeCartela(Jogador jogador)
{
    printf("\nCartela de Bingo - %s (ID: %d)\n", jogador.nome, jogador.id);

    for (int i = 0; i < 15; i++)
    {
        if (i % 5 == 0)
            printf("|----|----|----|----|----|\n");

        printf("| %2d ", jogador.cartela.numero[i]);

        if ((i + 1) % 5 == 0)
            printf("|\n");
    }
    printf("|----|----|----|----|----|\n");
}

int main(void)
{
    int qtsNumerosSorteados = 0;
    int numerosSorteados[60];
    int qtdJogadores;

    Jogador jogador;
    Jogador players[qtdJogadores];
    jogador.id = 1;

    srand(time(NULL));

    printf("Informe a quantidade de Jogadores: ");
    scanf("%d", &qtdJogadores);

    while (qtdJogadores <= 0){
        printf("quantidade inválida, informe novamente!");
        scanf("%d", &qtdJogadores);
    }

    jogador.cartela = geraCartela();
    exibeCartela(jogador);
    cadastraJogador(players, qtdJogadores);

    for (int z = 1; z <= 60; z++)
    {
        armazenaNumeroSorteado(numerosSorteados, &qtsNumerosSorteados);
        printf("Numero sorteado: %d\n", numerosSorteados[z - 1]);
        printf("Na posicao: %d\n", z);
    }
    return 0;
}