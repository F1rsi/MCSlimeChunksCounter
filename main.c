#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include "cubiomes/finders.h"

int main() {
	int chunk_x_begin = -1874999;
	int chunk_x_end = 1874998;
	int chunk_z_begin = -1874999;
	int chunk_z_end = 1874998;

	clock_t t;

	long unsigned int chunk_slimes_count = 0;
	for (int chunk_x = chunk_x_begin; chunk_x != chunk_x_end; chunk_x++) {
		t = clock();
		for (int chunk_z = chunk_z_begin; chunk_z != chunk_z_end; chunk_z++) {
			bool result = isSlimeChunk(0, chunk_x, chunk_z);
			if (result) chunk_slimes_count++;
		}
		t = clock() - t;
		printf("Chunk x at %d has been finished with time equals %fms!\n",
			   chunk_x, t / (double) CLOCKS_PER_SEC * 1000.0);
	}

	printf("%lu\n", chunk_slimes_count);
	return 0;
}

