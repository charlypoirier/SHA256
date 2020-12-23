#include <stdio.h>
#include "functions.h"

int main(int argc, char** argv) {
    
    if (argc == 1) {
        printf("Usage: ./bin/sha256 <input>\n");
        return 1;
    }

    // Conversion to bytes
    char* input = argv[0];

    // Padding and blocks
    
    // Message schedule
    
    // Compression

    // Final hash value
    printf("This is a work in progress\n");
    
    return 0;
}