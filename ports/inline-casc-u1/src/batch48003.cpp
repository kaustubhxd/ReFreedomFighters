// batch48003.cpp - cascade tier H, batch 48003: 0x6368d0 (desaturate and order the RGB565 pairs of a list of 4x4-block images).
#include "ff.h"

extern "C" void THISCALL ext_636540(void *rgb, float t);   // thiscall ret 4: moves the three ints toward their luma by t, clamps to [0, 1] scaled

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x6368d0, thiscall(float t) ret 4: for each of [this+0x10] (signed) records of 0x14 bytes at [this+0x14] (w = [rec+4], h = [rec+8], pixels = [rec+0x10]): w' = (w + 3) & ~3, h' = (h + 3) & ~3;
// when h' - 3 > 0: ((h' - 4) >> 2) + 1 passes of ((w' - 4) >> 2) + 1 steps (none when w' - 3 <= 0); the step counter k (0, 2, 4, ... continuing across passes) takes the dword at pixel dwords k:
// two RGB565 colours a (low) and b (high), each expanded to 8-bit ints (r = (c >> 8) & 0xf8, g = (c >> 3) & 0xfc, b = (c & 0x1f) << 3), run through ext_636540(&rgb, t), packed back to RGB565;
// the pair is swapped when (a < b && a' > b') || (a >= b && a' < b'), and stored back as (b' << 16) + a' to the same dword.
static void THISCALL fn6368d0(u8 *self, float t) {
  for (s32 i = 0; i < *(s32 *)(self + 0x10); i++) {
    u8 *rec = *(u8 **)(self + 0x14) + 0x14 * i;
    u32 w = (rd32(rec + 4) + 3) & 0xfffffffc;
    s32 hh = (s32)(((rd32(rec + 8) + 3) & 0xfffffffc) - 3);
    u8 *pix = *(u8 **)(rec + 0x10);
    u32 k = 0;
    if (hh > 0) {
      u32 outer = ((u32)(hh - 1) >> 2) + 1;
      s32 ww = (s32)(w - 3);
      for (; outer; outer--) {
        if (ww <= 0) continue;
        u32 inner = ((u32)(ww - 1) >> 2) + 1;
        for (; inner; inner--) {
          u32 d = rd32(pix + k * 4);
          u32 a = d & 0xffff, b = d >> 16;
          s32 sa[3], sb[3];
          sa[0] = (a >> 8) & 0xfffff8; sa[1] = (a >> 3) & 0xfc; sa[2] = (a & 0x1f) << 3;
          sb[0] = (b >> 8) & 0xfffff8; sb[1] = (b >> 3) & 0xfc; sb[2] = (b & 0x1f) << 3;
          ext_636540(sa, t);
          ext_636540(sb, t);
          u32 na = (u16)((((u32)(sa[0] & 0xfff8) << 5) + (u32)(sa[1] & 0xfffc)) * 8 + ((u32)sa[2] >> 3));
          u32 nb = (u16)((((u32)(sb[0] & 0xfff8) << 5) + (u32)(sb[1] & 0xfffc)) * 8 + ((u32)sb[2] >> 3));
          bool swap = (u16)a < (u16)b ? na > nb : na < nb;
          if (swap) { u32 x = na; na = nb; nb = x; }
          wr32(pix + k * 4, (nb << 16) + na);
          k += 2;
        }
      }
    }
  }
}
PCREG(6368d0, fn6368d0);
