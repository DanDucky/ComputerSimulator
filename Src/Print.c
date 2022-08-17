#include "Print.h"

//void printbox (char contents[1][1], char title[12]) {
//
//}

char *tobinary (uint8_t length, uint8_t *input) {
    
}

void printm () { // "print metrics"
    /*
     * How I would like it to look:
     *
     * Instruction ─────────────────────────────────────────────────────────╮
     * ├─ Instruction Position ───────[ MEMO17                              │
     * ├─ Instruction Type ───────────[ DECL                                │
     * ├─ Instruction Binary ─────────[ ● ● ● ○ ○ ○ ○ ○ ○ ○ ○ ○ 10100101001 │
     * ├─ Compiled Instruction ───────[ ● ● ● ○ ○ ○ ○ ○ ○ ○ ○ ○ 10100101001 │
     * ╰────────────────────────────────────────────────────────────────────╯
     */
    //TITLE
    printf("\x1b[2J");
    // Maybe some of following should be in "system specs" area
    printf("\033[1mBreadboard Computer Simulator\033[0m\nVersion: 0.0.1, 8/16/22\nBytecode file: (ADD FILE NAME PLEASE)\nClock speed: (ADD CLOCK SPEED)\n\n"); // "header"
    printf("\033[1mSystem\033[0m ");
}
