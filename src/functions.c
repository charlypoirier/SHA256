#include "functions.h"

uint32_t rotateRight (const uint32_t x, const unsigned int n) {
    return (x >> n) | (x << (32 - n));
}

uint32_t s0 (const uint32_t x) {
    return rotateRight(x, 7) ^ rotateRight(x, 18) ^ (x >> 3);
}

uint32_t s1 (const uint32_t x) {
    return rotateRight(x, 17) ^ rotateRight(x, 19) ^ (x >> 10);
}

uint32_t S0 (const uint32_t x) {
    return rotateRight(x, 2) ^ rotateRight(x, 13) ^ rotateRight(x, 22);
}

uint32_t S1 (const uint32_t x) {
    return rotateRight(x, 6) ^ rotateRight(x, 11) ^ rotateRight(x, 25);
}

uint32_t choice (const uint32_t x, const uint32_t y, const uint32_t z) {
    return ((x) & (y)) ^ (~(x) & (z));
}

uint32_t majority (const uint32_t x, const uint32_t y, const uint32_t z) {
    return ((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z));
}
