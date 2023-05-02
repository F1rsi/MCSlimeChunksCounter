#include <stdio.h>
#include <time.h>

#include "OnlyNeededFunctions.h"

int main() {
	const int chunk_x_begin = -1874999;
	const int chunk_x_end = 1874998 + 1; // Because I use "!=" instead of "<=".
	const int chunk_z_begin = -1874999;
	const int chunk_z_end = 1874998 + 1; // Because I use "!=" instead of "<=".

	clock_t t;

	long unsigned int chunk_slimes_count = 0;
	for (int chunk_x_current = chunk_x_begin; chunk_x_current != chunk_x_end; chunk_x_current++) {
		t = clock();

		for (int chunk_z_current = chunk_z_begin; chunk_z_current != chunk_z_end; chunk_z_current++)
			if (isSlimeChunk(chunk_x_current, chunk_z_current)) chunk_slimes_count++;

		t = clock() - t;
		printf("Chunk x at %d has been finished with time equals %fms!\n",
			   chunk_x_current, t / (double) CLOCKS_PER_SEC * 1000.0);
	}

	printf("%lu\n", chunk_slimes_count);
	return 0;
}

