#include <stdio.h>
#include <math.h>

double function (double x) { /* calculated and returns the function at point x */
	return (3 * pow (x, 2) + sqrt (x + 1) * pow (cos (x), 3) - 2);  /* INSERT YOUR FUNCTION HERE */
}

double mod (double x) { /* return the positive mod of the number */ 
	if (x < 0) {
		return (x * -1);
	} else {
		return x;
	}
}

void pegaso (double a, double b, double tolerance, int imax) { /* Pegaso method */
	double Fa, Fb, Fx, deltaX, x;
	int i;
	Fa = function (a);
	Fb = function (b);
	x = b;
	Fx = Fb;
	i = 0;
	do {
		i++;
		deltaX = - Fx / (Fb - Fa) * (b - a);
		x = x + deltaX;
		Fx = function (x);
		printf ("I: %d\na: %lf\nFa: %lf\nb: %lf\nFb: %lf\nx: %lf\nFx: %lf\nDeltaX: %lf\n\n", i, a, Fa, b, Fb, x, Fx, deltaX);
		if (((mod (deltaX)) < tolerance && (mod (Fx)) < tolerance) || (i >= imax)) { /* end the method */
			printf ("\nroot: %lf\n", x);
		}
		if (Fx * Fb < 0) { /* exchange values */
			a = b;
			Fa = Fb;
		} else {
			Fa = Fa * Fb / (Fb + Fx);
		}
		b = x;
		Fb = Fx;
	} while (mod (function (x)) > tolerance); /* while the mod of the function the X has larger of the tolerance */
	printf ("\nroot: %lf\n", x);
}

int main () {
	int imax;
    double a, b, tolerance;
    do {
        printf("x0: ");
        scanf("%lf", &a);
        printf("x1: ");
        scanf("%lf", &b);
    } while(a > b);
    do {
        printf("tolerance: ");
        scanf("%lf", &tolerance);
    } while(tolerance <= 0);
    do {
    	printf ("max interations: ");
    	scanf ("%d", &imax);
    } while (imax <= 0);
    pegaso (a, b, tolerance, imax);
    return 0;
}
