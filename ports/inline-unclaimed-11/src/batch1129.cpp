// batch1129.cpp - unclaimed-11 batch 30 (gap band): two GUESS functions.
#include "ff.h"

extern "C" void THISCALL ext_469870(void *self);

// 0x5bd6d0, GUESS: base constructor (exe, via ext), flag |= 0x20, +0x44 = 0, vtable 0x6b33b4, zero blocks, +0x70 = -1.
static void THISCALL guessCtor5bd6d0(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6b33b4;
  __builtin_memset(self + 0x48, 0, 16);
  __builtin_memset(self + 0x58, 0, 16);
  *(u32 *)(self + 0x68) = 0;
  *(u32 *)(self + 0x6c) = 0;
  *(u32 *)(self + 0x70) = 0xffffffffu;
  *(u32 *)(self + 0x7d) = 0;
}
PCREG(5bd6d0, guessCtor5bd6d0);

typedef u8(THISCALL *predFn)(void *self, u32 flag);

// 0x5a4690, GUESS: arg nonnull, arg vt[0x1e0](0x2003e8) true, arg+0x54 nonnull; d = [arg+0x54 + 4] - 3;
// d == -1 or d > 6 (signed) gives null; else this + 0x61 + 18*d.
static u8 *THISCALL guessIndexedPointer2(u8 *self, u8 *arg) {
  if (arg == nullptr) return nullptr;
  if (!((predFn)(*(void ***)arg)[0x1e0 / 4])(arg, 0x2003e8)) return nullptr;
  u8 *inner = *(u8 **)(arg + 0x54);
  if (inner == nullptr) return nullptr;
  s32 d = *(s32 *)(inner + 4) - 3;
  if (d == -1 || d > 6) return nullptr;
  return self + 0x61 + 18 * d;
}
PCREG(5a4690, guessIndexedPointer2);
