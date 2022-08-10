#include "InstructionCompiler.h"
#include <stdio.h>

int main (int argc,char* argv[]) {
    // TEST INSTRUCTION MOVE MEMO12 MEMO11 KEEP (00010110, 01010110)
    bool instruction[8] = {false, false, false, true, false, true, true, false};
    bool instruction2[8] = {false, true, false, true, false, true, true, false};
    bool* compiledInstruction = instructioncompiler(instruction);
    compiledInstruction = instructioncompiler(instruction2);
    for (int i = 0; i < 18; i++) {
        if (compiledInstruction[i] == true) {
            printf("1");
        } else if (compiledInstruction[i] == false) {
            printf("0");
        }
    }

    // FREE ALL POINTERS PLS
    free(compiledInstruction);
}
