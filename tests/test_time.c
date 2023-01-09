#include <stdio.h>
#include <time.h>

#include "../src/library.h"


int main() {
	const int chunk_x_begin = -100;
	const int chunk_x_end = 100;
	const int chunk_z_begin = -100;
	const int chunk_z_end = 100;
	
	uint64_t seed_begin = 0;
	uint64_t seed_end = 10000;
	uint64_t slime_chunks_count = 0;
	
	time_t time_before = time(NULL);
	
	for (uint64_t seed_current = seed_begin; seed_current != seed_end+1; seed_current++) {
		for (int chunk_x_current = chunk_x_begin; chunk_x_current != chunk_x_end+1; chunk_x_current++) {
			for (int chunk_z_current = chunk_z_begin; chunk_z_current != chunk_z_end+1; chunk_z_current++) {
				if (isSlimeChunk(seed_current, chunk_x_current, chunk_z_current)) slime_chunks_count++;
			}
		}
	}
	
	time_t time_after = time(NULL);
	
	int time_elapsed = time_after - time_before;
	
	printf("Time elapsed: %d seconds.\n", time_elapsed);
	
	return 0;
}