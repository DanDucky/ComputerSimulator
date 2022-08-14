#include "InstructionCompiler.h"
#include <stdio.h>

uint8_t *instructioncompiler(uint8_t instruction[8]) {
    /*
     * Instruction Compiler:
     * > compiles 8 bit instructions into 18 bit internal commands
     * If input is DECL or MOVE then store last 6 bits into a pointer array
     * pointer array should be freed after second call of instructioncompiler()
     * after second then return ret (return array) with first 4 bits included
     * on second call, free() the memory for the temporary storage before full output
     *
     * 8/11/22 - Now uses uint_8 instead of bool for binary arrays
     */
    uint8_t *compiledInstruction = malloc(18);
    for (int i = 0; i < 18; i++) {
        compiledInstruction[i] = 0;
    }
    static uint8_t instructionHold[7];
    static int cycle;
    if (instruction[0] == 0 && cycle != 1) {
        cycle = 1;
        for (int i= 0; i < 7; i++) {
            instructionHold[i] = instruction[i + 1];
        }
    } else if (instruction[0] == 1 && cycle != 1) {
        cycle = 0;
        if (instruction[1] == 1) {
            compiledInstruction[3] = 1;
        } else if (instruction[1] == 0) {
            compiledInstruction[1] = 1;
        }
        int ii = 0;
        for (int i = 10; i < 18; i++, ii++ ) {
            compiledInstruction[i] = instruction[ii];
        }
    } else if (cycle == 1) {
        if (instructionHold[0] == 1) {
            compiledInstruction[2] = 1;
        } else if (instructionHold[0] == 0) {
            compiledInstruction[0] = 1;
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
