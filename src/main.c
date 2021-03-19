#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"
#include "constants.h"

int main(int argc, char** argv) {
    
    if (argc == 1) {
        printf("Usage: ./sha256 <input>\n");
        return EXIT_FAILURE;
    }

    // Input data
    uint8_t* data = (uint8_t*)argv[1];
    uint64_t size = strlen(argv[1]);
    uint64_t totalSize = size * 8;

    // Initial hash values
    uint32_t H[] = { 0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19 };

    // Message schedule
    uint32_t W[64];

    // Process 512-bit chunks
    uint8_t chunk[64];
    memset(chunk, 0, sizeof(chunk));
    int oneDone = 0, sizeDone = 0;

    while (!sizeDone) {

        int n = size < 64 ? size : 64;
        memcpy(chunk, data, n);
        data = data + n;
        size -= n;

        // Padding
        if (size == 0 && n < 64) {
            if (!oneDone) {
                chunk[n] = 0b10000000;
                oneDone = 1;
            } else {
                chunk[n] = 0b00000000;
            }

            for (int i = n+1; i<64; ++i) {
                chunk[i] = 0b00000000;
            }

            if (n < 56) {
                for (int i=63; i>55; --i, totalSize >>= 8) {
                    chunk[i] = totalSize & 0b11111111;
                }
                sizeDone = 1;
            }
        }

        // Message schedule
        for (int i=0, j=0; i<16; ++i, j+=4) {
            W[i] = (chunk[j] << 24) | (chunk[j+1] << 16) | (chunk[j+2] << 8) | (chunk[j+3]);
        }

        for (int i=16; i<64; ++i) {
            W[i] = W[i-16] + s0(W[i-15]) + W[i-7] + s1(W[i-2]);
        }

        // Compression
        uint32_t a = H[0];
        uint32_t b = H[1];
        uint32_t c = H[2];
        uint32_t d = H[3];
        uint32_t e = H[4];
        uint32_t f = H[5];
        uint32_t g = H[6];
        uint32_t h = H[7];

        for (int i=0; i<64; ++i) {
            uint32_t T1 = S1(e) + choice(e, f, g) + h + K[i] + W[i];
            uint32_t T2 = S0(a) + majority(a, b, c);
            h = g;
            g = f;
            f = e;
            e = d + T1;
            d = c;
            c = b;
            b = a;
            a = T1 + T2;
        }

        H[0] += a;
        H[1] += b;
        H[2] += c;
        H[3] += d;
        H[4] += e;
        H[5] += f;
        H[6] += g;
        H[7] += h;
    }

    // Final hash
    for (int i=0; i<8; ++i) {
        printf("%08x", H[i]);
	}
    printf("\n");
    
    return EXIT_SUCCESS;
}
