#include "arvore.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // habilitar_log();
    printf("-Processador de expressoes aritmeticas-\n");
    while (1) {
        printf("\n= ");
        memset(buffer, 0, MAX_BUFFER);
        fgets(buffer, sizeof (buffer), stdin);
        No *no = gerar_arvore(buffer);
        if (no) {
            printf("-Expressao carregada com  sucesso-\n");
            // printf("%s",no->token);//raiz(operador)
            int op = 0;
            do {
                op = menu();
                switch (op) {
                    case 1:
                        printf("\nResultado: %i", calcExpressao(no));
                    break;
                    case 2:
                        calcExprPassoPasso(no);
                    break;
                    case 3:
                        imprimir_preordem(no);
                    break;
                    case 4:
                        imprimeExp(no);
                    break;
                    case 5:
                        divPorZero(no);
                    break;
                    case 6:
                        destruir_arvore(no);
                    break;
                    default:
                        printf("\nOpção Inválida!");
                        destruir_arvore(no);
                        op = 6;
                    break;
                }
            } while (op != 6);
        }
    }
    return 0;
}