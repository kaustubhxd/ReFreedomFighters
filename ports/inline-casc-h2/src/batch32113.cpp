// batch32113.cpp - cascade h2 (Sonnet): two tier H (float / SSE) functions.
#include "ff.h"

extern "C" void THISCALL ext_57f6b0(u8 *self);                 // thiscall, plain ret
extern "C" u32 THISCALL ext_57f750(u8 *self);                  // thiscall, plain ret (tail jump target)
typedef u32 (*cd2_t)(u32, u32);

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static inline void wrf(u8 *p, float f) { u32 b; __builtin_memcpy(&b, &f, 4); wr32(p, b); }

// 0x57f360, thiscall no args, returns the tail callee's eax: o1 = slot 0xbc of the engine object; slot 0xac of o1 with float [this+0x188]; slot 0x36c of [this+0x180] with ((int)trunc([this+0x188] * K(0x67da20)), 1);
// o2 = slot 0x84 of this; slot 0x314 of o2 with float [this+0x188]; 0x57f6b0(this); o3 = slot 0xbc of the engine object; slot 0xbc of o3 with byte [this+0x18c]; tail jump to 0x57f750(this).
static u32 THISCALL fn57f360(u8 *self) {
  void *eng = G(void *, 0x70039c);
  void *o1 = vcall<void *>(eng, 0xbc);
  vcall<void>(o1, 0xac, *(float *)(self + 0x188));
  float p = *(float *)(self + 0x188) * G(float, 0x67da20);
  s32 t;
  __asm__("cvttss2si %1, %0" : "=r"(t) : "m"(p));
  vcall<void>(*(void **)(self + 0x180), 0x36c, (u32)t, 1u);
  void *o2 = vcall<void *>(self, 0x84);
  vcall<void>(o2, 0x314, *(float *)(self + 0x188));
  ext_57f6b0(self);
  void *o3 = vcall<void *>(G(void *, 0x70039c), 0xbc);
  vcall<void>(o3, 0xbc, (u32)self[0x18c]);
  return ext_57f750(self);
}
PCREG(57f360, fn57f360);

// 0x4e7c50, thiscall(n) ret 4: p = unaligned [this+9] == 0 -> logs through [0x700390] (slot 0x20 with (0x697528, 0xa3), then its cdecl slot 0x2c with (o, 0x6975a0)); otherwise off = (flags [p+4] & 0xc0000000 is 0x40.., 0x80.. or 0xc..) ? [p+8] : 8;
// n is replaced by [p+off+8] when n < [p+off+4] or n > [p+off+8] (signed); unaligned [this+0x11] = (float)n.
static void THISCALL fn4e7c50(u8 *self, s32 n) {
  u8 *p = (u8 *)rd32(self + 9);
  if (!p) {
    void *g = G(void *, 0x700390);
    u8 *o = vcall<u8 *>(g, 0x20, 0x697528u, 0xa3u);
    (*(cd2_t *)(*(u8 **)o + 0x2c))((u32)o, 0x6975a0);
    return;
  }
  u32 k = *(u32 *)(p + 4) & 0xc0000000u;
  u32 off = 8;
  if (k == 0x40000000u || k == 0x80000000u || k == 0xc0000000u) off = *(u32 *)(p + 8);
  s32 lo = *(s32 *)(p + off + 4);
  s32 hi = *(s32 *)(p + off + 8);
  if (n < lo || n > hi) n = hi;
  wrf(self + 0x11, (float)n);
}
PCREG(4e7c50, fn4e7c50);
