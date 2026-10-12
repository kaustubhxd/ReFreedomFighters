// batch1958.cpp - unclaimed-66 batch 68 (gap band, GUESS name). Cdecl, no arguments; returns eax.
//   If the global at 0x7011fc is set: return vtable +0x24 of it (no arguments).
//   Else p = 0x41e290(0xc) (cdecl allocator, hooked by address); if p: [p+4] = 1, [p+8] = 0, [p] = 0x69d2ec; [0x7011fc] = p;
//   0x50b420(ECX = p) (THISCALL, no arguments; a GUESS stub by address); return [0x7011fc].
#include "ff.h"

extern "C" void *ext_41e290(u32 size);           // cdecl, one argument (hooked in the spec)
extern "C" void THISCALL ext_50b420(u8 *self);   // THISCALL, no arguments, plain ret (hooked in the spec)

// 0x50b620, GUESS FUN_0050b620 (batch 68).
static u32 gapGet50b620(void) {
  u8 *obj = *(u8 **)0x7011fc;
  if (obj) return vcall<u32>(obj, 0x24);
  u8 *p = (u8 *)ext_41e290(0xc);
  if (p) {
    *(u32 *)(p + 4) = 1;
    *(u32 *)(p + 8) = 0;
    *(u32 *)p = 0x69d2ec;
  }
  *(u32 *)0x7011fc = (u32)p;
  ext_50b420(p);
  return *(u32 *)0x7011fc;
}
PCREG(50b620, gapGet50b620);
