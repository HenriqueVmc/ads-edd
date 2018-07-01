#include "arvore.h"
#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

No* criar_arvore(char chave){
    No* no = malloc(sizeof(No));
    no->chave = chave;
    no->esquerda = NULL;
    no->direita = NULL;

    return no;
}

No* inserir(No* arvore, No* esquerdo, No* direito){
    arvore->esquerda = esquerdo;
    arvore->direita = direito;

    return arvore;
}

void imprimir_preordem(No* no){
 
   if(no != NULL){
     
      printf("\n%s",no);
      imprimir_preordem(no->esquerda);
      imprimir_preordem(no->direita);
    }
}

void imprimir_simetrica(No* no){
  
   if(no != NULL){
      
      imprimir_simetrica(no->esquerda);
      printf("\n%s",no);
      imprimir_simetrica(no->direita);
    }
}

void imprimir_posordem(No* no){
   
   if(no != NULL){
      
      imprimir_posordem(no->esquerda);
      imprimir_posordem(no->direita);
      printf("\n%s",no);
    }
}


void imprimir_largura(No* no){
  
  Fila* f = criar();
  No *aux = NULL;
  
  
  inserirFila(f,no);
  //while(tamanhoFila > 0) IMPLEMENTAR TAMANHO
  aux = remover(f);
  while(aux){
    
    printf("\n%c", aux->chave);
    
    if(aux->esquerda) inserirFila(f, aux->esquerda);
    if(aux->direita) inserirFila(f, aux->direita);
    
    aux = remover(f);
  }
}

void imprimirLarguraComFilaLocal(No* no){
  //Implementando fila aqui
  No* fila[100];
  int inicio =0, fim =0;
  
  fila[fim++] = no;
  
  while(inicio < fim && inicio < 100){
    No* atual = fila[inicio++];
    printf("\n%c", atual->chave);
    
    if(atual->esquerda)
      fila[fim++]=atual->esquerda;
    if(atual->direita)
      fila[fim++]=atual->direita;
  }
}