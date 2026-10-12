// batch234.cpp - area 59 (residue 18), docs/20-unclaimed-59.md. A ring of free ids: pop from a stack when it is not empty,
// otherwise take the next id (or, when the read cursor reaches the mask, read a byte from a buffer and call 0x45c0e0);
// then write the id into the buffer at the write cursor, clear its table slot, and advance the write cursor. Name GUESS.
#include "ff.h"

extern "C" void THISCALL ext_45c0e0(u8 *self, u32 id);   // original, thiscall, one stack word (ret 4)

// 0x45b620, thiscall() ret plain.
static void THISCALL ringPop_45b620(u8 *self) {
  u32 ebx;
  u32 cnt = *(u32 *)(self + 0x30);
  if (cnt != 0) {
    u32 *list = *(u32 **)(self + 0x24c);
    cnt -= 1;
    ebx = list[0];
    *(u32 *)(self + 0x30) = cnt;
    list[0] = list[cnt];
  } else {
    u32 cap1 = *(u32 *)(self + 0x1c) - 1;
    ebx = *(u32 *)(self + 0x34);
    if (ebx == cap1) {
      u32 cur = *(u32 *)(self + 0x3c);
      ebx = *(u8 *)(*(u8 **)(self + 0x248) + cur);
      *(u32 *)(self + 0x3c) = cur + 1;
      ext_45c0e0(self, ebx);
      *(u32 *)(self + 0x3c) &= *(u32 *)(self + 0x1c) - 1;
    } else {
      *(u32 *)(self + 0x34) = ebx + 1;
    }
  }
  u32 w = *(u32 *)(self + 0x38);
  *(u8 *)(*(u8 **)(self + 0x248) + w) = (u8)ebx;
  u32 *tab = *(u32 **)(self + 0x250);
  *(u32 *)(self + 0x38) = w + 1;
  tab[ebx] = 0;
  *(u32 *)(self + 0x38) &= *(u32 *)(self + 0x1c) - 1;
}
PCREG(45b620, ringPop_45b620);
