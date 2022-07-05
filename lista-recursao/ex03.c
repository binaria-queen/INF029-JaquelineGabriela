#include <stdio.h>

int inverter();

int main(void){

  int num, invertido;
  printf("%d", inverter(1230));
}

int inverter(int num){
  
  int result;
  if(num >= 0 && num < 10) 
    return num;
  else {
    printf("%d", num % 10);
    num = num / 10;
    return inverter(num);
  }
}
