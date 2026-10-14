// batch32115.cpp - cascade h2 (): tier H (float / SSE) functions, batch 32115.
#include "ff.h"

extern "C" u32 THISCALL ext_5b8d80(u8 *self);                 // thiscall, plain ret (tail jump target)
typedef double (*imp_cd1_t)(u32);                              // cdecl import, x87 result
typedef u32 (*cd_log_t)(u32, u32, double);                     // cdecl log slot with a double argument
typedef u32 (STDCALL *s1_t)(u32);

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static inline float rdf(const u8 *p) { u32 b = rd32(p); float f; __builtin_memcpy(&f, &b, 4); return f; }
static inline void wrf(u8 *p, float f) { u32 b; __builtin_memcpy(&b, &f, 4); wr32(p, b); }

// 0x6581c0, thiscall(char *p) ret 4: p != 0 -> f = (float) of the cdecl import 0x6762d4(p) (x87 result); returns slot 0x1e8 of the object [this+0x104] with f;
// p == 0 -> f = float (st0) of slot 0x1ec of that object; o = slot 0x20 of [0x700390] with (0x6c4214, 0x29); returns its cdecl slot 0x2c with (o, 0x6c423c, (double)f).
static u32 THISCALL fn6581c0(u8 *self, u32 p) {
  void *t = *(void **)(self + 0x104);
  if (p) {
    float f = (float)G(imp_cd1_t, 0x6762d4)(p);
    return vcall<u32>(*(void **)(self + 0x104), 0x1e8, f);
  }
  float f = vcall<float>(t, 0x1ec);
  void *g = G(void *, 0x700390);
  u8 *o = vcall<u8 *>(g, 0x20, 0x6c4214u, 0x29u);
  return (*(cd_log_t *)(*(u8 **)o + 0x2c))((u32)o, 0x6c423c, (double)f);
}
PCREG(6581c0, fn6581c0);

// 0x5b87f0, thiscall no args: byte [this+0xdd] set -> return; x = unaligned float [this+0xb3] + (float)([[0x70039c]+0x40] - [[0x70039c]+0x44]) * K(0x6785e4), stored; byte [this+0xb2] set -> tail jump to 0x5b8d80(this);
// else x > [this+0x5c] -> [this+0xb3] = 0, byte [this+0xb2] = 1 and, when s = unaligned [this+0xe2] is set: ax = slot 0x114 of the engine table with (0x6b2718, 0, 0x6b2690, 0x158, 0, 0); slot 0x128 of s (vtable read first) with (word ax).
static u32 THISCALL fn5b87f0(u8 *self) {
  if (self[0xdd]) return 0;
  u8 *eng = G(u8 *, 0x70039c);
  float x = rdf(self + 0xb3);
  s32 d = *(s32 *)(eng + 0x40) - *(s32 *)(eng + 0x44);
  u8 flag = self[0xb2];
  x = x + (float)d * G(float, 0x6785e4);
  wrf(self + 0xb3, x);
  if (flag) return ext_5b8d80(self);
  if (!(x > *(float *)(self + 0x5c))) return 0;
  u32 s = rd32(self + 0xe2);
  wr32(self + 0xb3, 0);
  self[0xb2] = 1;
  if (!s) return 0;
  u32 vt = *(u32 *)s;
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 r = vcall<u32>(tbl, 0x114, 0x6b2718u, 0u, 0x6b2690u, 0x158u, 0u, 0u);
  (*(void (THISCALL **)(void *, u32))(vt + 0x128))((void *)rd32(self + 0xe2), r & 0xffff);
  return 0;
}
PCREG(5b87f0, fn5b87f0);
