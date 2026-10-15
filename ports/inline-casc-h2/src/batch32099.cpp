// batch32099.cpp - cascade h2 (Sonnet): eight tier H (float / SSE) functions, seventh batch.
#include "ff.h"

extern "C" void THISCALL ext_5ec2b0(u8 *self, float a, s32 b);              // thiscall ret 8
extern "C" void THISCALL ext_44a1f0(u8 *self);                              // thiscall, plain ret (jmp thunk)
extern "C" u8 *ext_41e290(u32 n);                                           // alloc, cdecl
extern "C" void THISCALL ext_651850(u8 *self);                              // thiscall, plain ret
extern "C" float THISCALL ext_4a5f20(u8 *self, float a);                    // thiscall ret 4, float in st0
extern "C" void THISCALL ext_4a5fe0(u8 *self);                              // thiscall, plain ret
extern "C" void THISCALL ext_459c40(u8 *self, float a);                     // thiscall ret 4
extern "C" void THISCALL ext_515620(u8 *self);                              // thiscall, plain ret (jmp thunk)
extern "C" u8 THISCALL ext_5253b0(u8 *self, u32 a, u32 b, float c, u32 d, u32 e);   // thiscall ret 0x14, result in AL
extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 a);                        // thiscall ret 4
extern "C" void FASTCALL ext_633654(u32 cookie);                            // /GS check

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static inline float rdf(const u8 *p) { u32 b = rd32(p); float f; __builtin_memcpy(&f, &b, 4); return f; }
static inline void wrf(u8 *p, float f) { u32 b; __builtin_memcpy(&b, &f, 4); wr32(p, b); }
static inline s32 trunc_ss(float f) { s32 t; __asm__("cvttss2si %1, %0" : "=r"(t) : "m"(f)); return t; }

// 0x5a5be0, thiscall(float a) ret 4: o = [this+0x689] (unaligned) != 0: byte [o+0x35] = 0; t = [this+0x68d] + a, stored, and set to 1.0f when t > K(0x678858) (ordered);
// 0x5ec2b0([this+0x689], [this+0x68d], -1); byte [[this+0x689]+0x35] = 1.
static void THISCALL fn5a5be0(u8 *self, float a) {
  u8 *o = (u8 *)rd32(self + 0x689);
  if (!o) return;
  o[0x35] = 0;
  float t = rdf(self + 0x68d) + a;
  wrf(self + 0x68d, t);
  if (t > G(float, 0x678858)) wr32(self + 0x68d, 0x3f800000);
  ext_5ec2b0((u8 *)rd32(self + 0x689), rdf(self + 0x68d), -1);
  u8 *o2 = (u8 *)rd32(self + 0x689);
  o2[0x35] = 1;
}
PCREG(5a5be0, fn5a5be0);

// 0x4ef0e0, thiscall no args (/GS frame): 0x44a1f0(this); local 36 bytes = the 32 bytes at 0x698560 + a zero dword; slot 0x6c of this with &local; /GS check.
static void THISCALL fn4ef0e0(u8 *self) {
  u32 buf[9];
  ext_44a1f0(self);
  for (int i = 0; i < 4; i++) buf[i] = G(u32, 0x698560 + 4 * i);
  for (int i = 0; i < 4; i++) buf[4 + i] = G(u32, 0x698570 + 4 * i);
  buf[8] = 0;
  vcall<void>(self, 0x6c, (u32)buf);
  ext_633654(0);
}
PCREG(4ef0e0, fn4ef0e0);

// 0x607c20, cdecl no args: p = alloc(0xa5); p == 0 -> 0; else 0x651850(p); [p] = 0x6b9f00; q = alloc(0xe) filled from the exe bytes at 0x6b9fa8 (8), 0x6b9fb0 (4), 0x6b9fb4 (2); [p+4] = q; returns p.
static u8 *fn607c20() {
  u8 *p = ext_41e290(0xa5);
  if (!p) return 0;
  ext_651850(p);
  *(u32 *)p = 0x6b9f00;
  u8 *q = ext_41e290(0xe);
  *(u32 *)(q + 0) = G(u32, 0x6b9fa8);
  *(u32 *)(q + 4) = G(u32, 0x6b9fac);
  *(u32 *)(q + 8) = G(u32, 0x6b9fb0);
  *(u16 *)(q + 0xc) = G(u16, 0x6b9fb4);
  *(u8 **)(p + 4) = q;
  return p;
}
PCREG(607c20, fn607c20);

