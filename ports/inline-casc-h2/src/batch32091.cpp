// batch32091.cpp - cascade h2 (Sonnet): eight tier C wrappers (eleventh batch).
#include "ff.h"

extern "C" void THISCALL ext_610100(u8 *self, u32 a);   // thiscall ret 4
extern "C" u32 THISCALL ext_4e5e60(u8 *self);           // thiscall, plain ret
extern "C" void THISCALL ext_45bfd0(u8 *self, u32 a);   // thiscall ret 4

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline u8 *engTable() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x49ef50, thiscall(o) ret 4, returns true: [this+4] &= ~0x40; slot 0x3c of o with [this+0x48]; slot 0x40 of o with word [this+0x4c].
static bool THISCALL fn49ef50(u8 *self, void *o) {
  *(u32 *)(self + 4) &= 0xffffffbf;
  vcall<void>(o, 0x3c, *(u32 *)(self + 0x48));
  vcall<void>(o, 0x40, (u32)(*(u16 *)(self + 0x4c)));
  return true;
}
PCREG(49ef50, fn49ef50);

// 0x4c2780, thiscall(o) ret 4, returns true: [this+4] &= ~0x40; r = slot 0x3c of o with [this+0x1a8]; r2 = slot 0x44 of r with [this+0x1c8]; slot 0x44 of r2 with [this+0x1c4].
static bool THISCALL fn4c2780(u8 *self, void *o) {
  *(u32 *)(self + 4) &= 0xffffffbf;
  void *r = vcall<void *>(o, 0x3c, *(u32 *)(self + 0x1a8));
  void *r2 = vcall<void *>(r, 0x44, *(u32 *)(self + 0x1c8));
  vcall<void>(r2, 0x44, *(u32 *)(self + 0x1c4));
  return true;
}
PCREG(4c2780, fn4c2780);

// 0x4cdc20, thiscall no args: slot 0x10 of this; [this+0xc] |= 0x80000000; for each node p of the list starting at [this+4] (next = [p+4], read before the call): slot 0x7c of this with p; [this+4] = [this+0x14] = 0.
static void THISCALL fn4cdc20(u8 *self) {
  vcall<void>(self, 0x10);
  *(u32 *)(self + 0xc) |= 0x80000000u;
  u8 *p = *(u8 **)(self + 4);
  if (p) {
    do {
      u8 *nx = *(u8 **)(p + 4);
      vcall<void>(self, 0x7c, (u32)p);
      p = nx;
    } while (p);
  }
  *(u32 *)(self + 4) = 0;
  *(u32 *)(self + 0x14) = 0;
}
PCREG(4cdc20, fn4cdc20);

// 0x518750 / 0x518810, thiscall no args: o = [[0x70039c]+0x1a9f] (unaligned), 0 -> 0; vt = [this]; r = slot 0x60 of o with ([this+0x12f], k); returns slot 0x2e8 of vt (this ecx) with r.
static u32 THISCALL fn518750(u8 *self) {
  u32 o = rd32(G(u8 *, 0x70039c) + 0x1a9f);
  if (!o) return 0;
  u32 r = vcall<u32>((void *)o, 0x60, rd32(self + 0x12f), 0x69f124u);
  return vcall<u32>(self, 0x2e8, r);
}
PCREG(518750, fn518750);
static u32 THISCALL fn518810(u8 *self) {
  u32 o = rd32(G(u8 *, 0x70039c) + 0x1a9f);
  if (!o) return 0;
  u32 r = vcall<u32>((void *)o, 0x60, rd32(self + 0x12f), 0x69f190u);
  return vcall<u32>(self, 0x2e8, r);
}
PCREG(518810, fn518810);

// 0x537340, thiscall(a, b) ret 8: r = slot 0x1d8 of this with (a, b); r != 0 -> returns slot 0x54 of this with r; else 0.
static u32 THISCALL fn537340(void *self, u32 a, u32 b) {
  u32 r = vcall<u32>(self, 0x1d8, a, b);
  if (!r) return 0;
  return vcall<u32>(self, 0x54, r);
}
PCREG(537340, fn537340);

// 0x566ea0, thiscall(a) ret 4: 0x610100(this, a); then [this+0x18c], [this+0x190], [this+0x188] = three successive 0x4e5e60(a) results.
static void THISCALL fn566ea0(u8 *self, u8 *a) {
  ext_610100(self, (u32)a);
  *(u32 *)(self + 0x18c) = ext_4e5e60(a);
  *(u32 *)(self + 0x190) = ext_4e5e60(a);
  *(u32 *)(self + 0x188) = ext_4e5e60(a);
}
PCREG(566ea0, fn566ea0);

// 0x5cf3e0, thiscall(a) ret 4: 0x45bfd0(this+0xb5b, a); o = engine table slot 0x58 with [this+0xb9f] (unaligned); o != 0 -> tail jump to slot 0x88 of o with a; else 0.
static u32 THISCALL fn5cf3e0(u8 *self, u32 a) {
  ext_45bfd0(self + 0xb5b, a);
  void *o = vcall<void *>(engTable(), 0x58, rd32(self + 0xb9f));
  if (!o) return 0;
  return vcall<u32>(o, 0x88, a);
}
PCREG(5cf3e0, fn5cf3e0);
