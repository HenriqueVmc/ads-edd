#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

int zero = 0; //.:ENCERRA LOOP DO MENU() SE HOUVER DIVISÃO POR ZERO:.

No *criar_arvore(char *chave) {
    No *no = malloc(sizeof (No));
    no->token = chave;
    no->esquerda = NULL;
    no->direita = NULL;
    no->livre = 1;

    return no;
}

void destruir_arvore(No *no) {
    if (no->direita)
        destruir_arvore(no->direita);
    if (no->esquerda)
        destruir_arvore(no->esquerda);

    free(no->token);
    free(no);
}

No *inserir(No *arvore, No *esquerdo, No *direito) {
    arvore->esquerda = esquerdo;
    arvore->direita = direito;

    return arvore;
}

void imprimir_preordem(No *no) {
    if (no != NULL) {
        printf("%s ", no->token);
        imprimir_preordem(no->esquerda);
        imprimir_preordem(no->direita);
    }
}

int menu() {
    int op = 0;
    if (zero != 1) {
        printf("\n\t--- MENU ---\n");
        printf(
                "\n1-Calcular expressão\n2-Calcular expressão passo a "
                "passo\n3-Mostrar equivalente em notação polonesa\n4-Mostrar "
                "expressão parentizada\n5-Verificar se existe divisão por "
                "zero\n6-Ler outra expressão do teclado\n");
        printf("\n> ");
        scanf("%i", &op);
        return op;
    }
    zero = 0;
    return 6;
}

int calcExpressao(No *no) {
    if (no == NULL || zero == 1)return 0;
    // printf(" %s ",no->token);
    switch (no->token[0]) {
        case '+':
            return calcExpressao(no->esquerda) + calcExpressao(no->direita);

        case '-':
            return calcExpressao(no->esquerda) - calcExpressao(no->direita);

        case '*':
            return calcExpressao(no->esquerda) * calcExpressao(no->direita);

        case '/':
            return calcExpressao(no->esquerda) / calcExpressao(no->direita);

        default:
            return atoi(no->token);
    }
}

int calcExprPassoPasso(No *no) {
    int n1=0, n2=0;
    if (no == NULL || zero == 1)return 0;

    switch (no->token[0]) {
        case '+':
            n1 = calcExprPassoPasso(no->esquerda);
            n2 = calcExprPassoPasso(no->direita);

            printf("%i %s %i = %i\n", n1, no->token, n2, n1 + n2);
            return n1 + n2;

        case '-':
            n1 = calcExprPassoPasso(no->esquerda);
            n2 = calcExprPassoPasso(no->direita);

            printf("%i %s %i = %i\n", n1, no->token, n2, n1 - n2);
            return n1 - n2;

        case '*':
            n1 = calcExprPassoPasso(no->esquerda);
            n2 = calcExprPassoPasso(no->direita);

            printf("%i %s %i = %i\n", n1, no->token, n2, n1 * n2);
            return n1*n2;

        case '/':
            n1 = calcExprPassoPasso(no->esquerda);
            n2 = calcExprPassoPasso(no->direita);

            printf("%i %s %i = %i\n", n1, no->token, n2, n1 / n2);
            return n1 / n2;

        default:
            return atoi(no->token);
    }
}

void imprimeExp(No *no) {
    if (no != NULL) {
        switch (no->token[0]) {
            case '+':
            case '-':
            case '*':
            case '/':
                printf("(");
                imprimeExp(no->esquerda);
                printf("%s", no->token);
                imprimeExp(no->direita);
                printf(")");
                break;
            default:
                printf("%s", no->token);
        }
    }
}

int divPorZero(No *no) {
    int n1, n2, res;
    if (no == NULL)
        return 0;

    switch (no->token[0]) {
        case '+':
            return divPorZero(no->esquerda) + divPorZero(no->direita);

        case '-':
            return divPorZero(no->esquerda) - divPorZero(no->direita);

        case '*':
            return divPorZero(no->esquerda) * divPorZero(no->direita);

        case '/':

            n1 = divPorZero(no->esquerda);
            n2 = divPorZero(no->direita);

            if (n1 <= 0 || n2 <= 0) {
                printf("\nHá divisão por Zero!");
                zero = 1;
                return 0;
            }
            printf("\nNão há divisão por Zero!");
            return n1 / n2;
        default:
            return atoi(no->token);
    }
}