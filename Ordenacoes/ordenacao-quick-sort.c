#include<stdio.h>
#include<stdlib.h>

//int * preencheVetor(int val[], int n);

void imprime(int v[], int n);
void ordenacaoQuickSort(int v[10], int ini, int fim);

//Ordenacao Quick Sort(o mais Rápido)
void ordenacaoQuickSort(int v[10], int ini, int fim){	
		
	//if(ini <= fim){
		
		/* Sorteando o Pivo
		int sorteado = ini + rand() % (fim - ini);
		int tmp = v[sorteado];
		v[sorteado] = v[ini];
		v[ini] = tmp;*/
		
		int pivo = v[ini];		
		//int i = ini + 1;
		int i = ini, aux=ini;
		int j = fim;
		
		printf("\nPivo: %i\n", pivo);
		/*while(i < j){
			
			while(v[i] < pivo){
				
				i++;
			}
			
			while(v[j] > pivo){
				
				j--;
			}
			
			if(i <= j){
				
				int aux = v[i];
				v[i] = v[j];
				v[j] = aux;
				
				i++;
				j--;
			}	
		}
			
		v[i] = v[j];
		v[j] = pivo;	
		
		imprime(v, 10);
				
		ordenacaoQuickSort(v, ini, j-1);		
		ordenacaoQuickSort(v, j+1, fim);					
	}*/
	//return j;
		do{
			while (v[i] < pivo) i = i + 1;
			while (v[j] > pivo) j = j - 1;
		
			if(i <= j){
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
				i = i + 1;
				j = j - 1;
			}
		}while(j > i);
	
		imprime(v,10);
		if(ini < j) ordenacaoQuickSort(v, ini, j);
		if(i < fim) ordenacaoQuickSort(v, i, fim);	
}

/*Preenche Vetor
int * preencheVetor(int v[], int n){
	
	for(int i=0;i<n;i++){
		
		printf("\ninforme o %i valor: ",i+1);
		scanf("%i", &v[i]);
	}
	
	return v;
}*/

//Imprime Vetor Ordenado
void imprime(int v[], int n){
		
	for(int i=0;i<10;i++){	
		printf("%i ",v[i]);
	}
	printf("\n");
}

int main(){
	
	//srand((usigned) time(NULL));
	
	int v[] = {4,9,3,7,6,10,5,8,2,1};
	int n = 10;
		
	imprime(v, n);
	
	ordenacaoQuickSort(v, 0, n-1);

	imprime(v, n);
	
	return 0;	
}