// 0x4a58d0, thiscall no args: e = [[0x70039c]+0x40] - (int)trunc(float [this+0xbb] * K(0x678620)); r = 0x4a5f20(this, (float)e * K2(0x6785e4)) (float st0); 0 > r -> 0x4a5fe0(this).
static void THISCALL fn4a58d0(u8 *self) {
  s32 e = *(s32 *)(G(u8 *, 0x70039c) + 0x40) - trunc_ss(rdf(self + 0xbb) * G(float, 0x678620));
  float x = (float)e * G(float, 0x6785e4);
  float r = ext_4a5f20(self, x);
  if (0.0f > r) ext_4a5fe0(self);
}
PCREG(4a58d0, fn4a58d0);

// 0x517540, thiscall no args: 0x515620(this); [this+0x1614] = AL of 0x5253b0(this+0x2d8, this, [this+0x160c], float [this+0x1610], 0, byte [this+0x133]);
// slot 0x80 of this with (this+0x6c, this+0x60); returns slot 0x36c of this with 1.
static u32 THISCALL fn517540(u8 *self) {
  ext_515620(self);
  self[0x1614] = ext_5253b0(self + 0x2d8, (u32)self, *(u32 *)(self + 0x160c), *(float *)(self + 0x1610), 0, (u32)self[0x133]);
  vcall<void>(self, 0x80, (u32)(self + 0x6c), (u32)(self + 0x60));
  return vcall<u32>(self, 0x36c, 1u);
}
PCREG(517540, fn517540);

// 0x58b6d0, thiscall(float a) ret 4, returns this: d = (a > K1(0x6ad1fc) || K2(0x6ad234) > a) ? K3(0x67da18) : a; s = [this] + d;
// s > K3 -> s - K4(0x68aef8); else K5(0x6ad238) > s -> s + K4 else s; stored at [this].
static float *THISCALL fn58b6d0(float *self, float a) {
  float k3 = G(float, 0x67da18);
  float d = a;
  if (a > G(float, 0x6ad1fc) || G(float, 0x6ad234) > a) d = k3;
  float s = self[0] + d;
  if (s > k3) {
    self[0] = s - G(float, 0x68aef8);
    return self;
  }
  if (G(float, 0x6ad238) > s) s = s + G(float, 0x68aef8);
  self[0] = s;
  return self;
}
PCREG(58b6d0, fn58b6d0);

// 0x459980, thiscall(o, ignored, b, c) ret 0x10: slot 0x4c of o with (0, b, c, [this+8]+0x40); when [this+0x24] != [[0x70039c]+0x3c] it takes that value and 0x459c40(this, float [[0x70039c]+0x48] * K(0x67885c)).
static void THISCALL fn459980(u8 *self, void *o, u32, u32 b, u32 c) {
  vcall<void>(o, 0x4c, 0u, b, c, *(u32 *)(self + 8) + 0x40);
  u32 v = *(u32 *)(G(u8 *, 0x70039c) + 0x3c);
  if (*(u32 *)(self + 0x24) == v) return;
  *(u32 *)(self + 0x24) = v;
  float x = *(float *)(G(u8 *, 0x70039c) + 0x48) * G(float, 0x67885c);
  ext_459c40(self, x);
}
PCREG(459980, fn459980);

// 0x51eaf0, thiscall(a) ret 4, returns a dword: r = 0x5003d0([a+4], 0); slot 0 of the object embedded at [this+0x18]+0x39f with (float [r], 0x3d0efa35, 0x3f860a92); r2 = 0x5003d0([a+4], 1); [[this+0x18]+0x342] = [r2]; returns [r2].
static u32 THISCALL fn51eaf0(u8 *self, u8 *a) {
  u32 r = ext_5003d0(*(u8 **)(a + 4), 0);
  u8 *base = *(u8 **)(self + 0x18);
  vcall<void>(base + 0x39f, 0, *(float *)r, 0x3d0efa35u, 0x3f860a92u);
  u32 r2 = ext_5003d0(*(u8 **)(a + 4), 1);
  u8 *base2 = *(u8 **)(self + 0x18);
  u32 v = *(u32 *)r2;
  wr32(base2 + 0x342, v);
  return v;
}
PCREG(51eaf0, fn51eaf0);
