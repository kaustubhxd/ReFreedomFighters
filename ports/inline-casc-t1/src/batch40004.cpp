// batch40004.cpp - cascade t1 (Sonnet), tier H: 0x480020, 0x5d5fc0, 0x5162e0, 0x566b20, 0x4b8a30, 0x5de4c0.
#include "ff.h"

extern "C" float THISCALL ext_516130(u8 *self, float f, u32 a);        // thiscall ret 8, float on st0
extern "C" void THISCALL ext_5243f0(u8 *self, float f);                // thiscall ret 4
extern "C" void THISCALL ext_5243d0(u8 *self, float f);                // thiscall ret 4
extern "C" void THISCALL ext_524980(u8 *self, u8 *a, u8 *b);           // thiscall ret 8
extern "C" float THISCALL ext_5668d0(u8 *self, u32 a, u32 b, u32 c);   // thiscall ret 0xc, float on st0
extern "C" u32 THISCALL ext_4e5e40(u8 *self);                          // plain ret, ax = value
extern "C" float THISCALL ext_4e5e80(u8 *self);                        // plain ret, float on st0
extern "C" void THISCALL ext_4e6330(u8 *self, u32 a);                  // thiscall ret 4
typedef void (*hook_t)();

// 0x480020, thiscall(src) ret 4: assert hook (int3 when null); this->slot 0x48(src) (through thunk 0x45d5b0); when (u8) src->slot 0x1e0(0x2000cb) != 0:
// copies src[0x28..0x74) to this, then dwords 0x24, 0x20, 0x1c.
static void THISCALL fn480020(u8 *self, u8 *src) {
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
  vcall<void>(self, 0x48, (u32)src);
  u8 ok = vcall<u8>(src, 0x1e0, (u32)0x2000cb);
  if (!ok) return;
  for (int i = 0x28; i < 0x74; i++) self[i] = src[i];
  *(u32 *)(self + 0x24) = *(u32 *)(src + 0x24);
  *(u32 *)(self + 0x20) = *(u32 *)(src + 0x20);
  *(u32 *)(self + 0x1c) = *(u32 *)(src + 0x1c);
}
PCREG(480020, fn480020);

// 0x5d5fc0, thiscall(): a = [this+0x4c], b = [this+0x50] (signed); a == b -> nothing; cap = (int)(float [sys+0x48] * K(0x686098)); d = b - a; d > 0 -> d = min(d, cap);
// d < 0 -> d = max(d, -cap); c = a + d; a == 0 -> [this+0x44]->slot 0xbc(0); c == 0 -> slot 0xbc(1) else slot 0x250(c); [this+0x4c] = c.
static void THISCALL fn5d5fc0(u8 *self) {
  s32 a = *(s32 *)(self + 0x4c), b = *(s32 *)(self + 0x50);
  if (a == b) return;
  s32 cap = _mm_cvttss_si32(_mm_set_ss(*(float *)(G(u8 *, 0x70039c) + 0x48) * G(float, 0x686098)));
  s32 d = b - a;
  if (d > 0 && d > cap) d = cap;
  if (d < 0) {
    s32 nc = -cap;
    if (d < nc) d = nc;
  }
  s32 c = a + d;
  if (a == 0) vcall<void>(*(u8 **)(self + 0x44), 0xbc, (u32)0);
  u8 *o = *(u8 **)(self + 0x44);
  if (c == 0) {
    vcall<void>(o, 0xbc, (u32)1);
    *(s32 *)(self + 0x4c) = c;
    return;
  }
  vcall<void>(o, 0x250, (u32)c);
  *(s32 *)(self + 0x4c) = c;
}
PCREG(5d5fc0, fn5d5fc0);

// 0x5162e0, thiscall(p) ret 4: this[0..3] = p[0..3] dwords (3 of them); e = this + 0x41; ext_5243f0(e, [this+4] - unaligned float [this+0x35]); r = ext_516130(this, [this+4], 0);
// ext_5243d0(e, r); g = this + 0x55; ext_5243f0(g, [this+4]); ext_524980(this + 0x21, e, g).
static void THISCALL fn5162e0(u8 *self, u8 *p) {
  *(u32 *)self = *(u32 *)p;
  *(u32 *)(self + 4) = *(u32 *)(p + 4);
  *(u32 *)(self + 8) = *(u32 *)(p + 8);
  u8 *e = self + 0x41;
  u32 w = self[0x35] | self[0x36] << 8 | self[0x37] << 16 | (u32)self[0x38] << 24;
  ext_5243f0(e, *(float *)(self + 4) - bitsf(w));
  float r = ext_516130(self, *(float *)(self + 4), 0);
  ext_5243d0(e, r);
  u8 *g = self + 0x55;
  ext_5243f0(g, *(float *)(self + 4));
  ext_524980(self + 0x21, e, g);
}
PCREG(5162e0, fn5162e0);

