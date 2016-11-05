#include <stdio.h>
#include <math.h>

long double factl(long double n) {
	long double i, f = 1.00;

	for(i = 1.00; i <= n; i += 1) {
		f *= i;
	}

	return f;
}

long double chudnovsky() {
	long double r = 0, k, n, d;
	const long double a = pow(640320, 3);

	for(k = 0; k < 200; k += 1) {
		n = powl(-1.00, k) * factl(6 * k) * ((545140134 * k) + 13591409);
		d = factl(3 * k) * powl(factl(k), 3) * pow(a, k + 0.5);
		r += n / d;
	}

	r *= 12;
	return 1 / r;
}

int main() {
	printf("%.17g\n", chudnovsky());
}
