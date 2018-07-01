#include <stdlib.h>
#include "lista.h"


Lista* criar_lista(){
	Lista* l = malloc(sizeof(Lista));
	l->ptlista = malloc(sizeof(No));
	return l;
}

void destruir_lista(Lista* l){
	No* atual = l->ptlista;
    while(atual != 0){
        No* tmp = atual;
        atual = tmp-prox;
        free(tmp);

    /*  (não pode fazer esse treco)
        free(atual);
        atual = atual-prox;       */
    }
    free(l);
}

No* buscar(Lista* l, int x, No** ant){
    * ant = NULL;
    No* pont = NULL;

    return pont;
}

No* inserir(Lista* l, int x, No* ant, No* pont){
    No* ant = NULL;
    No* pont = NULL;

    pont = buscar(l,x,&ant);

}


int tamanho(Lista* l){
	int tamanho = -1;
	No* atual = l->ptlista;
	while (atual != NULL){
        atual = atual->prox;
        tamanho++;
	}
	return tamanho;
}


