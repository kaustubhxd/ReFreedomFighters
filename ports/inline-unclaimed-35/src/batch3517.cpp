#include "ff.h"
// batch3517.cpp - area 35 claim 17 (docs/20-unclaimed-35.md): two wrappers in slice 14. Names are GUESS (no GC name).
// Stubbed in the harness: 0x4edbd0 (thiscall, one arg); the vtable slot +4 of the object at this+0x65 (logged, one arg).

typedef u32(THISCALL *Slot1)(u8 *self, u32 a0);

extern "C" u32 THISCALL ext_4edbd0(u8 *self, u32 a0);

// 0x4362e0, GUESS FUN_4362e0 (thiscall): if the dword at this+0x65 is non-null, calls its vtable slot +4 with one argument (0).
static void THISCALL guessSlot4(u8 *self) {
  u8 *o = *(u8 **)(self + 0x65);
  if (o)
    ((Slot1)*(u32 *)(*(u32 *)o + 4))(o, 0);
}
PCREG(4362e0, guessSlot4);

// 0x48eda0, GUESS FUN_48eda0 (thiscall): reads this+0xaf4 first, then calls 0x4edbd0 on the object at
// (render manager + 0x1aa3)->+0x1c with that value as its argument.
static void THISCALL guessRenderCall(u8 *self) {
  u32 a = *(u32 *)(self + 0xaf4);
  u8 *rm = *(u8 **)0x70039c;
  u8 *p = *(u8 **)(rm + 0x1aa3);
  u8 *t = *(u8 **)(p + 0x1c);
  ext_4edbd0(t, a);
}
PCREG(48eda0, guessRenderCall);
