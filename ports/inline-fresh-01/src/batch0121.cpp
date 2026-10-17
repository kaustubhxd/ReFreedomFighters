// batch0121.cpp - fresh-01 batch 21 (docs/20-fresh-01.md).
#include "ff.h"

extern "C" void THISCALL ext_45d5b0(u8 *self, u8 *src);              // ZGEOM::CopyData (tail call to slot 0x48)
extern "C" void *ext_41e290(u32 size);                               // operator new
extern "C" void THISCALL ext_638ea0(void *sw, u32 w, u32 h, u32 d);  // swizzle masks (leaf, original code)
extern "C" void *ext_634d22(void *d, const void *s, u32 n);          // memcpy thunk
extern "C" void ext_634273(void *p, u32 n);                          // operator delete (sized)

static u8 *dupString(const char *s) {
  u32 n = 0;
  while (s[n]) n++;
  u8 *d = (u8 *)ext_41e290(n + 1);
  u8 *q = d;
  char ch;
  do {
    ch = *s++;
    *(volatile char *)q = ch;
    q++;
  } while (ch);
  return d;
}

// 0x4559d0, ZParticleTemplate::CopyData(const ZGEOM*): ZGEOM::CopyData, then when src slot 0x1e0(0x2000e5) says it is
// a particle template: dwords +0x18..+0x28 and +0x30..+0x44, byte +0x48, the name strings +0x55 and +0x4d duplicated
// (new + copy; 0 stays 0), dwords +0x49, +0x51, +0x59 and 0x20 dwords from +0x5d.
static void THISCALL particleTemplateCopyData(u8 *self, u8 *src) {
  ext_45d5b0(self, src);
  if (!vcall<u8>(src, 0x1e0, 0x2000e5u)) return;
  for (u32 o = 0x18; o <= 0x28; o += 4) *(u32 *)(self + o) = *(u32 *)(src + o);
  for (u32 o = 0x30; o <= 0x44; o += 4) *(u32 *)(self + o) = *(u32 *)(src + o);
  self[0x48] = src[0x48];
  const char *s = *(const char **)(src + 0x55);
  *(u8 **)(self + 0x55) = s ? dupString(s) : 0;
  *(u32 *)(self + 0x49) = *(u32 *)(src + 0x49);
  s = *(const char **)(src + 0x4d);
  *(u8 **)(self + 0x4d) = s ? dupString(s) : 0;
  *(u32 *)(self + 0x51) = *(u32 *)(src + 0x51);
  *(u32 *)(self + 0x59) = *(u32 *)(src + 0x59);
  for (u32 k = 0; k < 0x20; k++) *(volatile u32 *)(self + 0x5d + 4 * k) = *(u32 *)(src + 0x5d + 4 * k);
}
PCREG(4559d0, particleTemplateCopyData);

// 0x639e90 (unnamed, texture swizzle): for each of the +0x10 levels (20-byte records at +0x14: +4 width, +8 height,
// +0x10 texels; re-read through +0x14 every time), gets the x / y bit masks from 0x638ea0(w, h, 0), copies the
// texels into a new buffer at index ybits | xbits (bits stepped with (b - mask) & mask), copies the buffer back over
// the level (w * h * 4 bytes) and frees it (delete(buf, 4)). new's size saturates to -1 on overflow.
static void THISCALL swizzleLevels(u8 *self) {
  for (s32 lvl = 0; lvl < *(s32 *)(self + 0x10); lvl++) {
    u32 off = (u32)lvl * 0x14;
    u8 *ent = *(u8 **)(self + 0x14) + off;
    u32 sw[9];
    u32 h = *(u32 *)(ent + 8), w = *(u32 *)(ent + 4);
    ext_638ea0(sw, w, h, 0);
    unsigned long long bytes = (unsigned long long)(w * h) * 4;
    u32 *buf = (u32 *)ext_41e290((bytes >> 32) ? 0xffffffffu : (u32)bytes);
    u32 lin = 0, ybits = 0;
    ent = *(u8 **)(self + 0x14) + off;
    u32 *tex = *(u32 **)(ent + 0x10);
    if (*(s32 *)(ent + 8) > 0) {
      for (s32 row = 0;;) {
        u32 xbits = 0;
        s32 x = 0;
        if (*(s32 *)(*(u8 **)(self + 0x14) + off + 4) > 0) {
          do {
            u32 idx = ybits | xbits;
            x++;
            xbits = (xbits - sw[3]) & sw[3];
            buf[idx] = tex[lin];
            lin++;
          } while (x < *(s32 *)(*(u8 **)(self + 0x14) + off + 4));
        }
        ybits = (ybits - sw[4]) & sw[4];
        row++;
        if (row >= *(s32 *)(*(u8 **)(self + 0x14) + off + 8)) break;
      }
    }
    ent = *(u8 **)(self + 0x14) + off;
    ext_634d22(tex, buf, *(u32 *)(ent + 8) * *(u32 *)(ent + 4) * 4);
    ext_634273(buf, 4);
  }
}
PCREG(639e90, swizzleLevels);
