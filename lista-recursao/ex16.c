#include <stdio.h>
#include <stdlib.h>

int fatorial();

int main(void){
    int num, result;
    printf("Informe um numero: ");
    scanf("%d", &num);
    result = fatorial(num);
    printf("%d!! = %d", num, result);
}

int fatorial(int num){
    if(num == 1)
        return 1;
    if(num % 2 != 0)
        return num * fatorial(num - 1);
    return fatorial(num - 1);
}