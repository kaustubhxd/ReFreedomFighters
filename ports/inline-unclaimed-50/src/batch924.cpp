// batch924.cpp - 0x45f960 [thiscall (ECX = this), one stack arg (a stream object), ret 4, returns al = 1]. Body read in full.
// The stream's slot +0x3c is called with this+0x14. Then x = this+0x10: the word at x+0x18 (0 when x is null or that word is 0) is passed
// to the stream's slot +0x3c. Returns 1.
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

// 0x45f960 (no name in the map).
static bool THISCALL Write45f960(u8 *self, u8 *stream) {
  vcall<void>(stream, 0x3c, U32(self, 0x14));
  u32 v = 0;
  u8 *x = (u8 *)FP(self, 0x10);
  if (x) {
    u32 w = U32(x, 0x18);
    if (w) v = w;
  }
  vcall<void>(stream, 0x3c, v);
  return true;
}
PCREG(45f960, Write45f960);
