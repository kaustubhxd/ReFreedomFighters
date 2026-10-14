// batch1714.cpp - 0x5f3410 (GUESS, area-13 band, 2026-10-12). Factory function. Allocates 0x1014 bytes via new,
// then tail-jumps into the sound dll constructor 0x5f12d0 (thiscall, plain ret; already verified in docs/20-fresh-01.md).
// Returns the constructor's result (the allocated pointer) or 0 if allocation fails.
#include "ff.h"

extern "C" char ext_41e290[];
extern "C" char ext_5f12d0[];
typedef u32(*NewFn)(u32 size);
typedef u32(THISCALL *Ctor0Fn)(void *self);

u32 GUESS_5f3410() {
  u32 p = ((NewFn)(void *)ext_41e290)(0x1014u);
  if (!p) return 0;
  return ((Ctor0Fn)(void *)ext_5f12d0)((void *)p);
}
PCREG(5f3410, GUESS_5f3410);
