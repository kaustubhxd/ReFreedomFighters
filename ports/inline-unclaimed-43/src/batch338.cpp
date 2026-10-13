// batch338.cpp - 0x4063c0 (gap band 0x401000-0x421000). Returns 0x80 in eax. No arguments.
#include "ff.h"

static u32 THISCALL returnEighty(void) {
  return 0x80u;
}
PCREG(4063c0, returnEighty);
