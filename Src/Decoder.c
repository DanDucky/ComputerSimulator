#include "Decoder.h"
uint8_t decode(const uint8_t input[], const uint8_t arrSize) {
	uint8_t output = 0;
	for (int i = 0; i < arrSize; i++) {
		output = input[i] * pow(2, i + 1) + output;
	}
	return output;
}
