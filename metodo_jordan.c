#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define tam 100

void leitura (double A[][tam], int *n_e, int *n_v);

void pivo(double A[][tam], int pos, int **pont);

void Resultado(double A[][tam],int **linha,int **coluna);

void Jordan(double A[][tam],int *n_e, int *n_v);

int main()
{
    int var, eq,i, j;
	double matriz[tam][tam];
	char opc;
	do{
	    leitura(matriz, &eq, &var);
	    puts("Matriz informada: \n");
	    for(i = 0 ; i < eq; i++)
	    {
            puts("");
            for(j = 0; j < var; j++)
            {
                printf("   %lf", matriz[i][j]);
            }
        }
        puts("");
	    Jordan(matriz , &eq, &var);
        getch();
	    system("clear");
        do{
            printf("\n- Deseja resolver outro sistema linear?s/n: ");
            fflush(stdin);
            scanf("%c",&opc);
            fflush(stdin);
        }while((opc != 'S' && opc != 's') && (opc != 'N' && opc!= 'n'));   
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
	if (fabs(maior) == 0)
	{
	    printf("\n\aPivo nulo, sistema impossivel\n");
		exit(1);
	
	}
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
void Resultado(double A[][tam],int **linha,int **coluna)
{
    int i,j,validade=0;
    double a =0, b = 0, resul[**linha];
    //conferindo se algum elemento da diagonal é zero
    for(i=0; i < **linha; i++)
    {
        for(j=0; j < **coluna-1; j++)
        {
            if(j == i)
            {
                if(A[i][j] != 0)
                {
                    a = A[i][j];
                }
                b = A[i][**coluna-1];
            }
            if(a == 0)
            {
                validade = 1;
            }
        }
        resul[i] = b/a;
        a=0;
		
    }//imprimindo os valores da matriz se o sistema nao for impossivel
    if(validade != 0)
    {
	    puts("\n\nSolucao:\n\n");
        for(i=0; i< **linha; i++)
        {
            printf("     %lf\n",resul[i]);
        }
    }
    else
    {
        printf("[SISTEMA IMPOSSIVEL!]");
    }
}
void Jordan(double A[][tam],int *n_e, int *n_v)
{
    double mult;
    int i,j,k;
    for(i = 0; i < *n_v-1; i++) 
    {
        for(j = 0; j < *n_e; j++)
        {
            if(j != i)
            {
                if(A[j][i] != 0)
                {
				    pivo(A, i, &n_e);
		            mult = -1*(A[j][i] / A[i][i]);
					for(k = 0; k < *n_v; k++) 
                    {
                        A[j][k]= ( mult * A[i][k])+ A[j][k];
                    }
                }
            }
        }
    }
    Resultado(A, &n_e , &n_v); 
}

