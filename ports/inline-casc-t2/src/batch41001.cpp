// batch41001.cpp - cascade t2 (): tier H float functions 0x50ad50 and 0x4bfb80.
#include "ff.h"

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static inline float rdf(const u8 *p) { u32 b = rd32(p); float f; __builtin_memcpy(&f, &b, 4); return f; }
static inline void wrf(u8 *p, float f) { u32 b; __builtin_memcpy(&b, &f, 4); wr32(p, b); }

extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 idx); // thiscall, ret 4, returns element pointer

typedef u32 (*hook_t)();

// 0x50ad50, stdcall(p) ret 4 (ecx unused): tbl = [[0x70039c]+0x9b]; d = tbl slot 0x134(); cl = [p+4]; fp = 0x5003d0(cl, 1); el = 0x5003d0(cl, 0);
// by byte el[4]: 3 -> v = [el]; 4 -> v = slot 0x34 of the object [el]; otherwise the error path ([0x700390] slot 0x20(0x69c8e0, 0x111) -> o; o's vtable slot 0x2c(o, 0x69c6b0, 0x69c9b0)
// cdecl; assert hook 0x7003b0, int3 when null; v = 0). Finally d slot 0x58(v, float [fp], 3).
static void STDCALL fn50ad50(u8 *p) {
  void *tbl = (void *)rd32(G(u8 *, 0x70039c) + 0x9b);
  void *d = vcall<void *>(tbl, 0x134);
  u8 *cl = (u8 *)rd32(p + 4);
  u8 *fp = ext_5003d0(cl, 1);
  u8 *el = ext_5003d0(cl, 0);
  u32 v;
  u32 kind = el[4];
  if (kind == 3) {
    v = rd32(el);
  } else if (kind == 4) {
    v = vcall<u32>((void *)rd32(el), 0x34);
  } else {
    void *g = (void *)G(u32, 0x700390);
    u8 *o = vcall<u8 *>(g, 0x20, 0x69c8e0u, 0x111u);
    typedef void (*cd_t)(void *, u32, u32);
    (*(cd_t *)(rd32(o) + 0x2c))(o, 0x69c6b0, 0x69c9b0);
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
    v = 0;
  }
  vcall<void>(d, 0x58, v, rdf(fp), 3u);
}
PCREG(50ad50, fn50ad50);

static inline s32 trunc_ss(float f) { return _mm_cvttss_si32(_mm_set_ss(f)); }

// 0x4bfb80, thiscall, no args: when [this+0x64] >= 2 (signed) and s = [this+0x44] non-null: b = [s+0x18]; t = (int)(((float)(int)b[0x6c] * K1(0x6785e4) + b[0x78]) * K2(0x678620));
// when sys[0x30] >= t: x = b[0x70] - sys[0x34]; r = this slot 0x8c(b[0x60]) (float st0); b[0x60] = 0; f = (float)((double)x / (double)r) (x87 53-bit) -> [s+0x18][0x70];
// then u = (float)(sys[0x30] - (int)(((float)(int)b[0x6c] * K1 + b[0x78]) * K2)) * K1; when u >= u2 = u + f (ordered): s slot 0x210(1).
static void THISCALL fn4bfb80(u8 *self) {
  if ((s32)rd32(self + 0x64) < 2) return;
  u8 *s = (u8 *)rd32(self + 0x44);
  if (!s) return;
  u8 *b = (u8 *)rd32(s + 0x18);
  u8 *sys = G(u8 *, 0x70039c);
  float k1 = G(float, 0x6785e4);
  float k2 = G(float, 0x678620);
  float t0 = ((float)(s32)rd32(b + 0x6c) * k1 + rdf(b + 0x78)) * k2;
  if ((s32)rd32(sys + 0x30) < trunc_ss(t0)) return;
  float x = rdf(b + 0x70) - rdf(sys + 0x34);
  float r = vcall<float>(self, 0x8c, rd32(b + 0x60));
  float f = (float)((double)x / (double)r);
  wr32((u8 *)rd32(s + 0x18) + 0x60, 0);
  u8 *b2 = (u8 *)rd32(s + 0x18);
  wrf(b2 + 0x70, f);
  float t1 = ((float)(s32)rd32(b2 + 0x6c) * k1 + rdf(b2 + 0x78)) * k2;
  float u = (float)((s32)rd32(sys + 0x30) - trunc_ss(t1)) * k1;
  float u2 = u + f;
  if (!(u < u2) && !(u != u) && !(u2 != u2)) vcall<void>(s, 0x210, 1u);
}
PCREG(4bfb80, fn4bfb80);
