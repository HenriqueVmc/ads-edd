#include "compromisso.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	Lista *l = criar(100);

	int op = 0;
	do {
		op = menu();
		switch (op) {
		// Sair
		case 0:
			printf("\nSaindo...");
			return 0;
			break;

		// Listar All Compromissos
		case 1:
			listarTds(l);
			break;

		// Listar Compromissos para hoje
		case 2:
			listarHj(l);
			break;

		// Cadastrar Compromissos
		case 3:
			if (cadastrar(l)) {
				printf("\nCadastro realizado!");
			} else
				printf("\nErro ao cadastrar");
			break;

		// Marcar compromisso como terminado ou cancelado
		case 4:
			marcar(l);
			break;

		// Remover Compromisso
		case 5:
			if (remover(l)) {
				printf("\nRemovido!");
			} else
				printf("\nErro ao remover");
			break;
		default:
			printf("\nErro: Opcao Invalida");
			break;
		}
	} while (op != 0);

	return 0;
}
