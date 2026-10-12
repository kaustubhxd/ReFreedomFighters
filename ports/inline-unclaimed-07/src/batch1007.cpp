// batch1007.cpp - unclaimed-07 batch 7 (docs/20-unclaimed-07.md, slice 6): CImpactResponse::Load.
// Name from the GC name map (high). Body from the PC bytes. The output count is written by the load object's slot
// +0x40 through a pointer to the argument slot, as the PC code does.
#include "ff.h"

// 0x41e290: allocator used by the load (cdecl, one argument; original code, not lifted here).
extern "C" u32 __attribute__((cdecl)) ext_41e290(u32 n);

// 0x5dc420, CImpactResponse::Load(ZLoadGame*) (high):
//   clears bit 0x40 at this+4; load slot +0x70(this+0x48); slot +0x74(this+0x50); slot +0x6c(this+0x74);
//   slot +0x40(&slot) reads a count into the argument slot (initially the load pointer); buf = 0x41e290(count+1);
//   this+0x4c = buf; load slot +0x18(buf, count); buf[count] = 0. Returns true.
static bool THISCALL impactResponseLoad(u8 *self, u32 load) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  vcall<void>((void *)load, 0x70, *(u32 *)(self + 0x48));
  vcall<void>((void *)load, 0x74, (u32)(self + 0x50));
  vcall<void>((void *)load, 0x6c, (u32)(self + 0x74));
  u32 slot = load;
  vcall<void>((void *)load, 0x40, &slot);
  u32 n = slot;
  u32 buf = ext_41e290(n + 1);
  *(u32 *)(self + 0x4c) = buf;
  vcall<void>((void *)load, 0x18, buf, n);
  ((u8 *)*(u32 *)(self + 0x4c))[n] = 0;
  return true;
}
PCREG(5dc420, impactResponseLoad);
