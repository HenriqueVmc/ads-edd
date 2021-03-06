#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct Pilha{
    int M;
    int topo;
    char* dados;
}Pilha;

// cria uma pilha com tamanho definido
Pilha* criarPilha(int tamanho);
// destroi a pilha
void destruirPilha(Pilha* p);
// insere no topo da pilha
void push(Pilha* p, int x);
// remove do topo da pilha
int pop(Pilha* p);
// retorna o tamanho da pilha (numero de elementos inseridos)
int tamanho(Pilha* p);

#endif // PILHA_H_INCLUDED
