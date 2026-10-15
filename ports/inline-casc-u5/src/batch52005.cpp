// batch52005.cpp - cascade tier H, batch 52005: 0x526880 (fill the per-slot float fields of two arrays of records).
#include "ff.h"

extern "C" u32 THISCALL ext_516250(void *self);                 // plain thiscall, returns a pointer/handle
extern "C" void THISCALL ext_52a070(void *self, u32 a);         // ret 4
extern "C" void THISCALL ext_516f40(void *self, float *v);      // ret 4
extern "C" void FASTCALL ext_633654(u32 cookie);                // /GS check

static u32 rd32(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static float rdf(const u8 *p) { return bitsf(rd32(p)); }
static void wrf(u8 *p, float f) { wr32(p, fbits(f)); }

// Per record of an array (stride, count): [rec+0] = f18, [+0x79] = f1c, [+0x7d] = f20, ext_516f40(rec + 0x69, &vec), [+0xc6] = f24; a nonzero handle first goes to ext_52a070(rec - 0x4d, handle).
static void fill(u8 *base, int count, u32 stride, u32 handle, float f18, float f1c, float f20, float f24, float *vec) {
  u8 *p = base;
  for (int i = 0; i < count; i++) {
    if (handle) ext_52a070(p - 0x4d, handle);
    wrf(p, f18);
    wrf(p + 0x79, f1c);
    wrf(p + 0x7d, f20);
    ext_516f40(p + 0x69, vec);
    wrf(p + 0xc6, f24);
    p += stride;
  }
}

// 0x526880, thiscall plain, /GS. p = this[0x7c] * this[0x68]; q = (float)(|(double)p| via the mask at 0x67cd50); f18 = f1c = 0, f20 = 0x67c19c, f24 = q * 0x67c198; v = (0, 1, -1).
// rnd = engine slot 0x1c0 (0x6a0918, 0x288); when 0x67a284 >= rnd: handle = ext_516250(this + 0x435). q > 0x67da20: f18 = 0x67cd40 / q, f1c = 0x69eb58 / q.
// v[2] = 1 when p < 0. this[0xd49] (unaligned int) 2: v[2] = -v[2], f24 = q; 1: f24 = this[0x6c] + q; either: f1c = f18 = 0x69f9cc, f20 = 1.0.
// Then [this+0x8c] records at this+0x82a (stride 0x163), then [this+0x90] records at this+0xd86 (stride 0x133), through fill().
static void THISCALL fn526880(u8 *self) {
  float v[3];
  v[0] = 0; v[1] = 1.0f; v[2] = -1.0f;
  float p = rdf(self + 0x7c) * rdf(self + 0x68);
  u64 db = __builtin_bit_cast(u64, (double)p) & G(u64, 0x67cd50);
  float q = (float)__builtin_bit_cast(double, db);
  float f18 = 0, f1c = 0, f20 = G(float, 0x67c19c);
  float f24 = q * G(float, 0x67c198);
  float rnd = vcall<float>(G(u8 *, 0x70039c), 0x1c0, 0x6a0918u, 0x288u);
  u32 handle = 0;
  if (G(float, 0x67a284) >= rnd) handle = ext_516250(self + 0x435);
  if (q > G(float, 0x67da20)) {
    f18 = G(float, 0x67cd40) / q;
    f1c = G(float, 0x69eb58) / q;
  }
  float one = G(float, 0x678858);
  float s = (0.0f > p) ? one : v[2];
  v[2] = s;
  u32 mode = rd32(self + 0xd49);
  if (mode == 2) {
    s = bitsf(fbits(s) ^ G(u32, 0x67af40));
    f24 = q;
    v[2] = s;
  } else if (mode == 1) {
    f24 = rdf(self + 0x6c) + q;
  }
  if (mode == 2 || mode == 1) {
    f1c = G(float, 0x69f9cc);
    f20 = one;
    f18 = f1c;
  }
  fill(self + 0x82a, *(s32 *)(self + 0x8c), 0x163, handle, f18, f1c, f20, f24, v);
  fill(self + 0xd86, *(s32 *)(self + 0x90), 0x133, handle, f18, f1c, f20, f24, v);
  ext_633654(0);
}
PCREG(526880, fn526880);
