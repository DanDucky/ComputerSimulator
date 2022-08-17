#include "InstructionDriver.h"
#include "Decoder.h"

static uint8_t readPos = 0;
static uint8_t condition = 0; // condition:
                              // 0 = read only
                              // 1 = read from memo
                              // 2 = skip line EDIT: just realized this is completely unnecessary as the instruction driver can simply handle this and
                              //                     instructionget() does not need to care about the fact that the previous line was a skip (BLNK) IT SHOULD BE A BOOL BUT I'M TOO TIRED TO FIX THAT, HERE'S A TODO I GUESS

void instructiondriver(uint8_t instructionIn[7]) {
    /*
     * Storage Driver:
     * > decides which line of read only or memory to read instructions from
     * If instruction[1] is true then execute GOTO command
     * else just increase current counter
     */
    static uint8_t passDecode[5];
    if (instructionIn[1] == 1 && instructionIn[6] != 1) { // change read position to instruction
    	switch (instructionIn[2]) {
    	case 0: // MEMO
            condition = 1;
            for (int i = 0; i < 4; i++) {
                passDecode[i] = instructionIn[i + 3];
            }
            if (decode(passDecode, 4) - 1 < 24) {
            	readPos = (decode(passDecode, 4) - 1) * 8;
            } else { // 24 25 26 27 28 29 30 31
            	readPos = decode(passDecode, 4) - 1 + 175;
            }
    		break;
    	case 1: // READ ONLY
            condition = 0;
    		for (int i = 0; i < 5; i++) {
    			passDecode[i] = instructionIn[i + 3];
    		}
    		readPos = decode(passDecode, 5) - 1;
    		break;
    	}
    } else { // handles both BLNK calls (technically GOTO) and handles the fact that sometimes we're not calling GOTO
        // TODO create "adder" file which is an alternative to the current ++ system which rolls over at the desired number to emulate a 1 bit adder
    	// EDIT: dammit I just realized that if I had used C++ I could create an "8 bit int" class which would have an "add" method which would roll over 3:<
        readPos++;
    }
    return;
}

uint8_t *instructionget() {
    uint8_t *instructionOut = malloc(8);
    switch (condition) {
        case 0:
            // ADD IN FUNCTION FROM "FileOps.h"
            instructionOut = fileread(readPos); // TODO account for the fact that readPos will be only the "readPos" that it programmed, meaning the 32bits of steps, not the actual 200 bytes of instructions
            break;
        case 1:
            // GET FROM MEMORY THE SELECTED BYTE (Memo.h?)
            break;
    }
    return instructionOut;
}
