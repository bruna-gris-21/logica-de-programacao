#include<stdio.h> 

typedef struct ESTOQUE 
{
	char NOME[50];
	double PRECO_U;
	int QUANTIDADE;
	int CODIGO;
} estoque; 

void CADASTRAR (estoque * pont_deposito);
void LISTAR (estoque * pont_deposito);
void BUSCAR (estoque * pont_deposito);
void ATUALIZAR (estoque * pont_deposito);
void CALC_ESTOQUE (estoque * pont_deposito);
void FILTRAR(estoque * pont_deposito);
void FILTRO();
void ORDEM();
void BBSORT_NOME(estoque * pont_deposito, int opcao, int tamanho);
void BBSORT_PRECO(estoque * pont_deposito, int opcao, int tamanho);
void BBSORT_QUANTIDADE(estoque * pont_deposito, int opcao, int tamanho);
void BBSORT_CODIGO(estoque * pont_deposito, int opcao, int tamanho);
int COMPARARP(char * palav_1, char * palav_2);
void IMPRIMIR(estoque * pont_deposito, int tamanho);


int main()
{
	int opcao = 0;
	estoque deposito[1000]; 
	
	do 
	{
		printf("=========================================================\n");
		printf("|============== Bem - Vindo(a) a loja ☺! =============|\n");
		printf("| Escolha o numero correspondente ao que deseja fazer:  |\n");
		printf("| 1 - Cadastrar produtos ===============================|\n");
		printf("| 2 - Listar produtos ==================================|\n");
		printf("| 3 - Buscar produto ===================================|\n"); 
		printf("| 4 - Atualizar quantidade =============================|\n");
		printf("| 5 - Calcular valor em estoque ========================|\n");
		printf("| 6 - Filtrar produtos =================================|\n");
		printf("| 7 - Sair da loja :( ==================================|\n");
		printf("=========================================================\n");
		
		scanf("%d",&opcao);
		
		switch(opcao)
		{
			case 1: 
				printf("Voce selecionou a opcao de CADASTRAR um produto!\n");
				
				CADASTRAR(deposito); 
			break;
			
			case 2:
				printf("Voce selecionou a opcao de LISTAR os produtos em estoque!\n");
				
				LISTAR(deposito); 
			break;
			
			case 3: 
				printf("Voce selecionou a opcao de BUSCAR um produto!\n");
				
				BUSCAR(deposito);
			break;
			
			case 4: 
				printf("Voce selecionou a opcao de ATUALIZAR uma quantidade!\n");
				
				ATUALIZAR(deposito);
			break;
			
			case 5:
				printf("Voce selecionou a opcao para CALCULAR o valor em estoque!\n");
				
				CALC_ESTOQUE(deposito);
			break;
			
			case 6:
				printf("Voce selecionou a opcao para FILTRAR os produtos!\n");
				
				FILTRAR(deposito);
			break;
			
			case 7:
				printf("Voce selecionou a opcao SAIR :(\n");
				printf("Obrigada por utilizar o Estoque!\n");
			break;
			
			default:
				printf("Favor, digite um valor valido.\n"); 
		}
	}
	while(opcao != 7);
	
	return(0);
}

void CADASTRAR (estoque * pont_deposito) 
{
	int quant = 0;
	FILE * arquivo;
	
	arquivo = fopen("arquivo.txt","a"); 
	
	printf("Informe quantos produtos deseja cadastrar\n");
	scanf("%d", &quant);
	
		if(quant > 1000)
		{
			printf("Nao e possivel cadastrar mais de 500 produtos nesse estoque\n");
			printf("\n");
		}
		else
		{
			if(arquivo == NULL)
			{
				printf("Erro: o arquivo nao foi aberto!\n");
			}
			else
			{
				for(int i = 0; i < quant; i++) 
				{
					printf("Por favor, informe o nome do produto;\n");
					scanf(" %[^\n]", pont_deposito[i].NOME);
					printf("Informe o preco do produto:\n");
					scanf("%lf", &pont_deposito[i].PRECO_U);
					printf("Informe a quantidade do produto:\n");
					scanf("%d", &pont_deposito[i].QUANTIDADE);
					printf("Informe o codigo do produto:\n");
					scanf("%d", &pont_deposito[i].CODIGO);
					
					fprintf(arquivo,"%s\n%.2lf\n%d\n%d\n", pont_deposito[i].NOME, pont_deposito[i].PRECO_U, pont_deposito[i].QUANTIDADE, pont_deposito[i].CODIGO);
					
					printf("\n");
					printf("Cadastro concluido!\n");
					
				}
			}
			
			fclose(arquivo);
		}
}
	
