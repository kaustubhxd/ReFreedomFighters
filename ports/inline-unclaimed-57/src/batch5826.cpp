// batch5826.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 126: 0x5d4b80 (CBoxAutoFire::Init2, GUESS name unnamed5d4b80), thiscall, no args, plain ret.
// key = this+0x58; if key == 0: this+0x5c = 0; return. A = sub->vt[+0x58](key) (sub = engine+0x9b); assert hook (0x7003b0) called with no args;
// B = A->vt[+0x2c4](sub->dword(+0xadc), 0x4954454d); B->vt[+0x2c](); this+0x5c = sub->vt[+0x4c](B) (one argument).
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotA)(u8 *self, u32 a);
typedef u32(THISCALL *SlotA2)(u8 *self, u32 a, u32 b);
typedef u32(THISCALL *SlotN)(u8 *self);

// 0x5d4b80, thiscall, no args (GUESS name)
static void THISCALL unnamed5d4b80(u8 *self) {
  u32 key = *(u32 *)(self + 0x58);
  if (key == 0) {
    *(u32 *)(self + 0x5c) = 0;
    return;
  }
  u8 *eng = G(u8 *, 0x70039c);
  u8 *sub = *(u8 **)(eng + 0x9b);
  u8 *A = (u8 *)(unsigned long)((SlotA)VT(sub)[0x58 / 4])(sub, key);
  u32 hook = G(u32, 0x7003b0);
  if (hook) ((void (*)(void))hook)();
  eng = G(u8 *, 0x70039c);
  sub = *(u8 **)(eng + 0x9b);
  u8 *B = (u8 *)(unsigned long)((SlotA2)VT(A)[0x2c4 / 4])(A, *(u32 *)(sub + 0xadc), 0x4954454d);
  ((SlotN)VT(B)[0x2c / 4])(B);
  eng = G(u8 *, 0x70039c);
  sub = *(u8 **)(eng + 0x9b);
  *(u32 *)(self + 0x5c) = ((SlotA)VT(sub)[0x4c / 4])(sub, (u32)(unsigned long)B);
}
PCREG(5d4b80, unnamed5d4b80);
