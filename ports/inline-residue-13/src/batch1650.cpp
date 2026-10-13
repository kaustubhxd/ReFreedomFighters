// batch1650.cpp - ZActor::GetMoveFromPos(float* out) const (0x478d10, residue 13, 2026-10-12). Name map: high
// (ZActor[392]). Zeroes out, calls vslot 0x57c with (scratch, out) (the scratch is not read afterwards), then, when the
// byte at +0x726 is set, copies a vector from +0x6e6 when +0x64c == 0xa, else from +0x660. GUESS: the slot 0x57c and
// the field names. No SEH; the cookie check is kept out of the port.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

void THISCALL ZActor_GetMoveFromPos(u8 *self, u32 *out) {
  u32 scratch[4];
  AT(u32, out, 8) = 0;
  AT(u32, out, 4) = 0;
  AT(u32, out, 0) = 0;
  vcall<void>(self, 0x57c, (u32)scratch, (u32)out);
  if (AT(u8, self, 0x726)) {
    if (AT(u32, self, 0x64c) == 0xa) {
      AT(u32, out, 0) = AT(u32, self, 0x6e6);
      AT(u32, out, 4) = AT(u32, self, 0x6ea);
      AT(u32, out, 8) = AT(u32, self, 0x6ee);
    } else {
      AT(u32, out, 0) = AT(u32, self, 0x660);
      AT(u32, out, 4) = AT(u32, self, 0x664);
      AT(u32, out, 8) = AT(u32, self, 0x668);
    }
  }
}
PCREG(478d10, ZActor_GetMoveFromPos);
