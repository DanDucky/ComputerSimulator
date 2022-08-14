#ifndef FILEOPS_H_
#define FILEOPS_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void fileInit(char *file);
uint8_t *readFile();

#endif /* FILEOPS_H_ */
