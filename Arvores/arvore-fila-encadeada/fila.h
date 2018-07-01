#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

typedef struct NoFila{
    void *dado;
    struct NoFila* prox;
}NoFila;

typedef struct Fila{
  NoFila* inicio;
  NoFila* fim;
} Fila;

Fila* criar();

void destruir(Fila* f);

void* inserirFila(Fila* f, void *dados);

void* remover(Fila* f);

int tamanho(Fila* f);

#endif // FILA_H_INCLUDED


