/* Desenvolver um programa que recebe uma palavra e o tipo de conversão que 
o usuário deseja que ela sofra, que poderá ser letras maiúsculas ou minúsculas. 
Observe que o campo (variável) tipo de conversão deverá ser validado. */

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

printf

// Coloca em minusculas
while (*p != '\0' && *p != '\n') {
  char atual = tolower(*p); 

// Coloca em maiusculas
while (*p != '\0' && *p != '\n') {
  char atual = toupper(*p); 
