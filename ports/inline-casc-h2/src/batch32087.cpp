// batch32087.cpp - cascade h2 (Sonnet): eight tier C wrappers (seventh batch).
#include "ff.h"

extern "C" void THISCALL ext_562440(u8 *self);         // thiscall, plain ret
extern "C" void THISCALL ext_564e80(u8 *self);         // thiscall, plain ret
extern "C" void THISCALL ext_5d8470(u8 *self);         // thiscall, plain ret
extern "C" void THISCALL ext_610100(u8 *self, u32 a);  // thiscall ret 4
typedef u32 (*hook_t)();
typedef u32 (*cd3_t)(u32, u32, u32);

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }

// 0x536720 / 0x536920, thiscall(a) ret 4: P = u32 at this+0x5302 (unaligned), 0 -> 0; q = [P] + P; slot 0x1b0 of this with ([q+0x24], [q+0xc], a)
// resp. ([q+0x20], [q+8], a); returns its result.
static u32 THISCALL fn536720(u8 *self, u32 a) {
  u32 P = rd32(self + 0x5302);
  if (!P) return 0;
  u8 *q = (u8 *)(*(u32 *)P + P);
  return vcall<u32>(self, 0x1b0, *(u32 *)(q + 0x24), *(u32 *)(q + 0xc), a);
}
PCREG(536720, fn536720);
static u32 THISCALL fn536920(u8 *self, u32 a) {
  u32 P = rd32(self + 0x5302);
  if (!P) return 0;
  u8 *q = (u8 *)(*(u32 *)P + P);
  return vcall<u32>(self, 0x1b0, *(u32 *)(q + 0x20), *(u32 *)(q + 8), a);
}
PCREG(536920, fn536920);

// 0x551020 / 0x605890, stdcall(2 ignored) ret 8: r = slot 0x20 of [0x700390] with (s, line); slot 0x2c of r called cdecl with (r, 0x69c6b0, t);
// then the assert hook at 0x7003b0 (int3 when null); returns its eax.
static u32 STDCALL fn551020(u32, u32) {
  void *g = G(void *, 0x700390);
  u8 *r = vcall<u8 *>(g, 0x20, 0x6a4be4u, 0xaau);
  (*(cd3_t *)(*(u8 **)r + 0x2c))((u32)r, 0x69c6b0, 0x69c7f0);
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  return h();
}
PCREG(551020, fn551020);
static u32 STDCALL fn605890(u32, u32) {
  void *g = G(void *, 0x700390);
  u8 *r = vcall<u8 *>(g, 0x20, 0x6b9c38u, 0x14du);
  (*(cd3_t *)(*(u8 **)r + 0x2c))((u32)r, 0x69c6b0, 0x6b9cdc);
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  return h();
}
PCREG(605890, fn605890);

// 0x564b10, thiscall no args: 0x562440(this); 0x564e80(this); o = slot 0x134 of the engine table; returns slot 0x5c of o with (0x6a66ec, 0, 2).
static u32 THISCALL fn564b10(u8 *self) {
  ext_562440(self);
  ext_564e80(self);
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  void *o = vcall<void *>(tbl, 0x134);
  return vcall<u32>(o, 0x5c, 0x6a66ecu, 0u, 2u);
}
PCREG(564b10, fn564b10);

// 0x5d83e0, thiscall no args: byte [this+0xbb] == 0 and [[0x70039c]+0x40] > [this+0xb3] (signed, unaligned) -> 0x5d8470(this); then when [this+0xbc] == 0
// (unaligned) slot 0x114 of [this+0x44] with 0x10.
static void THISCALL fn5d83e0(u8 *self) {
  if (self[0xbb] != 0) return;
  int v = *(int *)(G(u8 *, 0x70039c) + 0x40);
  if (v <= (int)rd32(self + 0xb3)) return;
  ext_5d8470(self);
  if (rd32(self + 0xbc) != 0) return;
  vcall<void>(*(void **)(self + 0x44), 0x114, 0x10u);
}
PCREG(5d83e0, fn5d83e0);

// 0x5ee6f0, thiscall no args: p = [this+5] (unaligned); byte [this+0x77] = 1; for p != [this+9] (re-read each time): slot 8 of the object [[p]]; p += 4.
static void THISCALL fn5ee6f0(u8 *self) {
  u8 *p = (u8 *)rd32(self + 5);
  self[0x77] = 1;
  if (p == (u8 *)rd32(self + 9)) return;
  do {
    void *o = **(void ***)p;
    vcall<void>(o, 8);
    p += 4;
  } while (p != (u8 *)rd32(self + 9));
}
PCREG(5ee6f0, fn5ee6f0);

// 0x441630, stdcall(a) ret 4, bool: r = slot 0x58 of the engine table with [tbl+0x14]; r == 0 -> false; else 0x610100(r, a), true.
static bool STDCALL fn441630(u32 a) {
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *r = vcall<u8 *>(tbl, 0x58, *(u32 *)(tbl + 0x14));
  if (!r) return false;
  ext_610100(r, a);
  return true;
}
PCREG(441630, fn441630);
