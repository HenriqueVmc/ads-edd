#include "arvoreBB.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //PARA O MALLOC

ArvoreBB *criarArvore() {
	ArvoreBB *arvore = malloc(sizeof(ArvoreBB));
  //Pra saber se arvore esta vazia:
  arvore->raiz = NULL;
	return arvore;
}

No *inserirArvore(ArvoreBB *a, int x) {
	No *pont;
	No *pt = a->raiz;
	No *ptr = malloc(sizeof(No));

	if (pt == NULL) {
		ptr->chave = x;
		a->raiz = ptr;

	} else {
		pont = buscarNoDaArvore(pt, x);
		if (pont->chave == x) {
			printf("\nElemento já inserido");

		} else {
			ptr->chave = x;
			if (x < pont->chave) {
				pont->esq = ptr;

			} else {
				pont->dir = ptr;
			}
		}
	}
	return NULL;
}

No *buscarNoDaArvore(No *pt, int x) {
	if (pt->chave == x) {
		return pt;

	} else {
		if (x < pt->chave) {
			if (pt->esq == NULL) {
				return pt;

			} else {
				return buscarNoDaArvore(pt->esq, x);
			}

		} else {
			if (pt->dir == NULL) {
				return pt;

			} else {
				return buscarNoDaArvore(pt->dir, x);
			}
		}
	}
	return NULL;
}

No *buscaInterativaNoDaArvore(No *pt, int x) {
  do{

		if (pt->chave == x) {
			return pt;

		} else if (pt->chave > x) {
			pt = pt->esq;
      printf("\nFoi pra esquerda");

		} else {
			pt = pt->dir;
      printf("\nFoi pra esquerda");
		}		
	}while (pt != NULL || pt->chave != x); 
  return pt;
}

int buscar(ArvoreBB* a, int x){
  No* no;
  int val = -1;

  no = buscarNoDaArvore(a->raiz, x);

  if(no->chave == x){
    val = no->chave;
  }
  return val;
}

void imprimir_simetrica(No* no){
  
   if(no != NULL){
      
      imprimir_simetrica(no->esq);
      printf("\n%i",no->chave);
      imprimir_simetrica(no->dir);
    }
}

/*
	while (pt != NULL && pt->chave != x) {
		if (pt == x) {
			return pt;

		} else if (pt->chave > x) {
			pt = pt->esq;

		} else {
			pt = pt->dir;
		}
		return pt;
	}*/