#include <stdio.h>

void sequencia();

int main(void){
  
  int num;
  
  printf("Digite um numero: ");
  scanf("%d", &num);
  sequencia(num);
}

void sequencia(int num){

  if(num >= 0){
    sequencia(num - 1);
    if(num % 2 == 1)
      printf("%d ", num);
  }
}