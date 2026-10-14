// batch38021.cpp - cascade s8 batch 38021: 0x637be0 (build the next mip level of an RGBA image).
#include "ff.h"

extern "C" u8 *ext_41e290(u32 size);          // allocator, cdecl
extern "C" void ext_634273(void *p, u32 n);   // free(p, size), cdecl
typedef u32(THISCALL *v4_t)(void *, s32, s32, s32, u8 *);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))

// 0x637be0, thiscall(level, width, height, pixels) ret 0x10. Hands the level to slot 0x70; unless level + 1 equals this+0x10 builds the next level: every output pixel is the box
// average of a 2x2 block of RGBA bytes (2x1 when the width or height is 1 / the halved dimension is 0), packed with the byte sums masked before the shifts the way the original does;
// the half size image goes to slot 0x6c (level + 1) and is freed.
static void THISCALL fn637be0(u8 *self, s32 level, s32 w, s32 h, u8 *pix) {
  SLOT(self, 0x70, v4_t)(self, level, w, h, pix);
  s32 next = level + 1;
  if (next == *(s32 *)(self + 0x10)) return;
  s32 hw = w >> 1;      // [ebp+0xc]
  s32 hh = h >> 1;      // [ebp+0x10]
  s32 nw = w <= 1 ? w : hw;
  s32 nh = h <= 1 ? h : hh;
  u32 n = (u32)nh * (u32)nw;
  u64 prod = (u64)n * 4;
  u32 size = (prod >> 32) ? 0xffffffffu : (u32)prod;
  u8 *buf = ext_41e290(size);
  u8 *dst = buf;
  u8 *esi = pix;
  s32 stride2 = hw * 2;   // [ebp+0x14]
  if (nh > 0) {
    s32 rows = nh;
    do {
      if (nw > 0) {
        s32 cols = nw;
        do {
          u32 res;
          if (hw != 0 && hh != 0) {
            u8 *r2 = esi + (u32)stride2 * 4;
            u32 s3 = r2[3] + r2[7] + esi[7] + esi[3];
            u32 s2 = r2[6] + r2[2] + esi[6] + esi[2];
            u32 s1 = r2[5] + r2[1] + esi[5] + esi[1];
            u32 s0 = r2[4] + r2[0] + esi[4] + esi[0];
            u32 edx = (s3 & 0xfffffffc) << 8;
            edx = (edx + (s2 & 0xfffffffc)) << 8;
            edx = (edx + (s1 & 0xfffffffc)) << 6;
            res = edx + (s0 >> 2);
          } else {
            u32 s3 = esi[7] + esi[3];
            u32 s2 = esi[6] + esi[2];
            u32 s1 = esi[5] + esi[1];
            u32 s0 = esi[4] + esi[0];
            u32 edx = (s3 & 0xfffffffe) << 8;
            edx = (edx + (s2 & 0xfffffffe)) << 8;
            edx = (edx + (s1 & 0xfffffffe)) << 7;
            res = edx + (s0 >> 1);
          }
          *(u32 *)dst = res;
          dst += 4;
          if (hw != 0) esi += 8;
        } while (--cols != 0);
      }
      if (hh != 0) esi += (u32)stride2 * 4;
    } while (--rows != 0);
  }
  SLOT(self, 0x6c, v4_t)(self, next, nw, nh, buf);
  ext_634273(buf, 4);
}
PCREG(637be0, fn637be0);
