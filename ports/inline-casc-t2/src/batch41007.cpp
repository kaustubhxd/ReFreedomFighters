// batch41007.cpp - cascade t2 (Sonnet): tier H function 0x457c30.
#include "ff.h"

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static inline u32 rd16(const u8 *p) { return p[0] | (p[1] << 8); }
static inline void wrf(u8 *p, float f) { u32 b; __builtin_memcpy(&b, &f, 4); wr32(p, b); }

extern "C" u8 *ext_41e290(u32 size); // allocator, cdecl (the spec returns scripted blocks)

// 0x457c30, thiscall, no args: r = [[sys+0x1aa3]+0x18] slot 0xf8([[this+8]+0x6c]); when r: [this+0x78] = (float)u16 [r+0xc], [this+0x7c] = (float)u16 [r+0xe].
// n = [this+0x8c] * [this+0x88]; h = new(8); [this+0x84] = h; h[0] = n; h[1] = 0; buf = new(n*0x44, all ones on overflow); h[1] = buf;
// n elements of 0x44 bytes: +0, +4, +8 = 0; +0xc, +0x10 = 0; +0x14 = 1.0; +0x18 = 0; +0x1c = 1.0; +0x20 = 1.0; +0x24 = 0; +0x28 = 1.0; +0x2c = 5.0; +0x30 = 5.0; +0x34..0x43 = the 16 bytes at 0x67a290.
static void THISCALL fn457c30(u8 *self) {
  u32 id = rd32((u8 *)rd32(self + 8) + 0x6c);
  u8 *o = (u8 *)rd32(G(u8 *, 0x70039c) + 0x1aa3);
  u8 *r = vcall<u8 *>((void *)rd32(o + 0x18), 0xf8, id);
  if (r) {
    wrf(self + 0x78, (float)(s32)rd16(r + 0xc));
    wrf(self + 0x7c, (float)(s32)rd16(r + 0xe));
  }
  u32 n = rd32(self + 0x8c) * rd32(self + 0x88);
  u8 *h = ext_41e290(8);
  wr32(self + 0x84, (u32)h);
  wr32(h, n);
  wr32((u8 *)rd32(self + 0x84) + 4, 0);
  u64 bytes = (u64)n * 0x44;
  u32 size = (u32)bytes | ((bytes >> 32) ? 0xffffffffu : 0u);
  u8 *buf = ext_41e290(size);
  wr32((u8 *)rd32(self + 0x84) + 4, (u32)buf);
  buf = (u8 *)rd32((u8 *)rd32(self + 0x84) + 4);
  u32 c0 = G(u32, 0x67a290), c1 = G(u32, 0x67a294), c2 = G(u32, 0x67a298), c3 = G(u32, 0x67a29c);
  for (u32 i = n; i; i--) {
    wr32(buf + 0, 0);
    wr32(buf + 4, 0);
    wr32(buf + 8, 0);
    wr32(buf + 0x2c, 0x40a00000);
    wr32(buf + 0x30, 0x40a00000);
    wr32(buf + 0xc, 0);
    wr32(buf + 0x10, 0);
    wr32(buf + 0x14, 0x3f800000);
    wr32(buf + 0x18, 0);
    wr32(buf + 0x1c, 0x3f800000);
    wr32(buf + 0x20, 0x3f800000);
    wr32(buf + 0x24, 0);
    wr32(buf + 0x28, 0x3f800000);
    wr32(buf + 0x34, c0);
    wr32(buf + 0x38, c1);
    wr32(buf + 0x3c, c2);
    wr32(buf + 0x40, c3);
    buf += 0x44;
  }
}
PCREG(457c30, fn457c30);
