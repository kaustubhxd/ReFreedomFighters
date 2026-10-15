// batch32109.cpp - cascade h2 (Sonnet): three tier H (float / SSE) functions.
#include "ff.h"

extern "C" void THISCALL ext_5233a0(u8 *self, u32 *out, float a);   // thiscall ret 8
extern "C" void THISCALL ext_521600(u8 *self, u32 *p);              // thiscall ret 4
extern "C" void THISCALL ext_5168b0(u8 *self);                      // thiscall, plain ret
extern "C" void FASTCALL ext_633654(u32 cookie);                    // /GS check

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static inline float rdf(const u8 *p) { u32 b = rd32(p); float f; __builtin_memcpy(&f, &b, 4); return f; }

// 0x4f72c0, thiscall(a, float b) ret 8, bool: id = unaligned [this+0x8f] == 0 -> false; engine table slot 0x4c with id != a -> false; t = (int)trunc(unaligned float [this+0x9f]);
// n = slot 0x388 of this with 1; slot 0x374 of this with (float)(n - t) * b; true.
static bool THISCALL fn4f72c0(u8 *self, u32 a, float b) {
  u32 id = rd32(self + 0x8f);
  if (!id) return false;
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 r = vcall<u32>(tbl, 0x4c, id);
  if (r != a) return false;
  u32 fb = rd32(self + 0x9f);
  float ft;
  __builtin_memcpy(&ft, &fb, 4);
  s32 t;
  __asm__("cvttss2si %1, %0" : "=r"(t) : "m"(ft));
  u32 vt = *(u32 *)self;
  u32 n = (*(u32 (THISCALL **)(void *, u32))(vt + 0x388))(self, 1u);
  float x = (float)(s32)(n - (u32)t) * b;
  (*(void (THISCALL **)(void *, float))(vt + 0x374))(self, x);
  return true;
}
PCREG(4f72c0, fn4f72c0);

// 0x520bb0, thiscall(float a, byte flag) ret 8 (/GS frame): byte [this+0x2fc] = flag; [this+0x2f8] = a; [this+0x2f4] = 1; slot 0 of the object embedded at this+0x2695 (unaligned vtable) with
// (0x3f060a92, 0x3e32b8c2, 0x40490fdb); 0x5233a0([this+0x5c], &buf, [this+0x2f8]); 0x521600(this, &buf); [this+0x216] = 0 (unaligned dword); /GS check.
static void THISCALL fn520bb0(u8 *self, float a, u32 flag) {
  u32 buf[4];
  self[0x2fc] = (u8)flag;
  *(float *)(self + 0x2f8) = a;
  *(u32 *)(self + 0x2f4) = 1;
  vcall<void>(self + 0x2695, 0, 0x3f060a92u, 0x3e32b8c2u, 0x40490fdbu);
  ext_5233a0(*(u8 **)(self + 0x5c), buf, *(float *)(self + 0x2f8));
  ext_521600(self, buf);
  wr32(self + 0x216, 0);
  ext_633654(0);
}
PCREG(520bb0, fn520bb0);

// 0x5295d0, thiscall no args: s = (f = [this+0x68]) > 100.0 (0x67cd40) ? 5.0 (0x679544) / f : 0.05 (0x681dc4); when [this+0x6c] > 50.0 (0x680a84) s = 0.005 (0x69c69c); m = (0.005 > s) ? 0.005 : s (maxss order);
// for i < [this+0x22c0] (signed): [this+0x21ce + i*0x79 + 0x10] = m (unaligned) and 0x5168b0(record).
static void THISCALL fn5295d0(u8 *self) {
  float s = G(float, 0x681dc4);
  float f = *(float *)(self + 0x68);
  if (f > G(float, 0x67cd40)) s = G(float, 0x679544) / f;
  float g = *(float *)(self + 0x6c);
  float k5 = G(float, 0x69c69c);
  if (g > G(float, 0x680a84)) s = k5;
  float m = (k5 > s) ? k5 : s;
  s32 cnt = *(s32 *)(self + 0x22c0);
  for (s32 i = 0; i < cnt; i++) {
    u8 *rec = self + 0x21ce + 0x79 * i;
    u32 mb; __builtin_memcpy(&mb, &m, 4);
    wr32(rec + 0x10, mb);
    ext_5168b0(rec);
    cnt = *(s32 *)(self + 0x22c0);
  }
}
PCREG(5295d0, fn5295d0);
