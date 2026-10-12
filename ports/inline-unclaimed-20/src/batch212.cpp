// batch212.cpp - unclaimed area 20 (docs/20-unclaimed-20.md), slice floor(addr/16) mod 20 == 19. A pure bit-field reader
// (no calls): the first byte of the buffer is a signed bit width; a field is read from the buffer at a bit offset.
#include "ff.h"

typedef int i32;
typedef signed char i8;

// 0x4e8b70, stdcall(p, n): if n == 0, return 0. Otherwise w = (signed byte p[0]); t = (n - 1) * w (low 32 bits);
// shift = t & 7; q = p + (t >> 3) (arithmetic); v = (((q[1] << 8) | q[2]) << 8) | q[3]; then the value is shifted
// left by 8, arithmetic-shifted right by (32 - shift - w) (count masked to 5 bits, as the x86 shift does), and masked
// with (1 << (w & 31)) - 1. Name GUESS.
static u32 STDCALL readBitField_4e8b70(u8 *p, u32 n) {
  if (n == 0) return 0;
  i32 w = (i8)p[0];
  i32 t = (i32)(n - 1) * w;
  u32 shift = (u32)t & 7u;
  u8 *q = p + (t >> 3);
  u32 esi = ((u32)q[1] << 8 | q[2]) << 8;
  u32 eax = (u32)q[3] | esi;
  u32 cl = (32u - shift - (u32)w) & 31u;
  i32 r = (i32)(eax << 8) >> cl;
  u32 mask = (1u << ((u32)w & 31u)) - 1u;
  return (u32)r & mask;
}
PCREG(4e8b70, readBitField_4e8b70);
