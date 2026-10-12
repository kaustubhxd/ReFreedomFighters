// batch1043.cpp - unclaimed-04 batch 43 (docs/20-unclaimed-04.md): 0x6128b0, thiscall, no arguments, plain ret.
#include "ff.h"

extern "C" u32 __attribute__((stdcall)) ext_634cf2(u32 value, u32 *out);  // hooked by address in the spec (GUESS)
extern "C" void *__attribute__((stdcall)) ext_634ce0(u32 size);           // hooked by address in the spec (GUESS)

// 0x6128b0: out = 0; r = query(this+4, &out); if r != 0, this+8 = r. If the 0x10-byte block is allocated: {0x6bd5d0, out, this+8}.
static void THISCALL unk6128b0(u8 *self) {
  u32 out = 0;
  u32 r = ext_634cf2(*(u32 *)(self + 4), &out);
  if (r != 0) *(u32 *)(self + 8) = r;
  u8 *p = (u8 *)ext_634ce0(0x10);
  if (p != 0) {
    u32 edx = *(u32 *)(self + 8);
    *(u32 *)p = 0x6bd5d0;
    *(u32 *)(p + 4) = out;
    *(u32 *)(p + 8) = edx;
  }
}
PCREG(6128b0, unk6128b0);
