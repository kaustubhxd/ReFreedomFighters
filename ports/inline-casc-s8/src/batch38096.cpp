// batch38096.cpp - cascade s8 batch 38096: 0x446040 (load a record from a stream: count-prefixed id array, two ids, fixed fields, two raw blocks).
#include "ff.h"

extern "C" u8 THISCALL ext_45f3c0(u8 *self, u8 *st);   // ret 4 (base load, returns bool)
typedef u32(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v2_t)(void *, u32, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define SYS G(u8 *, 0x70039c)
#define UN32(p, off) (*(u32 *)((u8 *)(p) + (off)))   // unaligned dword

static u32 lookup(u32 slot, u32 id) { u8 *t = *(u8 **)(SYS + 0x9b); return SLOT(t, slot, v1_t)(t, id); }

// 0x446040, thiscall(stream) ret 4 -> bool. Stream slots: 0x40 (dword / id), 0x48 (4 bytes), 0x50 (4 bytes), 0x68 (1 byte), 0x6c (12 bytes), 0x18 (n raw bytes).
static u8 THISCALL fn446040(u8 *self, u8 *st) {
  if (!ext_45f3c0(self, st)) return 0;
  u32 loc;
#define F(slot, off) SLOT(st, slot, v1_t)(st, (u32)(self + (off)))
  F(0x40, 0x2c);
  for (u32 i = 0; UN32(self, 0x2c) > 0 && i < UN32(self, 0x2c); i++) {
    SLOT(st, 0x40, v1_t)(st, (u32)&loc);
    UN32(self, 0x24 + 4 * i) = lookup(0x54, loc);
  }
  SLOT(st, 0x40, v1_t)(st, (u32)&loc);
  UN32(self, 0x18) = lookup(0x58, loc);
  SLOT(st, 0x40, v1_t)(st, (u32)&loc);
  UN32(self, 0x192) = lookup(0x58, loc);
  F(0x40, 0x1c);
  F(0x48, 0x30);
  F(0x48, 0x34);
  F(0x50, 0x38);
  F(0x6c, 0x3c);
  F(0x48, 0x48);
  F(0x48, 0x4c);
  F(0x50, 0x50);
  F(0x50, 0x54);
  F(0x50, 0x58);
  F(0x50, 0x5c);
  F(0x50, 0x60);
  F(0x50, 0x64);
  F(0x50, 0x68);
  F(0x40, 0x6c);
  F(0x50, 0x70);
  F(0x50, 0x74);
  F(0x40, 0x78);
  SLOT(st, 0x18, v2_t)(st, (u32)(self + 0x7c), 0x34);
  SLOT(st, 0x18, v2_t)(st, (u32)(self + 0xb0), 0xc0);
  F(0x68, 0x170);
  F(0x50, 0x171);
  F(0x50, 0x175);
  F(0x50, 0x179);
  F(0x50, 0x17d);
  F(0x50, 0x181);
  F(0x50, 0x185);
  UN32(self, 0x189) = 0xbf800000;
  F(0x68, 0x18d);
  SLOT(st, 0x40, v1_t)(st, (u32)&loc);
  UN32(self, 0x18e) = loc;
  F(0x68, 0x196);
#undef F
  return 1;
}
PCREG(446040, fn446040);
