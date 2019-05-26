#include <stdint.h>
#include "params.h"

typedef  uint64_t block[2]; //a block is 128-bit
block mRoundKey[11];

static inline block toBlock(uint8_t*data) { }
static inline block toBlockLow(uint64_t low_u64)        { }
static inline block toBlockBoth(uint64_t high_u64, uint64_t low_u64) { }

// Encrypts the vector of blocks {baseIdx, baseIdx + 1, ..., baseIdx + length - 1} 
// and writes the result to cyphertext.
void ecbEncCounterMode(uint64_t baseIdx, uint64_t length, block* cyphertext) {};
void setKey(block userKey) {};

