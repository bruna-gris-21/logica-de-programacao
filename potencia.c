#include<stdio.h>

int potenciacao(int base,int exp);
int main()
{
	int result = 1;
	int base = 0;
	int exp = 0;
	
	printf("favor digite um valor para a base\n");
	
	scanf("%d",&base);
	
	printf("digite outro valor para o expoente\n");
	
	scanf("%d",&exp);
	
	for(int i = 0;i < exp;i++)
	{
		result = result * base;
	}
	
	printf("seu resultado e de %d\n",result);
	
	return(result);
	
}