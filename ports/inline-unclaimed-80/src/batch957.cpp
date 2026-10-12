#include "ff.h"
// batch957.cpp - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x432440 and 0x4324a0 (high). Thiscall, two stack arguments (a1, a2),
// ret 8. r = vslot +0x54 of self (ecx = self, one argument a1, callee-cleaned). If r == 0: return a2 (0x432440 returns its low byte in AL).
// Otherwise call the IAT slot 0x6762d8 as cdecl with r (the caller pops), then 0x432440 returns (result != 0) in AL, 0x4324a0 returns the result.

typedef u32(THISCALL *tcA)(u8 *, u32);
typedef u32(*cdecl1)(u32);

static u8 THISCALL zg432440(u8 *self, u32 a1, u32 a2) {
  u32 r = ((tcA)(*(u32 *)(*(u32 *)self + 0x54)))(self, a1);
  if (r == 0) return (u8)a2;
  u32 x = ((cdecl1)(*(u32 *)0x6762d8))(r);
  return (u8)(x != 0);
}
PCREG(432440, zg432440);

static u32 THISCALL zg4324a0(u8 *self, u32 a1, u32 a2) {
  u32 r = ((tcA)(*(u32 *)(*(u32 *)self + 0x54)))(self, a1);
  if (r == 0) return a2;
  return ((cdecl1)(*(u32 *)0x6762d8))(r);
}
PCREG(4324a0, zg4324a0);
