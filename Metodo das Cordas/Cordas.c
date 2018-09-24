#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double funcao (double x) { //Calcula e retorna a função no ponto x
    return x * log10 (x) - 1; //Insere sua funcao aqui
}

double calcula_xn (double fa, double fb, double a, double b) { // Cordas formula
    if((fb - fa)) {
        return (((a*fb)-(b*fa))/(fb-fa)); // Retorna a funcao no ponto xn
    } else { //divisão por zero
        printf("ERRO: DIVISAO POR ZERO!\n");
        exit(0);
    }
}

void cordas(double a, double b, double tolerancia) {
    double xn, fxn, fa, er, fb, erro;
    xn = 0;
    fxn = 0;
    fa = 0;
    er = 0;
    fb = 0;
    erro = 0;
    printf("\n");
    do {                            //loop while para que a diferença entre os pontos seja maior do que o erro de dado
        fa = funcao (a);
        fb = funcao (b);
        printf("a:%f   b:%f  ", a, b);
        if(((fa < 0) && (fb > 0)) || ((fa > 0) && (fb < 0))) {
            er = xn;
            xn = calcula_xn (fa, fb, a, b);
            fxn = (funcao (xn));        //Retorna o valor modulo de xn que é o resultado final
            erro = fabs (xn - er);
            printf(" Xn:%f   f(Xn):%f   ERRO:%f\n", xn, fxn, erro);
            if(erro <= tolerancia) {
                printf("\nZERO DA FUNCAO: %f\n", xn);
            } else {
                if (fxn > 0) {
                    b = xn;
                } else {
                    a = xn;
                }
            }
        } else {
            printf("\n\nSINAIS IGUAIS\n");
        }

    } while(erro > tolerancia);
}

int main () {
    double a, b, tolerancia;
    printf("================================================================================\n");
    printf("                             METODO DAS CORDAS\n");
    printf("\n================================================================================\n");

    do {
        printf("\nx0: ");
        scanf("%lf", &a);
        printf("\nx1: ");
        scanf("%lf", &b);
    } while(a > b);
    do {
        printf("\nTOLERANCIA: ");
        scanf("%lf", &tolerancia);
    } while(tolerancia <= 0);
    cordas (a, b, tolerancia);
    return 0;
}
