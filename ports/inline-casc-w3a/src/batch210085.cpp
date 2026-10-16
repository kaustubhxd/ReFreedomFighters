// batch210085.cpp - Sonnet-w3a: 0x4d0b10 (free the pointer stored just before this, through the import at 0x6762ec)
#include "ff.h"

typedef u32 (*FreeFn)(u32 p);

static u32 THISCALL fn4d0b10(u8 *self) {
  // the exe also reads dword [[0x6762f0] + 0x18] and compares it with 0xd; both branches call the same import with the same argument
  return G(FreeFn, 0x6762ec)(*(u32 *)(self - 4));  // @4d0b10_a
}
PCREG(4d0b10, fn4d0b10);
