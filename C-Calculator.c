#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define N 9.80665
#define CLEAR "\e[1;1H\e[2J"  //  ANSI code used to wipe output
#define MAX_OPS 50  //  Maximum number of operators

int first (int m, int div) {
	while ( (m / div) != 1 ) {
		if (m % div == 0 || m == 1) {
			return 0;
		}
		else {
			if (m % div != 0) {
				div++;
			}
		}
	}
	return 1;
}

void add (double *ops, int lops) {
	double h = 0.0;
	int i = 0;
	
	for (; i < lops; i++) {
		h += ops[i];
	}
	
	printf ("Sum's result is: %lf", h);
	printf ("\nAverage's result is: %lf", h / i);
}

void subtract (double *ops, int lops) {
	double h = 0.0;
	
	for (int i = 0; i < lops; i++) {
		if (i == 0) {
			h = ops[i];
		}
		else {
			h -= ops[i];
		}
	}
	
	printf ("Subtraction's result is: %lf", h);
}

void multiply (double *ops, int lops) {
	double h = 0.0;
	
	for (int i = 0; i < lops ; i++) {
		if (i == 0) {
			h = ops[i];
		}
		else {
			h *= ops[i];
		}
	}
	
	printf ("Multiplication's result is: %lf", h);
}

void divide (double *ops, int lops) {
	double h = 0.0;
	int i;
	
	if (lops == 1) {
		printf("It's impossible to divide with only one value");
	}
	else {
		for (i = 0; i < lops; i++) {
			if (ops[i] == 0 && i != 0) {
				printf("The division is impossible");
				break;
			}
			else {
				if (i == 0) {
					h = ops[i];
				}
				else {
					h /= ops[i];
				}
			}
			
			if (i == lops - 1) {
				printf("Division's result is: %lf", h);	
			}	
		}
	}	
}

void exponent (double *ops, int lops) {
	double expo;
	
	printf ("\nInsert exponentiation value: ");
	scanf ("%lf", & expo);
	
	for (int i = 0; i < lops; i++) {
		printf ( "\nExponentiation of %lf is: %lf", ops[i], pow (ops[i], expo) );
	}
}

void root (double *ops, int lops) {
	double expo;
	
	printf ("\nRoot type: ");
	scanf ("%lf", & expo);
	expo = 1 / expo;
	
	for (int i = 0; i < lops; i++) {
		printf ( "\nRoot of %lf is: %lf", ops[i], pow (ops[i], expo) );
	}
}

void sine (double *ops, int lops) {
	double a;
	
	for (int i = 0; i < lops; i++) {
		a = ops[i] * 2 * M_PI / 360.0;  //  Converting in radiants M_PI=3.14
		printf ( "\nSine of %lf is: %lf", ops[i], sin (a) );
	}
}

void cosine (double *ops, int lops) {
	double a;
	
	for (int i = 0; i < lops; i++) {
		a = ops[i] * 2 * M_PI / 360.0;
		printf ( "\nCosine of %lf is: %lf", ops[i], cos (a) );
	}
}

void tang (double *ops, int lops) {
	double a;
	
	for (int i = 0; i < lops; i++) {
		a = ops[i] * 2 * M_PI / 360.0;
		printf("\nTangent of %lf is: %lf", ops[i], tan (a) );
	}
}

void loga (double *ops, int lops) {
	for (int i = 0; i < lops; i++) {
		printf("\nLogarithm of %lf is: %lf", ops[i], log10 ( ops[i] ) );
	}	
}

void ln (double *ops, int lops) {
	for (int i = 0; i < lops; i++) {
		printf("\nNatural logarithm of %lf is: %lf", ops[i], log ( ops[i] ) );
	}	
}

void weight (double *ops, int lops) {
	for (int i = 0; i < lops; i++) {
		printf ("\nWeight of %lf is: %lf", ops[i], ops[i] * N);
	}
}

