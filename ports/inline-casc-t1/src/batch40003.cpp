// batch40003.cpp - cascade t1 (Sonnet), tier H: 0x57edf0, 0x459f40, 0x640c10, 0x524f50, 0x5072f0, 0x5a0b80.
#include "ff.h"

extern "C" void THISCALL ext_4e0a10(float *out);                         // thiscall(this = out vector), plain ret
extern "C" void THISCALL ext_4e0d00(u8 *self, float f);                  // thiscall ret 4
extern "C" void FASTCALL ext_451890(u8 *ecx, u8 *edx, float f);          // fastcall (ecx, edx) + 1 stack arg, ret 4
extern "C" void FASTCALL ext_443ef0(u8 *ecx, u8 *edx, u8 *p, float f);   // fastcall (ecx, edx) + 2 stack args, ret 8
extern "C" u32 THISCALL ext_658d30(u8 *self);                            // thiscall plain ret
extern "C" float THISCALL ext_63eb90(u8 *self, u32 a);                   // thiscall ret 4, float on st0
extern "C" void THISCALL ext_516070(u8 *self, float f);                  // thiscall ret 4
extern "C" u32 *THISCALL ext_5003d0(void *self, u32 i);                  // thiscall ret 4
extern "C" u32 THISCALL ext_5eade0(void *self, u32 a, u32 b, u32 c, u32 d, u32 e);   // ret 0x14

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x57edf0, thiscall(a, idx, n) ret 0xc: f = (float)((double)(s32)n + [0x680aa0 + (n >> 31) * 8]) (n as unsigned); o1 = [this + 0xc + idx*4], o2 = [this + 0x1c + idx*4];
// for each: o->slot 0x284(a), then o->slot 0x26c(f, 0, 0).
static void THISCALL fn57edf0(u8 *self, u32 a, u32 idx, u32 n) {
  u8 *o1 = *(u8 **)(self + 0xc + idx * 4);
  vcall<void>(o1, 0x284, a);
  double d = (double)(s32)n + G(double, 0x680aa0 + (n >> 31) * 8);
  float f = (float)d;
  o1 = *(u8 **)(self + 0xc + idx * 4);
  vcall<void>(o1, 0x26c, fbits(f), (u32)0, (u32)0);
  u8 *o2 = *(u8 **)(self + 0x1c + idx * 4);
  vcall<void>(o2, 0x284, a);
  o2 = *(u8 **)(self + 0x1c + idx * 4);
  vcall<void>(o2, 0x26c, fbits(f), (u32)0, (u32)0);
}
PCREG(57edf0, fn57edf0);

// 0x459f40, thiscall(p, f) ret 8: buf = 3 floats from 0x4e0a10; 0x4e0d00(this+0xac, 0.995f (0x3f7eb852)); 0x451890(this+0xac, buf, f * K(0x67a6ac)); 0x443ef0(p, this+0xa0, this+0xac, f).
static void THISCALL fn459f40(u8 *self, u8 *p, float f) {
  float buf[4];
  ext_4e0a10(buf);
  ext_4e0d00(self + 0xac, bitsf(0x3f7eb852));
  ext_451890(self + 0xac, (u8 *)buf, f * G(float, 0x67a6ac));
  ext_443ef0(p, self + 0xa0, self + 0xac, f);
}
PCREG(459f40, fn459f40);

// 0x640c10, thiscall(p) ret 4, returns al: w = u16 [p+0x5a]; w == 0 or [p+0x3c] & 0x2000 -> false; e = [[this+0x68] + (w & 0xfff)*4]; when ext_658d30(e) != 0:
// q = [p+0x54]->slot 0x24c(); f = unaligned float [q+0x271]; else f = ext_63eb90(this, w); result = !(f > K(0x67d164)) (true for NaN).
static u32 THISCALL fn640c10(u8 *self, u8 *p) {
  u32 w = *(u16 *)(p + 0x5a);
  if (!w) return 0;
  if (*(u32 *)(p + 0x3c) & 0x2000) return 0;
  u8 *e = *(u8 **)(*(u8 **)(self + 0x68) + (w & 0xfff) * 4);
  float f;
  if (ext_658d30(e)) {
    u8 *q = vcall<u8 *>(*(u8 **)(p + 0x54), 0x24c);
    f = bitsf(rd32(q + 0x271));
  } else {
    f = ext_63eb90(self, *(u16 *)(p + 0x5a));
  }
  return !(f > G(float, 0x67d164));
}
PCREG(640c10, fn640c10);

// 0x524f50, thiscall(): [this+0x80] = 0; for i < [this+0x8c] (signed): ext_516070(this + 0xbd + i*0xde, float [this+0x9c]); byte [this + 0xcd + i*0xde] -> [this+0x80] = 1.0f;
// for j < [this+0x90]: ext_516070(this + 0x435 + j*0xde, [this+0x9c]); byte [this + 0x445 + j*0xde] -> [this+0x80] = 1.0f.
static void THISCALL fn524f50(u8 *self) {
  *(u32 *)(self + 0x80) = 0;
  for (s32 i = 0; i < *(s32 *)(self + 0x8c); i++) {
    ext_516070(self + 0xbd + i * 0xde, *(float *)(self + 0x9c));
    if (self[0xcd + i * 0xde]) *(u32 *)(self + 0x80) = 0x3f800000;
  }
  for (s32 j = 0; j < *(s32 *)(self + 0x90); j++) {
    ext_516070(self + 0x435 + j * 0xde, *(float *)(self + 0x9c));
    if (self[0x445 + j * 0xde]) *(u32 *)(self + 0x80) = 0x3f800000;
  }
}
PCREG(524f50, fn524f50);

// 0x5072f0, thiscall(p) ret 4: c = [p+4]; z = *ext_5003d0(c, 2), y = *ext_5003d0(c, 1), x = *ext_5003d0(c, 0); v = {x, y, z}; [this+0x18]->slot 0x39c(v).
static void THISCALL fn5072f0(u8 *self, u8 *p) {
  u8 *c = *(u8 **)(p + 4);
  u32 z = *ext_5003d0(c, 2);
  u32 y = *ext_5003d0(c, 1);
  u32 x = *ext_5003d0(c, 0);
  u32 v[3] = {x, y, z};
  vcall<void>(*(u8 **)(self + 0x18), 0x39c, (u32)v);
}
PCREG(5072f0, fn5072f0);

// 0x5a0b80, thiscall(o) ret 4: o->slot 0x48(&n); for i < n (signed): tmp = ext_5eade0 block (all zero args); o->slot 0x18(tmp, 0x10); copies tmp to this + 4 + [this]*16; [this]++.
static void THISCALL fn5a0b80(u8 *self, u8 *o) {
  s32 n;
  vcall<void>(o, 0x48, (u32)&n);
  for (s32 i = 0; i < n; i++) {
    u8 tmp[16];
    ext_5eade0(tmp, 0, 0, 0, 0, 0);
    vcall<void>(o, 0x18, (u32)tmp, (u32)0x10);
    u32 cnt = *(u32 *)self;
    u8 *d = self + 4 + cnt * 16;
    for (int k = 0; k < 16; k++) d[k] = tmp[k];
    (*(u32 *)self)++;
  }
}
PCREG(5a0b80, fn5a0b80);
