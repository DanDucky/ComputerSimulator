#ifndef STORAGEDRIVER_H_
#define STORAGEDRIVER_H_

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

void instructiondriver(uint8_t instruction[7]);
uint8_t *instructionget();

#endif /* STORAGEDRIVER_H_ */
