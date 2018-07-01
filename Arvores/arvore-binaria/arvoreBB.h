#ifndef ARVOREBB_H_INCLUDED
#define ARVOREBB_H_INCLUDED

typedef struct No{
  int chave;
  //Se nao fosse binaria, teria um array de filhos
  struct No* esq;
  struct No* dir;
}No;

typedef struct ArvoreBB{
  No* raiz;
}ArvoreBB;

ArvoreBB* criarArvore();
No* inserirArvore(ArvoreBB* a, int x);
int buscar(ArvoreBB* a, int x);
No* buscarNoDaArvore(No* pt, int x);
No* buscaInterativaNoDaArvore(No* pt, int x);

void imprimir_preordem(No* arvore);
void imprimir_simetrica(No* no);
void imprimir_posordem(No* no);

#endif // ARVOREBB_H_INCLUDED