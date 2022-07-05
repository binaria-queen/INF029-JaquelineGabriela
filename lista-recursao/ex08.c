#include <stdio.h>

int mdc();

int main(void){

  int x = 0;
  int y = 0; 
  int result = 0;
  
  printf("Insira o 1º valor: ");
  scanf("%d", &x);
  printf("Insira o 2º valor: ");
  scanf("%d", &y);
  result = mdc(x, y);
  printf("O MDC é: %d\n", result);
}

int mdc(int n1, int n2) {
	if( n2 == 0) {
		return n1;
	}else
	  return mdc(n2, n1%n2);
}