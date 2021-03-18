#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"
#include "constants.h"

/**
 * See https://en.wikipedia.org/wiki/SHA-2
 */
int main(int argc, char** argv) {
    
    if (argc == 1) {
        printf("Usage: ./sha256 <input>\n");
        return EXIT_FAILURE;
    }

    // Input data
    uint8_t* data = (uint8_t*)argv[1];
    uint64_t size = strlen(argv[1]);
    uint64_t totalSize = size;

    // Current hash values
    uint32_t h[] = { 0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19 };

    // Message schedule
    uint32_t W[64];

    // Process 512-bit chunks
    uint8_t chunk[64];
    memset(chunk, 0, sizeof(chunk));
    int done = 0;

    while (!done) {

        int n = size < 64 ? size : 64;
        memcpy(chunk, data, n);
        data = data + n;
        
        if (n < 64) {
            chunk[n] = 0b10000000;
            for (int i=n+1; i<56; ++i) {
                chunk[i] = 0b00000000;
            }
            if (n < 56) {
                for (int i=63; i>55; --i, totalSize >>= 8) {
                    chunk[i] = totalSize & 0b11111111;
                }
                done = 1;
            } else {
                for (int i=56; i<64; ++i) {
                    chunk[i] = 0b00000000;
                }
            }
        }

        // Message schedule
        for (int i=0, j=0; i<16; ++i, j+=4) {
            W[i] = (chunk[j] << 24) | (chunk[j+1] << 16) | (chunk[j+2] << 8) | (chunk[j+3]);
        }

        for (int i=16; i<64; ++i) {
            W[i] = s1(W[i-2]) + W[i-7] + s0(W[i-15]) + W[i-16];
        }

        // Compression
        for (int i=0; i<64; ++i) {
            uint32_t T1 = S1(h[4]) + choice(h[4], h[5], h[6]) + h[7] + K[i] + W[i];
            uint32_t T2 = S0(h[0]) + majority(h[0], h[1], h[2]);
            for (int j=7; j>0; --j) {
                h[j] = h[j-1];
            }
            h[0] = T1 + T2;
            h[4] += T1;
        }

        for (int i=0; i<7; ++i) {
            h[i] += H[i];
        }

        size -= n;
    }

    // Final hash
    for (int i=0; i<8; ++i) {
        printf("%08x", h[i]);
	}
    printf("\n");
    
    return EXIT_SUCCESS;
}
