// batch5782.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 82: 0x5d4020 (GUESS name unnamed_5d4020), thiscall, one stack argument a
// (ret 4), returns al = 1. Order: a->vt[+0x44](this+0x80); a->vt[+0x44](this+0x58), (+0x5c), (+0x60), (+0x64); a->vt[+0x3c](this+0x68),
// (+0x6c), (+0x70), (+0x74). Each slot takes one dword value read from this. The slots run as fake vtable stubs in the spec.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef void(THISCALL *SlotV)(u8 *self, u32 v);

// 0x5d4020, thiscall, one stack argument (GUESS name)
static u8 THISCALL unnamed5d4020(u8 *self, u8 *a) {
  ((SlotV)VT(a)[0x44 / 4])(a, *(u32 *)(self + 0x80));
  ((SlotV)VT(a)[0x44 / 4])(a, *(u32 *)(self + 0x58));
  ((SlotV)VT(a)[0x44 / 4])(a, *(u32 *)(self + 0x5c));
  ((SlotV)VT(a)[0x44 / 4])(a, *(u32 *)(self + 0x60));
  ((SlotV)VT(a)[0x44 / 4])(a, *(u32 *)(self + 0x64));
  ((SlotV)VT(a)[0x3c / 4])(a, *(u32 *)(self + 0x68));
  ((SlotV)VT(a)[0x3c / 4])(a, *(u32 *)(self + 0x6c));
  ((SlotV)VT(a)[0x3c / 4])(a, *(u32 *)(self + 0x70));
  ((SlotV)VT(a)[0x3c / 4])(a, *(u32 *)(self + 0x74));
  return 1;
}
PCREG(5d4020, unnamed5d4020);
