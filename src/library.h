#include <stdint.h>


#if __GNUC__
#define ATTR(...) __attribute__((__VA_ARGS__))

#else
#define ATTR(...)

#endif


static inline void setSeed(uint64_t *seed, uint64_t value) {
    *seed = (value ^ 0x5deece66d) & ((1ULL << 48) - 1);
}


static inline int next(uint64_t *seed, const int bits) {
    *seed = (*seed * 0x5deece66d + 0xb) & ((1ULL << 48) - 1);
    return (int) ((int64_t)*seed >> (48 - bits));
}


static inline int nextInt(uint64_t *seed, const int n) {
    int bits, val;
    const int m = n - 1;

    if ((m & n) == 0) {
        uint64_t x = n * (uint64_t)next(seed, 31);
        return (int) ((int64_t) x >> 31);
    }

    do {
        bits = next(seed, 31);
        val = bits % n;
    }
    while (bits - val + m < 0);
    return val;
}


static inline ATTR(const)
int isSlimeChunk(uint64_t seed, int chunkX, int chunkZ) {
    uint64_t rnd = seed;
    rnd += (int)(chunkX * 0x5ac0db);
    rnd += (int)(chunkX * chunkX * 0x4c1906);
    rnd += (int)(chunkZ * 0x5f24f);
    rnd += (int)(chunkZ * chunkZ) * 0x4307a7ULL;
    rnd ^= 0x3ad8025fULL;
    setSeed(&rnd, rnd);
    return nextInt(&rnd, 10) == 0;
}
