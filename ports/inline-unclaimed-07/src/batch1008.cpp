// batch1008.cpp - unclaimed-07 batch 8 (docs/20-unclaimed-07.md, slice 6): CMsgForwardToActors::Load.
// Name from the GC name map (high). Body from the PC bytes.
#include "ff.h"

// 0x49f260, CMsgForwardToActors::Load(ZLoadGame*) (high): clears bit 0x40 at this+4; load slot +0x44 with the address
// this+0x48, slot +0x44 with this+0x4a, slot +0x50 with this+0x4c; slot +0x40 reads a flag into the argument slot
// (initially the load pointer). When the flag is not 0: g_sys+0x9b+0xadc gives an object whose slot +0x25c(0x685f44, 0)
// result is stored at this+0x50. Returns true (al = 1).
static bool THISCALL msgForwardLoad(u8 *self, u32 load) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  vcall<void>((void *)load, 0x44, (u32)(self + 0x48));
  vcall<void>((void *)load, 0x44, (u32)(self + 0x4a));
  vcall<void>((void *)load, 0x50, (u32)(self + 0x4c));
  u32 slot = load;
  vcall<void>((void *)load, 0x40, &slot);
  if (slot != 0) {
    u8 *sys = G(u8 *, 0x70039c);
    u8 *a = *(u8 **)(sys + 0x9b);
    void *b = *(void **)(a + 0xadc);
    *(u32 *)(self + 0x50) = vcall<u32>(b, 0x25c, 0x685f44u, 0u);
  }
  return true;
}
PCREG(49f260, msgForwardLoad);
