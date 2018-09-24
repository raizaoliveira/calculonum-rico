/*determinante pelo metodo de gauss com pivoteamento  parcial*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define tam 100

void leitura (double A[][tam], int *dim);

void pivo(double A[][tam], int pos, int **pont, int **tcl);

void gauss(double A[][tam], int *n, int *troca_linha);

double determinante(double A[][tam], int *n, int *quant_trc_linha);

int main()
{
    register int i,j;
    int D,qtl;    
    double matriz[tam][tam];
	qtl = 0;
    leitura(matriz, &D);
    gauss(matriz, &D, &qtl);
	puts ("\nMatriz informada:\n");
	for(i = 0 ; i < D; i++)
	{
        puts("");
        for(j = 0; j < D; j++)
        {
           printf("   %Lf", matriz[i][j]);
        }
    }
    printf("\n\nDeterminante da matriz A[%d][%d] : %Lf", D, D, determinante(matriz, &D, &qtl));
    puts("");
	fflush(stdin);
    getch();
    return 0;
}


void leitura (double A[][tam], int *dim)
{     
    register int i, j;
  do{
        puts("Por favor, informe a dimensao da matriz");
        scanf("%d", &(*dim));
    }while((*dim < 1) || (*dim > tam));
	    puts("Por favor informe os elemantos da matriz");
    /* inicio da leitura da matriz dos coeficientes*/
    for(i=0; i < *dim; i++)
    {  
        for (j=0; j < *dim; j++)
        {
            printf("A[%d][%d]:  ", i, j);
            scanf(" %Lf", &A[i][j]);				
        }
    }
}

void pivo(double A[][tam], int pos, int **pont, int **tcl)
{
    int i,j,linha;
	double maior;
    double *aux;
	linha = pos;
	maior =  fabs(A[pos][pos]);
    for(i = pos ; i < **pont; i++)
	{
	    if (fabs(A[i][pos]) > maior)
		{   
		    maior = A[i][pos];
		    linha = i;
			**tcl+=1;
		}
    }	
    aux = (double *) calloc(**pont+1, sizeof(double));
    if (aux == NULL) 
    {
    printf ("/a** Erro: Memoria Insuficiente **/a");
    exit(0);
    }
    else
	{
		for(i = 0; i <= **pont; i++)
		{
			aux[i] = A[linha][i];
		    A[linha][i] = A[pos][i];
		    A[pos][i] = aux[i];
	    }
	
	    
    }
}

void gauss(double A[][tam], int *n, int *troca_linha)
{
    double mul;
    register int i, j, k;
    for (k=0; k < *n-1; k++)
    {
     	for(i= k+1; i < *n; i++)
        {   
		    pivo(A, k, &n, &troca_linha);
		    mul = -1*(A[i][k] / A[k][k]);
			for(j=0; j < *n-1; j++)
			{
			    A[i][j] = ( A[k][j] * mul ) + A[i][j];
			}
        }         
    }
}//fim da funcao

double determinante(double A[][tam], int *n, int *quant_trc_linha)
{
    register i ;
	double cont = 1;
	for(i = 0; i < *n; i++)
	{
	    cont = cont * A[i][i]; 
	}
	for(i = 0; i < *quant_trc_linha; i++)
	{
	    cont = cont * -1; 
	}
	
    return cont;
}

