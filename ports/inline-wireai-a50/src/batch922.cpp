// batch922.cpp - residue-9 slice: 0x4d1f10 [thiscall (ECX = this), one stack arg (a), ret 4, returns a dword]. Body read in full:
// blk = 0x41e290 (cdecl, size 0x38); if blk is null, return 0 (the exe's eax); otherwise call 0x4d1320 on blk (thiscall: three words
// a, this, -1; the callee pops them) and return its eax. Stood in: 0x41e290 and 0x4d1320.
#include "ff.h"

extern "C" void *ext_41e290(u32 size);                                  // stood in (cdecl)
extern "C" u32 THISCALL ext_4d1320(void *obj, u32 a, void *self, u32 n);  // stood in; three words, callee pops

// 0x4d1f10 (no name in the map).
static u32 THISCALL Make4d1f10(u8 *self, u32 a) {
  void *blk = ext_41e290(0x38u);
  if (!blk) return 0;
  return ext_4d1320(blk, a, self, 0xffffffffu);
}
PCREG(4d1f10, Make4d1f10);
