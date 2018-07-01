#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  
	Pilha *p = criarPilha(10);

	push(p, 2);
	push(p, 4);
	push(p, 12);
	push(p, 15);

	while (tamanho(p) > 0) {
		printf("pop: %d\n", pop(p));
	}

	return 0;
}
