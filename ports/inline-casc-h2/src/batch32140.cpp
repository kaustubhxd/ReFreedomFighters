// batch32140.cpp - cascade h2 (Sonnet): two tier H (float / SSE) functions.
#include "ff.h"

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static inline float rdf(const u8 *p) { u32 b = rd32(p); float f; __builtin_memcpy(&f, &b, 4); return f; }
static inline void wrf(u8 *p, float f) { u32 b; __builtin_memcpy(&b, &f, 4); wr32(p, b); }

extern "C" void FASTCALL ext_633654(u32 cookie);                              // /GS check
extern "C" u32 THISCALL ext_5c8750(u8 *self, u32 *v);                         // thiscall ret 4, returns al
extern "C" void THISCALL ext_529e30(u8 *self, float a, float b);              // thiscall ret 8
typedef u32 (*cd2_t)(u32, u32);

// 0x5c87f0, thiscall(pp) ret 4 (/GS frame), returns al: s = [pp]; s == 0 -> o = slot 0x20 of [0x700390] with (0x6b49b8, 0x1b1), then o's cdecl slot 0x2c with (o, 0x6b4a90); return 0.
// Otherwise t = slot 0x58 of [[0x70039c]+0x9b] with s; v[3] = {0, 0, 0}; slot 0x84 of t with (&v); v[1] += 100.0f (float); r = 0x5c8750(this, &v); r == 0 (al) -> [pp] = 0; returns r.
static u32 THISCALL fn5c87f0(u8 *self, u32 *pp) {
  u32 s = pp[0];
  if (s == 0) {
    void *g = G(void *, 0x700390);
    u8 *o = vcall<u8 *>(g, 0x20, 0x6b49b8u, 0x1b1u);
    (*(cd2_t *)(*(u8 **)o + 0x2c))((u32)o, 0x6b4a90);
    ext_633654(0);
    return 0;
  }
  u8 *eng = G(u8 *, 0x70039c);
  u8 *t = vcall<u8 *>(*(void **)(eng + 0x9b), 0x58, s);
  u32 v[3];
  v[0] = 0;
  v[1] = 0;
  v[2] = 0;
  vcall<void>(t, 0x84, (u32)v);
  float f = bitsf(v[1]) + 100.0f;
  v[1] = fbits(f);
  u32 r = ext_5c8750(self, v);
  if ((u8)r == 0) pp[0] = 0;
  ext_633654(0);
  return r;
}
PCREG(5c87f0, fn5c87f0);

// 0x528b60, thiscall no args: m = float [this+0x78] * float [this+0x68]; h = float [this+0x21b9] * float [this+0x74] * 0.5f; float [this+0x7c] = m + h; float [this+0x80] = m - h (all unaligned);
// for i = 0, 2, .. while i < [this+0x8d] (signed; entered only when > 0): 0x529e30(this+0xfa8+0x266*(i/2) - 0x133, [this+0x7c], [this+0x6c]); 0x529e30(this+0xfa8+0x266*(i/2), [this+0x80], [this+0x6c]);
// then the same with count [this+0x91] and base this+0x1940. Fields are re-read for every call.
static void THISCALL fn528b60(u8 *self) {
  float a = rdf(self + 0x21b9) * rdf(self + 0x74);
  float b = rdf(self + 0x78) * rdf(self + 0x68);
  a = a * 0.5f;
  wrf(self + 0x7c, b + a);
  wrf(self + 0x80, b - a);
  s32 i = 0;
  if ((s32)rd32(self + 0x8d) > 0) {
    u8 *p = self + 0xfa8;
    do {
      ext_529e30(p - 0x133, rdf(self + 0x7c), rdf(self + 0x6c));
      ext_529e30(p, rdf(self + 0x80), rdf(self + 0x6c));
      i += 2;
      p += 0x266;
    } while (i < (s32)rd32(self + 0x8d));
  }
  i = 0;
  if ((s32)rd32(self + 0x91) > 0) {
    u8 *p = self + 0x1940;
    do {
      ext_529e30(p - 0x133, rdf(self + 0x7c), rdf(self + 0x6c));
      ext_529e30(p, rdf(self + 0x80), rdf(self + 0x6c));
      i += 2;
      p += 0x266;
    } while (i < (s32)rd32(self + 0x91));
  }
}
PCREG(528b60, fn528b60);
