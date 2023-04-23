#include <stdint.h>

#define ATTR(...)               __attribute__((__VA_ARGS__))

static inline void setSeed(uint64_t *seed, uint64_t value)
{
    *seed = (value ^ 0x5deece66d) & ((1ULL << 48) - 1);
}

//static inline int next(uint64_t *seed, const int bits)
static inline int next(uint64_t *seed)
{
    *seed = (*seed * 0x5deece66d + 0xb) & ((1ULL << 48) - 1);
    return (int) ((int64_t)*seed >> 17);
    //return (int) ((int64_t)*seed >> (48 - bits));
}

//static inline int nextInt(uint64_t *seed, const int n)
static inline int nextInt(uint64_t *seed) // n = 10
{
    int bits, val;
    //const int m = n - 1; // m = 9

    //if ((m & n) == 0) {
    //    uint64_t x = n * (uint64_t)next(seed, 31);
    //    return (int) ((int64_t) x >> 31);
    //}

    do {
        bits = next(seed);
        val = bits % 10;
    }
    //while (bits - val + m < 0);
    while (bits - val < -9);
    return val;
}

static inline ATTR(const)
//int isSlimeChunk(uint64_t seed, int chunkX, int chunkZ)
int isSlimeChunk(int chunkX, int chunkZ)
{
    uint64_t rnd = 0;
    rnd += (int)(chunkX * 0x5ac0db);
    rnd += (int)(chunkX * chunkX * 0x4c1906);
    rnd += (int)(chunkZ * 0x5f24f);
    rnd += (int)(chunkZ * chunkZ) * 0x4307a7ULL;
    rnd ^= 0x3ad8025fULL;
    setSeed(&rnd, rnd);
    return nextInt(&rnd) == 0;
}
