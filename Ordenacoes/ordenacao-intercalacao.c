#include<stdio.h>
#include<stdlib.h>

void imprime(int val[], int n);
void ordenacaoByIntercalacao(int val[], int aux[], int ini, int fim);
int * preencheVetor(int val[], int n);

//Ordenacao Crescente Metodo de Intercalacao (Marge Sort)
void ordenacaoByIntercalacao(int val[], int aux[], int ini, int fim){	
	
	if(ini < fim){
			
		int meio = (ini+fim)/2;
		
		ordenacaoByIntercalacao(val, aux, ini, meio);
		ordenacaoByIntercalacao(val, aux, meio+1, fim);
		
		//Intercalacao(poderia ser uma funcao)
		int posicao = ini, esquerda = ini, direita = meio+1;
		
		while(esquerda <= meio && direita <= fim){
			
			if(val[esquerda] <= val[direita]){
				
				aux[posicao++] = val[esquerda++];
				/* 
				 aux[posicao++] == aux[posicao]; posicao++;
				 val[esquerda++] == val[esquerda]; esquerda++;
				*/
			}else{
				
				aux[posicao++] = val[direita++];
			}
		}

		while(esquerda <= meio){
			
			aux[posicao++] = val[esquerda++];	
		}
		
		while(direita <= fim){
			
			aux[posicao++] = val[direita++];			
		}
		
		while(ini <= fim){
			
			val[ini] = aux[ini];

			ini++;
		}		
	}
}

//Preenche Vetor
int * preencheVetor(int val[], int n){
	
	for(int i=0;i<n;i++){
		
		printf("\ninforme o %i valor: ",i+1);
		scanf("%i", &val[i]);
	}
	printf("\n");
	
	return val;
}

//Imprime Vetor Ordenado
void imprime(int val[], int n){
	
	printf("\nOrdem Crescente: ");
	for(int i=0;i<n;i++){	
		printf("%i,",val[i]);
	}
}

int main(){
	
	int t;
	printf("\nInforme o Tamanho do Vetor: ");
	scanf("%i",&t);
	
	int val[t], aux[t];
	
	preencheVetor(val, t);
	imprime(val, t);
	ordenacaoByIntercalacao(val, aux, 0,t-1);
	imprime(val, t);
	
	return 0;	
}
