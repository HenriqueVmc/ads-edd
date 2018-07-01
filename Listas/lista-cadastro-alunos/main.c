#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

int main (){

	Lista* l = criarLista();
	int sair =-1;
	do{
		switch(menu()){
			case 0:
			 system("pause");
			break;
			
			case 1:
				cadastrarAluno(l);
			break;
			
			case 2:
				imprimirTdsAlunos(l);
			break;
			
			case 3:
				printf("\nPrimeiro elemento:\n %s", primeiro(l)->nome);
			break;
			
			case 4:
				printf("\nUltimo elemento:\n %s", ultimo(l)->nome);
			break;
			
			case 5:
				if(remover(l) ==1){
					printf("\nRemovido!");
				}else
					printf("\nErro em remover aluno!");
			break;
			
			case 6:
				destruirLista(l);
				printf("\nDestruindo...\n Existem %d elemento na lista", tamanho(l));
			break;
		}
		printf("\n\n1-[ Menu ] ou 0-[ Sair ]: ");
		scanf("%d", &sair);
	}while(sair != 0);
	
	return 0;
}