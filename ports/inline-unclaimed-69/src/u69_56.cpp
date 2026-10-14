// u69_56.cpp - area 69, group 56 (slice 8). A 3x3x3 neighbourhood scan over a cell array at self+0x3c (cells 0x7c bytes apart), one call per non-centre neighbour.
// The callee 0x459b90 (thiscall, four stack args, ret 0x10, other area) is a GUESS stub in the spec.
#include "ff.h"

extern "C" u32 THISCALL ext_459b90(void *self, u32 a1, u32 a2, u32 a3, u32 a4);

// 0x457840, thiscall one stack arg (p, ret 4), returns a 27-bit mask (bits start at 0x0fffffff). w0 = the word at p. If w0 is 0 nothing is looked up.
// For each (dx, dy, dz) in {-1,0,1}^3, with bit index idx = (dx+1) + 3*(dy+1) + 9*(dz+1): the cell is base = [self+0x3c] + (w0-1)*0x7c; the callee is called with a
// neighbour word chosen by the signs of dx, dy, dz (the centre cell is not called; r = cell itself). A non-zero result r other than p whose byte at +2 has 0x80 set clears bit idx.
static u32 THISCALL neighbourMask457840(u8 *self, u8 *p) {
  u32 w0 = *(u16 *)p;
  u32 mask = 0x0fffffff;
  for (s32 k = 0; k < 3; ++k) {
    s32 dx = k - 1;
    for (s32 dy = -1; dy <= 1; ++dy) {
      u32 idx = (u32)k + 3 * (u32)(dy + 1);
      for (s32 dz = -1; dz <= 1; ++dz, idx += 9) {
        if (w0 == 0)
          continue;
        u8 *cell = *(u8 **)(self + 0x3c) + (w0 - 1) * 0x7c;
        u8 *r;
        if (dx > 0) {
          r = (u8 *)ext_459b90(self, *(u16 *)(cell + 6), 0, (u32)dy, (u32)dz);
        } else if (dx < 0) {
          r = (u8 *)ext_459b90(self, *(u16 *)(cell + 4), 0, (u32)dy, (u32)dz);
        } else if (dy > 0) {
          r = (u8 *)ext_459b90(self, *(u16 *)(cell + 0xa), 0, 0, (u32)dz);
        } else if (dy < 0) {
          r = (u8 *)ext_459b90(self, *(u16 *)(cell + 8), 0, 0, (u32)dz);
        } else if (dz > 0) {
          r = (u8 *)ext_459b90(self, *(u16 *)(cell + 0xe), 0, 0, 0);
        } else if (dz < 0) {
          r = (u8 *)ext_459b90(self, *(u16 *)(cell + 0xc), 0, 0, 0);
        } else {
          r = cell;
        }
        if (r != 0 && r != p && (r[2] & 0x80))
          mask &= ~(1u << idx);
      }
    }
  }
  return mask;
}
PCREG(457840, neighbourMask457840);
