#include<stdio.h>
#include<math.h>
#define MAX 200

//  x[max] e f[max] tabela com os pontos dados
//  prod= produtório
//  n= numeros de pontos
//  y= ordenada do ponto interpolado


void main()
{
int n,i,j ;
char ch;
double x[MAX],f[MAX],prod,y,xp;

    printf("================================================================================\n");
    printf("                    INTERPOLACAO PELO METODO DE LAGRANGE\n");
    printf("\n================================================================================\n");

    //do
    //{
        while((n<=0) || (n>200))            //Condição para evitar do numero de pontos conhecidos seja muito grandee negativo.
        {
            printf("\nNUMEROS DE PONTOS PARA INTERPOLACAO:\n");
            scanf("%d",&n);
            if (n<=0)
            {
                printf("\nNUMEROS DE PONTOS PARA INTERPOLACAO DEVE SER POSITIVO!\n");
            }


            if (n>200)
            {
                printf("\nNUMERO INVALIDO!\n");
            }

        }

        for(i=1;i<=n;i++)
        {
            printf("\nENTRE COM O VALOR DE x%d= ",i);
            scanf("%lf",&x[i]);
            printf("\nENTRE COM O VALOR DE f(x%d)= ",i);
            scanf("%lf",&f[i]);
        }
        printf("\nENTRE COM O VALOR DE X: ");       //Ordenada do ponto interpolador, ou seja o valor de x para calcular ja no final da equacao
        scanf("%lf",&xp);
        y=0;

        for(i=1;i<=n;i++)
        {
            prod=1;
            for(j=1;j<=n;j++)
            {
                if(i!=j)
                {
                    prod=prod*(xp-x[j])/(x[i]-x[j]);      //Fórmula de Lagrange
                }

            }
        y=y+prod*f[i];
        }
        printf("\nO VALOR INTERPOLADO: %lf\n", y);


    return 0;
}
