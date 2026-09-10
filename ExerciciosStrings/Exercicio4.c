/* Declare um vetor de char com espaço para uma frase de até 99 caracteres;
Leia a frase digitada pelo usuário, com espaços, usando fgets;
Remova o ’\n’ do final, se houver, e imprima a frase lida */

#include <stdio.h>
#include <string.h>

int main()
{
    char frase[100];

    printf("Informe uma frase: ");
    fgets(frase,100,stdin);

    int tam = (int) strlen(frase);

    if (tam > 0 && frase[tam- 1] == '\n') {
    frase[tam- 1] = '\0';
    }
    
    puts(frase);
    
    return 0;
}
