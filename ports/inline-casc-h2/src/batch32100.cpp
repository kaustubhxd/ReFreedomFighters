// batch32100.cpp - cascade h2 (): eight tier H (float / SSE) functions, eighth batch.
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 a);                  // thiscall ret 4
extern "C" u32 THISCALL ext_520c50(u8 *self, float a, u32 b);         // thiscall ret 8
extern "C" void THISCALL ext_4ef210(u8 *self, u8 *o);                 // thiscall ret 4
extern "C" void THISCALL ext_4db500(u8 *self, float *out);            // thiscall ret 4
extern "C" void THISCALL ext_4db7c0(u8 *self, float *out);            // thiscall ret 4
extern "C" void FASTCALL ext_633654(u32 cookie);                      // /GS check

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static inline float rdf(const u8 *p) { u32 b = rd32(p); float f; __builtin_memcpy(&f, &b, 4); return f; }
static inline void wrf(u8 *p, float f) { u32 b; __builtin_memcpy(&b, &f, 4); wr32(p, b); }
static inline s32 trunc_ss(float f) { s32 t; __asm__("cvttss2si %1, %0" : "=r"(t) : "m"(f)); return t; }
static inline u8 *engTable() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x522770, thiscall(a) ret 4: r1 = 0x5003d0([a+4], 1); r0 = 0x5003d0([a+4], 0); returns 0x520c50([this+0x1c], float [r0], ([r1] != 0)).
static u32 THISCALL fn522770(u8 *self, u8 *a) {
  u32 r1 = ext_5003d0(*(u8 **)(a + 4), 1);
  u32 r0 = ext_5003d0(*(u8 **)(a + 4), 0);
  u32 flag = *(u32 *)r1 != 0;
  return ext_520c50(*(u8 **)(self + 0x1c), *(float *)r0, flag);
}
PCREG(522770, fn522770);

// 0x584f40, thiscall(o) ret 4, returns true: [this+4] &= ~0x40; slot 0x4c of o with float [this+0x64]; slot 0x4c of o with float [this+0x57] (unaligned); slot 0x3c of o with [this+0x6c].
static bool THISCALL fn584f40(u8 *self, void *o) {
  *(u32 *)(self + 4) &= 0xffffffbf;
  vcall<void>(o, 0x4c, *(float *)(self + 0x64));
  vcall<void>(o, 0x4c, rdf(self + 0x57));
  vcall<void>(o, 0x3c, *(u32 *)(self + 0x6c));
  return true;
}
PCREG(584f40, fn584f40);

// 0x466ce0, thiscall no args: o = engine table slot 0x60 with unaligned [this+0x13b]; o set -> byte [o+0xec] = 1, [o+0xed] = (float)[[0x70039c]+0x40] * K(0x6785e4), [o+0xf1] = [o+0x88], [o+0xf5] = [o+0x88] / K2(0x67a284);
// byte [this+0x13a] = 0; p = unaligned [[0x70039c]+0x1a9f]; p != 0 -> slot 0x84 of p with this.
static void THISCALL fn466ce0(u8 *self) {
  u8 *o = vcall<u8 *>(engTable(), 0x60, rd32(self + 0x13b));
  if (o) {
    o[0xec] = 1;
    wrf(o + 0xed, (float)*(s32 *)(G(u8 *, 0x70039c) + 0x40) * G(float, 0x6785e4));
    float w = *(float *)(o + 0x88);
    wrf(o + 0xf1, w);
    wrf(o + 0xf5, w / G(float, 0x67a284));
  }
  self[0x13a] = 0;
  u32 p = rd32(G(u8 *, 0x70039c) + 0x1a9f);
  if (p) vcall<void>((void *)p, 0x84, (u32)self);
}
PCREG(466ce0, fn466ce0);

