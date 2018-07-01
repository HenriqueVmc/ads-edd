#include "compromisso.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int menu() {
	int op;

	printf(
		"\n---Menu---\n"
		"\n1- Listar todos os compromissos"
		"\n2- Listar compromissos para hoje"
		"\n3- Cadastrar compromisso"
		"\n4- Marcar compromisso como terminado ou cancelado"
		"\n5- Remover compromisso"
		"\n0- Sair");

	printf("\nInforme uma opcao: ");
	scanf(" %i", &op);
	// system("clear");

	return op;
}

int tamanho(Lista *l) {
	return l->tamanho;
}

Lista *criar(int tamanho) {
	Lista *l = malloc(sizeof(Lista));

	l->compromisso = malloc(sizeof(No) * tamanho);
	l->tamanho = 0;
	l->limite = tamanho;

	return l;
}

int cadastrar(Lista *l) {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	if (tamanho(l) < (l->limite)) {
		int index = tamanho(l);

		printf("\n---Cadastro de Compromisso---\n");
		printf("\nDescricao: ");
		scanf(" %[^\n]s", l->compromisso[index].descricao);
		do {
			printf("\n---Data---\n");
			printf("\nDia: ");
			scanf("%i", &l->compromisso[index].data[0]);

			printf("\nMes: ");
			scanf("%i", &l->compromisso[index].data[1]);

			printf("\nAno: ");
			scanf("%i", &l->compromisso[index].data[2]);

		} while (!verificarData(l, index));

		do {
			printf("\n---Horario---\n");
			printf("\nHora: ");
			scanf("%i", &l->compromisso[index].horas[0]);

			printf("\nMinutos: ");
			scanf("%i", &l->compromisso[index].horas[1]);

		} while (!verificarHoras(l, index));

		l->compromisso[index].horas[2] = tm.tm_sec;

		sprintf(l->compromisso[index].status, "%s", "Novo");

		l->tamanho = tamanho(l) + 1;

		if (tamanho(l) >= 2) {
			ordenacaoByInsercao(l, 2);
		}
		return 1;
	}
	return 0;
}

void listarHj(Lista *l) {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
    int i;
	for ( i = 0; i < tamanho(l); i++) {
		No *c = &l->compromisso[i];

		if ((c->data[0] == (tm.tm_mday)) && (c->data[1] == (tm.tm_mon + 1)) &&
			(c->data[2] == (tm.tm_year + 1900))) {
			printf("\nDescricao: %s", c->descricao);
			printf("\nData: %i de %s de %i - Hora: %ih%i:%is",
				c->data[0],
				getMes(c->data[1]),
				c->data[2],
				c->horas[0],
				c->horas[1],
				c->horas[2]);
			printf("\nStatus: %s", c->status);
		}
	}
}

void listarTds(Lista *l) {
	int i;
	for (i=0; i < tamanho(l); i++) {
		No *c = &l->compromisso[i];

		printf("\nDescricao: %s", c->descricao);
		printf(
			"\nData: %i de %s de %i - Hora: %ih%i:%is",
			c->data[0],
			getMes(c->data[1]),
			c->data[2],
			c->horas[0],
			c->horas[1],
			c->horas[2]);
		printf("\nStatus: %s", c->status);
	}
}

void marcar(Lista *l) {
	int op;

	printf("\n---Marcar Compromissos---\n");
	printf("\n1-Cancelar\n2-Concluido\n-0-Sair\n");
	printf("\nInforme uma opcao: ");
	scanf("%i", &op);

	switch (op) {
	case 0:
		break;
	case 1:
		cancelar(l);
		break;
	case 2:
		concluido(l);
		break;
	default:
		printf("\nErro ao Marcar Compromisso");
		break;
	}
}

void cancelar(Lista *l) {
	char desc[30];
	int index = -1;

	printf("\n---Cancelar Compromissos---\n");
	listarTds(l);
	printf("\nInforme a Descricao: ");
	scanf(" %[^\n]s", &desc);
	index = getIndexByDesc(l, desc);
	sprintf(l->compromisso[index].status, "%s", "Cancelado");
}

void concluido(Lista *l) {
	char desc[30];
	int index = -1;

	printf("\n---Concluir Compromissos---\n");
	listarTds(l);
	printf("\nInforme a Descricao: ");
	scanf(" %[^\n]s", &desc);
	index = getIndexByDesc(l, desc);
	sprintf(l->compromisso[index].status, "%s", "Concluido");
}

