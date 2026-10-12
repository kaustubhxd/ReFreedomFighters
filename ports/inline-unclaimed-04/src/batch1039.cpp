// batch1039.cpp - unclaimed-04 batch 39 (docs/20-unclaimed-04.md): 0x64b430, thiscall, one stack argument (key), ret 4.
#include "ff.h"

// 0x64b430: the i-th entry E (i < count) leads to node2 = (E+0xc)+0xc; node2+8 == key returns this+0x10075, else 0.
static u8 *THISCALL unk64b430FindChain(u8 *self, u32 key) {
  u32 count = *(u32 *)(self + 0x10089);
  u32 *arr = (u32 *)(self + 0x1008d);
  for (u32 i = 0; i < count; i++) {
    u8 *e = (u8 *)arr[i];
    u8 *node = *(u8 **)(e + 0xc);
    u8 *node2 = *(u8 **)(node + 0xc);
    if (*(u32 *)(node2 + 8) == key) return self + 0x10075;
  }
  return 0;
}
PCREG(64b430, unk64b430FindChain);
