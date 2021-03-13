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
    uint64_t length = strlen(argv[1]);
    uint64_t bits = length * 8;
    
    printf("Input data (decimal)\n");
    for (int i=0; i<length; ++i) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // Buffer
    uint8_t buffer[64];
    uint8_t size = length;
    memset(buffer, 0, sizeof(buffer));
    
    printf("\nBuffer (hexadecimal)\n");
    for (int i=0; i<64; ++i) {
        printf("%02x ", buffer[i]);
    }
    printf("\n");

    // Initial hash values
    uint32_t h[] = { 0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19 };

    // Pre-processing
    memcpy(buffer, data, size);
    buffer[size++] = 0b10000000;

    // Split in 512-bit blocks

    // Message schedule (w0..w15 binary operations)
    
    // Compression (h0..h15 binary operations)

    // Final hash
    printf("\nFinal hash\n");
    for (int i=0; i<8; ++i) {
        printf("%08x", h[i]);
	}
    printf("\n");
    
    return EXIT_SUCCESS;
}