// 0x566b20, thiscall(): t = [sys+0x40]; t < (int)(float [this+0x1ea] * K(0x678620)) -> return; i = [this+0x9f8]; i >= [this+0x1be] (signed) -> byte [this+0xa0b] = 0, return;
// c = [this + 0x19e + i*4]; c == 0 -> return; r = ext_5668d0(this, [this+0x19a], c, [this + 0x1c2 + i*4]); x = (int)(float)((double)r * K(0x67862c)); [this+0x9f8]++;
// float [this+0x1ea] = (float)(t + 0x600 - x) * K(0x6785e4).
static void THISCALL fn566b20(u8 *self) {
  s32 t = *(s32 *)(G(u8 *, 0x70039c) + 0x40);
  s32 lim = _mm_cvttss_si32(_mm_set_ss(*(float *)(self + 0x1ea) * G(float, 0x678620)));
  if (t < lim) return;
  s32 i = *(s32 *)(self + 0x9f8);
  if (i >= *(s32 *)(self + 0x1be)) {
    self[0xa0b] = 0;
    return;
  }
  u32 c = *(u32 *)(self + 0x19e + i * 4);
  if (!c) return;
  float r = ext_5668d0(self, *(u32 *)(self + 0x19a), c, *(u32 *)(self + 0x1c2 + i * 4));
  float x = (float)((double)r * (double)G(float, 0x67862c));
  s32 xi = _mm_cvttss_si32(_mm_set_ss(x));
  s32 v = t + 0x600 - xi;
  (*(s32 *)(self + 0x9f8))++;
  float f = _mm_cvtss_f32(_mm_cvtepi32_ps(_mm_cvtsi32_si128(v))) * G(float, 0x6785e4);
  *(float *)(self + 0x1ea) = f;
}
PCREG(566b20, fn566b20);

// 0x4b8a30, thiscall(s) ret 4: [this+0x48] = (u16) ext_4e5e40(s); [this+0x4a] = (u16) ext_4e5e40(s); ext_4e6330(s, [this+0x4c]); k = byte [[s]]; k != 0xff and (k & 0x3f) == 2 -> float [this+0x50] = ext_4e5e80(s), else [this+0x50] = 0;
// q = [this+0x4c]; q->slot 0x14() == 0 -> q->slot 4(engine table slot 0x4c([this+0x44])) with the vtable of q read before the engine call.
static void THISCALL fn4b8a30(u8 *self, u8 *s) {
  *(u16 *)(self + 0x48) = (u16)ext_4e5e40(s);
  *(u16 *)(self + 0x4a) = (u16)ext_4e5e40(s);
  ext_4e6330(s, *(u32 *)(self + 0x4c));
  u8 k = **(u8 **)s;
  if (k != 0xff && (k & 0x3f) == 2) *(float *)(self + 0x50) = ext_4e5e80(s);
  else *(u32 *)(self + 0x50) = 0;
  u8 *q = *(u8 **)(self + 0x4c);
  u32 r = vcall<u32>(q, 0x14);
  if (r) return;
  q = *(u8 **)(self + 0x4c);
  u8 *vt = *(u8 **)q;
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 e = vcall<u32>(tbl, 0x4c, *(u32 *)(self + 0x44));
  ((void(THISCALL *)(u8 *, u32))*(u32 *)(vt + 4))(*(u8 **)(self + 0x4c), e);
}
PCREG(4b8a30, fn4b8a30);

// 0x5de4c0, thiscall(o) ret 4, returns al = 1: [this+4] &= ~0x40; o->slot 0x10(this+0x48, 0xcc); o->slot 0x64([this+0x114]); o->slot 0x4c([this+0x118]); o->slot 0x4c([this+0x11c]);
// o->slot 0x10(this+0x120, 0xc); o->slot 0x4c([this+0x12c]).
static u32 THISCALL fn5de4c0(u8 *self, u8 *o) {
  *(u32 *)(self + 4) &= 0xffffffbf;
  vcall<void>(o, 0x10, (u32)(self + 0x48), (u32)0xcc);
  vcall<void>(o, 0x64, *(u32 *)(self + 0x114));
  vcall<void>(o, 0x4c, *(u32 *)(self + 0x118));
  vcall<void>(o, 0x4c, *(u32 *)(self + 0x11c));
  vcall<void>(o, 0x10, (u32)(self + 0x120), (u32)0xc);
  vcall<void>(o, 0x4c, *(u32 *)(self + 0x12c));
  return 1;
}
PCREG(5de4c0, fn5de4c0);
