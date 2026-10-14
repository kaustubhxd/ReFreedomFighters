// batch32108.cpp - cascade h2 (): three tier H (float / SSE) functions.
#include "ff.h"

extern "C" void THISCALL ext_4da1d0(u8 *self, u32 a);          // thiscall ret 4
extern "C" void THISCALL ext_4dd060(u8 *self, float *p);       // thiscall ret 4
extern "C" void FASTCALL ext_633654(u32 cookie);               // /GS check
extern "C" float THISCALL ext_4e6910(u8 *self, float a);       // thiscall ret 4, float in st0
extern "C" void ext_634273(u8 *p, u32 n);                      // free-style, cdecl
typedef u32 (*cd2_t)(u32, u32);

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x453090, thiscall no args (/GS frame): 0x4da1d0([this+8], 1); o = [this+8]; v = {[o+0x40], [o+0x44], [o+0x48]}, each replaced by 0x39000000 (2^-13) when K(0x679540) > value (ordered);
// 0x4dd060(o, v); /GS check.
static void THISCALL fn453090(u8 *self) {
  float v[3];
  ext_4da1d0(*(u8 **)(self + 8), 1);
  u8 *o = *(u8 **)(self + 8);
  float k = G(float, 0x679540);
  v[0] = *(float *)(o + 0x40);
  v[1] = *(float *)(o + 0x44);
  v[2] = *(float *)(o + 0x48);
  for (int i = 0; i < 3; i++)
    if (k > v[i]) *(u32 *)&v[i] = 0x39000000;
  ext_4dd060(o, v);
  ext_633654(0);
}
PCREG(453090, fn453090);

// 0x4e6780, thiscall(n) ret 4, returns this: m = n >= 0x20 (unsigned) ? n : 0x20; [this] = 0x697510; [4] = [8] = [0x10] = [0x14] = 0; f = (float)((double)(int)m + table[m >> 31] (0x680aa0)) + K(0x678858);
// r = 0x4e6910(this, f) (float); sh = 1 << ((int)trunc(r) & 31); [this+0xc] = sh, doubled when sh < m (unsigned).
static u8 *THISCALL fn4e6780(u8 *self, u32 n) {
  u32 m = n >= 0x20 ? n : 0x20;
  *(u32 *)self = 0x697510;
  *(u32 *)(self + 4) = 0;
  *(u32 *)(self + 8) = 0;
  *(u32 *)(self + 0x10) = 0;
  *(u32 *)(self + 0x14) = 0;
  *(u32 *)(self + 0xc) = 1;
  double d = (double)(s32)m + G(double, 0x680aa0 + 8 * (m >> 31));
  float f = (float)d;
  f = f + G(float, 0x678858);
  float r = ext_4e6910(self, f);
  s32 t;
  __asm__("cvttss2si %1, %0" : "=r"(t) : "m"(r));
  u32 sh = 1u << ((u32)t & 31);
  *(u32 *)(self + 0xc) = sh;
  if (sh < m) *(u32 *)(self + 0xc) = sh * 2;
  return self;
}
PCREG(4e6780, fn4e6780);

// 0x650eb0, thiscall(float *p) ret 4: 0 >= p[0] or 0 >= p[1] (ordered) -> logs through [0x700390] (slot 0x20 with (0x6c3180, 0x506), then its cdecl slot 0x2c with (o, 0x6c34a8));
// else unaligned [this+0xb5] = p[0], [this+0xb9] = p[1]; [this+0x74] != 0 -> free it (size 1) and clear it.
static void THISCALL fn650eb0(u8 *self, float *p) {
  float a = p[0];
  if (0.0f >= a || 0.0f >= p[1]) {
    void *g = G(void *, 0x700390);
    u8 *o = vcall<u8 *>(g, 0x20, 0x6c3180u, 0x506u);
    (*(cd2_t *)(*(u8 **)o + 0x2c))((u32)o, 0x6c34a8);
    return;
  }
  u32 ab; __builtin_memcpy(&ab, &a, 4);
  wr32(self + 0xb5, ab);
  wr32(self + 0xb9, *(u32 *)(p + 1));
  u8 *q = *(u8 **)(self + 0x74);
  if (!q) return;
  ext_634273(q, 1);
  *(u32 *)(self + 0x74) = 0;
}
PCREG(650eb0, fn650eb0);
