#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvoreBB.h"

int main() {

  ArvoreBB* arvore = criarArvore();
  No* no;
  inserirArvore(arvore,1);
  inserirArvore(arvore,10);
  inserirArvore(arvore,20);
  inserirArvore(arvore,2);

  printf("\nChave: %i",buscar(arvore, 1));
  printf("\nChave: %i",buscar(arvore, 10));

  imprimir_simetrica(arvore->raiz);
  
  printf("\n");

  return 0;
}