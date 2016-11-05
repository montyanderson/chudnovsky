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
	long double r = 0.00, k, n, d;
	const long double a = powl(640320.00, 3.00);

	for(k = 0; k < 200.00; k += 1) {
		n = powl(-1.00, k) * factl(6.00 * k) * (545140134.00 * k + 13591409.00);
		d = factl(3.00 * k) * powl(factl(k), 3.00) * powl(a, k + 0.5);
		r += n / d;
	}

	r *= 12;
	return 1 / r;
}

int main() {
	printf("%Le\n", chudnovsky());
}
