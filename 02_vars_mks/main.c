#include <stdio.h>

int main() {
	unsigned int x = 6402L;
	char a_12;
	long random;
	++x;
	a_12 = 'a';
	x *= a_12++;
	printf("Total: %d\tSize: %ld\n", x, sizeof(x));
	x *= ( random = 10 );
	printf("Total: %d\tSize: %ld\n", x, sizeof(x));
	x = a_12;
	printf("Total: %d\tSize: %ld\n", x, sizeof(x));
	x >>= a_12;
	printf("Total: %d\tSize: %ld\n", x, sizeof(x));
	return 0;
}
