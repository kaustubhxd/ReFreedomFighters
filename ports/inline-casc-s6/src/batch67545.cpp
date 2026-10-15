// batch67545.cpp - cascade s6 batch 67545: 0x61a520.
#include "ff.h"

extern "C" u8 *THISCALL ext_60ed80(u8 *ring, u32 *count, u32 *offset);   // ret 8: locks `count` entries, returns the mapped pointer (offset out)

#define G32(a) (*(volatile u32 *)(a))
#define G16(a) (*(volatile u16 *)(a))
typedef u32 (STDCALL *com3_t)(u8 *, u32, u32);
typedef u32 (STDCALL *com6_t)(u8 *, u32, u32, u32, u32, u32);

// 0x61a520, stdcall(n, base, ctx) ret 0xc, return value unused: writes n quads (4 corner vertices, 3 u16 pairs per 12-byte record = 6 words, the six words offset from the u16 counter base + 4 per
// quad by the globals at 0x6efd2c..0x6efd36) into the vertex ring ctx[0x13f6] (0x60ed80 locks 6*n entries) and submits them: when the ring's lock flag (+0xc) is set and it has a buffer (+0), that buffer's
// slot 0x30 is called and the flag cleared; the ring's buffer becomes the bound one in the device at [0x724a00] (slot 0x154, remembered in 0x7249f0 / 0x7249f4); finally the device ctx[0x1377] slot
// 0x11c draws (4, base, n * 4, offset, n * 2).
static void STDCALL fn61a520(u32 n, u32 base, u8 *ctx) {
  if (!n) return;
  u8 *ring = *(u8 **)(ctx + 0x13f6);
  u8 *dev = *(u8 **)(ctx + 0x1377);
  u32 off;
  u32 cnt = n * 6;
  u8 *buf = ext_60ed80(ring, &cnt, &off);
  if (cnt != 0) {
    u32 k = (u32)(((u64)(cnt - 1) * 0xaaaaaaabULL >> 32) >> 2) + 1;
    u16 *w = (u16 *)buf;
    u32 edx = base;
    u32 ebx = G32(0x6efd34);
    while (k--) {
      u32 cx = (u16)edx;
      edx += 4;
      w[0] = (u16)(G32(0x6efd2c) + cx);
      w[1] = (u16)(cx + G16(0x6efd2e));
      w[2] = (u16)(G32(0x6efd30) + cx);
      w[3] = (u16)(cx + G16(0x6efd32));
      w[4] = (u16)(cx + ebx);
      w[5] = (u16)(cx + G16(0x6efd36));
      w += 6;
    }
  }
  if (ring[0xc]) {
    u8 *b = *(u8 **)ring;
    if (b) {
      vcall<void>(b, 0x30, (u32)b);
      ring[0xc] = 0;
    }
  }
  u32 e = *(u32 *)ring;
  if (G32(0x7249f0) != e || G32(0x7249f4) != 0) {
    u8 *d2 = *(u8 **)0x724a00;
    G32(0x7249f0) = e;
    G32(0x7249f4) = 0;
    (*(com3_t *)(*(u8 **)d2 + 0x154))(d2, e, 0);
  }
  (*(com6_t *)(*(u8 **)dev + 0x11c))(dev, 4, base, n * 4, off, n * 2);
}
PCREG(61a520, fn61a520);