void LISTAR (estoque * pont_deposito) 
{
	FILE * arquivo;
	int i = 0;
	
	arquivo = fopen("arquivo.txt","r");
	
	if(arquivo == NULL)
	{
		printf("Erro: o arquivo nao foi aberto!\n");
	}
	else
	{	
		printf("\n");
		printf("==========================================================================\n");
		printf("|== COD ==|===== DESCRICAO ====|==== QUANTIDADE ====|=== VALOR UNIDADE ===|\n");
		while(fscanf(arquivo, "%[^\n]\n%lf\n%d\n%d\n", pont_deposito[i].NOME, &pont_deposito[i].PRECO_U, &pont_deposito[i].QUANTIDADE, &pont_deposito[i].CODIGO) != EOF)
		{
			printf("|%9d|%20s|%20d|%21.2lf|", pont_deposito[i].CODIGO, pont_deposito[i].NOME, pont_deposito[i].QUANTIDADE, pont_deposito[i].PRECO_U);
			i++;
			printf("\n");
		}
		printf("==========================================================================\n");
	}
	
	fclose(arquivo);
}

void BUSCAR (estoque * pont_deposito)
{
	FILE * arquivo;
	int i = 0;
	int codigo = 0;
	
	arquivo = fopen("arquivo.txt","r");
	
	printf("Por favor, digite o codigo do produto que voce procura:\n");
	scanf("%d",&codigo);
	
	if(arquivo == NULL)
	{
		printf("Erro: o arquivo nao foi aberto!\n");
	}
	else
	{
		
		while(fscanf(arquivo, "%[^\n]\n%lf\n%d\n%d\n", pont_deposito[i].NOME, &pont_deposito[i].PRECO_U, &pont_deposito[i].QUANTIDADE, &pont_deposito[i].CODIGO) != EOF)
		{
			if(codigo == pont_deposito[i].CODIGO)
			{
				printf("\n");
				printf("==========================================================================\n");
				printf("|== COD ==|===== DESCRICAO ====|==== QUANTIDADE ====|=== VALOR UNIDADE ===|\n");
				printf("|%9d|%20s|%20d|%21.2lf|\n", pont_deposito[i].CODIGO, pont_deposito[i].NOME, pont_deposito[i].QUANTIDADE, pont_deposito[i].PRECO_U);
			}
			
		i++;
		}
		printf("==========================================================================\n");
	}
	
	fclose(arquivo);
}

