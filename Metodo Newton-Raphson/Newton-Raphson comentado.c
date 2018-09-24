#include <stdio.h>
#include <math.h>
#define DEF 10 // max de Xi

double funcao(double x) { // Calcula e retorna a funcao no ponto x
	return (x * log10 (x) - 1); //Insere sua funcao aqui
}

double derivada (double x) { // Calcula e retorna a derivada no ponto x
	return (log10 (x) + (x * (1 / (x * log(10))))); // Insere a derivada da funcao aqui
}

double segunda_derivada (double x) { // Calcula e retorna a segunda derivada no ponto x
	return (1 / (x * log (10))); // Insere a segunda derivada aqui
}

void newton_raphson (double erro, float x0, float x1) {
	int i = 0;
	double x[DEF], aux, aux2;

	aux = funcao (x0);
	aux2 = funcao (x1);
	// selecciona o intervalo em que a função e a segunda derivada é do mesmo sinal
	if ((aux > 0 && segunda_derivada (x0) > 0) || (aux < 0 && segunda_derivada (x0) > 0)) {
		x[0] = x0;
	} else {
		x[0] = x1;
	}
	x[0] = x[0] - (funcao (x[0]) / derivada (x[0])); /* Inserir o primeiro Xi */
	printf ("\n X%d: %f\n", i, x[0]);
	do { // loop while a diferença entre os pontos é maior do que o erro de dado
		i++;
		x[i] = x[i - 1] - (funcao (x[i - 1]) / derivada (x[i - 1])); /* Newton-Raphson formula */
		printf (" X%d: %f\n", i, x[i]);
	} while ((fabs (x[i] - x[i - 1])) > erro);
}

int main () {
	double erro;
	float x0, x1;

    printf("================================================================================\n");
    printf("                             METODO DE NEWTON-RAPHSON\n");
    printf("\n================================================================================\n");

	printf ("DIGITE O ERRO:\n");
	scanf ("%lf", &erro);
	printf ("\nx0: ");
	scanf ("%f", &x0);
	printf ("\nx1: ");
	scanf ("%f", &x1);
	newton_raphson (erro, x0, x1);
	return 0;
}

