#include "ff.h"
extern "C" void THISCALL ext_5ec5a0(u8 *object, u32 value);

static void THISCALL fn5a58a0(u8 *self) {
  for (u32 off = 0x5f8; off <= 0x624; off += 4)
    ext_5ec5a0((u8 *)G(u32, self + off), 0);
}
PCREG(5a58a0, fn5a58a0);
