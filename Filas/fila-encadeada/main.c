#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	Fila *f = criar();

	printf("\nElemento Insrido: %i", inserir(f, 2)->chave);
	printf("\nElemento Insrido: %i", inserir(f, 3)->chave);
	printf("\nElemento Insrido: %i", inserir(f, 1)->chave);
	printf("\nElemento Insrido: %i", inserir(f, 5)->chave);
	printf("\n");

  printf("\nTamanho: %d", tamanho(f));
	while (tamanho(f) > 0) {
		printf("\nRemover: %d", remover(f)->chave);
	}
	printf("\nTamanho: %d", tamanho(f));
	printf("\nDestruindo...");
	destruir(f);


	return 0;
}
