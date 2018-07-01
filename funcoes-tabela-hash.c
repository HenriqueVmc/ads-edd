#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//TABELA HASH COM 256 POSICOES
char* tabela [256];

int hash(char* str){

  //char sem sinal (byte)
  unsigned char val = 0;

  //Função de HASH: pegar byte por byte e fzr XOR(Somá-los)
  for(int i = 0; i < strlen(str); i++){
      unsigned char byte = str[i];
      val ^= byte; //XOR -> ^= 
  }
  return val;
}

//Inserir chave
void inserir(char* chave, char* val){
  //tratar mlhr as coolisões dps
  tabela [hash(chave)] = val;
}
//Buscar
char* buscar(char* chave){

  return tabela[hash(chave)];
}

int main(void) {
  printf("--- Função Hash(XOR) ---\n");

  printf("Teste -> %i\n", hash("Teste"));

  inserir("um", "one");  
  inserir("dois", "two");

  printf("\n--- Buscar ---\n");
  printf("Um -> %s\n", buscar("um"));
  printf("Dois -> %s\n", buscar("dois"));
  printf("Três -> %s\n", buscar("tres"));

  return 0;
}
