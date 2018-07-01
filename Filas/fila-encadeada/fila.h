#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

typedef struct No{
    int tamanho;
    int chave;
    struct No* prox;
}No;

typedef struct Fila{
  No* ptFila; // elemento que está na lista
} Fila;

Fila* criar();

void destruir(Fila* f);

No* inserir(Fila* f, int x);

No* remover(Fila* f);

int tamanho(Fila* f);

#endif // FILA_H_INCLUDED

