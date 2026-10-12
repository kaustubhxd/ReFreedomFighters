// batch6311.cpp - unclaimed-63 batch 11 (docs/20-unclaimed-63.md): ZGEOM::CreateExData() at 0x45d960 (GC name, high).
// If [this+0x10] is nonzero, returns. Otherwise p = 0x41e290(0x20) (cdecl allocation, one argument, original code). If p: the
// vptr at p = 0x684e1c, the seven dwords at p+4 .. p+0x1c are zero, and [this+0x10] = p. Returns (ret, no arguments).
#include "ff.h"

extern "C" u32 ext_41e290(u32 size);   // cdecl allocation, original code, stubbed by the spec

// 0x45d960, ZGEOM::CreateExData() (high).
static void THISCALL geomCreateExData(u8 *self) {
  if (*(u32 *)(self + 0x10) != 0)
    return;
  u32 p = ext_41e290(0x20);
  if (p != 0) {
    *(u32 *)p = 0x684e1c;
    for (u32 k = 1; k <= 7; k++)
      *(u32 *)(p + 4 * k) = 0;
    *(u32 *)(self + 0x10) = p;
  }
}
PCREG(45d960, geomCreateExData);
