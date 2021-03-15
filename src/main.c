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

    // Initial hash values
    uint32_t h[] = { 0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19 };

    // Process 512-bit chunks
    uint8_t chunk[64];
    memset(chunk, 0, sizeof(chunk));

    while (size > 0) {

        int n = size < 64 ? size : 64;
        memcpy(chunk, data, n);
        data = data + n;

        // Padding
        if (64 - n > 0) {
            chunk[n] = 0b10000000;
            for (int i=n+1; i<64; ++i) {
                chunk[i] = 0b00000000;
            }
        }

        printf("\n");
        for (int i=0; i<64; ++i) {
            printf("%02x ", chunk[i]);
        }
        printf("\n");

        // Message schedule (w0..w15 binary operations)
        // Compression (h0..h15 binary operations)

        size -= n;
    }

    // Final hash
    printf("\n");
    for (int i=0; i<8; ++i) {
        printf("%08x", h[i]);
	}
    printf("\n");
    
    return EXIT_SUCCESS;
}
