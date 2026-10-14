// u69_58.cpp - area 69, group 58 (slice 8). A ring-buffer push (ZDrawBase::Leave). The object holds the write pointer at +0x268 and the read pointer at +0x26c; the ring
// runs from +0x270 to +0x8270 (its end is +0x268 + 0x8008). The one callee, 0x63cc50, is a GUESS stub (thiscall, two stack args; ret 8 assumed) in the spec.
#include "ff.h"

extern "C" u32 THISCALL ext_63cc50(void *self, u32 a, u32 b);

// 0x63ef00, ZDrawBase::Leave(ZDrawResource*) (GC map high). thiscall one stack arg (res, ret 4). Clears bit 0 of res[5]; stores the dword at 0x70039c -> +0x3c into *res;
// stores res at the write slot, advances the write pointer by 4 (wrapping to the start of the ring); sets word res[6] to (write slot index) truncated to 16 bits;
// computes the occupancy v (from the write and read pointers: (w - r) >> 2, or 0x2000 - ((r - w) >> 2) when w < r) and calls 0x63cc50(self, 0, x-1) when v > 0x800,
// where x = the dword at 0x70039c -> +0x3c.
static void THISCALL leave63ef00(u8 *self, u8 *res) {
  res[5] &= 0xfe;
  u32 *q = (u32 *)(self + 0x268);
  *(u32 *)res = *(u32 *)(*(u8 **)0x70039c + 0x3c);
  u32 ecx = *q;
  u32 eax = ecx - (u32)q - 8;
  s32 idx = (s32)eax >> 2;
  u16 bx = (u16)idx;
  eax = (u32)q + 0x8008;
  *(u32 *)ecx = (u32)res;
  *q += 4;
  if (*q == eax)
    *q = (u32)q + 8;
  *(u16 *)(res + 6) = bx;
  eax = *q;
  u32 r = *(u32 *)(self + 0x26c);
  u32 v;
  if (eax >= r) {
    v = (u32)((s32)(eax - r) >> 2);
  } else {
    v = 0x2000 - (u32)((s32)(r - eax) >> 2);
  }
  if (v > 0x800) {
    u32 x = *(u32 *)(*(u8 **)0x70039c + 0x3c);
    ext_63cc50(self, 0, x - 1);
  }
}
PCREG(63ef00, leave63ef00);
