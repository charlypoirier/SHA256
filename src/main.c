#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"
#include "constants.h"

int main(int argc, char** argv) {
    
    if (argc == 1) {
        printf("Usage: ./bin/sha256 <input>\n");
        return 1;
    }

    char* message = argv[1];
    size_t message_size = strlen(message) * 8;

    // Create a buffer
    size_t buffer_size = 512 * ((message_size + 65) / 512 + 1);
    void* buffer = malloc(buffer_size);

    // Fill it with message (TODO: padding and size)
    memcpy(buffer, message, message_size);
    // fwrite(buffer, 1, buffer_size, stdout);
    // printf("\n\n");

    // Split in 512-bits message blocks

    // Message schedule
    
    // Compression

    // Final hash value
    printf("This is a work in progress\n");
    
    free(buffer);
    return 0;
}