#include <stdlib.h>
#include <stdio.h>
#include "lista.h"



int main (int argc, char* argv[]){

	Lista* l = criar_lista(10);

	if(inserir(l, 1)){
		printf("1 inserido na lista\n");
	}
	if(!inserir(l, 1)){
		printf("1 já estava na lista na lista\n");
	}
	if(inserir(l, 2)){
		printf("2 inserido na lista\n");
	}
	if(inserir(l, 3)){
		printf("3 inserido na lista\n");
	}

	printf("Primeiro elemento: %d\n", primeiro(l)->chave);

	printf("Ultimo elemento: %d\n", ultimo(l)->chave);

	printf("Existem %d elementos na lista", tamanho(l));

	destruir_lista(l);


	return 0;
}
