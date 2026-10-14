// batch893.cpp - gap band slice: 0x41f190 [16 instr, the pointer is the stack arg (ECX is not used), ret 4, void]. If the word at
// p-8 is negative, the word at p-0x10 becomes the xor of the words at p-8, p-0xc, p-0x14, p-0x18, p-0x1c and p-0x20, or 1 if
// that xor is zero (cmove).
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x41f190 (name GUESS "Fix41f190").
static void THISCALL Fix41f190(void *unused, u8 *p) {
  (void)unused;
  if ((s32)U32(p, -8) >= 0) return;
  u32 v = U32(p, -8) ^ U32(p, -0xc) ^ U32(p, -0x14) ^ U32(p, -0x18) ^ U32(p, -0x1c) ^ U32(p, -0x20);
  if (v == 0) v = 1;
  U32(p, -0x10) = v;
}
PCREG(41f190, Fix41f190);
