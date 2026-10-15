// batch52007.cpp - cascade tier H, batch 52007: 0x5251c0 (set up a moving point and refresh derived state).
#include "ff.h"

extern "C" void THISCALL ext_524ff0(void *self);
extern "C" void THISCALL ext_526cf0(void *self);
extern "C" void THISCALL ext_524de0(void *self);
extern "C" void THISCALL ext_526470(void *self);
extern "C" void THISCALL ext_526ac0(void *self);
extern "C" void THISCALL ext_526360(void *self);
extern "C" void THISCALL ext_525f30(void *self);
extern "C" void THISCALL ext_526880(void *self);
extern "C" void THISCALL ext_526c60(void *self);
extern "C" void FASTCALL ext_4de420(void *dst, void *src);                  // copies 0x24 bytes
extern "C" float FASTCALL ext_4e0030(void *p, void *q);                     // float in st0
extern "C" void FASTCALL ext_446ee0(float *out, float *a, float *b);        // ret 4: out = a x b

static void copy3(u8 *dst, const u8 *src) {
  *(u32 *)dst = *(const u32 *)src;
  *(u32 *)(dst + 4) = *(const u32 *)(src + 4);
  *(u32 *)(dst + 8) = *(const u32 *)(src + 8);
}

// 0x5251c0, thiscall(a, b, c, d, e, f, g, h) ret 0x20. a: 3x3 matrix out, b: vec3 out, c, d: vec3 in, e, f, g, h floats.
// this[0xbc] set: when [0x70039c][0x40] < this[0x84]: ext_524ff0, ext_526cf0, [this+0x88]->slot0x7c(this+0xc, this), ext_524de0, copy this+0xc into a, copy this[0..2] into b;
//   else [this+0x88]->slot0x80(a, b). Otherwise: this[0..2] = c; this[0x64] = c[1] + 150.0 (0x68af14); this+0x58 = this+0x4c; this+0x4c = d; this[0x50] = 0; this[0x68] = e, [0x6c] = f, [0x78] = g, [0x7c] = h;
//   this[0x70] = ext_4e0030(this+0x58, this+0x4c); cross product v of the two vectors by ext_446ee0; v[1] < 0 negates this[0x70]; this[0x74] = this[0x70] / [0x70039c][0x48];
//   then the refreshers 526470, 526ac0, 526360, 524ff0, 526cf0, 525f30, 526880, 526c60, 524de0, copy this+0xc into a and this[0..2] into b.
static void THISCALL fn5251c0(u8 *self, u8 *a, u8 *b, u8 *c, u8 *d, float e, float f, float g, float h) {
  if (self[0xbc]) {
    s32 n = *(s32 *)(G(u8 *, 0x70039c) + 0x40);
    if (n < *(s32 *)(self + 0x84)) {
      ext_524ff0(self);
      ext_526cf0(self);
      vcall<void>(*(u8 **)(self + 0x88), 0x7c, (u32)(self + 0xc), (u32)self);
      ext_524de0(self);
      ext_4de420(a, self + 0xc);
      copy3(b, self);
      return;
    }
    vcall<void>(*(u8 **)(self + 0x88), 0x80, (u32)a, (u32)b);
    return;
  }
  u8 *p58 = self + 0x58, *p4c = self + 0x4c;
  copy3(self, c);
  *(float *)(self + 0x64) = *(float *)(c + 4) + G(float, 0x68af14);
  copy3(p58, p4c);
  copy3(p4c, d);
  *(u32 *)(self + 0x50) = 0;
  *(float *)(self + 0x68) = e;
  *(float *)(self + 0x6c) = f;
  *(float *)(self + 0x78) = g;
  *(float *)(self + 0x7c) = h;
  *(float *)(self + 0x70) = ext_4e0030(p58, p4c);
  float v[3];
  ext_446ee0(v, (float *)p58, (float *)p4c);
  if (0.0f > v[1]) *(u32 *)(self + 0x70) ^= G(u32, 0x67af40);
  *(float *)(self + 0x74) = *(float *)(self + 0x70) / *(float *)(G(u8 *, 0x70039c) + 0x48);
  ext_526470(self);
  ext_526ac0(self);
  ext_526360(self);
  ext_524ff0(self);
  ext_526cf0(self);
  ext_525f30(self);
  ext_526880(self);
  ext_526c60(self);
  ext_524de0(self);
  ext_4de420(a, self + 0xc);
  copy3(b, self);
}
PCREG(5251c0, fn5251c0);
