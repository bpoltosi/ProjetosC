/* Leia uma palavra (sem espaços);
Usando dois ponteiros — um a partir do início e outro a partir do fim
verifique se a palavra é um palíndromo (lida da mesma forma de trás para frente, como “arara” ou “ovo”);
Emseguida, inverta a palavra “no lugar” (sem usar um segundo vetor) e imprima o resultado */

while (*p1 == *p2){
    p1++;
    p2--;
}

#include <stdio.h>
#include <string.h>

int main()
{
	char palavra[99];
    int tamanhoPalvra = strlen(palavra);

    int *p1 = palavra;
    int *p2 = palavra[tamanhoPalvra];

    

    return 0;
}
