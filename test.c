#include <stdio.h>
#include <time.h>

int main() {
	clock_t t;
	t = clock();
	printf("%ld\n", t / CLOCKS_PER_SEC);
}
