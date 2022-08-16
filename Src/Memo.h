#ifndef MEMO_H_
#define MEMO_H_

#include <stdint.h>

void writememo(uint8_t position, uint8_t value[]);
uint8_t *readmemo(uint8_t position);

#endif /* MEMO_H_ */