void temp (double *ops, int lops) {
	for (int i = 0; i < lops; i++) {
		printf ("\nConversion in °F of %lf is: %lf", ops[i], ops[i] * 1.800 + 32.00);
		printf ("\nConversion in °K of %lf is: %lf", ops[i], ops[i] + 273.15);
	}
}

void dtob (double *ops, int lops) {
	int bas, m;
	
	printf ("Insert the base: ");
	scanf ("%d", & bas);
	
	for (int i = 0; i < lops; i++) {
		m = (int) ops[i];  //  Converting to integer
		int r[10], h = 0, k;
		
		do {
			r[h] = m % bas;
			h++;
			m /= bas;
		} while (m != 0);
		
		printf ("\nThe converted number %lf in base %d is: ", ops[i], bas);
		
		for (k = h - 1; k >= 0; k--) {
			printf ("%d", r[k]);
		}
	}
}

void btod (double *ops, int lops) {
	int bas;
	
	printf ("\nInsert the base of the number: ");
	scanf ("%d", & bas);
	
	for (int i = 0; i < lops; i++) {
		int d = 0, k;
		k = (int) ops[i];
		
		for (int c = 0; k > 0; c++) {
			if (k % 10 != 0) {
				d += pow (bas, c);
			}
			
			k /= 10;
		}
		
		printf ("\nThe converted number %.0lf in decimals is: %d", ops[i], d);
	}
}

void prime (double *ops, int lops) {
	for (int i = 0; i < lops; i++) {
		int m, div = 2, h = 0, l = 0;
		
		if (ops[i] == 0) {
			printf ("\nIt's impossible to do prime factorization on zero");
		}
		else {
			m = (int) ops[i];
			
			if (first (m, div) == 1) {
				printf("\nThe number %.0lf is prime", ops[i]);
			}
			else {
				while (m != 1) {
					if (m % div == 0) {
						m /= div;
						h++;
					}
					else {
						if (h != 0) {
							l++;
							
							if(l == 1) {
								printf("\nPrime factorization of the number %.0lf is: %d ^ %d *", ops[i], div, h);
							}
							else {
								printf("%d ^ %d *", div, h);
							}
						}
						
						h=0;
						div++;
					}
				}
				
				if (l == 0) {
					printf("\nPrime factorization of the number %.0lf is: %d ^ %d ", ops[i], div, h);
				}
				else {
					printf("%d ^ %d", div, h);
				}
			}
		}
	}
}

int main () {
	void (*calc_function[]) (double *ops, int lops) = { add, subtract, multiply,
														divide, exponent, root,
														sine, cosine,tang,loga,
														ln,weight,temp,dtob, 
														btod,prime };
	
	int b, choice = -1;
	double (c[MAX_OPS]);
	
	printf ("Specify the number of operators (Max %d): ", MAX_OPS);
	scanf ("%d", & b);
	
	if (b <= 0) {
		exit (0);
	}
	
	printf (CLEAR);
	
	printf ("Insert the numbers: \n");
	
	for (int i = 0; i < b; i++) {
		scanf ("%lf", & c[i]);
	}
	
	printf (CLEAR);
	
	while (1 != 0) {
		printf("\n");
		printf("\nWhich operation you want to do?\n");
		printf("    (1) Sum/Average      (2) Subtraction      (3) Multiplication      (4) Division\n");
		printf("    (5) Exponentiation   (6) Roots            (7) Sine                (8) Cosine\n");
		printf("    (9) Tangent         (10) Logarithm       (11) Natural logarithm\n");
		printf("\nConversion\n");
		printf("    (12) Conversion from Kilograms to Weight\n");
		printf("    (13) Celsius Degrees to Kelvin or Fahrenheit\n");
		printf("    (14) Conversion from binaries to decimals\n");
		printf("    (15) Conversion from decimals to binaries\n");
		printf("    (16) Prime factorization of the numbers\n");
	
		scanf ("%d", & choice);
		
		if (choice <= 0 || choice > 16) {
			exit (0);
		}
		else {
			printf (CLEAR);
			
			calc_function[choice - 1] (c, b);
		}
	}
}
