// batch976.cpp - area 56 band, claim A42 (0x534010): a float loop over an array, no calls.
#include "ff.h"

// A42 0x534010: for 0x400 slots c = this->p + 0x78 + i*0xfd: if *(c-0x68) != 0 and *c is not 0.0 (NaN counts as not zero), *c += f.
static void THISCALL addLoop534010(u8 *self, float f) {
  u8 *c = *(u8 **)(self + 8) + 0x78;
  for (u32 i = 0x400; i != 0; i--) {
    if (*(u32 *)(c - 0x68) != 0) {
      float x = *(float *)c;
      if (!(x == 0.0f)) *(float *)c = x + f;
    }
    c += 0xfd;
  }
}
PCREG(534010, addLoop534010);
