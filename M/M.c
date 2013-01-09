/*
 *      M.c
 *      Copyright 2012 João Ferreira <joao@void>
 */

#include <stdio.h>

int gcd (int u, int v)
{
	return v == 0 ? u : gcd(v, u%v);
}

int main(int argc, char** argv)
{
	int n, m, i;
	int numerator, denominator;

	while ( scanf("%d %d", &n, &m) != EOF ) {
		
		if (n-m+1 < m)
			printf("1/1\n");
		else {

			numerator = 1;
			denominator = 1;

			for (i = m-1; i > 0; --i) {
				numerator *= n - m - m + 1 + i;
				denominator *= n - m + 1 + i;

				int x = gcd(numerator, denominator);
				numerator /= x;
				denominator /= x;
			}

			numerator = denominator - numerator;
			printf("%d/%d\n", numerator, denominator);
		}	
	}
	
	return 0;
}
