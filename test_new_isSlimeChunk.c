#include <stdio.h>
#include <stdbool.h>
#include "OnlyNeededFunctions.h"

int main() {
	const int chunk_x_begin = -1874999;
	const int chunk_x_end = 1874998;
	const int chunk_z_begin = -1874999;
	const int chunk_z_end = 1874998;

	for (int chunk_x = -100; chunk_x != 100; chunk_x++) {
		for (int chunk_z = -100; chunk_z != 100; chunk_z++) {
			const bool result1 = isSlimeChunk(chunk_x, chunk_z); // Seed equals zero for optimizations.
			const bool result2 = MyIsSlimeChunk(chunk_x, chunk_z); // Seed equals zero for optimizations.
			if (result1 != result2) printf("False at chunk_x=%d; chunk_z%d\n", chunk_x, chunk_z);
		}
	}

	printf("\n");
}
