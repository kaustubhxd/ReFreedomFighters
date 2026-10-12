// batch820.cpp - core gameplay batch 820 (docs/20-unclaimed-65.md, batch 820): 0x4fb8d0, a thiscall with no arguments. It compares the byte
// returned by 0x4fbd50 with the byte at this+0x48. If they differ and slot 0x58 of the render sub-object ([0x70039c]+0x9b) with the dword at
// this+0x55 returns an object, it stores the byte at +0x48 and calls slot 0x128 of that object with three arguments (callee pops):
// the word at +0x4d when the byte is nonzero, else the word at +0x4f; then the dword at +0x49, then 0.
#include "ff.h"

typedef u32(THISCALL *F1)(u8 *self, u32 a);
typedef void(THISCALL *F3)(u8 *self, u32 a, u32 b, u32 c);

extern "C" u32 THISCALL ext_4fbd50(u8 *self);   // thiscall, no arguments, returns al (hooked in the spec)

static void THISCALL fn4fb8d0(u8 *self) {
  const u8 bl = (u8)ext_4fbd50(self);
  if (bl == *(const u8 *)(self + 0x48)) return;
  u8 *r9 = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *obj = (u8 *)((F1)(*(const u32 *)(*(const u32 *)r9 + 0x58)))(r9, *(const u32 *)(self + 0x55));
  if (obj == 0) return;
  *(u8 *)(self + 0x48) = bl;
  const u32 w = bl != 0 ? *(const u16 *)(self + 0x4d) : *(const u16 *)(self + 0x4f);
  ((F3)(*(const u32 *)(*(const u32 *)obj + 0x128)))(obj, w, *(const u32 *)(self + 0x49), 0);
}

PCREG(4fb8d0, fn4fb8d0);
