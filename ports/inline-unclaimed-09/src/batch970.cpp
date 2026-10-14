// batch970.cpp - area 56 band, claims A35-A36 (0x534150, 0x533ce0): the same 0x7ff-entry table loop.
#include "ff.h"

// Shared loop: [this+4] = 1, [this] = 0, slots k = 2..0x7ff at this+0x14+8*(k-2) hold k | 0x80000000, then the
// zero at this + eax*8 + 0xc with eax = 0x7ff. Returns the final eax (0x7ff).
static u32 fillTable(u8 *self) {
  u32 eax = 1;
  *(u32 *)(self + 4) = 1;
  u8 *edx = self + 0x14;
  *(u32 *)self = 0;
  do {
    eax++;
    u8 *slot = edx;
    edx += 8;
    *(u32 *)slot = eax | 0x80000000u;
  } while ((int)eax < 0x7ff);
  *(u32 *)(self + eax * 8 + 0xc) = 0;
  return eax;
}

// A35 0x534150: returns the loop's final eax.
static u32 THISCALL table534150(u8 *self) {
  return fillTable(self);
}
PCREG(534150, table534150);

// A36 0x533ce0: returns this.
static u8 *THISCALL table533ce0(u8 *self) {
  fillTable(self);
  return self;
}
PCREG(533ce0, table533ce0);
