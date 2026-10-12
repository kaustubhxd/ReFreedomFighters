// batch1013.cpp - unclaimed-04 batch 14 (docs/20-unclaimed-04.md): comparator 0x5bfdd0 (cdecl, two record pointers).
// Returns 1 when a.key - b.key > 0.0f, else -1 (equal keys and NaN give -1). The key is the float at +4 of each 0x17-byte
// record. Used by qsort from the builder 0x5c0500 (GUESS name: a comparator on the record key).
#include "ff.h"

static s32 __attribute__((cdecl)) entityRecordCompare(const u8 *a, const u8 *b) {
  float d = *(const float *)(a + 4) - *(const float *)(b + 4);
  return d > 0.0f ? 1 : -1;
}
PCREG(5bfdd0, entityRecordCompare);
