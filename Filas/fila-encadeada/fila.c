#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

Fila *criar() {
	Fila *f = malloc(sizeof(Fila));
	f->ptFila = malloc(sizeof(No));

	No *ptr = f->ptFila;
	ptr->tamanho = 0;

	return f;
}

void destruir(Fila *f) {

	free(f);
}

No *inserir(Fila *f, int x) {
	No *ant = f->ptFila;
	No *ptr = NULL;

	ptr = malloc(sizeof(No));
	ptr->prox = NULL;
	ptr->chave = x;

	if (ant->prox == NULL) {
		ant->prox = ptr;
	} else {
		No *tmp = ant->prox;

		while (tmp->prox != NULL) {
			tmp = tmp->prox;
		}

		tmp->prox = ptr;
	}
	ant->tamanho += 1;

	return ptr;
}

No* remover(Fila *f) {
	No *ptr = f->ptFila;

	if (ptr->prox == NULL) {
		printf("\nFila Vazia");
		return NULL;
	} else {
		No *tmp = ptr->prox;
		ptr->prox = tmp->prox;
		ptr->tamanho -= 1;

		return tmp;
	}
	return NULL;
}

int tamanho(Fila *f) {
	No *ptr = f->ptFila;
	return ptr->tamanho;
}
