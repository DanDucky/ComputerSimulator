#include "InstructionCompiler.h"
#include "FileOps.h"
#include <stdio.h>
#include <stdint.h>

int main (int argc,char* argv[]) {
    // TEST INSTRUCTION MOVE MEMO12 MEMO11 KEEP (00010110, 01010110)
    uint8_t instruction[8] = {0, 1, 0, 1, 0, 1, 1, 0};
    uint8_t instruction2[8] = {0, 1, 0, 1, 0, 1, 1, 0};
    uint8_t* compiledInstruction = instructioncompiler(instruction);
    compiledInstruction = instructioncompiler(instruction2);
    for (int i = 0; i < 18; i++) {
        printf("%u", compiledInstruction[i]);
    }

    // FREE ALL POINTERS PLS
    free(compiledInstruction);

    return 0;
}
