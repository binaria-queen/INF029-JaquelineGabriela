#include <stdio.h>

int tribonacci();

int main(){
  
  int num, result;
  
  printf("Insira um numero: ");
  scanf("%d", &num);
  result = tribonacci(num);
  printf("O termo na posição %d é %d:", num, result);
}

int tribonacci(int numero){
  
  int tribo;
  if (numero == 0 || numero == 1 ){
    return 0;
  }else if (numero == 2){
    return 1;
  }else
    return tribonacci(numero - 1) + tribonacci(numero - 2) + tribonacci(numero - 3);
}