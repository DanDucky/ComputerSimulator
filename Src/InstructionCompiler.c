#include "InstructionCompiler.h"

bool *instructioncompiler(bool instruction[8]) {
    /*
     * Instruction Compiler:
     * > compiles 8 bit instructions into 18 bit internal commands
     * If input is DECL or MOVE then store last 6 bits into a pointer array
     * pointer array should be freed after second call of instructioncompiler()
     * after second then return ret (return array) with first 4 bits included
     * on second call, free() the memory for the temporary storage before full output
     */
    bool *compiledInstruction = malloc(18);
    for (int i = 0; i < 18; i++) {
        compiledInstruction[i] = false;
    }
    static bool instructionHold[7];
    static int cycle;
    if (instruction[0] == false && cycle != 1) {
        cycle = 1;
        for (int i= 0; i < 7; i++) {
            instructionHold[i] = instruction[i + 1];
        }
    } else if (instruction[0] == true && cycle != 1) {
        cycle = 0;
        if (instruction[1] == true) {
            compiledInstruction[3] = true;
        } else if (instruction[1] == false) {
            compiledInstruction[1] = true;
        }
        int ii = 0;
        for (int i = 10; i < 18; i++, ii++ ) {
            compiledInstruction[i] = instruction[ii];
        }
    } else if (cycle == 1) {
        if (instructionHold[0] == true) {
            compiledInstruction[2] = true;
        } else if (instructionHold[0] == false) {
            compiledInstruction[0] = true;
        }
        int ii = 4;
        for (int i = 1; i < 7; i++, ii++) {
            compiledInstruction[ii] = instructionHold[i];
        }
        ii = 10;
        for (int i = 0; i < 8; i++, ii++) {
            compiledInstruction[ii] = instruction[i];
        }
        cycle = 0;
    }
    return compiledInstruction;
}
