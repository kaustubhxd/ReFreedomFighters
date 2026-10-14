// batch995.cpp - residue-10 (core todo), batch 995: CEnemyFlag::Load(ZLoadGame*), 0x5c1b60, thiscall, ret 4, returns 1.
// Clears bit 0x40 of [this+4]; helpers 0x6352f0 and 0x5c1dc0 (stood in) with a zero local. Then the load object's slots: 0x40 -> render
// vslot 0x58 -> [this+0xe0]; 0x48(this+0xe8); 0x68(flag byte); 0x58(this+0x100); 0x40 -> render -> [this+0x50]; 0x68(this+0x106);
// 0x48(this+0x8c); 0x18(this+0x90, 0x50); 0x6c(this+0xf4); 0x68(this+0x104); 0x68(this+0x107); 0x40 -> render -> [this+0x108];
// 0x40 -> render -> [this+0x10d]; 0x48(&l8) -> [this+0x48]; 0x48(&l8) -> [this+0x4c]; [this+0xe4] = flag ? 0x6eef78 : 0x6eef68;
// the object at [this+0x44]: vslot 0x1e0(0x100001) -> [this+0x10d] = [this+0x44], otherwise [this+0x10d] = vslot 0x20().
// The flag is a byte: the slot 0x68 writes one byte (a dword would overwrite the saved EBP).
#include "ff.h"

extern "C" void THISCALL ext_6352f0(void *self, u32 *p);   // stood in
extern "C" void THISCALL ext_5c1dc0(void *self, u32 *p);   // stood in

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x5c1b60 CEnemyFlag::Load(ZLoadGame*).
static u8 THISCALL enemyFlagLoad(u8 *t, u8 *L) {
  D(t, 4) &= 0xffffffbfu;
  u32 l0 = 0;
  ext_6352f0(t, &l0);
  ext_5c1dc0(t, &l0);
  void *rm = *(void **)(*(u8 **)0x70039c + 0x9b);
  u32 sv = 0;
  vcall<void>(L, 0x40, (u32)&sv);
  D(t, 0xe0) = vcall<u32>(rm, 0x58, sv);
  vcall<void>(L, 0x48, (u32)(t + 0xe8));
  u8 flag = 0;
  vcall<void>(L, 0x68, (u32)&flag);
  vcall<void>(L, 0x58, (u32)(t + 0x100));
  vcall<void>(L, 0x40, (u32)&sv);
  D(t, 0x50) = vcall<u32>(rm, 0x58, sv);
  vcall<void>(L, 0x68, (u32)(t + 0x106));
  vcall<void>(L, 0x48, (u32)(t + 0x8c));
  vcall<void>(L, 0x18, (u32)(t + 0x90), 0x50u);
  vcall<void>(L, 0x6c, (u32)(t + 0xf4));
  vcall<void>(L, 0x68, (u32)(t + 0x104));
  vcall<void>(L, 0x68, (u32)(t + 0x107));
  vcall<void>(L, 0x40, (u32)&sv);
  D(t, 0x108) = vcall<u32>(rm, 0x58, sv);
  vcall<void>(L, 0x40, (u32)&sv);
  D(t, 0x10d) = vcall<u32>(rm, 0x58, sv);
  u32 l8 = 0;
  vcall<void>(L, 0x48, (u32)&l8);
  D(t, 0x48) = l8;
  vcall<void>(L, 0x48, (u32)&l8);
  D(t, 0x4c) = l8;
  D(t, 0xe4) = flag != 0 ? 0x6eef78u : 0x6eef68u;
  u8 *p = (u8 *)D(t, 0x44);
  if ((u8)vcall<u32>(p, 0x1e0, 0x100001u)) {
    D(t, 0x10d) = D(t, 0x44);
    return 1;
  }
  D(t, 0x10d) = vcall<u32>(p, 0x20);
  return 1;
}
PCREG(5c1b60, enemyFlagLoad);
