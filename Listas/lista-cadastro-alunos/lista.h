#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct No{

	struct No* prox;
	int mat;
	char nome[100];
	double notaFinal;

} No;

typedef struct Lista{
	
  No* ptLista; 
  
} Lista;

Lista* criarLista();

No* buscar(Lista* l, int mat);

No* inserir(Lista* l, int mat, char* nome, double nota);

int remover(Lista* l);

No* buscaEncadeada(Lista* l, int mat, No** ant);

No* buscarByIndice(Lista *l, int i);

No* primeiro(Lista* l);

No *ultimo(Lista *l);

int tamanho(Lista *l);

void destruirLista(Lista *l);

int menu();

void cadastrarAluno(Lista* l);

void imprimirTdsAlunos(Lista* l);


#endif // LISTA_H_INCLUDED