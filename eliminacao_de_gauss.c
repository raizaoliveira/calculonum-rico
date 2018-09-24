/*Eliminacao de gauss a complexidade detse algoritmo e de O(n^2) e na fase de eliminacao e de O(4n^3+3n^2-7n)/6, entao para resolver
um sitema pela eliminacao de gauss e O(4n^3+ 9n^2 -7n)/6  */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define tam 100


void leitura (double A[][tam], int *n_e, int *n_v);

void pivo(double A[][tam], int pos, int **pont);

void gauss(double A[][tam], int *n);


int main()
{  
    register int i,j;
    int var, eq;    
    double matriz[tam][tam];
	char opc;
	do{
        leitura(matriz, &eq, &var);
	    puts("Matriz informada: ");
	    for(i = 0 ; i < eq; i++)
	   {
            puts("");
            for(j = 0; j < var; j++)
            {
                printf("   %.4lf", matriz[i][j]);
            }
        }
        gauss(matriz, &eq);
		getch();
		system("clear");
        do
        {
            printf("\n- Deseja resolver outro sistema linear?s/n: ");
            fflush(stdin);
            scanf("%c",&opc);
            fflush(stdin);
        }
        while((opc != 'S' && opc != 's') && (opc != 'N' && opc!= 'n'));   
    }while(opc=='S'|| opc=='s');		
	   
    return 0;

}
void leitura (double A[][tam], int *n_e, int *n_v)
{     
    register int i, j, bool;
	int c, l;
	c =0;
	l=0;
  do{
        puts("Por favor, informe o quantas equacoes e quantas variaveis tem o sistema");
        scanf("%d", &l);
        scanf("%d", &c);
		fflush(stdin);
    }while((l > tam) || (c > tam) || (l < 1) || (c < 1));
	*n_e = l;
	*n_v = c;
	if (*n_e != *n_v)
	{
	    puts("\aLamento, sistema indeterminado");
		exit(1);
	}
	else
	{   
	    *n_v+=1;
	    puts("Por favor informe os coeficientes e os termos independentes");
    /* inicio da leitura da matriz dos coeficientes*/
        for(i=0; i < *n_e; i++)
        {  
            for (j=0; j < *n_v; j++)
            {    
                printf("linha %d.  coluna %d:  ", i, j);
                scanf(" %lf", &A[i][j]);
            }
        }
	}
}
void pivo(double A[][tam], int pos, int **pont)
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
		}
    }
    if(linha != pos)
    {	
        aux = (double *) calloc(**pont+1, sizeof(double));
        if (aux == NULL)
        {
            printf ("/a** Erro: Memoria Insuficiente **/a");
            exit(0);
        }
        else
	    {
		    for(j = 0; j <= **pont; j++)
		    {
			    aux[j] = A[linha][j];
		        A[linha][j] = A[pos][j];
		        A[pos][j] = aux[j];
	        }
        }
        free(aux);
    }
}
void gauss(double A[][tam], int *n)
{
 double mul, *x;
    register int i,j,k, l,termo;
    for (k=0;k<*n-1;k++)
	{
        for (i=k+1; i < *n;i++)
        {
	        pivo(A, k, &n);
			mul =-1*(A[i][k]/A[k][k]);
            for (j=0;j< *n+1;j++)
		    {
                A[i][j]=(A[k][j]*mul)+A[i][j];
		    }
        }
    }
	x = (double *) calloc(*n+1, sizeof(double));
        if (x == NULL)
        {
            printf ("/a** Erro: Memoria Insuficiente **/a");
            exit(0);
        }
	for (i = 0 ; i < *n ; i++)
	{
        termo = 0;
        l = *n-i;
        for (j = l ; j < *n ; j++)
		{
            termo = termo + ( x[j] * A[*n-i-1][j] );
		}
        x[*n-i-1] = ( A[*n-1-i][*n] - termo ) / A[*n-i-1][*n-i-1];
    }
	puts("\n\nSolucao:\n");
	for(i = 0; i < *n; i++)
	{
	    printf("     %lf  \n", x[i]);
	}
	free(x);
}
