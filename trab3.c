#include<stdio.h>

int MDC (int A, int B);
double MULT (double dA, double dB);
double SOMA (double dA, double dB);
double DIVISAO (double dA, double dB);
double SUB (double dA, double dB);
double POT (double dA, int B);
double RAIZ(double A);
int FATP(int A);
int FATI(int A);
int FAT (int A);
void BHASKARA(double dA, double dB, double dC);
double MOD (double dA);


int main()
{
	int opcao = 0; 
	int A = 0; 
	int B = 0;
	int resultado = 0;
	double dA = 0.0;
	double dB = 0.0;
	double dC = 0.0;
	double result = 0.0;
	double num = 0.0;
	double x1 = 0.0;
	double x2 = 0.0;
	
	
	do{
		
		printf("|-------------------------------------------|\n");
		printf("|Bem-vindo(a) a Calculadora 1.0.............|\n");
		printf("|Escolha uma opcao..........................|\n");
		printf("|-------------------------------------------|\n");
		printf("|0 - MDC....................................|\n");
		printf("|1 - MMC....................................|\n");
		printf("|2 - Soma...................................|\n");
		printf("|3 - SAIR...................................|\n");
		printf("|4 - Divisao................................|\n");
		printf("|5 - Subtracao..............................|\n");
		printf("|6 - Potenciacao............................|\n");
		printf("|7 - Multiplicacao..........................|\n");
		printf("|8 - Raiz Quadrada..........................|\n");
		printf("|9 - Fatorial Duplo (N!!)...................|\n");
		printf("|10- Fatorial Simples (N!)..................|\n");
		printf("|11- Equacao do Segundo Grau................|\n");
		printf("|-------------------------------------------|\n");
	
		scanf("%d",&opcao);
		
		switch(opcao)
		{
			case 0:
			
				printf("Voce selecionou a opcao MDC\n");
			
				printf("Favor insira o primeiro valor\n");
				scanf("%d",&A);
			
				printf("Favor insira o segundo valor\n");
				scanf("%d",&B);
			
				resultado = MDC(A, B);
				printf("O valor do MDC de %d e %d e de %d\n", A, B, resultado);
			
			break;
			
			case 1: 
			
			printf("Voce selecionou a opcao MMC\n");
			
			printf("Favor insira o primeiro valor\n");
			scanf("%d",&A);
			
			printf("Favor insira o segundo valor\n");
			scanf("%d",&B);
			
			resultado = MOD(MULT(A, B)) / MDC(A, B);
			printf("O valor do MMC de %d e %d e de %d\n", A, B, resultado);
			
			break;
			
			case 2: 
			
			printf("Voce selecionou a opcao soma\n");
			
			printf("Favor insira um primeiro valor\n");
			
			scanf("%lf",&dA);
			
			printf("Insira outro valor para somar ao primeiro\n");
			
			scanf("%lf",&dB);
			
			result = SOMA(dA, dB);
			printf("O resultado da sua soma e igual a %.5lf\n",result);
			
			break;
			
			case 3:
			
			printf("Obrigada por usar minha calculadora super legal :]]]]\n");
			
			break;
			
			case 4: 
			
			printf("Voce selecionou a opcao divisao\n");
			printf("Favor insira um valor para dividir\n");
			
			scanf("%lf",&dA);
			
			printf("Insira outro valor para dividir o primeiro\n");
			
			scanf("%lf",&dB);
			
			while(dB == 0)
			{
				printf("Nao e possivel fazer uma divisao por zero\n");
				printf("Favor digite um valor diferente de zero\n");
				scanf("%lf",&dB);
			}
			
			result = DIVISAO(dA, dB);
			printf("O resultado da divisao e de %.5lf\n",result); 

			break;
			
			case 5: 
			
			printf("Voce selecionou a opcao de subtracao\n");
			printf("Favor digite um valor\n");
			
			scanf("%lf",&dA);
			
			printf("Por favor, digite outro valor\n");
			
			scanf("%lf",&dB);
			
			result = SUB(dA, dB);
			
			printf("O valor da subtracao e de %.5lf\n",result);
			
			break;
			
			case 6: // ? // 
			
			printf("Voce selecionou a opcao de potenciacao\n");
			printf("Digite um valor para a base\n");
			
			scanf("%lf",&dA);
			
			printf("Digite outro valor para ser o expoente\n");
			
			scanf("%d",&B);
			
			while(B < 0)
			{
				printf("Nao e possivel realizar o calculo com o expoente negativo\n");
				printf("Favor digite um valor positivo\n");
				scanf("%d",&B);
			}
			
			result = POT(dA, B);
			
			printf("O valor da potenciacao e de %.5lf\n",result);
			
			break;
			
			case 7: 
			
			printf("Voce selecionou a opcao da multiplicacao\n");
			printf("Por favor, digite um valor para multiplicar\n");
			
			scanf("%lf",&dA);
			
			printf("Digite outro valor\n");
			
			scanf("%lf",&dB);
			
			result = MULT(dA, dB);
			
			printf("O resultado da multiplicacao e de %.5lf\n",result);
			
			break;
			
			case 8: 
			
			printf("Voce selecionou a opcao de raiz quadrada\n");
			printf("Favor digite um valor positivo para calcular sua raiz\n");
			
			scanf("%lf",&dA);
			
			while(dA < 0)
			{
				printf("Impossivel calcular a raiz de numero negativo\n");
				printf("Favor insira um valor positivo\n");
				scanf("%lf",&dA);
			}

			result = RAIZ(dA);
			printf("O valor da raiz de %.0lf e de %.5lf\n",dA,result);
			
			break;
			
			case 9: 
			
			printf("Voce selecionou a opcao do fatorial duplo\n");
			printf("Favor digite um valor para calcular seu fatorial duplo\n");
			
			scanf("%d",&A);
			
			while(A < 0)
			{
				printf("Nao e possivel calcular o fatorial duplo de um numero negativo\n");
				printf("Por favor, insira um valor positivo\n");
				scanf("%d",&A);
			}
			
			if(A % 2 == 0)
			{
				resultado = FATP(A);
				printf("O valor do fatorial duplo de %d e %d\n",A,resultado);
			}
			else
			{
				resultado = FATI(A);
				printf("O valor do fatorial duplo de %d e %d\n",A, resultado);
			}
			
			break;
			
			case 10: 
			
			printf("Voce selecionou a opcao do fatorial simples\n");
			printf("Favor digite um numero para calcular seu fatorial\n");
			
			scanf("%d",&A); 
			
			resultado = FAT(A);
			
			printf("O valor do fatorial simples de %d e de %d\n",A,resultado);
			
			break;
			
			case 11: 
			
			printf("Voce selecionou a opcao da equacao do segundo grau (A*x^2 + B*x + C = 0)\n");
			printf("Favor digite o primeiro valor para A\n");
			
			scanf("%lf",&dA);
			
			while(dA == 0)
			{
				printf("Nao e possivel calcular as raizes com o A igual a zero\n");
				printf("Digite outro valor para A\n");
				scanf("%lf",&dA);
			}
			
			printf("Favor digite outro valor para B\n");
			
			scanf("%lf",&dB);
			
			printf("Favor digite outro valor para C\n");
			
			scanf("%lf",&dC);
			BHASKARA(dA, dB, dC);
			
			break;

			default:
			
				printf("Favor digite um valor valido\n");
			
			break;
		}
	}
	while(opcao != 3);
	
	return(0);
	
}

