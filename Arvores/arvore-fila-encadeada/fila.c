#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

Fila *criar() {
	
	Fila *f = malloc(sizeof(Fila));
	f->inicio = NULL;
	f->fim = NULL;
	
	return f;
}

void destruir(Fila *f) {
	free(f);
}

void *inserirFila(Fila *f, void *dado) {
	//No *ini = f->inicio;
	//No *fim = f->fim;
		
	NoFila* ptr = malloc(sizeof(NoFila));
	ptr->dado = dado;
	ptr->prox = NULL;//significa q ele esta no fim

	if (f->fim != NULL) {//Se a fila não esta vazia, insiro no próx do fim, ou seja, no primeiro no!
		f->fim->prox = ptr;
	}else {
		f->inicio = ptr;
	}
	f->fim = ptr;
}

void* remover(Fila *f) {
  //No *ini = f->inicio;
  //No *fim = f->fim;
	NoFila *ptr = NULL;
  void *dado = NULL;
  
	if (f->inicio == NULL){
		printf("\nFila Vazia");
		
	} else {
		ptr = f->inicio;
		f->inicio = f->inicio->prox;
		dado = ptr->dado;
		
		if(f->inicio == NULL){ // se ini == NULL, fim tbem deve ser NULL
		  f->fim  = NULL;
		}
		free(ptr);
	}
  return dado;
}

int tamanho(Fila *f) {

}
