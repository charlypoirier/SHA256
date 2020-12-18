#include "functions.h"

uint32_t s0 (uint32_t w) {
    int32_t a = (w >> 7)|(w << (32 - 7));   // ROTR7
    int32_t b = (w >> 18)|(w << (32 - 18)); // ROTR18
    int32_t c = (w >> 3);                   // SHR3
    return a ^ b ^ c;
}

uint32_t s1 (uint32_t w) {
    int32_t a = (w >> 17)|(w << (32 - 17)); // ROTR17
    int32_t b = (w >> 19)|(w << (32 - 19)); // ROTR19
    int32_t c = (w >> 10);                  // SHR10
    return a ^ b ^ c;
}

uint32_t S0 (uint32_t w) {
    int32_t a = (w >> 2)|(w << (32 - 2));   // ROTR2
    int32_t b = (w >> 13)|(w << (32 - 13)); // ROTR13
    int32_t c = (w >> 22)|(w << (32 - 22)); // ROTR22
    return a ^ b ^ c;
}

uint32_t S1 (uint32_t w) {
    int32_t a = (w >> 6)|(w << (32 - 6));   // ROTR6
    int32_t b = (w >> 11)|(w << (32 - 11)); // ROTR11
    int32_t c = (w >> 25)|(w << (32 - 25)); // ROTR25
    return a ^ b ^ c;
}