// batch758.cpp - unclaimed area 75 (docs/20-unclaimed-75.md), slice floor(addr/16) mod 20 == 13.
#include "ff.h"

typedef int i32;

extern "C" void THISCALL ext_5a3690(u8 *self, u32 a, u32 b);   // original removeOrShift (batch753's routine), thiscall, ret 8

// 0x59e690, thiscall(a0, a1) ret 8. esi = this+0x7ce (count dword), entries of 16 bytes start at esi+4 (this+0x7d2).
// Scan 1: the first entry with a1 < key < a0 (signed); edi = its address. Scan 2: from that entry (or the end), the
// first entry with key >= a0; edx = its address (the end if none). If edi != 0: ext_5a3690(esi, (edi-esi-4)>>4,
// (edx-esi-4)>>4). Name GUESS.
static void THISCALL findRangeAndRemove_59e690(u8 *self, u32 a0u, u32 a1u) {
  i32 a0 = (i32)a0u;
  i32 a1 = (i32)a1u;
  u8 *esi = self + 0x7ce;
  u32 n = *(u32 *)esi;
  u8 *end = esi + 4 + 16 * n;
  u8 *e = esi + 4;
  u8 *edi = nullptr;
  if (e != end) {
    for (; e != end; e += 16) {
      i32 k = *(i32 *)e;
      if (k > a1 && k < a0) {
        edi = e;
        break;
      }
    }
  }
  u8 *edx = end;
  if (e != end) {
    for (; e != end; e += 16) {
      if (*(i32 *)e >= a0) {
        edx = e;
        break;
      }
    }
  }
  if (edi != nullptr) {
    i32 ia = ((i32)(u32)(edi - esi) - 4) >> 4;
    i32 ib = ((i32)(u32)(edx - esi) - 4) >> 4;
    ext_5a3690(esi, (u32)ia, (u32)ib);
  }
}
PCREG(59e690, findRangeAndRemove_59e690);
