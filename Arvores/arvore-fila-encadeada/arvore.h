#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

typedef struct No{
    char chave;
    struct No* esquerda;
    struct No* direita;

} No;

No* criar_arvore(char chave);

No* inserir(No* arvore, No* esquerdo, No* direito);

void imprimir_preordem(No* no);
void imprimir_simetrica(No* no);
void imprimir_posordem(No* no);
void imprimir_largura(No* no);
void imprimirLarguraComFilaLocal(No* no);
#endif // ARVORE_H_INCLUDED

