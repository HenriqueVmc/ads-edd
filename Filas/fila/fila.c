#include <stdlib.h>
#include "fila.h"


Fila* criar_fila(int tamanho){
    Fila* f = malloc(sizeof(Fila));
    f->dados = malloc(sizeof(int)*tamanho);
    f->M = tamanho;
    f->f = -1;
    f->r = -1;
    f->tamanho = 0;
    return f;
}

void destruir_fila(Fila* f){
    free(f->dados);
    free(f);
}

void inserir(Fila* f, int x){

  if(f->tamanho < f->M){
    f->tamanho = f->tamanho+1;
    f->r = (f->r+1)%f->M;
    f->dados[f->r] = x;
  }
}

int remover(Fila* f){
  
    int val = 0;  
    
    if(f->tamanho > 0){
      f->tamanho = f->tamanho -1;
      f->f = (f->f+1)%f->M;
      val = f->dados[f->f];
      
      return val;
    }
}

int tamanho(Fila* f){
  
    return f->tamanho;
}
