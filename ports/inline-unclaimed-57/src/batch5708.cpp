// batch5708.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 8: four call-free leaves from the full function list (no GC
// name; names are GUESS, the address is the identifier). Bodies are copied from the PC bytes.
#include "ff.h"

// 0x54db80 (GUESS: unnamed, thiscall, no arguments): v = dword this+0x40ad; returns 0 if v == 1, else v + 1.
static u32 THISCALL unnamed54db80(u8 *self) {
  u32 v = *(u32 *)(self + 0x40ad);
  if (v == 1) return 0;
  return v + 1;
}
PCREG(54db80, unnamed54db80);

// 0x49b340 (GUESS: unnamed, thiscall, two stack arguments, ret 8): this+0x14 = a1; this+0x18 = a2.
static void THISCALL unnamed49b340(u8 *self, u32 a1, u32 a2) {
  *(u32 *)(self + 0x14) = a1;
  *(u32 *)(self + 0x18) = a2;
}
PCREG(49b340, unnamed49b340);

// 0x4d61c0 (GUESS: unnamed, one stack argument, ret 4, callee pops): returns al = (dword at p+0x42e == 1).
static u8 STDCALL unnamed4d61c0(u8 *p) {
  return *(u32 *)(p + 0x42e) == 1;
}
PCREG(4d61c0, unnamed4d61c0);

// 0x61c5c0 (GUESS: unnamed, cdecl, three arguments, ret without a pop): obj+0x34 = a; obj+0x38 = b.
static void unnamed61c5c0(u8 *obj, u32 a, u32 b) {
  *(u32 *)(obj + 0x34) = a;
  *(u32 *)(obj + 0x38) = b;
}
PCREG(61c5c0, unnamed61c5c0);
