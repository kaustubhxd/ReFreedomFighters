// batch3020.cpp - unclaimed-30 claim 2 (core-todo residue 10): ZOnScreenDisplay::MapIconClear() [map 0x5aa6e0; thiscall, ret 0].
// The dword at +0x69d is cleared; then for each of the 24 pointers at +0x4cc: the object's byte +0x35 is cleared and its vtable slot 8
// is called (no arguments).
#include "ff.h"

static void THISCALL mapIconClear(u8 *self) {
  *(u32 *)(self + 0x69d) = 0;
  for (int i = 0; i < 24; i++) {
    u8 *o = (u8 *)*(u32 *)(self + 0x4cc + 4 * i);
    o[0x35] = 0;
    vcall<void>(o, 0x8);
  }
}
PCREG(5aa6e0, mapIconClear);
