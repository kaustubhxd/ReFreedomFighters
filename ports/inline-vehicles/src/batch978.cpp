// batch978.cpp - residue-05 (core todo), batch 978: ZFFSimpleTrain2::Load(ZLoadGame*), 0x5b8b50, thiscall, ret 4, returns 1.
// The SEH frame is not reproduced. Clears bit 0x40 of [this+4]; L vslot 0x40(&[this+0x48]); allocation 0x41e290 (cdecl, 0x1c,
// stood in) and, when it succeeds, the constructor 0x4ccbe0(obj, 1, 0) (stood in); [this+0x4c] = that; L vslot 0x70(it);
// further L reads into this+0x50..+0x5c, the render-manager lookups (vslot 0x58 of [sys+0x9b]) on values read through a
// slot (stored at +0x7e, +0x82 and +0x86), L vslots 0x6c, 0x68, 0x50, 0x74 into this+0x8a..+0xb7, the render lookups into +0xe2
// and +0xe6, and vslots 0x6c and 0x68 into +0xea and +0xdd.
#include "ff.h"

extern "C" void *__attribute__((cdecl)) ext_41e290(u32 size);          // allocator (stood in)
extern "C" u32 THISCALL ext_4ccbe0(void *self, u32 a, u32 b);         // constructor (stood in)

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x5b8b50 ZFFSimpleTrain2::Load(ZLoadGame*).
static u8 THISCALL simpleTrain2Load(u8 *t, u8 *L) {
  D(t, 4) &= 0xffffffbfu;
  vcall<void>(L, 0x40, (u32)(t + 0x48));
  void *buf = ext_41e290(0x1c);
  u32 obj = 0;
  if (buf)
    obj = ext_4ccbe0(buf, 1u, 0u);
  D(t, 0x4c) = obj;
  vcall<void>(L, 0x70, obj);
  vcall<void>(L, 0x40, (u32)(t + 0x50));
  vcall<void>(L, 0x40, (u32)(t + 0x54));
  vcall<void>(L, 0x50, (u32)(t + 0x58));
  vcall<void>(L, 0x50, (u32)(t + 0x5c));
  void *rm = *(void **)(*(u8 **)0x70039c + 0x9b);
  u32 slot = 0;
  vcall<void>(L, 0x40, (u32)&slot);
  D(t, 0x7e) = vcall<u32>(rm, 0x58, slot);
  vcall<void>(L, 0x40, (u32)&slot);
  D(t, 0x82) = vcall<u32>(rm, 0x58, slot);
  vcall<void>(L, 0x40, (u32)&slot);
  D(t, 0x86) = vcall<u32>(rm, 0x58, slot);
  vcall<void>(L, 0x6c, (u32)(t + 0x8a));
  vcall<void>(L, 0x6c, (u32)(t + 0x96));
  vcall<void>(L, 0x6c, (u32)(t + 0xa2));
  vcall<void>(L, 0x50, (u32)(t + 0xae));
  vcall<void>(L, 0x68, (u32)(t + 0xb2));
  vcall<void>(L, 0x50, (u32)(t + 0xb3));
  vcall<void>(L, 0x74, (u32)(t + 0xb7));
  vcall<void>(L, 0x40, (u32)&slot);
  D(t, 0xe2) = vcall<u32>(rm, 0x58, slot);
  vcall<void>(L, 0x40, (u32)(t + 0xde));
  vcall<void>(L, 0x40, (u32)&slot);
  D(t, 0xe2) = vcall<u32>(rm, 0x58, slot);
  u32 s2 = 0;
  vcall<void>(L, 0x40, (u32)&s2);
  D(t, 0xe6) = vcall<u32>(rm, 0x58, s2);
  vcall<void>(L, 0x6c, (u32)(t + 0xea));
  vcall<void>(L, 0x68, (u32)(t + 0xdd));
  return 1;
}
PCREG(5b8b50, simpleTrain2Load);
