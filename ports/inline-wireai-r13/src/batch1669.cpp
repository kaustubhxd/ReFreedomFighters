// batch1669.cpp - 0x462a20 (GUESS, residue 13 gap band, 2026-10-12). Thiscall with four stack arguments, ret 0x10; only
// the fourth is read. Calls the table lookup 0x463030 (verified in docs/20-collision.md, batch 1142; hooked here) as a
// thiscall on the fourth argument with (0x4e414d45, 0): the exe pushes 0 first, then the name, then the manager's vslot 0x114(result, 0, "zlnkobj.cpp", 0x67b)
// (word result), then this's vslot 0x128(word, 0, 0). Returns the last eax with its low byte cleared (the function's
// xor al,al). The first pushed 0 is 0x463030's first argument (its ret 8 pops it), so the stack balances.
// GUESS: the slot names; the string is the file name shown in the exe (zlnkobj.cpp).
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_463030[];
typedef u32(THISCALL *LookupFn)(void *self, u32 a, u32 b);

u32 THISCALL GUESS_462a20(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4) {
  u32 name = ((LookupFn)(void *)ext_463030)((void *)a4, 0x4e414d45u, 0u);
  u8 *R = AT(u8 *, AT(u8 *, 0x70039c, 0), 0x9b);
  u32 ax = vcall<u16>(R, 0x114, name, (u32)0, (u32)0x685834u, (u32)0x67bu);
  u32 r = vcall<u32>(self, 0x128, (u32)(u16)ax, (u32)0, (u32)0);
  return r & 0xffffff00u;
}
PCREG(462a20, GUESS_462a20);
