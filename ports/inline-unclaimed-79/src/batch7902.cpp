#include "ff.h"
// batch7902.cpp - unclaimed-79 batch 2 (docs/20-unclaimed-79.md). Name from the residue list (no GC name conflict).
// The helper at 0x47aad0 (not lifted here) runs as original code; the harness stubs it with a logger.

extern "C" void THISCALL ext_47aad0(u8 *self, u32 a1, u8 *a2);

// 0x479620, ZActor::MoveToMatPos(const float*, const float*) (vtable). Thiscall, two stack arguments (ret 8).
static void THISCALL actorMoveToMatPos(u8 *self, u8 *a, u8 *b) {
  vcall<void, u8 *, u8 *>(self, 0x578, a, b);
  if (vcall<u8>(self, 0x2fc) != 0)
    return;
  if (self[0x726] != 0) {
    vcall<void, u32, u32, u32>(self, 0x628, 2u, 2u, 0u);
    u32 eax = *(u32 *)(self + 0x6ce);
    self[0x726] = 0;
    if (eax != 0 && *(u32 *)(self + 0x64c) == 0xa) {
      ext_47aad0((u8 *)0x6ff9c0, eax, self);
      *(u32 *)(self + 0x6ce) = 0;
      *(u32 *)(self + 0x64c) = 0;
    }
    u32 moving = vcall<u32>(self, 0x588) != 0;
    vcall<void, u32>(self, 0x62c, moving);
  }
  *(u32 *)(self + 0x660) = *(u32 *)b;
  *(u32 *)(self + 0x664) = *(u32 *)(b + 4);
  *(u32 *)(self + 0x668) = *(u32 *)(b + 8);
}
PCREG(479620, actorMoveToMatPos);
