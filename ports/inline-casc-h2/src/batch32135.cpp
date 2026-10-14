// batch32135.cpp - cascade h2 (): three tier H (float / SSE) functions.
#include "ff.h"

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static inline float rdf(const u8 *p) { u32 b = rd32(p); float f; __builtin_memcpy(&f, &b, 4); return f; }
static inline void wrf(u8 *p, float f) { u32 b; __builtin_memcpy(&b, &f, 4); wr32(p, b); }

extern "C" void FASTCALL ext_633654(u32 cookie);          // /GS check
extern "C" void THISCALL ext_516690(u8 *self, float f);    // thiscall ret 4
extern "C" void THISCALL ext_52a1c0(u8 *self);             // thiscall

// 0x60f0b0, fastcall(out = ecx, in = edx), void: out is the inverse of a rigid 4x4 matrix in (3x3 transposed, last column 0 / 1, translation -R^T t).
static void FASTCALL fn60f0b0(u8 *out, u8 *in) {
  u32 *o = (u32 *)out;
  float *i = (float *)in;
  o[0] = rd32(in);
  o[4] = rd32(in + 4);
  o[8] = rd32(in + 8);
  o[1] = rd32(in + 0x10);
  o[5] = rd32(in + 0x14);
  o[9] = rd32(in + 0x18);
  o[2] = rd32(in + 0x20);
  o[6] = rd32(in + 0x24);
  o[10] = rd32(in + 0x28);
  o[0xb] = 0;
  o[7] = 0;
  o[3] = 0;
  o[0xf] = 0x3f800000;
  float tx = i[0xc], ty = i[0xd], tz = i[0xe];
  float a = i[1] * ty;
  float b = i[0] * tx;
  a = a + b;
  b = tz * i[2];
  a = a + b;
  o[0xc] = fbits(a) ^ 0x80000000;
  a = i[5] * ty;
  b = i[4] * tx;
  a = a + b;
  b = i[6] * tz;
  a = a + b;
  o[0xd] = fbits(a) ^ 0x80000000;
  a = i[9] * ty;
  float c = tx * i[8];
  b = i[10] * tz;
  a = a + c;
  a = a + b;
  o[0xe] = fbits(a) ^ 0x80000000;
}
PCREG(60f0b0, fn60f0b0);

// 0x504ac0, thiscall(a, float f1, float f2) ret 0xc (/GS frame): a == 0 -> 0. o = [this+0x14]; slot 0x80 of o with (&b34[9 dwords], &b10[3 dwords]);
// r = slot 0x37c of o with (a, f1, f2, &b34, &b10, 50.0f, -130.0f); returns r != 0 (al).
static u32 THISCALL fn504ac0(u8 *self, u32 a, float f1, float f2) {
  if (a == 0) {
    ext_633654(0);
    return 0;
  }
  u32 b34[9];
  u32 b10[3];
  vcall<void>(*(void **)(self + 0x14), 0x80, (u32)b34, (u32)b10);
  u32 r = vcall<u32>(*(void **)(self + 0x14), 0x37c, a, f1, f2, (u32)b34, (u32)b10, 50.0f, -130.0f);
  u32 ret = (u8)r != 0;
  ext_633654(0);
  return ret;
}
PCREG(504ac0, fn504ac0);

// 0x526610, thiscall(float f) ret 4: [this+0x94] = 0x43c80000, [this+0x98] = 0x3f860a92, [this+0x9c] = 0x3b03126f;
// for i in 0 .. [this+0x8c] (signed, re-read each pass): 0x516690(this+0xbd + 0xde*i, f); 0x52a1c0(this+0x7dd + 0x163*i);
// for j in 0 .. [this+0x90]: 0x516690(this+0x435 + 0xde*j, f); 0x52a1c0(this+0xd39 + 0x133*j).
static void THISCALL fn526610(u8 *self, float f) {
  s32 i = 0;
  wr32(self + 0x94, 0x43c80000);
  wr32(self + 0x98, 0x3f860a92);
  wr32(self + 0x9c, 0x3b03126f);
  if ((s32)rd32(self + 0x8c) > 0) {
    u8 *p = self + 0xbd;
    u8 *q = self + 0x7dd;
    do {
      ext_516690(p, f);
      ext_52a1c0(q);
      i++;
      p += 0xde;
      q += 0x163;
    } while (i < (s32)rd32(self + 0x8c));
  }
  i = 0;
  if ((s32)rd32(self + 0x90) > 0) {
    u8 *p = self + 0x435;
    u8 *q = self + 0xd39;
    do {
      ext_516690(p, f);
      ext_52a1c0(q);
      i++;
      p += 0xde;
      q += 0x133;
    } while (i < (s32)rd32(self + 0x90));
  }
}
PCREG(526610, fn526610);
