#ifndef STORAGEDRIVER_H_
#define STORAGEDRIVER_H_

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

static uint8_t readPos;
static bool readOnly;

void instructiondriver(bool instruction[7]);
uint8_t *instructionget();

#endif /* STORAGEDRIVER_H_ */
