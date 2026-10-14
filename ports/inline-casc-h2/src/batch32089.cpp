// batch32089.cpp - cascade h2 (): eight tier C wrappers (ninth batch).
#include "ff.h"

extern "C" void THISCALL ext_52a370(u8 *self, u32 a, u32 b, u32 c);   // thiscall ret 0xc
extern "C" void THISCALL ext_52a600(u8 *self);                        // thiscall, plain ret
extern "C" void FASTCALL ext_633654(u32 cookie);                      // /GS check
extern "C" u8 *ext_41e290(u32 n);                                     // alloc, cdecl
extern "C" void THISCALL ext_5f09b0(u8 *self);                        // thiscall, plain ret
typedef u32 (*hook_t)();
typedef u32 (*cd3_t)(u32, u32, u32);

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static inline u8 *engTable() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x476bd0, thiscall no args: byte [this+0x72] == 0 -> assert hook (int3 when null); slot 0x4c of the engine table with this; tail jump to slot 0x28 of this.
static u32 THISCALL fn476bd0(u8 *self) {
  if (self[0x72] == 0) {
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  vcall<void>(engTable(), 0x4c, (u32)self);
  return vcall<u32>(self, 0x28);
}
PCREG(476bd0, fn476bd0);

// 0x52a2c0, cdecl no args (/GS frame, 0xa0-byte local): 0x52a370(local, 0, 0, 0); 0x52a600(local); /GS check.
static void fn52a2c0() {
  u8 local[0xa0];
  ext_52a370(local, 0, 0, 0);
  ext_52a600(local);
  ext_633654(0);
}
PCREG(52a2c0, fn52a2c0);

// 0x54a680, thiscall(a, b) ret 8: p = alloc(a); [this+0xa269] = p (unaligned); returns slot 0x60 of [0x700394] with (b, p, a, 0, 0).
static u32 THISCALL fn54a680(u8 *self, u32 a, u32 b) {
  u8 *p = ext_41e290(a);
  wr32(self + 0xa269, (u32)p);
  void *o = G(void *, 0x700394);
  return vcall<u32>(o, 0x60, b, (u32)p, a, 0u, 0u);
}
PCREG(54a680, fn54a680);

// 0x563400, cdecl no args, bool: o = slot 0x134 of the engine table; v = 0; slot 0x88 of o with (0x6a66ec, &v); v != 0.
static bool fn563400() {
  void *o = vcall<void *>(engTable(), 0x134);
  u32 v = 0;
  vcall<void>(o, 0x88, 0x6a66ecu, (u32)&v);
  return v != 0;
}
PCREG(563400, fn563400);

// 0x5d5940, thiscall no args: 0x5f09b0([this+0x19]); byte [this+0x31] != 0 and [this+0x2d] < 2 (unsigned, unaligned) -> increment; at 2: slot 0x114 of this with 0x10.
static void THISCALL fn5d5940(u8 *self) {
  ext_5f09b0((u8 *)rd32(self + 0x19));
  if (self[0x31] == 0) return;
  u32 v = rd32(self + 0x2d);
  if (v >= 2) return;
  v++;
  wr32(self + 0x2d, v);
  if (v == 2) vcall<void>(self, 0x114, 0x10u);
}
PCREG(5d5940, fn5d5940);

// 0x656420, stdcall(a, n) ret 8: s = n*8; s != 0 -> o = [[0x70039c]+0x190f] (unaligned); t = slot 0x20 of o; slot 0x18 of t with (a, s).
static void STDCALL fn656420(u32 a, u32 n) {
  u32 s = n * 8;
  if (!s) return;
  u8 *eng = G(u8 *, 0x70039c);
  void *o = (void *)rd32(eng + 0x190f);
  void *t = vcall<void *>(o, 0x20);
  vcall<void>(t, 0x18, a, s);
}
PCREG(656420, fn656420);

// 0x4639f0, thiscall no args: slot 0x2f8 of this with 1; slot 0x330 of this; [0x72] = [0x5c], [0x76] = [0x60], [0x7a] = [0x64], [0x7e] = [0x68]; [0x64] = [0x68] = 0 (all unaligned).
static void THISCALL fn4639f0(u8 *self) {
  vcall<void>(self, 0x2f8, 1u);
  vcall<void>(self, 0x330);
  wr32(self + 0x72, rd32(self + 0x5c));
  wr32(self + 0x76, rd32(self + 0x60));
  wr32(self + 0x7a, rd32(self + 0x64));
  wr32(self + 0x7e, rd32(self + 0x68));
  wr32(self + 0x64, 0);
  wr32(self + 0x68, 0);
}
PCREG(4639f0, fn4639f0);

// 0x474690, thiscall no args: r = slot 0x10 of the object embedded at this+0x34f; r == 0 -> 0; else r when slot 0x1e0 of r with 0x1007d2 returns true (al), else 0.
static u8 *THISCALL fn474690(u8 *self) {
  u8 *r = vcall<u8 *>(self + 0x34f, 0x10);
  if (!r) return 0;
  u8 ok = vcall<u8>(r, 0x1e0, 0x1007d2u);
  return ok ? r : 0;
}
PCREG(474690, fn474690);
