#include "lista.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Lista *criarLista() {
	Lista *l = malloc(sizeof(Lista));
	l->ptLista = malloc(sizeof(No));

	return l;
}

No *buscaEncadeada(Lista *l, int mat, No **ant) {
	
	No *pont = NULL;
	*ant = l->ptLista;
	No *ptr = l->ptLista->prox;

	while (ptr != NULL) {
		if (ptr->mat < mat) {
			*ant = ptr;
			ptr = ptr->prox;

		} else if (ptr->mat == mat) {
			pont = ptr;
			ptr = NULL;
			
		} else {
			ptr = NULL;
		}

		return pont;
	}
}

No *inserir(Lista *l, int mat, char * nome, double nota) {
	//printf("entrou no inserir");
	No *ant = l->ptLista;
	No *pont = NULL;
	No *ptr = NULL;

	pont = buscar(l, mat);

	if (pont == NULL) {
		
		ptr = malloc(sizeof(No));

		ptr->mat = mat;
		//isso no existe ptr->nome = nome;
		strcpy(ptr->nome, nome);
		ptr->notaFinal = nota;

		ptr->prox = ant->prox;
		ant->prox = ptr;
		
		return ptr;
	}else
		return NULL;
}

No *buscar(Lista *l, int mat) {
	No *ant;

	return buscaEncadeada(l, mat, &ant);
}

No *buscarByIndice(Lista *l, int i) {
	
	No *ptr = l->ptLista->prox;//primeiro elemento
	No *buscado = NULL;
	int cont = 0;

	while (ptr) {
		if (cont++ == i) {// vou contando até achar o elemento q qero(i)
			buscado = ptr;
		}
		ptr = ptr->prox;//increnta elemento
	}

	return buscado;
}

int remover(Lista *l) {
	
	No *ant = l->ptLista;
	No *pont;
	int mat=0;
	
	printf("\n---Remover por Matricula---\n");
	printf("\nMatricula: ");
	scanf("%i", &mat);
	
	pont = buscar(l, mat);

	if (pont != NULL) {
		ant->prox = pont->prox;
		free(pont);
		return 1;
	}
	return 0;
}

No *primeiro(Lista *l) {
	return l->ptLista->prox;
}

No *ultimo(Lista *l) {
	No *ptr = l->ptLista->prox;

	while (ptr && ptr->prox) {
		ptr = ptr->prox;
	}

	return ptr;
}

int tamanho(Lista *l) {
	int tamanho = -1;
	No *atual = l->ptLista;
	while (atual != NULL) {
		atual = atual->prox;
		tamanho++;
	}
	return tamanho;
}

void destruirLista(Lista *l) {
	No *atual = l->ptLista;
	while (atual != 0) {
		No *tmp = atual;
		atual = tmp->prox;
		free(tmp);
	}
	free(l);
}

int menu(){
	int op = 0;
	
	printf("\n---Menu---\n");
	printf("\n1- Cadastrar Aluno");
	printf("\n2- Imprimir Todos os Alunos");
	printf("\n3- Primeiro Aluno da Lista");
	printf("\n4- Ultimo Aluno da Lista");
	printf("\n5- Remover Aluno da Lista");
	printf("\n6- Destruir Lista de Alunos");
	printf("\nOpcao: ");
	scanf("%i", &op);
	
	return op;
}

void cadastrarAluno(Lista* l){
	
	int mat;
	double nota;
	char nome[100];
	
	printf("\n---Cadastro de Alunos---");

	printf("\nNome: ");
	scanf("%s", nome);
	printf("\nMatricula: ");
	scanf("%i", &mat);
	printf("\nNota Final: ");
	scanf("%d", &nota);
	
	if(inserir(l, mat, nome, nota)){
		
		printf("\n%s inserido na lista\n",buscar(l,mat)->nome);
	}
	
	else if(!inserir(l, mat, nome, nota)){
		
		printf("\nerro:[%s já foi inserido na lista]",buscar(l,mat)->nome);
		
	}
	}

void imprimirTdsAlunos(Lista* l){
	int i = 0;
	if(tamanho(l) > 0){
		printf("\n\n---Busca de Alunos---");
		printf("\nExistem %d elementos na lista", tamanho(l));
		
		do{
			printf("\n Nome: %s - Matricula: %i",buscarByIndice(l,i)->nome, buscarByIndice(l,i)->mat);
		
			i++;
			
		}while(buscarByIndice(l,i));
	}else
		printf("\nNão Existem elementos na lista"); 
}