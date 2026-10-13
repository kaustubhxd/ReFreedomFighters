// batch1144.cpp - collision thread, batch 1144 (hard-row lane, name GUESS): 0x43fb00. Thiscall (ECX = holder), three stack
// arguments (A, argB, unused), ret 0xc. If slot 0x20 of A (no arguments) is zero, returns 0. Otherwise r1 = slot 0x20 of A with
// (argB, 1), slot 0x274 of holder with r1, then the lookup r = slot 0x25c of C = *argB with (s, 0), where s = [A+4] or the default
// string 0x67c8e8. While r has flag 0x800 (dword at +0x30), r = slot 0x25c of C with (s, [r+8]), stopping when r is zero; a zero
// lookup ends with r = slot 0x1b8 of A with (C, 0, 0, 0, 0). Stores r into the cell at argB (the exe's ebx) and returns r.
#include "ff.h"

static u32 THISCALL find43fb00(u8 *holder, u8 *A, u32 *argB, u32 unused) {
  (void)unused;
  if (vcall<u32>(A, 0x20) == 0) return 0;
  u32 r1 = vcall<u32>(A, 0x20, (u32)argB, 1u);
  vcall<void>(holder, 0x274, r1);
  u32 *C = *(u32 **)argB;
  u32 s = *(u32 *)(A + 4) != 0 ? *(u32 *)(A + 4) : 0x67c8e8u;
  u32 r = vcall<u32>(C, 0x25c, s, 0u);
  bool tail = (r == 0);
  if (!tail) {
    for (;;) {
      if ((*(u32 *)((u8 *)r + 0x30) & 0x800u) == 0) break;
      r = vcall<u32>(C, 0x25c, s, *(u32 *)((u8 *)r + 8));
      if (r == 0) {
        tail = true;
        break;
      }
    }
  }
  if (tail) r = vcall<u32>(A, 0x1b8, (u32)C, 0u, 0u, 0u, 0u);
  *argB = r;                                   // the exe stores through ebx, which now holds argB (not the holder)
  return r;
}
PCREG(43fb00, find43fb00);
