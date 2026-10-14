// u69_97.cpp - area 69, residue-8 (batch 97).
// 0x5f51c0 (thiscall, one stack arg, ret 4): `sub = self+0xaca; return sub->vt[0](a, 0);` (thiscall callee, pops 8).
// 0x64d000 (thiscall, one stack arg, ret 4): `r = (self+0x10165)->vt[2](); r+0x30 = p+0x14; ++(u16)p+0x1e; p+0x14 = r;`
//   An intrusive list push onto p (head at +0x14, count at +0x1e). Returns r in EAX.
// 0x5650c0 (thiscall, plain ret): `self+8 = (self+0xade)->vt[3](self+0xb1a, self+0xb0a); self+9 = 1;` (callee pops 8).
// 0x60fe80 (no args, plain ret): if g_724950 != g_72495c, store it and call g_724a00->vt[0xc8/4](dev, 0x22, v) (COM stdcall,
//   pops 12). 0xc8/4 = 50 is SetRenderState on IDirect3DDevice8 and 0x22 is D3DRS_FOGCOLOR (GUESS; name not in map).
// 0x557880 (stdcall, one unused stack arg, ret 4): memset(0x713e30, 0, 0xd4) via 0x634d10; g_713e2c = 0;
//   if g_713f04, g_713f04->vt[0](1) (scalar deleting dtor shape, thiscall, pops 4); g_713f04 = 0.
#include "ff.h"

static u32 THISCALL call5f51c0(u8 *self, u32 a) {
  u8 *sub = self + 0xaca;
  u32 vt = *(u32 *)sub;
  return ((u32(THISCALL *)(void *, u32, u32))*(u32 *)vt)(sub, a, 0);
}
PCREG(5f51c0, call5f51c0);

static u8 *THISCALL push64d000(u8 *self, u8 *p) {
  u8 *o = *(u8 **)(self + 0x10165);
  u32 vt = *(u32 *)o;
  u8 *r = ((u8 *(THISCALL *)(void *))*(u32 *)(vt + 8))(o);
  *(u32 *)(r + 0x30) = *(u32 *)(p + 0x14);
  ++*(u16 *)(p + 0x1e);
  *(u8 **)(p + 0x14) = r;
  return r;
}
PCREG(64d000, push64d000);

static void THISCALL poll5650c0(u8 *self) {
  u8 *o = *(u8 **)(self + 0xade);
  u32 vt = *(u32 *)o;
  self[8] = (u8)((u32(THISCALL *)(void *, u32, void *))*(u32 *)(vt + 0xc))(o, *(u32 *)(self + 0xb1a), self + 0xb0a);
  self[9] = 1;
}
PCREG(5650c0, poll5650c0);

static void fog60fe80(void) {
  u32 v = G(u32, 0x72495c);
  if (G(u32, 0x724950) == v)
    return;
  u8 *dev = G(u8 *, 0x724a00);
  G(u32, 0x724950) = v;
  u32 vt = *(u32 *)dev;
  ((u32(STDCALL *)(void *, u32, u32))*(u32 *)(vt + 0xc8))(dev, 0x22, v);
}
PCREG(60fe80, fog60fe80);

extern "C" void *ext_634d10(void *p, int c, u32 n);   // memset-shaped, cdecl (GUESS hook)
static void STDCALL reset557880(u32) {
  ext_634d10((void *)0x713e30, 0, 0xd4);
  G(u32, 0x713e2c) = 0;
  u8 *p = G(u8 *, 0x713f04);
  if (p) {
    u32 vt = *(u32 *)p;
    ((void(THISCALL *)(void *, u32))*(u32 *)vt)(p, 1);
  }
  G(u32, 0x713f04) = 0;
}
PCREG(557880, reset557880);
