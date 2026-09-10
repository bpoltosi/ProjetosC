/* Fazer um programa que leia uma string de caracteres maiúsculos e troque 
todos os caracteres por letras minúsculas. */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Recebe entrada da palavra
char palavra[100];
printf("Informe uma palavra: ");
fgets(palavra,100, stdin);                    

// Tira o "espaco final"
if (tam > 0 && palavra[tam - 1] == '\n') {
	palavra[tam - 1] = '\0';
	tam--;
}

// Valida entrada
if (tam <= 0) {
	printf("Nenhuma palavra informada.\n");
	return 0;
}

// Coloca em minusculas
while (*p != '\0' && *p != '\n') {
  char atual = tolower(*p); 
