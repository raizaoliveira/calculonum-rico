#include <stdio.h>
#include <math.h>

//prototipos
void MIL (double , double, double, double, int);
double psi (double x) ;

int main ()

{

        int Nmax;
        double x, x0, Epsilon, E;

        scanf ("%lf", &x0);
        scanf ("%lf", &Epsilon);
        scanf ("%d", &Nmax);
        MIL (x, x0, Epsilon, E, Nmax);

        return 0;
}



//metodo iterativo linear que calcula a raiz da esquacao f(x) = 0.

void MIL (double x , double x0, double Eps, double E, int Nmax) {

        int i = 0;

        do {
                x = psi (x0);
                E = fabs (x - x0);
                x0 = x;
                i++;

        } while ( ( E > Eps ) && ( i < Nmax ) );

       printf ("Riaz aproximada == %lf\nN Iteracoes == %d\n", x, i);
}


// Aqui o usuario escreve a função que quiser
double psi (double x)

{
        return cos (x);

}