int remover(Lista *l) {
	int index;
	char desc[30];

	printf("\n---Remover Compromissos---\n");
	listarTds(l);

	printf("\nInforme a Descricao:");
	scanf(" %[^\n]s", &desc);

	index = getIndexByDesc(l, desc);
    int i;
	for (i = index; i < tamanho(l) - 1; i++) {
		l->compromisso[i] = l->compromisso[i + 1];
	}
	l->tamanho = l->tamanho - 1;
	return 1;
}

int getIndexByDesc(Lista *l, char *desc) {
	int index = -1;
    int i;
	for (i = 0; i < tamanho(l); i++) {
		No *c = &l->compromisso[i];
		if (strcmp(c->descricao, desc) == 0) {
			index = i;
			break;
		}
	}
	return index;
}

int comparaDataHora(No *comp1, No *comp2) {
	if (comp1->data[2] > comp2->data[2]) {
		return 1;
	} else if (comp1->data[2] < comp2->data[2]) {
		return 0;
	} else {
		if (comp1->data[1] > comp2->data[1]) {
			return 1;
		} else if (comp1->data[1] < comp2->data[1]) {
			return 0;
		} else {
			if (comp1->data[0] > comp2->data[0]) {
				return 1;
			} else if (comp1->data[0] < comp2->data[0]) {
				return 0;
			} else {
				if (comp1->horas[0] > comp2->horas[0]) {
					return 1;
				} else if (comp1->horas[0] < comp2->horas[0]) {
					return 0;
				} else {
					if (comp1->horas[1] > comp2->horas[1]) {
						return 1;
					} else if (comp1->horas[1] < comp2->horas[1]) {
						return 0;
					} else {
						if (comp1->horas[2] > comp2->horas[2]) {
							return 1;
						} else if (comp1->horas[2] < comp2->horas[2]) {
							return 0;
						} else {
							return 0;
						}
					}
				}
			}
		}
	}
}
void ordenacaoByInsercao(Lista *l, int index) {
	int i;
	for (i = 1; i < tamanho(l); i++) {
		No aux = l->compromisso[i];
		int j = 0;
		for (j = i - 1; j >= 0; j--) {
			if (comparaDataHora(&l->compromisso[j], &l->compromisso[j + 1])) {
				aux = l->compromisso[j];
				l->compromisso[j] = l->compromisso[j + 1];
				l->compromisso[j + 1] = aux;
			}
		}
	}
}

char *getMes(int mes) {
	switch (mes) {
	case 1:
		return "Janeiro";
		break;
	case 2:
		return "Fevereiro";
		break;
	case 3:
		return "Marco";
		break;
	case 4:
		return "Abril";
		break;
	case 5:
		return "Maio";
		break;
	case 6:
		return "Junho";
		break;
	case 7:
		return "Julho";
		break;
	case 8:
		return "Agosto";
		break;
	case 9:
		return "Setembro";
		break;
	case 10:
		return "Outubro";
		break;
	case 11:
		return "Novembro";
		break;
	case 12:
		return "Dezembro";
		break;
	}
}

int verificarData(Lista *l, int index) {
	if (l->compromisso[index].data[2] >= 2018) {
		if (l->compromisso[index].data[1] == 2) {
			if (l->compromisso[index].data[0] > 1 &&
				l->compromisso[index].data[0] <= 28) {
				return 1;
			}
		} else if (
			l->compromisso[index].data[1] == 4 ||
			l->compromisso[index].data[1] == 6 ||
			l->compromisso[index].data[1] == 9 ||
			l->compromisso[index].data[1] == 11) {
			if (l->compromisso[index].data[0] > 1 &&
				l->compromisso[index].data[0] <= 30) {
				return 1;
			}
		} else if (
			l->compromisso[index].data[1] > 0 &&
			l->compromisso[index].data[1] <= 12) {
			if (l->compromisso[index].data[0] > 0 &&
				l->compromisso[index].data[0] <= 31) {
				return 1;
			}
		}
	}
	return 0;
}

int verificarHoras(Lista *l, int index) {
	if (l->compromisso[index].horas[1] >= 0 &&
		l->compromisso[index].horas[1] < 60) {
		if (l->compromisso[index].horas[0] >= 0 &&
			l->compromisso[index].horas[0] < 24) {
			return 1;
		}
	}
	return 0;
}