void ATUALIZAR (estoque * pont_deposito) 
{
	FILE * arquivo;
	int i = 0;
	int codigo = 0;
	int quantidade = 0;
	
	arquivo = fopen("arquivo.txt","r");
	
	printf("Por favor, digite o codigo do produto que deseja atualizar a quantidade:\n");
	scanf("%d",&codigo);
	
	if(arquivo == NULL)
	{
		printf("Erro: o arquivo nao foi aberto!\n");
	}
	else
	{
		while(fscanf(arquivo, "%[^\n]\n%lf\n%d\n%d\n", pont_deposito[i].NOME, &pont_deposito[i].PRECO_U, &pont_deposito[i].QUANTIDADE, &pont_deposito[i].CODIGO) != EOF)
		{
			if(codigo == pont_deposito[i].CODIGO)
			{
				printf("Produto escolhido:\n");
				printf("==========================================================================\n");
				printf("|== COD ==|===== DESCRICAO ====|==== QUANTIDADE ====|=== VALOR UNIDADE ===|\n");
				printf("|%9d|%20s|%20d|%21.2lf|\n", pont_deposito[i].CODIGO, pont_deposito[i].NOME, pont_deposito[i].QUANTIDADE, pont_deposito[i].PRECO_U);
				printf("==========================================================================\n");
				
				printf("Informe a nova quantidade para o/a %s:\n", pont_deposito[i].NOME);
				scanf("%d",&quantidade);
				pont_deposito[i].QUANTIDADE = quantidade; 
			}
			i++;
		}
		fclose(arquivo);
		
		arquivo = fopen("arquivo.txt","w");
		
		if(arquivo == NULL)
		{
			printf("Erro: o arquivo nao foi aberto!\n");
		}
		else
		{
			for(int x = 0; x < i; x++)
			{
				fprintf(arquivo, "%s\n%.2lf\n%d\n%d\n", pont_deposito[x].NOME, pont_deposito[x].PRECO_U, pont_deposito[x].QUANTIDADE, pont_deposito[x].CODIGO);
			}
			
			fclose(arquivo);
			
			printf("Atualizacao concluida!\n");
		}
	}
}

void CALC_ESTOQUE (estoque * pont_deposito)
{
	FILE * arquivo;
	int i = 0;
	double preco_t = 0.0;
	
	arquivo = fopen("arquivo.txt","r");
	
	if(arquivo == NULL)
	{
		printf("Erro: o arquivo nao foi aberto!\n");
	}
	else
	{
		printf("==========================================================================\n");
		printf("|== COD ==|===== DESCRICAO ====|==== QUANTIDADE ====|=== VALOR UNIDADE ===|\n");
		
		while(fscanf(arquivo, "%[^\n]\n%lf\n%d\n%d\n", pont_deposito[i].NOME, &pont_deposito[i].PRECO_U, &pont_deposito[i].QUANTIDADE, &pont_deposito[i].CODIGO) != EOF)
		{
			printf("|%9d|%20s|%20d|%21.2lf|\n", pont_deposito[i].CODIGO, pont_deposito[i].NOME, pont_deposito[i].QUANTIDADE, pont_deposito[i].PRECO_U);
			preco_t = preco_t + (pont_deposito[i].QUANTIDADE * pont_deposito[i].PRECO_U);
			
			i++;
		}
		printf("==========================================================================\n");
		
		printf("O valor em estoque corresponde a: %.2lf\n", preco_t);
		printf("\n");
	}

	fclose(arquivo);
}

