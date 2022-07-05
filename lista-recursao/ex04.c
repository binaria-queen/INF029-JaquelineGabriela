#include <stdio.h>

int somaVet();

int main(void){

  int vetor[] = {1, 2, 3, 6, 9};
  
  int tam = sizeof(vetor) / sizeof(int);
  int result;
  result = somaVet(vetor, tam);
  printf("A soma dos elementos do vetor eh %d", result);
}

int somaVet(int vetor[], int tam){
  
  if(tam == 1){
    return vetor[tam-1];
  }else{
    return vetor[tam-1] + somaVet(vetor, tam-1);
  } 
}

