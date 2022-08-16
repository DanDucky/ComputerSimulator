#ifndef FILEOPS_H_
#define FILEOPS_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void fileinit(char *file);
uint8_t *fileread(uint8_t line);
void fileclose();

#endif /* FILEOPS_H_ */
