// batch7575.cpp - area 73 batch 75 (unmentioned band rows, GUESS names): FUN_4fc090 and FUN_4f4f00.
#include "ff.h"

extern "C" void THISCALL ext_4ee4e0(u8 *self);
extern "C" void __attribute__((cdecl)) ext_45c510(void *p);
extern "C" void __attribute__((cdecl)) ext_4690b0(void *p, u32 n);

// 0x4fc090 (GUESS FUN_4fc090): ret 4. Copies six words from the argument object to this, at offsets 0x54 to 0x5e.
static void THISCALL guess4fc090(u8 *self, u8 *src) {
  for (u32 off = 0x54; off <= 0x5e; off += 2)
    *(u16 *)(self + off) = *(u16 *)(src + off);
}
PCREG(4fc090, guess4fc090);

// 0x4f4f00 (GUESS FUN_4f4f00): ret 4, returns this. 0x4ee4e0 on this with no arguments; flag bit 0 gives 0x4690b0(this, 0xc3) when
// bit 2 is set, else 0x45c510(this).
static u8 *THISCALL guess4f4f00(u8 *self, u32 flags) {
  ext_4ee4e0(self);
  if (flags & 1) {
    if (flags & 4)
      ext_4690b0(self, 0xc3u);
    else
      ext_45c510(self);
  }
  return self;
}
PCREG(4f4f00, guess4f4f00);
