#include <stdio.h>

int main(int argc, char** argv) {
    
    if (argc == 1) {
        printf("Usage: ./bin/sha256 <input>\n");
        return 1;
    }

    char* input = argv[0];
    // TODO: Hash the input string
    
    return 0;
}