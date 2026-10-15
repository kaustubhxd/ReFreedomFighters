// batch52001.cpp - cascade tier H, batch 52001: 0x636a80 (re-encode 4x4 colour blocks through 0x636540).
#include "ff.h"

extern "C" void THISCALL ext_636540(void *rgb, float f);  // ret 4: adjusts three dword channels in place

// 0x636a80, thiscall(float f) ret 4: [this+0x10] records of 0x14 bytes at [this+0x14]; each record has width [+4], height [+8] (both rounded up to a multiple of 4) and a data pointer [+0x10].
// For every 4x4 block (16 bytes, the colour pair sits 8 bytes in): split the two RGB565 words into three dword channels, run ext_636540 on both with f,
// re-pack each to 565 (channel masks 0xfff8/0xfffc), order the pair so the new words keep the order of the old ones, and store (hi << 16) + lo.
static void THISCALL fn636a80(u8 *self, float f) {
  int n = *(int *)(self + 0x10);
  for (int i = 0; i < n; i++) {
    u8 *rec = *(u8 **)(self + 0x14) + i * 0x14;
    s32 w = (*(s32 *)(rec + 4) + 3 & 0xfffffffc) - 3;
    s32 h = (*(s32 *)(rec + 8) + 3 & 0xfffffffc) - 3;
    u8 *base = *(u8 **)(rec + 0x10);
    u32 edx = 0;
    if (h <= 0) continue;
    u32 outer = ((u32)(h - 1) >> 2) + 1;
    do {
      if (w > 0) {
        u32 cnt = ((u32)(w - 1) >> 2) + 1;
        u8 *p = base + edx * 4 + 8;
        edx += cnt * 4;
        do {
          u32 c0 = *(u16 *)p, c1 = *(u16 *)(p + 2);
          u32 a[3], b[3];
          a[0] = (c0 >> 8) & 0xfffff8; a[1] = (c0 >> 3) & 0xfc; a[2] = (c0 & 0x1f) << 3;
          b[0] = (c1 >> 8) & 0xfffff8; b[1] = (c1 >> 3) & 0xfc; b[2] = (c1 & 0x1f) << 3;
          ext_636540(a, f);
          ext_636540(b, f);
          u32 v0 = (u16)((a[2] >> 3) + (((a[0] & 0xfff8) << 5) + (a[1] & 0xfffc)) * 8);
          u32 v1 = (u16)((b[2] >> 3) + (((b[0] & 0xfff8) << 5) + (b[1] & 0xfffc)) * 8);
          u32 lo = v0, hi = v1;
          bool swap = (u16)c0 < (u16)c1 ? v0 > v1 : v0 < v1;
          if (swap) { lo = v1; hi = v0; }
          *(u32 *)p = (hi << 16) + lo;
          p += 0x10;
        } while (--cnt);
      }
    } while (--outer);
  }
}
PCREG(636a80, fn636a80);
