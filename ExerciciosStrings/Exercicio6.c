/* Leia uma palavra (sem espaços);
Usando dois ponteiros — um a partir do início e outro a partir do fim
verifique se a palavra é um palíndromo (lida da mesma forma de trás para frente, como “arara” ou “ovo”);
Emseguida, inverta a palavra “no lugar” (sem usar um segundo vetor) e imprima o resultado */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char palavra[100];

	printf("Informe uma palavra: ");
	fgets(palavra,100, stdin);
	
	int tam = (int) strlen(palavra);
	
	if (tam > 0 && palavra[tam - 1] == '\n') {
		palavra[tam - 1] = '\0';
		tam--;
	}

	if (tam <= 0) {
		printf("Nenhuma palavra informada.\n");     // Valida entrada
		return 0;
	}

	char *p1 = palavra;
	char *p2 = palavra + tam - 1;
	int validadorPalindromo = 1;

	// Verifica caso de palindromo
	while (p1 < p2) {
		if (tolower(*p1) != tolower(*p2)) {         // Converte para minuscula
			validadorPalindromo = 0;
			break;
		}
		p1++;
		p2--;
	}

	if (validadorPalindromo == 0) {
		printf("A palavra não é um palíndromo.\n");
	} else {
		printf("A palavra é um palíndromo.\n");
	}

	// Inversão
	p1 = palavra;
	p2 = palavra + tam - 1;
	while (p1 < p2) {
		char temp = *p1;
		*p1 = *p2;
		*p2 = temp;
		p1++;
		p2--;
	}
	printf("Palavra invertida: %s\n", palavra);
	return 0;
}
