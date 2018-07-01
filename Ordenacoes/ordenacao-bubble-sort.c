#include<stdio.h>
#include<stdlib.h>

void imprime(int val[], int n);
void bubbleSort(int val[], int n);
int * preencheVetor(int val[], int n);

//Ordenacao Crescente Metodo Bolha
void bubbleSort(int val[], int n){	
	
	int temp=0;
	
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(val[j] > val[j+1]){
				temp = val[j];
				val[j]=val[j+1];
				val[j+1]=temp;
			}
		}		
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
	printf("\ninforme o Tamanho do Vetor: ");
	scanf("%i",&t);
	
	int val[t];
	
	preencheVetor(val, t);
	bubbleSort(val, t);
	
	return 0;	
}
