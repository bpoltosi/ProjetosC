/* Desenvolver um programa que recebe uma palavra e
o tipo de conversão que o usuário deseja que ela sofra, que poderá ser letras maiúsculas ou minúsculas.
Observe que o campo (variável) tipo de conversão deverá ser validado. */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	// Recebe entrada da palavra
	char palavra[100];
	printf("Informe uma palavra: ");
	fgets(palavra, 100, stdin);

	// Tira o "espaco final"
	int tam = strlen(palavra);
	if (tam > 0 && palavra[tam - 1] == '\n')
	{
		palavra[tam - 1] = '\0';
		tam--;
	}

	// Valida entrada
	if (tam <= 0)
	{
		printf("Nenhuma palavra informada.\n");
		return 0;
	}

	// Recebe a escolha
	int escolha = 0;
	printf("Informe 1 para Maiusculas\n");
	printf("Informe 2 para Minusculas\n");
	scanf("%i", &escolha);

	// Faz a alteração necessaria + validação
	char *p = palavra;
	switch (escolha)
	{
	case 1:
		while (*p != '\0')
		{
			*p = toupper(*p);
			p++;
		}
		break;

	case 2:
		while (*p != '\0')
		{
			*p = tolower(*p);
			p++;
		}
		break;

	default:
		printf("Escolha inválida!");
		return 0;
	}

	printf("Resultado: %s", palavra);

	return 0;
}