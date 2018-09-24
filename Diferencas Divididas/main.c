# include <stdio.h>
# define MAX 20
void main()
{
    int i,j,n;
    float x[MAX],fx[MAX][MAX],xp,u,sum=0;
    printf("================================================================================\n");
    printf("                      METODO DE NEWTON COM DIFERENCAS DIVIDIDAS\n");
    printf("\n================================================================================\n");
    printf("ENTRE COM O NUMERO DE PONTOS:\n");
    scanf("%d",&n);
    printf("DIGITE OS VALORES DE x E F(x)\n");

    for(i=0;i<=n;i++)
    {
        scanf("%f%f",&x[i],&fx[i][1]);

    }
    printf("DIGITE O VALOR DE x PARA A INTERPOLACAO:\n ");// Ordenada do ponto interpolado, valor calculado
    scanf("%f",&xp);

    for(i=2;i<=n;i++)
    {
        for(j=1;j<=n-i+1;j++)
        {
            fx[j][i]=(fx[j+1][i-1]-fx[j][i-1])/(x[j+i-1]-x[j]);
        }

    }

    printf("-------------------------------------------------------------------\n");
    printf("       X               F(x) ");

    for(i=1;i<n;i++)
    {
        printf("y%d ",i);
    }

    printf("\n-----------------------------------------------------------------\n");

    for(i=1;i<=n;i++)
    {
    printf("%4.2f\t ",x[i]);

    for(j=1;j<=n-i+1;j++)
    {
        printf("%4.2f ",fx[i][j]);
    }

    printf("\n");
    }
    printf("\n-----------------------------------------------------------------\n");

    sum=fx[1][1];
    for(i=2;i<=n;i++)
    {
    u=1;
    for(j=1;j<i;j++)
    u=u*(xp-x[j]);
    u=u*fx[1][i];
    sum=sum+u;
    }
    printf("\nPARA %lf VALOR INTERPOLADO = %lf\n",xp,sum);

}
