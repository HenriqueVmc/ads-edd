#include<stdio.h>
#include<stdlib.h>

void imprime(int val[], int n);
void ordenacaoByInsercao(int val[], int n);
int * preencheVetor(int val[], int n);

//Ordenacao Crescente Metodo de Insercao (Para metodos mais simples)
void ordenacaoByInsercao(int val[], int n){	
	
	
	for(int i=1;i<n;i++){
		
		int eleito = val[i], j=0;
		
		for(j=i-1; j>=0 && val[j]>eleito; j--){
			
			val[j+1]=val[j];			
		}		
		//val[j+1]=eleito;
	}
	
	imprime(val, n);
}

//Preenche Vetor
int * preencheVetor(int val[], int n){
	
	for(int i=0;i<n;i++){
		
		printf("\ninforme o %i valor: ",i+1);
		scanf("%i", &val[i]);
	}
	
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
	
	int val[t];
	
	preencheVetor(val, t);
	ordenacaoByInsercao(val, t);
	
	return 0;	
}
