/* Fazer um programa para ler uma string e
contar quantas vezes um determinado caractere aparece na string.
O caractere deverá ser informado pelo usuário. */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	// Recebe entrada da frase
	char frase[100];
	printf("Informe uma frase: ");
	fgets(frase, 100, stdin);

	// Tira o "espaco final"
	int tam = strlen(frase);
	if (tam > 0 && frase[tam - 1] == '\n')
	{
		frase[tam - 1] = '\0';
		tam--;
	}

	// Valida entrada
	if (tam <= 0)
	{
		printf("Nenhuma frase informada.\n");
		return 0;
	}

    // Coloca em minusculas (padroniza procura)
    char *ponteiroMinusculas = frase;
    while (*ponteiroMinusculas != '\0') {
        *ponteiroMinusculas = tolower(*ponteiroMinusculas);
        ponteiroMinusculas++;
    }

	// Recebe a escolha
	char escolhido;
	printf("Informe o caracter a ser contado: ");
	scanf("%c", &escolhido);

    // Encontra e Conta
    int contadorEncontrado = 0;
    char *ponteiroContador = frase;
    for (int i=0;i<tam;i++){
        if(*ponteiroContador == escolhido){
            contadorEncontrado++;
        }
        ponteiroContador++;
    }

	printf("\nQuantas vezes o caracter '%c' foi encontrado: %i", escolhido, contadorEncontrado);

	return 0;
}