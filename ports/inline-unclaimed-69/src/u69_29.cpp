// u69_29.cpp - area 69, group 29 (slice 8). stdcall, three args (ret 0xc, ignored). Clears bit 7 of two bytes of the object at the global pointer 0x70039c.
#include "ff.h"

static void STDCALL clearBits655200(u32 a, u32 b, u32 c) {
  u8 *g = *(u8 **)0x70039c;
  g[0xa15] &= 0x7f;
  g[0x1401] &= 0x7f;
}
PCREG(655200, clearBits655200);