void FILTRAR(estoque * pont_deposito)
{
	FILE * arquivo;
	int i = 0;
	int opcao = 0;
	
	arquivo = fopen("arquivo.txt","r");
	
	if(arquivo == NULL)
	{
		printf("Erro: o arquivo nao foi aberto!\n");
	}
	else
	{
		while(fscanf(arquivo, "%[^\n]\n%lf\n%d\n%d\n", pont_deposito[i].NOME, &pont_deposito[i].PRECO_U, &pont_deposito[i].QUANTIDADE, &pont_deposito[i].CODIGO) != EOF)
		{
			i++;
		}
		fclose(arquivo);
		
		printf("Escolha como ordenar o estoque:\n");
		
		FILTRO();
		scanf("%d",&opcao);
		
		switch(opcao)
		{
			case 1:
				printf("Voce selecionou: Ordenar por Nome!\n");
				
				ORDEM();
				scanf("%d",&opcao);
				
				switch(opcao)
				{
					case 1:
						printf("Voce escolheu ordenar em ordem alfabetica Crescente!\n");
						
						BBSORT_NOME(pont_deposito, opcao, i);
						
						IMPRIMIR(pont_deposito, i);
					break;
					
					case 2:
						printf("Voce escolheu ordenar em ordem alfabetica descrescente!\n");
						
						BBSORT_NOME(pont_deposito, opcao, i);
						
						IMPRIMIR(pont_deposito, i);
					break;
					
					default:
						printf("Favor, digite um valor valido!\n");
				}
			break;
			
			case 2:
				printf("Voce selecionou: Ordenar por Preco!\n");
				
				ORDEM();
				scanf("%d",&opcao);
				
				switch(opcao)
				{
					case 1:
						printf("Voce escolheu ordenar por ordem crescente!\n");
						
						BBSORT_PRECO(pont_deposito, opcao, i);
						
						IMPRIMIR(pont_deposito, i);
					break;
						
					case 2:	
						printf("Voce escolheu ordenar por ordem decrescente!\n");
						
						BBSORT_PRECO(pont_deposito, opcao, i);
						
						IMPRIMIR(pont_deposito, i);
					break;
					
					default:
						printf("Favor, digite um valor valido!\n");
				}
			break;
			
			case 3: 
				printf("Voce selecionou: Ordenar por Quantidade!\n");
				
				ORDEM();
				scanf("%d",&opcao);
				
				switch(opcao)
				{
					case 1:
						printf("Voce escolheu ordenar por ordem crescente!\n");
						
						BBSORT_QUANTIDADE(pont_deposito, opcao, i);
						
						IMPRIMIR(pont_deposito, i);
					break;
					
					case 2:
						printf("Voce escolheu ordenar por ordem decrescente!\n");
						
						BBSORT_QUANTIDADE(pont_deposito, opcao, i);
						
						IMPRIMIR(pont_deposito, i);
					break;
					
					default:
						printf("Favor, digite um valor valido!\n");
				}
			break;
			
			case 4:
				printf("Voce selecionou: Ordenar por Codigo!\n");
				
				ORDEM();
				scanf("%d",&opcao);
				
				switch(opcao)
				{
					case 1:
						printf("Voce escolheu ordenar por ordem crescente!\n");
						
						BBSORT_CODIGO(pont_deposito, opcao, i);
						
						IMPRIMIR(pont_deposito, i);
					break;
					
					case 2:
						printf("Voce escolheu ordenar por ordem crescente!\n");
						
						BBSORT_CODIGO(pont_deposito, opcao, i);
						
						IMPRIMIR(pont_deposito, i);
					break;
					
					default:
						printf("Favor, digite um valor valido!\n");
				}
			break;
				
			default:
				printf("Favor, digite um valor valido!\n");
		}
	}
}

void FILTRO()
{
	printf("=====================================================\n");
	printf("|==================== Ordenaçao ====================|\n");
	printf("| 1 - Ordenar por Nome =============================|\n");
	printf("| 2 - Ordenar por Preco ============================|\n"); 
	printf("| 3 - Ordenar por Quantidade =======================|\n");
	printf("| 4 - Ordenar por Codigo ===========================|\n"); 
	printf("=====================================================\n");
}

void ORDEM()
{
	printf("=====================================================\n");
	printf("|==================== Ordenacao ====================|\n");
	printf("| 1 - Ordenar de forma Crescente ===================|\n");
	printf("| 2 - Ordenar de forma Decrescente =================|\n"); 
	printf("=====================================================\n");
}

void BBSORT_NOME(estoque * pont_deposito, int opcao, int tamanho) 
{
	estoque aux;
	int troca = -1;
	
	for(int i = 0; i < tamanho; i++)
	{
		for(int k = 0; k < tamanho - 1; k++)
		{
			if(opcao == 1)
			{
				
				troca = COMPARARP(pont_deposito[i].NOME, pont_deposito[k].NOME);
				if(!troca)
				{
					aux = pont_deposito[i];
					pont_deposito[i] = pont_deposito[k];
					pont_deposito[k] = aux;
				}
			}
			else
			{
				troca = COMPARARP(pont_deposito[i].NOME, pont_deposito[k].NOME);
				if(troca)
				{
					aux = pont_deposito[i];
					pont_deposito[i] = pont_deposito[k];
					pont_deposito[k] = aux;
				}
			}
		}
	}
}

