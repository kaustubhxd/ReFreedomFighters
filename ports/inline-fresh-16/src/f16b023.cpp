// f16b023.cpp - fresh slice 16, batch 23 (2026-10-12).
// 0x45ac00 ZPICOBJ::ReadIndex4(buf, x, y, pitch, o0..o3): reads a 2x2 block of pixel indices. 4-bit images (b+0x2e): s =
//           pitch >> 1, p = buf + (x >> 1) + y * s; odd x: lo([p]), hi([p+1]), lo([p+s]), hi([p+s+1]); even x: hi([p]),
//           lo([p]), hi([p+s]), lo([p+s]). 8-bit: p = buf + y * pitch + x; [p], [p+1], [p+pitch], [p+pitch+1]. Ret 0x20.
// 0x562080 (thiscall t): a = f+0x6c * t; this slot 0xd4(0x633910((1 - a) * 254)) (CRT float-to-int
//           helper, run as exe code; _except1 stubbed); a = f+0x6c * t again; v = {(float)(int)(f+0x78 - a * 15), (float)(int)(f+0x7c - a * 0), f+0x80};
//           [+0x54] slot 0x70(&v) when set. Cookie not reproduced.
// 0x4cd5c0 STATICREFTAB::Add(v): +0x14++; h = +0x1c; h slot 0x14() == 0 -> new block b = this slot 0x80(): b = {0, +4, 0},
//           old head [+4] -> [old] = b, +4 = b; n = +0xc & 0x7fffffff entries at d = b+0x10, each: h slot 4(d),
//           d[k-1] = b (k = +0x18), d += k. Then h: h slot 0x4c(&it); e = h slot 0x5c(&it); it[0] -> h slot 0x44(&it), else
//           (or no h) e = v. [e[k-1]+8]++; e[0] = v; returns e+1.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_633910[];

extern "C" void THISCALL f16_45ac00(u8 *self, u8 *buf, int x, int y, int pitch, u8 *o0, u8 *o1, u8 *o2, u8 *o3) {
  if (AT(u8, self, 0x2e)) {
    int s = pitch >> 1;
    u8 *p = buf + (x >> 1) + y * s;
    if (x & 1) {
      *o0 = p[0] & 0xf;
      *o1 = p[1] >> 4;
      *o2 = p[s] & 0xf;
      *o3 = p[s + 1] >> 4;
    } else {
      *o0 = p[0] >> 4;
      *o1 = p[0] & 0xf;
      *o2 = p[s] >> 4;
      *o3 = p[s] & 0xf;
    }
  } else {
    u8 *p = buf + (y * pitch + x);
    *o0 = p[0];
    *o1 = p[1];
    *o2 = p[pitch];
    *o3 = p[pitch + 1];
  }
}

static inline int cvtt(float f) {
  int r;
  __asm__("cvttss2si %1, %0" : "=r"(r) : "x"(f));
  return r;
}

static inline u32 crt_ftoi(float f) {
  u32 r;
  __asm__ volatile("call ext_633910"
                   : "=a"(r), "+x"(f)
                   :
                   : "ecx", "edx", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7", "memory", "cc");
  return r;
}

extern "C" void THISCALL f16_562080(u8 *self, float t) {
  float a = AT(float, self, 0x6c) * t;
  u32 i = crt_ftoi((1.0f - a) * 254.0f);
  vcall<void>(self, 0xd4, i);
  float a2 = AT(float, self, 0x6c) * t;
  void *h = AT(void *, self, 0x54);
  volatile float v[3];
  v[0] = (float)cvtt(AT(float, self, 0x78) - a2 * 15.0f);
  v[1] = (float)cvtt(AT(float, self, 0x7c) - a2 * 0.0f);
  v[2] = AT(float, self, 0x80);
  if (h) vcall<void>(h, 0x70, (float *)v);
}

extern "C" u32 *THISCALL f16_4cd5c0(u8 *self, u32 v) {
  AT(u32, self, 0x14)++;
  if (vcall<u32>(AT(void *, self, 0x1c), 0x14) == 0) {
    u32 *b = vcall<u32 *>(self, 0x80);
    b[0] = 0;
    b[1] = AT(u32, self, 4);
    b[2] = 0;
    if (AT(u32 *, self, 4)) *AT(u32 *, self, 4) = (u32)b;
    u32 *d = b + 4;
    u32 n = AT(u32, self, 0xc) & 0x7fffffff;
    AT(u32 *, self, 4) = b;
    if (n) {
      do {
        vcall<void>(AT(void *, self, 0x1c), 4, d);
        d[AT(u32, self, 0x18) - 1] = (u32)b;
        d += AT(u32, self, 0x18);
      } while (--n);
    }
  }
  u32 *e = (u32 *)v;
  void *h = AT(void *, self, 0x1c);
  if (h) {
    volatile u32 it[4];
    vcall<void>(h, 0x4c, (u32 *)it);
    u32 *r = vcall<u32 *>(AT(void *, self, 0x1c), 0x5c, (u32 *)it);
    if (it[0]) {
      e = r;
      vcall<void>(AT(void *, self, 0x1c), 0x44, (u32 *)it);
    }
  }
  AT(u32, (u8 *)e[AT(u32, self, 0x18) - 1], 8)++;
  e[0] = v;
  return e + 1;
}

PCREG(45ac00, f16_45ac00);
PCREG(562080, f16_562080);
PCREG(4cd5c0, f16_4cd5c0);
