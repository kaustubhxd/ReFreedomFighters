// batch413.cpp - 0x6097a0 (residue 2; thiscall, no arguments). If byte [this+0x33] != 0:
//   obj = dword [this+0x1377]; call slot 8 of obj's vtable (target = dword [[obj] + 8]) with ECX = this (unchanged from entry)
//   and the one stack argument obj;
//   obj2 = dword 0x724b38; call the slot 8 target dword [[obj2] + 8] with ECX = [obj2] (the vtable pointer) and the argument obj2;
//   then byte [this+0x33] = 0.
// The first call uses ECX = this on purpose: the exe does not load ECX from obj before its call.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

typedef void(THISCALL *SlotFn)(void *self, void *arg);

static void THISCALL slot8Pair(u8 *self) {
  if (self[0x33] == 0)
    return;
  u32 obj = U32(self, 0x1377);
  u32 fn = *(u32 *)(unsigned long)(*(u32 *)(unsigned long)obj + 8);
  ((SlotFn)(unsigned long)fn)(self, (void *)(unsigned long)obj);
  u32 obj2 = G(u32, 0x724b38);
  u32 vt2 = *(u32 *)(unsigned long)obj2;
  u32 fn2 = *(u32 *)(unsigned long)(vt2 + 8);
  ((SlotFn)(unsigned long)fn2)((void *)(unsigned long)vt2, (void *)(unsigned long)obj2);
  self[0x33] = 0;
}
PCREG(6097a0, slot8Pair);
