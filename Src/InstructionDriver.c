#include "InstructionDriver.h"

static uint8_t readPos = 0;
static bool readOnly = true;

void instructiondriver(bool instructionIn[7]) {
    /*
     * Storage Driver:
     * > decides which line of read only or memory to read instructions from
     * If instruction[1] is true then execute GOTO command
     * else just increase current counter
     */
    if (instructionIn[1] == true) {
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
