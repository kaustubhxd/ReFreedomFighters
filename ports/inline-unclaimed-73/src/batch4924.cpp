// batch4924.cpp - area 73 batch 49 (gap band, GUESS name): FUN_4e6420, a bytecode cursor advance.
// this is a pointer to a cursor (u8 *). kind = (opcode & 0x3f) - 1. The jump table maps kinds 0..10 to five cases;
// kinds outside 0..10 leave the cursor unchanged.
#include "ff.h"

static void THISCALL guess4e6420(u8 **self) {
  u8 *p = *self;
  u32 kind = (u32)((p[0] & 0x3f) - 1);
  if (kind > 10)
    return;
  switch (kind) {
  case 0:
    *self = p + 9;
    return;
  case 1:
  case 2:
  case 7:
  case 9:
  case 10:
    *self = p + 5;
    return;
  case 3:
  case 4: {
    // Skip the opcode and a NUL-terminated string that starts at p+1.
    const u8 *s = p + 1;
    while (*s)
      s++;
    *self = p + 2 + (u32)(s - (p + 1));
    return;
  }
  case 6:
  case 8:
    *self = p + 1 + *(u32 *)(p + 1);
    return;
  default:
    return; // kind 5: unchanged
  }
}
PCREG(4e6420, guess4e6420);
