#include "StorageDriver.h"

bool *instructiondriver(bool instructionIn[7]) {
    /*
     * Storage Driver:
     * > decides which line of read only or memory to read instructions from
     * If instruction[1] is true then execute GOTO command
     * else just increase current counter
     */
    bool *instructionOut = malloc(8);
    static uint8_t readPos = 0;
    static bool readOnly = true;
    if (instructionIn[1] == true) {
    } else if (readOnly == true) {
        readPos++;
    } else if (readOnly == false) {
        readPos++;
    }
    return instructionOut;
}
