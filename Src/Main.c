#include "InstructionCompiler.h"
#include "InstructionDriver.h"
#include "FileOps.h" // for init of file from argv
#include <stdio.h>
#include <stdint.h>

int main (int argc,char* argv[]) {
    fileinit(argv[0]);
    // TEST INSTRUCTION MOVE MEMO12 MEMO11 KEEP (00010110, 01010110)
    //uint8_t instruction[8] = {0, 1, 0, 1, 0, 1, 1, 0};
    //uint8_t instruction2[8] = {0, 1, 0, 1, 0, 1, 1, 0};
    //uint8_t* compiledInstruction = instructioncompiler(instruction);
    //compiledInstruction = instructioncompiler(instruction2);
    //for (int i = 0; i < 18; i++) {
    //    printf("%u", compiledInstruction[i]); %u is important pls rembr
    //}
    bool clock = true;
    while (clock == true) { // please for the love of god do not run this yet
        uint8_t* instruction = instructionget();
        uint8_t* compiledInstruction = instructioncompiler(instruction);
        // see below comment for what to put here
        free(instruction);
        free(compiledInstruction);
    }
    /*
     * Possible chain of command?
     * instructionget -> instructioncompiler -> (following do not need to be in any particular order) -> instructiondriver && storagedriver
     */
    // FREE ALL POINTERS PLS
    fileclose();
    free(argv);
    return 0;
}
