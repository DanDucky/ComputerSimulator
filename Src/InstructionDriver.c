#include "InstructionDriver.h"
#include "Decoder.h"

static uint8_t readPos = 0;
static bool readOnly = true;

void instructiondriver(uint8_t instructionIn[7]) {
    /*
     * Storage Driver:
     * > decides which line of read only or memory to read instructions from
     * If instruction[1] is true then execute GOTO command
     * else just increase current counter
     */
    if (instructionIn[1] == 1) { // change read position to instruction
    	switch (instructionIn[2]) {
    	case 0: // MEMO
    		break;
    	case 1: // READ ONLY
    		uint8_t passDecode[5];
    		for (int i = 0; i < 5; i++) {
    			passDecode[i] = instructionIn[i + 3];
    		}
    		readPos = Decoder(passDecode, 5);
    		break;
    	}
    } else if (readOnly == true) {
        readPos++;
    } else if (readOnly == false) {
        readPos++;
    }
    return;
}

uint8_t *instructionget() {
    uint8_t *instructionOut = malloc(8);
    return instructionOut;
}
