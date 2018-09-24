#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define tam 100
#define maximo 100

void leitura (double A[][tam], double v[tam], int *n_e, int *n_v, double *erro);

void pivo(double A[][tam], int **pont, int pos);

void cria_B(double A[][tam], double B[tam], int **n);

int criterio_das_linhas(double A[][tam],int *n);

void imprime(int **n, double resultado[tam], int *iteracoes);

void copia(double x0[tam], double x[tam], int **tamanho);

void seidel( double a[][tam], double y[tam], int *n, double *erro);

int teste_parada(double x[tam], double y[tam], int **n, double **erro);

int main()
{ 
    double matriz[tam][tam], inicial[tam];
	int eq, var;
	double e;
	char opc;
	do{
	    leitura( matriz, inicial, &eq, &var, &e);
	    if(criterio_das_linhas( matriz, &eq))
	    {
	        seidel( matriz, inicial, &eq, &e);
			do
            {
                printf("\n- Deseja resolver outro sistema linear?s/n: ");
                fflush(stdin);
                scanf("%c",&opc);
                fflush(stdin);
            }while((opc != 'S' && opc != 's') && (opc != 'N' && opc!= 'n'));  
	    }
	    else
        {		puts("\n Sistema informado nao converge");
		    do
            {
                printf("\n- Deseja resolver outro sistema linear?s/n: ");
                fflush(stdin);
                scanf(" %c", &opc);
                fflush(stdin);
            }while((opc != 'S' && opc != 's') && (opc != 'N' && opc!= 'n'));  
		}
    }while(opc=='S'|| opc=='s');
	system("clear");
	
    return 0;
}

void leitura (double A[][tam], double v[tam], int *n_e, int *n_v, double *erro)//ok
{     
    register int i, j;
	int c, l;
	double ep;
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
        puts("Por favor, informe os valores iniciais");
		for(i=0; i < *n_e; i++)
		{
		    printf("\nx(%d):  ", i);
			scanf(" %lf", &v[i]);
		}
		ep = 0;
		do{
            puts("\nPor favor, informe o erro");
            scanf(" %lf", &ep);
            fflush(stdin);
        }while(ep < 0);
	    *erro = ep;
		
		
	}
}

void pivo(double A[][tam], int **pont, int pos)
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

void init_b(double A[][tam], double B[tam], int **n)
{
    register int i;
    for(i = 0; i < **n; i++)
	{
		B[i] = A[i][**n];
	}
	
}

int criterio_das_linhas(double A[][tam],int *n)
{
    register int i, j;
	double maior, soma, max;

    for (i = 0; i < *n-1; i++)
	{
        for (j = i+1; j < *n; j++)
        {
	        pivo(A, &n, i);
        }

    }
	
	max = 1.0;
	for(i = 0; i < *n; i++)
    {
	    soma = 0.0;
	    for( j = 0; j < *n; j++)
		{
		    if (i != j)
	        {
			    soma+= fabs(A[i][j]);
	        }
		}
		soma = soma / fabs(A[i][i]);
		
	    if (max < soma)
	    {
			max = soma;
		}
	}
	if(max == 1.0)
	{
	    return 1;
	}
	else
	{
	    return 0;
    }
	
}

void imprime(int **n, double resultado[tam], int *iteracoes)
{
    register int i;
	if(*iteracoes >= maximo)
	{
	    puts("\n\n\a Numero maximo de iteracoes atingido");
	}
	else
	{
	    printf("\nSolucao atingida apos %d iteracoes.\nSolucao:\n\n", *iteracoes);
	    for(i = 0; i < **n; i++)
	    {
	        printf("   %lf\n", resultado[i]);
	    }
	}
}

int teste_parada(double x[tam], double y[tam], int **n, double **erro)
{
    register int i;
    double max;
	max = 0;
	for(i = 0; i < **n; i++ )
	{
	    if( fabs( y[i] - x[i] ) > max)
		{
		    max = fabs( y[i] - x[i]);
		}
	}
	if( max < **erro) return 0;
    else  return 1;
}

void copia(double x0[tam], double x[tam], int **tamanho)
{
    register int i;
	for(i = 0 ; i < **tamanho; i++)
	{
        x0[i] = x[i];
	}

}

void seidel( double a[][tam], double y[tam], int *n, double *erro)
{
    register int i, j;
	int k, v;
	double *x, *b;
	b = (double *) calloc (*n+1, sizeof(double));
    x = (double *) calloc (*n+1, sizeof(double));
	if(( x == NULL ) || ( b == NULL))
	{
	    puts("\nERRO.\a MEMORIA INSUFICIENTE");
		exit(0);
	}
	else
	{
	    init_b( a, b, &n);
	    copia( x, y, &n);
	    k = 0;
		do{
		    for( i = 0; i < *n; i++)
			{
			    y[i] = 0;
				for( j = 0; j < *n; j++)
				{
				    if( j != i )
					{
			            y[i] = y[i] + ( a[i][j] * x[j]);
					}
				}
				y[i] = (b[i] - y[i]) / a[i][i];
			    x[i]=y[i];
			}
		    k++;
			v = teste_parada( x, y, &n, &erro);
		}while( v  && ( k < maximo));
	    imprime( &n, y, &k);
		free(x);
		free(b);
	}
}


