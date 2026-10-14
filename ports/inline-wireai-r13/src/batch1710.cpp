// batch1710.cpp - 0x433350 (GUESS, area-13 band, 2026-10-12). Thiscall, two stack arguments (a, b), ret 8 (the function
// itself has no epilogue of its own; it tail-jumps). Replaces b with (b != 0) and tail-jumps into 0x431410 (notify helper,
// thiscall, two arguments, ret 8; hooked by address) with the same this; returns its eax.
#include "ff.h"

extern "C" char ext_431410[];
typedef u32(THISCALL *NotifyFn)(void *self, u32 a, u32 b);

u32 THISCALL GUESS_433350(u8 *self, u32 a, u32 b) {
  u32 flag = (b & 0xffu) != 0;
  return ((NotifyFn)(void *)ext_431410)(self, a, flag);
}
PCREG(433350, GUESS_433350);
