#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct No{
	// exemplo usando chave inteira
	struct No* prox;
	int chave;

} No;

typedef struct Lista{
  No* ptLista; // elemento que está na lista
} Lista;

// cria uma lista com tamanho definido
Lista* criarLista();
// destroi a lista
void destruir_lista(Lista* l);
// retorna o tamanho da lista (numero de elementos inseridos)
int tamanho(Lista* l);
// retorna quantidade maxima de elementos
No* buscar(Lista* l, int x);
// insere um dado pela (chave x). retorna NULL em caso de falha
No* inserir(Lista* l, int x);
// remove dado da lista
void remover(Lista* l, int x);
// retorna o primeiro da lista
No* primeiro(Lista* l);
// retorna o ultimo da lista
No* ultimo(Lista* l);
// retorna um elemento pela posicao
No* buscar_por_indice(Lista* l, int i);

No* buscaEncadeada(Lista* l, int x, No** ant);

#endif // LISTA_H_INCLUDED