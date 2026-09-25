/*
 * utils.c
 *
 * Funções utilitárias reutilizáveis para os exercícios do repositório ProjetosC.
 *
 * As funções deste arquivo não possuem main(), permitindo que sejam usadas
 * por diferentes exercícios através de um arquivo de cabeçalho (utils.h)
 * ou por declaração de protótipos no próprio exercício.
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

/*
 * Remove o '\n' deixado pelo fgets() e também o '\r' em entradas
 * que utilizam final de linha Windows (\r\n).
 */
void removerQuebraLinha(char *texto)
{
    if (texto == NULL) {
        return;
    }

    texto[strcspn(texto, "\r\n")] = '\0';
}

/*
 * Remove espaços, tabulações e quebras de linha do início e do fim.
 * A própria string é modificada.
 */
void removerEspacosExtremos(char *texto)
{
    char *inicio;
    size_t tamanho;

    if (texto == NULL) {
        return;
    }

    inicio = texto;

    while (*inicio != '\0' && isspace((unsigned char)*inicio)) {
        inicio++;
    }

    if (inicio != texto) {
        memmove(texto, inicio, strlen(inicio) + 1);
    }

    tamanho = strlen(texto);

    while (tamanho > 0 && isspace((unsigned char)texto[tamanho - 1])) {
        texto[--tamanho] = '\0';
    }
}

/*
 * Lê uma linha inteira com fgets() e remove a quebra de linha.
 * Retorna 1 em caso de sucesso e 0 em caso de erro/EOF.
 */
int lerString(char *texto, size_t tamanho)
{
    if (texto == NULL || tamanho == 0) {
        return 0;
    }

    if (fgets(texto, (int)tamanho, stdin) == NULL) {
        texto[0] = '\0';
        return 0;
    }

    removerQuebraLinha(texto);
    return 1;
}

/*
 * Converte uma string para letras minúsculas.
 */
void paraMinusculas(char *texto)
{
    if (texto == NULL) {
        return;
    }

    while (*texto != '\0') {
        *texto = (char)tolower((unsigned char)*texto);
        texto++;
    }
}

/*
 * Converte uma string para letras maiúsculas.
 */
void paraMaiusculas(char *texto)
{
    if (texto == NULL) {
        return;
    }

    while (*texto != '\0') {
        *texto = (char)toupper((unsigned char)*texto);
        texto++;
    }
}

/*
 * Inverte uma string no próprio espaço de memória.
 */
void inverterString(char *texto)
{
    size_t inicio;
    size_t fim;
    char temp;

    if (texto == NULL) {
        return;
    }

    inicio = 0;
    fim = strlen(texto);

    if (fim == 0) {
        return;
    }

    fim--;

    while (inicio < fim) {
        temp = texto[inicio];
        texto[inicio] = texto[fim];
        texto[fim] = temp;

        inicio++;
        fim--;
    }
}

/*
 * Verifica se uma string é um palíndromo.
 * A comparação ignora maiúsculas/minúsculas e espaços.
 * Retorna 1 se for palíndromo e 0 caso contrário.
 */
int ehPalindromo(const char *texto)
{
    size_t inicio;
    size_t fim;

    if (texto == NULL) {
        return 0;
    }

    inicio = 0;
    fim = strlen(texto);

    if (fim == 0) {
        return 1;
    }

    fim--;

    while (inicio < fim) {
        while (inicio < fim &&
               isspace((unsigned char)texto[inicio])) {
            inicio++;
        }

        while (inicio < fim &&
               isspace((unsigned char)texto[fim])) {
            fim--;
        }

        if (tolower((unsigned char)texto[inicio]) !=
            tolower((unsigned char)texto[fim])) {
            return 0;
        }

        inicio++;
        fim--;
    }

    return 1;
}

/*
 * Conta quantas vezes um caractere aparece em uma string.
 */
size_t contarCaractere(const char *texto, char caractere)
{
    size_t quantidade = 0;

    if (texto == NULL) {
        return 0;
    }

    while (*texto != '\0') {
        if (*texto == caractere) {
            quantidade++;
        }

        texto++;
    }

    return quantidade;
}

/*
 * Conta apenas caracteres alfabéticos.
 */
size_t contarLetras(const char *texto)
{
    size_t quantidade = 0;

    if (texto == NULL) {
        return 0;
    }

    while (*texto != '\0') {
        if (isalpha((unsigned char)*texto)) {
            quantidade++;
        }

        texto++;
    }

    return quantidade;
}

/*
 * Conta palavras separadas por espaços em branco.
 */
size_t contarPalavras(const char *texto)
{
    size_t quantidade = 0;
    int dentroDaPalavra = 0;

    if (texto == NULL) {
        return 0;
    }

    while (*texto != '\0') {
        if (isspace((unsigned char)*texto)) {
            dentroDaPalavra = 0;
        } else if (!dentroDaPalavra) {
            quantidade++;
            dentroDaPalavra = 1;
        }

        texto++;
    }

    return quantidade;
}

/*
 * Copia uma string para um destino de tamanho limitado.
 * Garante que o destino termine com '\0'.
 *
 * Retorna 1 se a string coube inteira e 0 se foi truncada/argumentos inválidos.
 */
int copiarString(char *destino, size_t tamanhoDestino, const char *origem)
{
    size_t tamanhoOrigem;

    if (destino == NULL || origem == NULL || tamanhoDestino == 0) {
        return 0;
    }

    tamanhoOrigem = strlen(origem);

    if (tamanhoOrigem >= tamanhoDestino) {
        memcpy(destino, origem, tamanhoDestino - 1);
        destino[tamanhoDestino - 1] = '\0';
        return 0;
    }

    memcpy(destino, origem, tamanhoOrigem + 1);
    return 1;
}

/*
 * Verifica se uma string contém somente dígitos.
 * String vazia não é considerada válida.
 */
int somenteDigitos(const char *texto)
{
    if (texto == NULL || *texto == '\0') {
        return 0;
    }

    while (*texto != '\0') {
        if (!isdigit((unsigned char)*texto)) {
            return 0;
        }

        texto++;
    }

    return 1;
}

/*
 * Exemplos dos conceitos estudados neste arquivo:
 *
 * strlen(s)              -> tamanho da string
 * strcpy(destino, origem) -> copia uma string
 * strcmp(s1, s2)         -> compara duas strings
 * strcat(destino, origem) -> concatena strings
 * tolower(c) / toupper(c) -> altera maiúsculas/minúsculas
 *
 * Percorrendo uma string com ponteiro:
 *
 * char *p = palavra;
 * while (*p != '\0') {
 *     printf("%c\n", *p);
 *     p++;
 * }
 *
 * Copiando uma string com ponteiros:
 *
 * char *po = origem;
 * char *pd = destino;
 *
 * while (*po != '\0') {
 *     *pd = *po;
 *     po++;
 *     pd++;
 * }
 *
 * *pd = '\0';
 */
