// batch32082.cpp - cascade h2 (): eight tier C vtable-slot wrappers (second batch).
#include "ff.h"

extern "C" u8 *ext_5fa630();                   // no args, returns an object pointer
extern "C" u32 THISCALL ext_43ea20(u8 *self);  // thiscall, plain ret (tail jump target)
typedef u32 (*cd3_t)(u32, u32, u32);

// 0x46e740, thiscall no args: e = [this+0x64]; e == 0 -> 0; else slot 0x58 of the engine table ([[0x70039c]+0x9b]) with e.
static u32 THISCALL fn46e740(u8 *self) {
  u32 e = *(u32 *)(self + 0x64);
  if (!e) return 0;
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  return vcall<u32>(tbl, 0x58, e);
}
PCREG(46e740, fn46e740);

// 0x4c62f0, thiscall(o) ret 4, returns true: [this+4] &= ~0x40; slot 0x3c of o with the unaligned dword [this+0x4a].
static bool THISCALL fn4c62f0(u8 *self, void *o) {
  *(u32 *)(self + 4) &= 0xffffffbf;
  u32 v = self[0x4a] | (self[0x4b] << 8) | (self[0x4c] << 16) | ((u32)self[0x4d] << 24);
  vcall<void>(o, 0x3c, v);
  return true;
}
PCREG(4c62f0, fn4c62f0);

// 0x52cf40, thiscall no args: [this] = slot 0x1c8 of the engine object with (0x6a13d8, 0x23).
static void THISCALL fn52cf40(u8 *self) {
  void *eng = G(void *, 0x70039c);
  *(u32 *)self = vcall<u32>(eng, 0x1c8, 0x6a13d8u, 0x23u);
}
PCREG(52cf40, fn52cf40);

// 0x5fa4d0, stdcall(a) ret 4: r = 0x5fa630(); slot 0xc of r, called cdecl with (r, 0x6b918c, a); returns its result.
static u32 STDCALL fn5fa4d0(u32 a) {
  u8 *r = ext_5fa630();
  return (*(cd3_t *)(*(u8 **)r + 0xc))((u32)r, 0x6b918c, a);
}
PCREG(5fa4d0, fn5fa4d0);

// 0x4610f0, thiscall(a, b) ret 8: slot 0x228 of this with (a, b, 0, -1.0f, 1.0f) (floats as raw dwords).
static u32 THISCALL fn4610f0(void *self, u32 a, u32 b) {
  return vcall<u32>(self, 0x228, a, b, 0u, 0xbf800000u, 0x3f800000u);
}
PCREG(4610f0, fn4610f0);

// 0x46a5c0, thiscall no args: o = [this+0x70]; vtable (this) = 0x6868e8; o != 0 -> slot 0 of o with 1; tail jump to 0x43ea20(this).
static u32 THISCALL fn46a5c0(u8 *self) {
  void *o = *(void **)(self + 0x70);
  *(u32 *)self = 0x6868e8;
  if (o) vcall<void>(o, 0, 1u);
  return ext_43ea20(self);
}
PCREG(46a5c0, fn46a5c0);

// 0x47a4d0, thiscall no args: slot 0x128 of this with (word [0x6ffa44], 0, 0); [this+0x6ba] = 0 (unaligned dword); byte [this+0x6be] = 0.
static void THISCALL fn47a4d0(u8 *self) {
  u32 w = G(u16, 0x6ffa44);
  vcall<void>(self, 0x128, w, 0u, 0u);
  self[0x6ba] = self[0x6bb] = self[0x6bc] = self[0x6bd] = 0;
  self[0x6be] = 0;
}
PCREG(47a4d0, fn47a4d0);

// 0x4cb4f0, thiscall(o) ret 4, returns true: [this+4] &= ~0x40; slot 0x48 of o with this+0x4c.
static bool THISCALL fn4cb4f0(u8 *self, void *o) {
  *(u32 *)(self + 4) &= 0xffffffbf;
  vcall<void>(o, 0x48, (u32)(self + 0x4c));
  return true;
}
PCREG(4cb4f0, fn4cb4f0);
