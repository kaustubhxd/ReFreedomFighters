// batch5827.cpp - residue 9 (floor(addr/16) mod 20 = 9), 0x4b8a10 (ZRelayMessageList::Load(ZLoadGame*), name from gc name map), thiscall, one stack arg L, ret 4, returns al = 1.
// this+4 &= ~0x40; L->vt[+0x50](this+0x54); return 1.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef void(THISCALL *Slot1)(u8 *self, u32 a);

// 0x4b8a10, thiscall, one stack argument (ZRelayMessageList::Load)
static u8 THISCALL unnamed4b8a10(u8 *self, u8 *L) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  ((Slot1)VT(L)[0x50 / 4])(L, (u32)(unsigned long)(self + 0x54));
  return 1;
}
PCREG(4b8a10, unnamed4b8a10);
