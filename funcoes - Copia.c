#include<stdio.h>

double soma(double a, double b);
double subt(double a, double b);
double mult(double a, double b);
double div(double a, double b);
double pot(double base, int expo);

int main()
{

	int opcao = 0;
	double a = 0.0;
	double b = 0.0;
	double base = 0.0;
	int expo = 0;
	double resultado = 0.0;
	
	
	do{
		printf("Selecione um numero de 1 a 6\n");
		scanf("%d",&opcao);
	

		switch(opcao)
		{
		case 1:
			printf("Voce fara uma adicao. Por favor, digite um valor\n");
			scanf("%lf",&a);
	
			printf("Digite outro valor\n");
			scanf("%lf",&b);
			
			resultado = soma(a, b); /* NAO COLOCA O TIPO DAS VARIAVEIS AQUI, SO LA NAS FUNCOES */
			printf("%lf\n",resultado);
		break;
		
		case 2:
			printf("Voce fara uma subtracao. Por favor, digite um valor\n");
			scanf("%lf", &a);
			
			printf("Digite outro valor\n");
			scanf("%lf",&b);
			
			resultado = subt(a, b);
			printf("%lf\n",resultado);
		break;
		
		case 3:
			printf("Voce fara uma multiplicacao. Por favor, digite um valor\n");
			scanf("%lf",&a);
			
			printf("Digite outro valor\n");
			scanf("%lf",&b);
			
			resultado = mult( a, b);
			printf("%lf\n",resultado);
		break;
		
		case 4:
			printf("Voce fara uma divisao. Por favor digite um valor\n");
			scanf("%lf",&a);
			
			printf("Digite outro valor\n");
			scanf("%lf",&b);
			
			resultado = div(a, b);
			printf("%lf\n",resultado);
		
		break;
		
		case 5:
			printf("Voce vai fazer uma potenciacao. Por favor digite um valor para ser a base\n");
			scanf("%lf",&base);
			
			printf("Favor, digite outro valor para ser o expoente\n");
			scanf("%d",&expo);
			
			resultado = pot(base, expo);
			printf("O resultado da potenciacao e de %d\n",resultado);
			
		break;
		}
	}while(opcao != 6);
	
		
	return(0);
}


double soma(double a, double b) /*AQUI COLOCA O TIPO DAS VARIAVEIS */
{
	double resultado = 0;
	
	resultado = a + b;
	
	return(resultado);
}
	
double subt(double a, double b)
	{
		double resultado = 0;
		
		resultado = a - b;
		
		return(resultado);
	}
	
double mult(double a, double b)
	{
		double resultado = 0;
		
		resultado = a * b;
		
		return(resultado);
	}
	
double div(double a, double b)
{
		double resultado = 0;
		
		resultado = a / b;
		
	if(b = 0)
	{
		printf("Impossivel\n");
	}
	else
	{
		resultado = a/b;
	}
	
	return(resultado);
}
	
double pot(double base, int expo)
{
	double resultado = 1;
	
	for(int i =0; i< expo;i++)
	{
		resultado = resultado * base;
	}
	return(resultado);
}