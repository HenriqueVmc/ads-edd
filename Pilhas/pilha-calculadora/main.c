#include "pilha.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void soma(Pilha *p);
void subtracao(Pilha *p);
void multiplicacao(Pilha *p);
void divisao(Pilha *p);
void modulo(Pilha *p);
void calcLog(Pilha *p);
void imprimir(Pilha *p);

int main() {
	Pilha *p = criarPilha(10);
	char val[10];
	int cont = 0;
	printf("\n---Calculadora de Pilha---");
	do {
		printf("\n> ");
		scanf(" %s", val);
		if (cont >= 2) {
			cont = 0;
			if (strcmp(val, "+") == 0) {
				soma(p);
				imprimir(p);

			} else if (strcmp(val, "-") == 0) {
				subtracao(p);
				imprimir(p);

			} else if (strcmp(val, "*") == 0) {
				multiplicacao(p);
				imprimir(p);

			} else if (strcmp(val, "/") == 0) {
				divisao(p);
				imprimir(p);

			} else if (strcmp(val, "%") == 0) {
				modulo(p);
				imprimir(p);

			} else if (strcmp(val, "log") == 0) {
				float aux = log(pop(p));
				float res = log(pop(p)) / aux;
				push(p, res);
				imprimir(p);
			} else {
				printf(
					"\nOperador Inválido!\nOperadores disponíveis[ "
					"+,-,*,/,%,log ]");
			}
		} else if (strcmp(val, "sair") == 0) {
		  printf("\nSaindo...");
		  break;
		} else {
			float f = atof(val);
			push(p, f);
			cont++;
		}
		printf("\n");
	} while (1);

	return 0;
}

void soma(Pilha *p) {
	float res = pop(p) + pop(p);
	push(p, res);
}

void subtracao(Pilha *p) {
	float aux = pop(p);
	float res = pop(p) - aux;
	push(p, res);
}

void multiplicacao(Pilha *p) {
	float res = pop(p) * pop(p);
	push(p, res);
}

void divisao(Pilha *p) {
	float aux = pop(p);
	float res = pop(p) / aux;
	push(p, res);
}

void modulo(Pilha *p) {
	int aux = (int)pop(p);
	int res = (int)pop(p) % aux;
	push(p, (float)res);
}

void calcLog(Pilha *p) {
	float aux = log(pop(p));
	float res = log(pop(p)) / aux;
	push(p, res);
}

void imprimir(Pilha *p) {
	printf("\n= %.2f", pop(p));
}
