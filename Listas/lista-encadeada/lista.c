#include "lista.h"
#include <stdlib.h>
#include <stdio.h>


Lista *criarLista() {
	Lista *l = malloc(sizeof(Lista));
	l->ptLista = malloc(sizeof(No));
	return l;
}

void destruir_lista(Lista *l) {
	No *atual = l->ptLista;
	while (atual != 0) {
		No *tmp = atual;
		atual = tmp->prox;
		free(tmp);
	}
	free(l);
}

No *buscaEncadeada(Lista *l, int x, No **ant) {
	No *pont = NULL;
	// anterior recebe no cabeca
	*ant = l->ptLista;
	// seguinte ao no cabeca
	No *ptr;
	ptr = l->ptLista->prox;

	// elemento atual é menor
	while (ptr) {
		if (ptr->chave < x) {
			*ant = ptr;
			ptr = ptr->prox;
		} /// se realmente achei:
		else if (ptr->chave == x) {
			pont = ptr;
			// parar a buscar
			ptr = NULL;
		} else {
			// a chave do ptr é maior que o x, entao para!
			ptr = NULL;
		}

		return pont;
	}
}

No *inserir(Lista *l, int x) {
	
	No *ant = l->ptLista;
	// pont so serve pra veririficar possibilidade de insercao
	No *pont = NULL;
	No *ptr = NULL;

	pont = buscar(l, x);

	// Se eu n encontrar nda posso inserir dps do ant
	if (pont == NULL) {
		// Alocando ponteiro em qualquer lular da memoria, oq ordena são os
		// ponteiros
		ptr = malloc(sizeof(No));
		ptr->chave = x;
		// apontando para o proximo do no, q era o prox do ant
		ptr->prox = ant->prox;
		ant->prox = ptr;
	}
	return ptr;
}

No *buscar(Lista *l, int x) {
	No *ant;

	return buscaEncadeada(l, x, &ant);
}

int tamanho(Lista *l) {
	int tamanho = -1;
	No *atual = l->ptLista;
	while (atual != NULL) {
		atual = atual->prox;
		tamanho++;
	}
	return tamanho;
}

void remover(Lista *l, int x) {
	No *ant;
	No *pont;

	pont = buscar(l, x);

	if (pont != NULL) {
		ant->prox = pont->prox;
		free(pont);
	}
}
No *buscar_por_indice(Lista *l, int i) {
	No *ptr = l->ptLista->prox;
	No *buscado = NULL;
	int cont = 0;

	while (ptr) {
		if (cont++ == i) { // vou contando até achar o elemento q qero(i)
			buscado = ptr;
		}
		ptr = ptr->prox;
	}

	return buscado;
}

No *primeiro(Lista *l) {
	return l->ptLista->prox;
}

No *ultimo(Lista *l) {
	No *ptr = l->ptLista->prox;

	while (ptr && ptr->prox) {
		ptr = ptr->prox;
	}

	return ptr;
}
