// batch996.cpp - residue-10 (core todo), batch 996: ZFFActor::Load(ZLoadGame*), 0x5a0be0, thiscall, ret 4, returns 1.
// Base 0x479190 (stood in), then the load object's slots (0x50 with this+0x94d; 0x40 into a local -> [this+0x77f]; 0x68, 0x40, 0x40, 0x40,
// 0x40, 0x40, 0x48, 0x4c x3, 0x6c, 0x40, 0x48 into fields; 0x5a0b80 (stood in) with this+0x7ce; 0x18(this+0x8d2, 0x10); 0x68 x2; 0x4c;
// 0x40 -> [this+0x7b2] = render +0x44 + value; 0x40 -> [this+0x7ae] = render +0x44 + value after 0x59d3a0(this+0x54, stood in);
// then 0x40, 0x68, 0x68, 0x48 into fields.
#include "ff.h"

extern "C" void THISCALL ext_479190(void *self, void *ld);   // base load (stood in)
extern "C" void THISCALL ext_5a0b80(void *self, void *ld);   // helper (stood in)
extern "C" void THISCALL ext_59d3a0(void *self, void *ld);   // helper (stood in)

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x5a0be0 ZFFActor::Load(ZLoadGame*).
static u8 THISCALL actorLoad(u8 *t, u8 *L) {
  ext_479190(t, L);
  vcall<void>(L, 0x50, (u32)(t + 0x94d));
  u32 sv = 0;
  vcall<void>(L, 0x40, (u32)&sv);
  D(t, 0x77f) = sv;
  vcall<void>(L, 0x68, (u32)(t + 0x783));
  vcall<void>(L, 0x40, (u32)(t + 0x784));
  vcall<void>(L, 0x40, (u32)(t + 0x792));
  vcall<void>(L, 0x40, (u32)(t + 0x796));
  vcall<void>(L, 0x40, (u32)(t + 0x78a));
  vcall<void>(L, 0x40, (u32)(t + 0x78e));
  vcall<void>(L, 0x48, (u32)(t + 0x79a));
  vcall<void>(L, 0x4c, (u32)(t + 0x7a0));
  vcall<void>(L, 0x4c, (u32)(t + 0x7a2));
  vcall<void>(L, 0x4c, (u32)(t + 0x7a4));
  vcall<void>(L, 0x6c, (u32)(t + 0x8fb));
  vcall<void>(L, 0x40, (u32)(t + 0x907));
  vcall<void>(L, 0x48, (u32)(t + 0x90f));
  ext_5a0b80(t + 0x7ce, L);
  vcall<void>(L, 0x18, (u32)(t + 0x8d2), 0x10u);
  vcall<void>(L, 0x68, (u32)(t + 0x920));
  vcall<void>(L, 0x68, (u32)(t + 0x929));
  vcall<void>(L, 0x4c, (u32)(t + 0x788));
  vcall<void>(L, 0x40, (u32)&sv);
  u8 *rm = *(u8 **)(*(u8 **)0x70039c + 0x9b);
  D(t, 0x7b2) = D(rm, 0x44) + sv;
  vcall<void>(L, 0x40, (u32)&sv);
  D(t, 0x7ae) = D(rm, 0x44) + sv;
  ext_59d3a0((void *)D(t, 0x54), L);
  vcall<void>(L, 0x40, (u32)(t + 0x8f2));
  vcall<void>(L, 0x68, (u32)(t + 0x8fa));
  vcall<void>(L, 0x68, (u32)(t + 0x917));
  vcall<void>(L, 0x48, (u32)(t + 0x925));
  return 1;
}
PCREG(5a0be0, actorLoad);
