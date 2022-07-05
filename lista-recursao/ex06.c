#include <stdio.h>

int exponencial(int base, int expoente){
    if (expoente > 0)
        return base * exponencial(base, expoente - 1);
    return 1;
}

int main(){
    int base, expoente;
    printf("Digite a base: ");
    scanf("%d", &base);
    printf("Digite o expoente: ");
    scanf("%d", &expoente);

    printf("Resutado: %d", exponencial(base, expoente));
    
    return 0;
}