int MDC (int A, int B)
{
	int resto = 0;
	
	do{	

		resto = A % B;
		A = B;
		B = resto; 
		
	}while(resto != 0);
	
	return(A);
}

double MULT (double dA, double dB)
{
	double resultado = 0.0;
	
	resultado = dA * dB;
	
	return(resultado);
}

double SOMA (double dA, double dB)
{
	double resultado = 0.0;
	
	resultado = dA + dB;
	
	return(resultado);
}

double DIVISAO (double dA, double dB)
{
	double resultado = 0;
	
	resultado = dA / dB;
	
	return(resultado);
}

double SUB (double dA, double dB)
{
	double resultado = 0;
	
	resultado = dA - dB;
	
	return(resultado);
}

double POT (double dA, int B)
{
	double resultado = 1.0;
	
	for(int i = 0;i < B;i++)
	{
		resultado = resultado * dA;
	}
	
	return(resultado);
}

double RAIZ(double dA)
{
	double novo_x = 0;
	double x = 0;
	
	x = dA;
	for(int i = 0; i < 100; i++)
	{
		novo_x = 0.5 * (x + dA / x);
		x = novo_x;
	}
	
	return(x);
}

int FATP(int A)
{
	int resultado = 1;
	int i;
	
	for(int i = 2; i <= A; i = i + 2) 
	{
		resultado = resultado * i;
	}
	return(resultado);
}

int FATI(int A)
{
	int resultado = 1; 
	
	for(int i = 1; i <= A; i = i + 2)
	{
		resultado = resultado * i;
	}
	
	return(resultado);
}

int FAT (int A)
{
	int resultado = 1; 
	
	for(int i = 1; i <= A; i++)
	{
		resultado = resultado * i;
	}
	
	return(resultado);
}

void BHASKARA(double dA, double dB, double dC)
{
	double delta = 0.0;
	double x1 = 0.0;
	double x2 = 0.0;
	
	delta = POT(dB, 2) - 4 * dA * dC;
			
		if(delta < 0 || dA == 0)
		{
			printf("Delta negativo, impossivel calcular a raiz\n");
		}
		else
		{
			x1 = ((-1 * dB) + RAIZ(delta))/ (2 * dA);
			x2 = ((-1 * dB) - RAIZ(delta))/ (2 * dA);
			
			printf("As raizes da equacao correspondem a %.5lf e %.5lf\n",x1, x2);
		}

}

double MOD (double A)
{	
	if(A > 0.0)
	{
		return(A);
	}
	else
	{
		return(-1.0 * A);
	}
}