// batch6321.cpp - unclaimed-63 batch 21 (docs/20-unclaimed-63.md): 0x5ec7e0 (GUESS: a destructor of a vector of pointers, vptr
// 0x6b8114; no GC name). SEH frame not reproduced. Body: [this] = 0x6b8114; for each pointer p in [this+0xcb, this+0xcf) (4-byte
// steps): 0x634273(p, 0x10) (cdecl, caller cleans); then count = ([this+0xd3] - [this+0xcb]) >> 2 (signed); if count != 0:
// 0x54f870(ECX = this+0xcb; begin = [this+0xcb], size = count*4) (thiscall, two stack arguments, callee pops 8); then 0x5ebbd0(this)
// (thiscall, no arguments). Returns (ret). 0x634273, 0x54f870 and 0x5ebbd0 are original code, stubbed by the spec.
#include "ff.h"

extern "C" void ext_634273(void *p, u32 size);                 // cdecl, original, stubbed by the spec
extern "C" void THISCALL ext_54f870(void *self, u32 a, u32 b);  // thiscall, two stack arguments, original, stubbed by the spec
extern "C" void THISCALL ext_5ebbd0(void *self);                // original, stubbed by the spec

// 0x5ec7e0 (GUESS, vector of pointers destructor).
static void THISCALL vecPtrDtor(u8 *self) {
  *(u32 *)self = 0x6b8114u;
  u32 begin = *(u32 *)(self + 0xcb);
  u32 end = *(u32 *)(self + 0xcf);
  for (u32 p = begin; p != end; p += 4)
    ext_634273((void *)*(u32 *)p, 0x10);
  s32 count = (s32)(*(u32 *)(self + 0xd3) - *(u32 *)(self + 0xcb)) >> 2;
  if (count != 0)
    ext_54f870((void *)(self + 0xcb), *(u32 *)(self + 0xcb), (u32)count << 2);
  ext_5ebbd0((void *)self);
}
PCREG(5ec7e0, vecPtrDtor);
