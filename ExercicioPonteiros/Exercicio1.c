#include <stdio.h>

int main(){
int idade = 19, *p = &idade;

printf("Valor de idade: %d", idade);
printf("\nValor do endereço do ponteiro de idade: %p", p);
printf("\nValor do ponteiro de idade: %p", *p);

return 0;
}
