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
        printf("Usage: ./bin/sha256 <input>\n");
        return EXIT_FAILURE;
    }

    char* message = argv[1];
    size_t length = strlen(message) * 8;

    // Hash values
    uint32_t h[] = { 0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19 };

    ///////////
    // To do //
    ///////////

    // Final digest
    for (int i=0; i<8; ++i) {
        printf("%08x", h[i]);
	}
    printf("\n");
    
    return EXIT_SUCCESS;
}