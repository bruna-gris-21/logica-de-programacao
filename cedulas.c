#include<stdio.h>

int main()
{
	int Q100 = 0;
    int Q50 = 0;
    int Q20 = 0;
    int Q10 = 0;
    int Q5 = 0;
    int Q2 = 0;
    int Q1 = 0;
    int N = 0;
    int resto = 0;
    
	printf("Insira um valor\n");
    scanf("%d",&N);
    
    do
    {
        resto = N % 100;
		N = resto;
    
    }while(resto != 0);
    
    printf("%d");
    printf("%d nota(s) de R$ 100,00\n");
    printf("%d nota(s) de R$ 50,00\n");
    printf("%d nota(s) de R$ 20,00\n");
    printf("%d nota(s) de R$ 10,00\n");
    printf("%d nota(s) de R$ 5,00\n");
    printf("%d nota(s) de R$ 2,00\n");
    printf("%d nota(s) de R$ 1,00\n");
    
    return 0;
}