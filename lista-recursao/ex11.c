#include <stdio.h>

int multiplica();
int main(void) {
 
  int num1, num2, result;
  
  printf("Insira o 1º numero: ");
  scanf("%d",&num1);
  printf("Insira o 2º numero: ");
  scanf("%d",&num2); 
  
  result = multiplica(num1, num2);
  
  printf("%d * %d = %d", num1, num2, result);
}

int multiplica(int n1,int n2) {
  
  if(n1 == 0)
    return 0;
  else
    return n2 + multiplica(n1 - 1, n2);
}
