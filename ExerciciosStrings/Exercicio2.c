#include <stdio.h>

int main()
{
    char frase[50];
    printf("Digite uma frase: ");
    fgets(frase, 50, stdin); // le a linha inteira, com espacos

        // remove o ’\n’ do final, se ele tiver sido lido
    int tam = (int) strlen(frase);
    if (tam > 0 && frase[tam- 1] == ’\n’) {
    frase[tam- 1] = ’\0’;
    }
    
    return 0;
}
