// batch1120.cpp - unclaimed-11 batch 21 (gap band): two GUESS functions.
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 size);

// 0x5a5490, GUESS: cdecl free(this+4, 4), then free(this+8, 4).
static void THISCALL guessTwoFrees(u8 *self) {
  ext_634273(*(void **)(self + 4), 4);
  ext_634273(*(void **)(self + 8), 4);
}
PCREG(5a5490, guessTwoFrees);

typedef u32(THISCALL *fnU32Arg)(void *self, u32 a);

// 0x5b76f0, GUESS: eax = render object's slot 0x58 (object at global 0x70039c +0x9b) with argument this+0x48; stored to this+0x50.
static void THISCALL guessRenderSlot58(u8 *self) {
  void *rm = G(void *, 0x70039c);
  void *o = *(void **)((u8 *)rm + 0x9b);
  u32 r = ((fnU32Arg)(*(void ***)o)[0x58 / 4])(o, *(u32 *)(self + 0x48));
  *(u32 *)(self + 0x50) = r;
}
PCREG(5b76f0, guessRenderSlot58);
