/* Dois vetores de inteiros, 'V1' e 'V2', cada um com 5 elementos.
Cria um terceiro vetor 'V3' com 10 elementos e preenche de forma intercalada (ex: V3[0] recebe V1[0], V3[1] recebe V2[0], V3[2] recebe V1[1], ...).
E exibe o vetor 'V3' completo no final. */

#include <stdio.h>

int main()
{
	int V1[5] = {1,2,3,4,5};
	int V2[5] = {12,13,14,15,16};
	int V3[10] = {0};

	for (int i = 0; i < 5; i++) {
		V3[i * 2] = V1[i];
		V3[i * 2 + 1] = V2[i];
	}
	for (int i = 0; i < 10; i++) {
		printf("%d ,", V3[i]);
	}
	return 0;
}
