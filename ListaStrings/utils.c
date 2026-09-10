// strlen(s) calcular o tamanho
//strcpy(destino, origem) copiar
// strcmp(s1, s2) comparar (retorna 0 se forem iguais)
// strcat(destino, origem) concatenar (juntar) duas strings
// strupr(destino) converter para maiúsculas
// strlwr(destino) converter para minúsculas

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

// Calcula o tamanho da frase
while (*p != '\0' && *p != '\n') {
  tamanhoFrase++;
  p++;
}

// Percorre a palavra
char *p = "casa";
while (*p != ’\0’) {
  printf("%c\n", *p);
  p++;
}

// Copia String com Ponteiro
char origem[] = "linguagem c";
char destino[20];

char *po = origem;
char *pd = destino;

while (*po != ’\0’) {
  *pd = *po;
  po++;
  pd++;
}

*pd = ’\0’;
printf("%s\n", destino);

// Coloca em minusculas usando ponteiro
char *p = palavra;
while (*p != '\0') {
	*p = tolower(*p);
	p++;
}

// Coloca em maiusculas usando ponteiro
char *p = palavra;
while (*p != '\0') {
	*p = toupper(*p);
	p++;
}
