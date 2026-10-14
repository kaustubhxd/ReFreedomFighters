// batch244.cpp - ZFFHERO::AddToTargetList (inline-ladder thread, 2026-10-11).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" void THISCALL ext_4dc630(void *geom, u32 set, u32 clear);   // ZBaseGeom::SetControl (batch 225 family)

// 0x58b930 ZFFHERO::AddToTargetList() [, high], thiscall, no args.
// The engine list "TargetListEnemy" (database +0xadc slot 0x25c finds it by name); when missing it is made as a ZLIST
// (slot 0x294 with name, "ZLIST", 0, 1), its slot 0x154 runs, SetControl(list geom, 0x800000, 0) and its slot 0x124(1, 0, 0, 0).
// Then the list's slot 0x218(hero) adds the hero (every call, whether found or made).
static void THISCALL heroAddToTargetList(u8 *self) {
  u8 *eng = (u8 *)G(u32, 0x70039c);
  u8 *db = (u8 *)U32(eng, 0x9b);
  void *list = vcall<void *>((void *)U32(db, 0xadc), 0x25c, (const char *)0x6acfbc, 0u);   // "TargetListEnemy"
  if (!list) {
    list = vcall<void *>((void *)U32(db, 0xadc), 0x294, (const char *)0x6acfbc, (const char *)0x67f610, (void *)0, 1u);
    vcall<void>(list, 0x154);
    ext_4dc630((void *)U32(list, 8), 0x800000u, 0u);
    vcall<void>(list, 0x124, 1u, 0u, 0u, 0u);
  }
  vcall<void>(list, 0x218, self);
}
PCREG(58b930, heroAddToTargetList);
