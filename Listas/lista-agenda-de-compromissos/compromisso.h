#ifndef COMPROMISSO_H_INCLUDED
#define COMPROMISSO_H_INCLUDED

typedef struct No{
	
    char descricao[30];
    char status[30];
    int data[3];
    int horas[3];

} No;

typedef struct Lista{
    
  No* compromisso;
  int tamanho;
  int limite; 
  
} Lista;

Lista* criar(int tamanho);

int tamanho(Lista* l);

void listarHj(Lista* l);

void listarTds(Lista* l);

int cadastrar(Lista* l);

void marcar(Lista* l);

void cancelar(Lista* l);

void concluido(Lista* l);

int getIndexByDesc(Lista* l, char* desc);

int remover(Lista* l);

void ordenacaoByInsercao(Lista* l, int index);

char* getMes(int mes);

int comparaDataHora(No* comp1, No*comp2);

int verificarData(Lista* l, int index);

int verificarHoras(Lista* l, int index);

int menu();

#endif /* COMPROMISSO_H */
