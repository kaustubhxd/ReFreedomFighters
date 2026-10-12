// batch6225.cpp - unclaimed-62 claim 18 (larger, 103 instructions): 0x4bb6b0 [thiscall, one argument, ret 4, returns al].
// arg == 0 or arg == the message table's +0xadc object -> 0. Otherwise: A = this+0xf4 and B = this+0x48 are sub-objects with a value
// (slot 0x14, no argument). If B's value is less than A's (signed) the B walk runs, otherwise the A walk runs; a walk calls the sub-object's
// slot 0x4c and then its slot 0x5c with &loc (the loc word, zero ends the walk) and asks the message table's slot 0x58 with the previous 0x5c
// result; a match with arg returns 0 for A and 1 for B. A walk that ends without a match returns 1 for A and 0 for B.
// The exe's SEH frame is not used here (no SEH frame in this function).
#include "ff.h"

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }
static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

static u8 THISCALL fn4bb6b0(u8 *self, u32 arg) {
  if (arg == 0) return 0;
  u8 *eng = G(u8 *, 0x70039c);
  u8 *msg = rdp(eng + 0x9b);
  if (arg == rd32u(msg + 0xadc)) return 0;
  u8 *A = self + 0xf4;
  u8 *B = self + 0x48;
  u32 esi = vcall<u32>(A, 0x14);
  u32 eax = vcall<u32>(B, 0x14);
  u32 loc = 0;
  if ((s32)eax > (s32)esi) {
    vcall<u32>(A, 0x4c, (u32)&loc);
    eax = vcall<u32>(A, 0x5c, (u32)&loc);
    if (loc == 0) return 1;
    for (;;) {
      u32 v = vcall<u32>(rdp(G(u8 *, 0x70039c) + 0x9b), 0x58, eax);
      if (arg == v) return 0;
      eax = vcall<u32>(A, 0x5c, (u32)&loc);
      if (loc == 0) return 1;
    }
  }
  vcall<u32>(B, 0x4c, (u32)&loc);
  eax = vcall<u32>(B, 0x5c, (u32)&loc);
  if (loc == 0) return 0;
  for (;;) {
    u32 v = vcall<u32>(rdp(G(u8 *, 0x70039c) + 0x9b), 0x58, eax);
    if (arg == v) return 1;
    eax = vcall<u32>(B, 0x5c, (u32)&loc);
    if (loc == 0) return 0;
  }
}
PCREG(4bb6b0, fn4bb6b0);
