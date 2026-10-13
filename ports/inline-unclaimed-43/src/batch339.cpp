// batch339.cpp - 0x41d0b0 (gap band). Returns 0x186a0 in eax. No arguments.
#include "ff.h"

static u32 THISCALL returnHundredThousandish(void) {
  return 0x186a0u;
}
PCREG(41d0b0, returnHundredThousandish);