// 0x4a37f0, thiscall no args: [this+0x48] = [this+0x44]; [this+0x128] = 0; [this+0x124] = slot 0x14 of the object embedded at this+0x78; slot 0x84 of this with this+0x4c; slot 0x84 with this+0x58;
// slot 0x88 of this; [this+0x74] = (float)[[0x70039c]+0x40] * K(0x6785e4).
static void THISCALL fn4a37f0(u8 *self) {
  *(u32 *)(self + 0x48) = *(u32 *)(self + 0x44);
  *(u32 *)(self + 0x128) = 0;
  *(u32 *)(self + 0x124) = vcall<u32>(self + 0x78, 0x14);
  vcall<void>(self, 0x84, (u32)(self + 0x4c));
  vcall<void>(self, 0x84, (u32)(self + 0x58));
  vcall<void>(self, 0x88);
  *(float *)(self + 0x74) = (float)*(s32 *)(G(u8 *, 0x70039c) + 0x40) * G(float, 0x6785e4);
}
PCREG(4a37f0, fn4a37f0);

// 0x4f50f0, thiscall(o) ret 4: 0x4ef210(this, o); slot 0x1e0 of o with 0x200045 returns true (al) -> copies the 16-byte blocks at 0x93 and 0xa3 and the dwords at 0xb3, 0xbb, 0xbf from o to this (unaligned).
static void THISCALL fn4f50f0(u8 *self, u8 *o) {
  ext_4ef210(self, o);
  if (!vcall<u8>(o, 0x1e0, 0x200045u)) return;
  for (int i = 0; i < 32; i++) self[0x93 + i] = o[0x93 + i];
  for (int i = 0; i < 4; i++) self[0xb3 + i] = o[0xb3 + i];
  for (int i = 0; i < 4; i++) self[0xbb + i] = o[0xbb + i];
  for (int i = 0; i < 4; i++) self[0xbf + i] = o[0xbf + i];
}
PCREG(4f50f0, fn4f50f0);

// 0x4f8940, thiscall no args: t = [[0x70039c]+0x40]; t > (int)trunc(float [this+0x1cf] * K(0x678620)) and o = unaligned [this+0x1bf] != 0 -> [this+0x1cf] = (float)(t + 0x133) * K2(0x6785e4);
// slot 0xbc of o with (byte flag: 0 when bit 0x800 of [[o+8]+0x3c] is set, else 1).
static void THISCALL fn4f8940(u8 *self) {
  s32 t = *(s32 *)(G(u8 *, 0x70039c) + 0x40);
  if (t <= trunc_ss(rdf(self + 0x1cf) * G(float, 0x678620))) return;
  u8 *o = (u8 *)rd32(self + 0x1bf);
  if (!o) return;
  wrf(self + 0x1cf, (float)(t + 0x133) * G(float, 0x6785e4));
  u32 flags = *(u32 *)(*(u8 **)(o + 8) + 0x3c);
  vcall<void>(o, 0xbc, (flags & 0x800) ? 0u : 1u);
}
PCREG(4f8940, fn4f8940);

// 0x51e7b0, thiscall no args: e = object embedded at this+0x29a, b = this+0x26e; slot 8 of e with b; slot 0x20 of e returns true (al) -> slot 4 of e with (float [b], float [this+0x272], 0).
static void THISCALL fn51e7b0(u8 *self) {
  u8 *e = self + 0x29a;
  u8 *b = self + 0x26e;
  vcall<void>(e, 8, (u32)b);
  if (!vcall<u8>(e, 0x20)) return;
  vcall<void>(e, 4, rdf(b), rdf(self + 0x272), 0u);
}
PCREG(51e7b0, fn51e7b0);

// 0x5d8740, thiscall no args (/GS frame): 0x4db500([[this+0x44]+8], &a); [this+0x4c] = a; 0x4db7c0([[this+0x44]+8], &b); [this+0x50] = b; /GS check.
static void THISCALL fn5d8740(u8 *self) {
  float a, b;
  ext_4db500(*(u8 **)(*(u8 **)(self + 0x44) + 8), &a);
  *(float *)(self + 0x4c) = a;
  ext_4db7c0(*(u8 **)(*(u8 **)(self + 0x44) + 8), &b);
  *(float *)(self + 0x50) = b;
  ext_633654(0);
}
PCREG(5d8740, fn5d8740);
