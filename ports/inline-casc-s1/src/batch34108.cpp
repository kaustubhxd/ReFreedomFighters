// batch34108.cpp - escalation batch 34108: 0x525380, 0x5d48e0, 0x475300, 0x4dcb50, 0x5aee20, 0x42abbd, 0x468030.
#include "ff.h"

extern "C" u32 FASTCALL ext_4de420(u8 *dst, u8 *src);              // ecx = dst, edx = src; copies 0x24 bytes, returns [src+0x20]
extern "C" u32 THISCALL ext_469870(void *self);                    // thiscall, plain ret
extern "C" u32 THISCALL ext_467710(void *self);                    // thiscall, plain ret
extern "C" u32 THISCALL ext_466220(void *self);                    // thiscall, plain ret
extern "C" u32 THISCALL ext_5af040(void *self, u32 a);             // thiscall ret 4
extern "C" u32 *ext_42acaf(u32 a, u32 b, u32 c, u32 d, u32 e);     // cdecl
extern "C" s32 ext_634d94(u32 a, u32 b);                           // cdecl import thunk
extern "C" u32 THISCALL ext_4654b0(void *self, u32 a, u32 b, u32 c);   // thiscall ret 0xc

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x525380, thiscall(a, v) ret 8, returns [this+8]: ext_4de420(a, this+0xc); v[0..2] = [this+0..8].
static u32 THISCALL fn525380(u32 *self, u8 *a, u32 *v) {
  ext_4de420(a, (u8 *)(self + 3));
  v[0] = self[0];
  v[1] = self[1];
  v[2] = self[2];
  return self[2];
}
PCREG(525380, fn525380);

// 0x5d48e0, thiscall plain, returns this: ext_469870(this); [this+4] |= 0x20; [this+0x44] = 0; [this] = 0x6b5304; byte [this+0x5c] = 0; unaligned dword [this+0x5d] = 0.
static u32 THISCALL fn5d48e0(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6b5304;
  self[0x5c] = 0;
  wr32(self + 0x5d, 0);
  return (u32)self;
}
PCREG(5d48e0, fn5d48e0);

// 0x475300, thiscall plain: ext_467710(this); v = ext_466220(this+0x26a); dwords +0x3bc..+0x3dc (9 of them) = 0, byte +0x3e9 = 0, unaligned dword +0x1e2 = 1.0f; returns v.
static u32 THISCALL fn475300(u8 *self) {
  ext_467710(self);
  u32 v = ext_466220(self + 0x26a);
  for (int i = 0; i < 9; i++) *(u32 *)(self + 0x3bc + 4 * i) = 0;
  self[0x3e9] = 0;
  wr32(self + 0x1e2, 0x3f800000);
  return v;
}
PCREG(475300, fn475300);

// 0x4dcb50, thiscall(a, v) ret 8: [this+0x24..0x2c] = v[0..2]; [this+0x3c] |= 0x100000; ext_4de420(this, a) (copies 0x24 bytes from a to this); [this+0x3c] |= 0x100000 again; returns its eax.
static u32 THISCALL fn4dcb50(u8 *self, u8 *a, u32 *v) {
  *(u32 *)(self + 0x24) = v[0];
  *(u32 *)(self + 0x28) = v[1];
  *(u32 *)(self + 0x2c) = v[2];
  *(u32 *)(self + 0x3c) |= 0x100000;
  u32 r = ext_4de420(self, a);
  *(u32 *)(self + 0x3c) |= 0x100000;
  return r;
}
PCREG(4dcb50, fn4dcb50);

// 0x5aee20, thiscall(a, b) ret 8: i = ext_5af040(this, a); unless i == 8: when [this+4i] == 0 then [this+0x20+4i] = 0; [this+0x20+4i] += b; [this+4i] = 1.
static void THISCALL fn5aee20(u8 *self, u32 a, u32 b) {
  u32 i = ext_5af040(self, a);
  if (i == 8) return;
  u32 *flag = (u32 *)(self + 4 * i);
  u32 *sum = (u32 *)(self + 0x20 + 4 * i);
  if (*flag == 0) *sum = 0;
  *sum += b;
  *flag = 1;
}
PCREG(5aee20, fn5aee20);

// 0x42abbd, cdecl(a, b, c, d, e): p = ext_42acaf(a, b, c, d, e); r = ext_634d94(p[0] | 1, p[1]); returns -1 when r is negative, else r.
static s32 fn42abbd(u32 a, u32 b, u32 c, u32 d, u32 e) {
  u32 *p = ext_42acaf(a, b, c, d, e);
  s32 r = ext_634d94(p[0] | 1, p[1]);
  if (r < 0) r = -1;
  return r;
}
PCREG(42abbd, fn42abbd);

// 0x468030, thiscall(a, b, c) ret 0xc, returns this: ext_4654b0(this, a, b, c); [this] = 0x6860b0; unaligned dwords +0x1d2 = 1, +0x1d6 = 0, +0x1da = 1.0f.
static u32 THISCALL fn468030(u8 *self, u32 a, u32 b, u32 c) {
  ext_4654b0(self, a, b, c);
  *(u32 *)self = 0x6860b0;
  wr32(self + 0x1d2, 1);
  wr32(self + 0x1d6, 0);
  wr32(self + 0x1da, 0x3f800000);
  return (u32)self;
}
PCREG(468030, fn468030);
