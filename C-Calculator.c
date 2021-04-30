#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define N 9.80665
#define CLEAR "\e[1;1H\e[2J" /* ANSI code used to wipe output */
#define MAX_OPS 50 /* Maximum number of operators */

int first(int m, int div)
{
	while ((m / div) != 1) {
		if (m % div == 0 || m == 1) {
			return 0;
		} else if (m % div != 0) {
			div++;
		}
	}

	return 1;
}

void add(long double *ops, int lops)
{
	long double h = 0.00;
	int i = 0;

	for (; i < lops; i++)
		h += ops[i];

	printf("Sum's result is: %Lf", h);
	printf("\nAverage's result is: %Lf", h / i);
}

void subtract(long double *ops, int lops)
{
	long double h = 0.00;

	for (int i = 0; i < lops; i++) {
		if (i == 0) {
			h = ops[i];
		} else {
			h -= ops[i];
		}
	}

	printf("Subtraction's result is: %Lf", h);
}

void multiply(long double *ops, int lops)
{
	long double h = 0.00;

	for (int i = 0; i < lops; i++) {
		if (i == 0) {
			h = ops[i];
		} else {
			h *= ops[i];
		}
	}

	printf("Multiplication's result is: %Lf", h);
}

void divide(long double *ops, int lops)
{
	long double h = 0.00;

	if (lops == 1) {
		printf("It's impossible to divide with only one value");
	} else {
		for (int i = 0; i < lops; i++) {
			/* Checks input */
			if (ops[i] == 0 && i != 0) {
				printf("The division is impossible");
				break;
			} else {
				if (i == 0)
					h = ops[i];
				else
					h /= ops[i];
			}

			if (i == lops - 1)
				printf("Division's result is: %Lf", h);
		}
	}
}

void exponent(long double *ops, int lops)
{
	long double expo = 0.00;

	printf("\nInsert exponentiation value: ");
	scanf("%Lf", &expo);

	for (int i = 0; i < lops; i++)
		printf("\nExponentiation of %Lf is: %Lf", ops[i], powl(ops[i], expo));
}

void root(long double *ops, int lops)
{
	long double expo = 0.00;

	printf("\nRoot type: ");
	scanf("%Lf", &expo);
	expo = 1 / expo;

	for (int i = 0; i < lops; i++)
		printf("\nRoot of %Lf is: %Lf", ops[i], powl(ops[i], expo));
}

void sine(long double *ops, int lops)
{
	long double a = 0.00;

	for (int i = 0; i < lops; i++) {
		a = ops[i] * 2 * M_PI / 360; /* Converting in radiants M_PI */
		printf("\nSine of %Lf is: %Lf", ops[i], sinl(a));
	}
}

void cosine(long double *ops, int lops)
{
	long double a = 0.00;

	for (int i = 0; i < lops; i++) {
		a = ops[i] * 2 * M_PI / 360;
		printf("\nCosine of %Lf is: %Lf", ops[i], cosl(a));
	}
}

void tang(long double *ops, int lops)
{
	long double a = 0.00;

	for (int i = 0; i < lops; i++) {
		a = ops[i] * 2 * M_PI / 360;
		printf("\nTangent of %Lf is: %Lf", ops[i], tanl(a));
	}
}

void loga(long double *ops, int lops)
{
	for (int i = 0; i < lops; i++)
		printf("\nLogarithm of %Lf is: %Lf", ops[i], logl(ops[i]));
}

void nl(long double *ops, int lops)
{
	for (int i = 0; i < lops; i++)
		printf("\nNatural logarithm of %Lf is: %Lf", ops[i], logl(ops[i]));
}

void weight(long double *ops, int lops)
{
	for (int i = 0; i < lops; i++)
		printf("\nWeight of %Lf is: %Lf", ops[i], ops[i] * N);
}

