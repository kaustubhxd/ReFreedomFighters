// batch955.cpp - residue-03 (core todo), batch 955: ZFFActorActionCloseCombat::Load(ZLoadGame&), 0x5eb530, thiscall, ret 4.
// Reads (vslot 0x40 with a pointer) into a temporary, stores RM->vslot 0x58(temp) at +8, reads again and stores at +0xc;
// reads the offset into the argument slot (the exe overwrites its own [ebp+8]) and stores RM+0x44 + offset at +0x10;
// reads again, stores RM+0x44 + that at +0x14; reads a dword (vslot 0x48) into +0x18; then vslot 0x50 (this+0x1c),
// vslot 0x68 (this+0x20) and vslot 0x18 (this+0x21, 0x30). RM = [0x70039c]+0x9b (the render manager).
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x5eb530 ZFFActorActionCloseCombat::Load(ZLoadGame&).
static void THISCALL closeCombatLoad(u8 *t, void *ld) {
  u32 tmp, arg, off2;
  vcall<void>(ld, 0x40, (u32)&tmp);
  void *rm = *(void **)(*(u8 **)0x70039c + 0x9b);
  D(t, 0x8) = vcall<u32>(rm, 0x58, tmp);
  vcall<void>(ld, 0x40, (u32)&tmp);
  D(t, 0xc) = vcall<u32>(rm, 0x58, tmp);
  vcall<void>(ld, 0x40, (u32)&arg);
  D(t, 0x10) = D(rm, 0x44) + arg;
  vcall<void>(ld, 0x40, (u32)&arg);
  D(t, 0x14) = D(rm, 0x44) + arg;
  vcall<void>(ld, 0x48, (u32)&off2);
  D(t, 0x18) = off2;
  vcall<void>(ld, 0x50, (u32)(t + 0x1c));
  vcall<void>(ld, 0x68, (u32)(t + 0x20));
  vcall<void>(ld, 0x18, (u32)(t + 0x21), 0x30u);
}
PCREG(5eb530, closeCombatLoad);
