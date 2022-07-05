#include <stdio.h>

int fib(int n)
{
    if (n == 1)
        return 0;
    else if (n == 2)
    {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int x;
    printf("Digite um número: ");
    scanf("%d", &x);

    for (int i = 1; i <= x; i++)
    {
        printf("%d, ", fib(i));
    }

    return 0;
}