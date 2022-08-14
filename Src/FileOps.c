#include "FileOps.h"

FILE *binary;

void fileInit(char *file) {
    binary = fopen(file, "r");
}

uint8_t *readFile(int line) { // line is 0 based ( B) )
    uint8_t *instructionOut = malloc(8);
    char instructionIn[8];
    fgets(instructionIn, 8, binary);
    for (int cLine = 0; line != cLine; cLine++) {
        fgets(instructionIn, 8, binary);
    }
    for (int i = 0; i < 8; i++) {
    	instructionOut[i] = atoi(&instructionIn[i]);
    }
    return instructionOut;
}
