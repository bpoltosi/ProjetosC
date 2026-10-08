/* Modele um pedido de compra usando as structs:
Data, Endereco, Produto, ItemPedido (que contém um Produto),
Cliente (que contém um CPF e Endereco)
Pedido (que contém Cliente, Data e um vetor de ItemPedido).

cliente - cpf,endereco (supondo que ele esta "identificado", mas vamos criar alguns cliente fixos e usar a funcao rand() para aleatorizar os clientes)
produto - codigo,nome
escrever em pedidos - cpf,endereco,codigoDosProduto * quantidade (podem ser varios produtos)

O programa deve fazer quatro coisas:
a. Preencher os dados do pedido;
b. Adicionar 3 itens a partir de um catálogo de produtos;
c. Calcular o subtotal e aplicar 10% de desconto se ele passar de R$500,00;
d. Imprimir um cupom fiscal. (data e hora da compra / nome do produto(s) -  quantidade valor = preco(s) / cpf do cliente / endereço entrega) */

#include <stdio.h>
#include <string.h>

int main (void)
{
	return 0;
}
