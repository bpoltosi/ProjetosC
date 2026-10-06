/* Escreva um programa completo em C que:
1 Defina um registro Funcionario com nome, salário e data de admissão (sendo a data,ela própria, um registro Data);
2 Leia os dados de N funcionários em um vetor de registros;
3 Usando um ponteiro e o operador->, percorra o vetor e imprima o funcionário com o maior salário;
4 Informe também quantos funcionários foram admitidos antes de um ano digitado pelo usuário. */

#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct
{
    int dia, mes, ano;
} Data;

typedef struct
{
    char nome[50];
    float salario;
    Data admissao;
} Funcionario;

int main(void)
{
    int quantidadeFuncionarios = 0;
    printf("Informe a quantidade de funcionários: ");
    scanf("%i", &quantidadeFuncionarios);

    while (quantidadeFuncionarios <= 0)
    {
        printf("\nValor inválido! \nInforme novamente: ");
        scanf("%i", &quantidadeFuncionarios);
    }

    Funcionario f[quantidadeFuncionarios];

    // Receber as informacoes
    for (int i = 0; i < quantidadeFuncionarios; i++)
    {

        // Limpa o buffer deixado pelo scanf anterior, se nao for a primeira interacao
        if (i > 0)
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
        }

        printf("\n--- Funcionario %d ---", (i + 1));

        // recebe os nomes
        printf("\nInforme o nome: ");
        fgets(f[i].nome, 50, stdin);

        // Remove o '\n' do final gerado pelo fgets
        int tam = strlen(f[i].nome);
        if (tam > 0 && f[i].nome[tam - 1] == '\n')
        {
            f[i].nome[tam - 1] = '\0';
        }

        // Receber o salario
        printf("\nInforme o salario: ");
        scanf("%f", &f[i].salario);

        // Receber informacoes desejadas do funcionario
        printf("\nInforme apenas o dia da data de admissao: ");
        scanf("%i", &f[i].admissao.dia);
        printf("\nInforme apenas o mes da data de admissao: ");
        scanf("%i", &f[i].admissao.mes);
        printf("\nInforme apenas o ano da data de admissao: ");
        scanf("%i", &f[i].admissao.ano);
    }

    // Recebe ano para pesquisa
    int anoBusca;
    printf("\nInforme um ano para buscar quantos funcionários foram admitidos antes desse ano ");
    scanf("%i", &anoBusca);

    // obter ano atual
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    int anoAtual = tm.tm_year + 1900;

    // Validacao do ano
    while (anoBusca > anoAtual || anoBusca <= 0)
    {
        printf("\nAno inválido! \nInforme novamente: ");
        scanf("%i", &anoBusca);
    }

    // Ponteiro para percorrer os funcionarios
    Funcionario *p1 = f;
    int funcionariosAdmitidos = 0;

    // Contagem de funcionários admitidos antes do ano informado
    for (int i = 0; i < quantidadeFuncionarios; i++)
    {
        if ((p1 + i)->admissao.ano < anoBusca)
        {
            funcionariosAdmitidos++;
        }
    }

    // Variaveis para encontrar funcionario com maior salario
    Funcionario *p2 = f;
    float maiorSalario = p2->salario;
    char nomeMaiorSalario[50];

    // Copia inicialmente o nome do primeiro funcionario
    strcpy(nomeMaiorSalario, p2->nome);

    // Encontrar funcionário com maior salário
    for (int i = 1; i < quantidadeFuncionarios; i++)
    {
        if ((p2 + i)->salario > maiorSalario)
        {
            maiorSalario = (p2 + i)->salario;
            strcpy(nomeMaiorSalario, (p2+i)->nome);
        }
    }

    printf("\nForam admitidos %i funcionários antes do ano %d", funcionariosAdmitidos, anoBusca);
    printf("\nO funcionario '%s' possui o maior salário (%.2f)", nomeMaiorSalario, maiorSalario);

    return 0;
}