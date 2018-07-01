#include "pilha.h"
#include <stdlib.h>

Pilha *criarPilha(int tamanho) {
	
	Pilha *p = malloc(sizeof(Pilha));
	
	p->dados = (float*)malloc(sizeof(float) * tamanho);
	p->M = tamanho;
	p->topo = -1;
	
	return p;
}

void destruirPilha(Pilha *p) {
	free(p->dados);
	free(p);
}

void push(Pilha *p, float x) {
	if (p->topo != p->M - 1) {
		p->topo = p->topo + 1;
		p->dados[p->topo] = x;
	}
}

float pop(Pilha *p) {
  float val = 0;
  
  if(p->topo != -1){
    
    val = p->dados[p->topo];
    p->topo = p->topo-1;
    
    return val;
  }
  //return val;
}

int tamanho(Pilha *p) {
  
	return p->topo+1;
}
