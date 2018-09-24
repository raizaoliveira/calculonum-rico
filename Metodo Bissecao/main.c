#include <stdio.h>
#include <math.h>
#define e  2.7182818284590452354
#define ln 2.30258509299404568402

/* Equaçoes testadas
    pow(x,3)- 9 * x + 3
    x * log10 (x) - 1;
    pow(e,x)- x - 2
    x * pow(e,x) - 1.2


*/

float f(float x) {
   return 2 * cos(x) - pow(e,x);  // Função cuja raiz deve ser determinada
}


int main()
{

   int it=0;
   float eps, a, b, xn, tam=99999999;

   printf("================================================================================\n");
   printf("                             METODO DA BISSECAO\n");
   printf("\n================================================================================\n");

   printf("\nDIGITE O ERRO: \n");
   scanf("%f",&eps);

   printf("\nDIGITE O INTERVALO ONDE DEVE SE BUSCAR A RAIZ: \n");
   scanf("%f %f",&a,&b);


   while(tam > eps)
   {
        tam = b-a;
        xn = (a+b)/2;
        printf("\n %f \n", xn);

        if(f(xn) == 0)
        {
            printf("\nSOLUCAO EXATA ENCONTRADA!! x = %f\n",xn);
        }


        if(f(a)*f(xn) < 0)
        {
            b = xn; // a solução está a esquerda
        }

        else
        {
            a = xn;  // a solução está a direita

        }
        tam = b-a;
        it++;
   }

   printf("\nITERACAO:%d\n", it);
   printf("\nSOLUCAO APROXIMADA:%f \n",xn);



   return 0;
}