void BBSORT_PRECO(estoque * pont_deposito, int opcao, int tamanho)
{
	estoque aux;
	
	if(opcao ==1)
	{
		for(int i = 0; i < tamanho; i++)
		{
			for(int k = 0; k < tamanho - 1; k++)
			{
				if(pont_deposito[i].PRECO_U < pont_deposito[k].PRECO_U)
				{
					aux = pont_deposito[i];
					pont_deposito[i] = pont_deposito[k];
					pont_deposito[k] = aux; 
				}
			}
		}
	}
	else
	{
		for(int i = 0; i < tamanho; i++)
		{
			for(int k = 0; k < tamanho - 1; k++)
			{
				if(pont_deposito[i].PRECO_U > pont_deposito[k].PRECO_U)
				{
					aux = pont_deposito[i];
					pont_deposito[i] = pont_deposito[k];
					pont_deposito[k] = aux; 
				}
			}
		}
	}
}

void BBSORT_QUANTIDADE(estoque * pont_deposito, int opcao, int tamanho)
{
	estoque aux;
	
	if(opcao == 1)
	{
		for(int i = 0; i < tamanho; i++)
		{
			for(int k = 0; k < tamanho; k++)
			{
				if(pont_deposito[i].QUANTIDADE < pont_deposito[k].QUANTIDADE)
				{
					aux = pont_deposito[i];
					pont_deposito[i] = pont_deposito[k];
					pont_deposito[k] = aux;
				}
			}
		}
	}
	else
	{
		for(int i = 0; i < tamanho; i++)
		{
			for(int k = 0; k < tamanho; k++)
			{
				if(pont_deposito[i].QUANTIDADE > pont_deposito[k].QUANTIDADE)
				{
					aux = pont_deposito[i];
					pont_deposito[i] = pont_deposito[k];
					pont_deposito[k] = aux;
				}
			}
		}
	}
}

void BBSORT_CODIGO(estoque * pont_deposito, int opcao, int tamanho)
{
	estoque aux;
	
	if(opcao == 1)
	{
		for(int i = 0; i < tamanho; i++)
		{
			for(int k = 0; k < tamanho; k++)
			{
				if(pont_deposito[i].CODIGO < pont_deposito[k].CODIGO)
				{
					aux = pont_deposito[i];
					pont_deposito[i] = pont_deposito[k];
					pont_deposito[k] = aux;
				}
			}
		}
	}
	else
	{
		for(int i = 0; i < tamanho; i++)
		{
			for(int k = 0; k < tamanho; k++)
			{
				if(pont_deposito[i].CODIGO > pont_deposito[k].CODIGO)
				{
					aux = pont_deposito[i];
					pont_deposito[i] = pont_deposito[k];
					pont_deposito[k] = aux;
				}
			}
		}
	}
}

void IMPRIMIR(estoque * pont_deposito, int tamanho)
{
	int i = 0;
	
	printf("==========================================================================\n");
	printf("|== COD ==|===== DESCRICAO ====|==== QUANTIDADE ====|=== VALOR UNIDADE ===|\n");
	for(int i = 0; i < tamanho; i++)
	{
		printf("|%9d|%20s|%20d|%21.2lf|\n", pont_deposito[i].CODIGO, pont_deposito[i].NOME, pont_deposito[i].QUANTIDADE, pont_deposito[i].PRECO_U);
	}
	printf("==========================================================================\n");
}

int COMPARARP(char * palav_1, char * palav_2)
{
	int i = 0;
	
	while(palav_1[i] != '\0' && palav_2[i] != '\0')
	{
		if(palav_1[i] < palav_2[i])
		{
			return(0);
		}
		else if(palav_1[i] > palav_2[i])
		{
			return(1);
		}
		i++;
	}
	
	if(palav_1[i] == '\0' && palav_2[i] == '\0')
	{
		return(0);
	}
	else if(palav_1[i] == '\0')
	{
		return(0);
	}
	else
	{
		return(1);
	}
}