/* Conversion from Celsius to Fahrenheit or Kelvin */
void temp(long double *ops, int lops)
{
	for (int i = 0; i < lops; i++) {
		printf("\nConversion in °F of %Lf is: %Lf", ops[i], ops[i] * 1.8 + 32);
		printf("\nConversion in °K of %Lf is: %Lf", ops[i], ops[i] + 273.15);
	}
}

/* Decimals to binary */
void dtob(long double *ops, int lops)
{
	int bas, m;

	printf("Insert the base: ");
	scanf("%d", &bas);

	/* Converting to integer */
	for (int i = 0; i < lops; i++) {
		int r[10], h = 0, k;
		m = (int)ops[i];
		
		do {
			r[h] = m % bas;
			h++;
			m /= bas;
		} while (m != 0);

		printf("\nThe converted number %Lf in base %d is: ", ops[i], bas);

		for (k = h - 1; k >= 0; k--)
			printf("%d", r[k]);
	}
}

/* Binary to decimals */
void btod(long double *ops, int lops)
{
	int bas;

	printf("\nInsert the base of the number: ");
	scanf("%d", &bas);

	for (int i = 0; i < lops; i++) {
		int d = 0, k;
		k = (int)ops[i];
		
		for (int c = 0; k > 0; c++) {
			if (k % 10 != 0)
				d += pow(bas, c);

			k /= 10;
		}

		printf("\nThe converted number %Lf in decimals is: %d", ops[i], d);
	}
}

/* Prime factorization */
void prime(long double *ops, int lops)
{
	for (int i = 0; i < lops; i++) {
		int m, div = 2, h = 0, l = 0;

		if (ops[i] == 0) {
			printf("\nIt's impossible to do prime factorization on zero");
		} else {
			m = (int)ops[i];

			if (first(m, div) == 1) {
				printf("\nThe number %Lf is prime", ops[i]);
			} else {
				while (m != 1) {
					if (m % div == 0) {
						m /= div;
						h++;
					} else {
						if (h != 0) {
							l++;

							if (l == 1)
								printf("\nPrime factorization of the number %Lf is: %d ^ %d *", ops[i], div, h);
							else
								printf("%d ^ %d *", div, h);
						}

						h = 0;
						div++;
					}
				}

				if (l == 0)
					printf("\nPrime factorization of the number %Lf is: %d ^ %d ", ops[i], div, h);
				else
					printf("%d ^ %d", div, h);
			}
		}
	}
}

int main()
{
	void (*calc_function[])(long double *ops, int lops) = { add, subtract, multiply, 
								divide, exponent, root,
								sine, cosine, tang, loga,
								nl, weight, temp, dtob,
								btod, prime };

	int nops, choice;
	long double c[MAX_OPS];

	do {
		printf("Specify the number of operators (Max %d): ", MAX_OPS);
		scanf("%d", &nops);
	} while (nops < 1 || nops > MAX_OPS);

	printf(CLEAR);
	printf("Insert the numbers: \n");

	for (int i = 0; i < nops; i++)
		scanf("%Lf", &c[i]);

	printf(CLEAR);

	while (0 == 0) {
		printf("\n\nWhich operation you want to do?\n");
		printf("    (1) Sum/Average      (2) Subtraction      (3) Multiplication      (4) Division\n");
		printf("    (5) Exponentiation   (6) Roots            (7) Sine                (8) Cosine\n");
		printf("    (9) Tangent         (10) Logarithm       (11) Natural logarithm\n");
		printf("\nConversions\n");
		printf("    (12) Conversion from Kilograms to Weight\n");
		printf("    (13) Celsius Degrees to Kelvin or Fahrenheit\n");
		printf("    (14) Conversion from binaries to decimals\n");
		printf("    (15) Conversion from decimals to binaries\n");
		printf("    (16) Prime factorization of the numbers\n");

		scanf("%d", &choice);

		if (choice <= 0 || choice > 16) {
			exit (0);
		} else {
			printf(CLEAR);
			calc_function[choice - 1](c, nops);
		}
	}
}
