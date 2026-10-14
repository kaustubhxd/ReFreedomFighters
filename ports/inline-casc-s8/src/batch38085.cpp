// batch38085.cpp - cascade s8 batch 38085: 0x521070 (load a record from a stream: fixed fields in order, three object references resolved through the engine table).
#include "ff.h"

extern "C" u8 THISCALL ext_5159b0(u8 *self, u8 *st);    // ret 4
extern "C" void THISCALL ext_528740(u8 *p, u8 *st);     // ret 4
extern "C" void THISCALL ext_5274a0(u8 *p, u8 *st);     // ret 4
typedef u32(THISCALL *v0_t)(void *);
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define SYS G(u8 *, 0x70039c)
#define UN32(p, off) (*(u32 *)((u8 *)(p) + (off)))   // unaligned dword

static u32 lookup(u32 id) {
  u8 *t = *(u8 **)(SYS + 0x9b);
  return SLOT(t, 0x58, v1_t)(t, id);
}

// 0x521070, thiscall(stream) ret 4 -> bool. Stream slots: 0x6c (12-byte value), 0x50 (dword), 0x18 (n bytes), 0x68 (byte), 0x40 (dword / id out), 0x48 (dword).
static u8 THISCALL fn521070(u8 *self, u8 *st) {
  if (!ext_5159b0(self, st)) return 0;
  u32 loc;
#define F(slot, off) SLOT(st, slot, v1_t)(st, (u32)(self + (off)))
  F(0x6c, 0x2d8);
  F(0x6c, 0x2e4);
  F(0x50, 0x2f0);
  SLOT(st, 0x18, v2_t)(st, (u32)(self + 0x2f4), 4);
  F(0x50, 0x2f8);
  F(0x68, 0x2fc);
  ext_528740(self + 0x2fd, st);
  F(0x50, 0x25cd);
  SLOT(st, 0x40, v1_t)(st, (u32)&loc);
  UN32(self, 0x25d1) = lookup(loc);
  F(0x40, 0x25d5);
  F(0x40, 0x25d9);
  SLOT(st, 0x40, v1_t)(st, (u32)&loc);
  UN32(self, 0x25dd) = lookup(loc);
  SLOT(st, 0x40, v1_t)(st, (u32)&loc);
  UN32(self, 0x25e1) = lookup(loc);
  F(0x6c, 0x25e5);
  F(0x6c, 0x25f1);
  F(0x6c, 0x25fd);
  F(0x68, 0x2609);
  F(0x68, 0x260a);
  F(0x68, 0x260b);
  F(0x40, 0x260c);
  F(0x40, 0x2610);
  F(0x48, 0x2614);
  F(0x50, 0x2618);
  F(0x48, 0x2620);
  F(0x6c, 0x2624);
  F(0x6c, 0x2630);
  ext_5274a0(self + 0x263c, st);
  F(0x50, 0x268d);
  F(0x50, 0x2691);
  F(0x40, 0x26e6);
  F(0x68, 0x2706);
  F(0x40, 0x26ea);
  ext_5274a0(self + 0x2695, st);
  u8 *t = *(u8 **)(SYS + 0x9b);
  u8 *Z = (u8 *)SLOT(t, 0x138, v0_t)(t);
  loc = 0;
  SLOT(Z, 0x88, v2_t)(Z, 0x681320, (u32)&loc);
  UN32(self, 0x2707) = lookup(loc);
#undef F
  return 1;
}
PCREG(521070, fn521070);
