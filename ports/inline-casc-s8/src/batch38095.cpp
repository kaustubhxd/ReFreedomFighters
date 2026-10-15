// batch38095.cpp - cascade s8 batch 38095: 0x525bc0 (load a record from a stream: fixed fields, an id looked up in the engine table, four arrays of sub-records).
#include "ff.h"

extern "C" void THISCALL ext_516470(u8 *p, u8 *st);   // ret 4
extern "C" void THISCALL ext_529d00(u8 *p, u8 *st);   // ret 4
extern "C" void THISCALL ext_529d70(u8 *p, u8 *st);   // ret 4
extern "C" void THISCALL ext_516d10(u8 *p, u8 *st);   // ret 4
typedef u32(THISCALL *v1_t)(void *, u32);
#define SLOT(o, off, T) ((T)(*(u8 **)(*(u8 **)(o) + (off))))
#define SYS G(u8 *, 0x70039c)

// 0x525bc0, thiscall(stream) ret 4 -> bool (always true). Stream slots: 0x6c (12-byte value), 0x74 (value), 0x50 / 0x48 / 0x68 (dword / word / byte reads) into the object fields; generated from the disassembly.
static u8 THISCALL fn525bc0(u8 *self, u8 *st) {
  u32 loc;
#define F(slot, off) SLOT(st, slot, v1_t)(st, (u32)(self + (off)))
  SLOT(st, 0x6c, v1_t)(st, (u32)self);
  F(0x74, 0xc);
  F(0x50, 0x30);
  F(0x50, 0x34);
  F(0x50, 0x38);
  F(0x50, 0x3c);
  F(0x48, 0x40);
  F(0x48, 0x44);
  F(0x50, 0x48);
  F(0x6c, 0x4c);
  F(0x6c, 0x58);
  F(0x50, 0x64);
  F(0x50, 0x68);
  F(0x50, 0x6c);
  F(0x50, 0x70);
  F(0x50, 0x74);
  F(0x50, 0x78);
  F(0x50, 0x7c);
  F(0x50, 0x80);
  SLOT(st, 0x40, v1_t)(st, (u32)&loc);
  { u8 *t = *(u8 **)(SYS + 0x9b); *(u32 *)(self + 0x88) = SLOT(t, 0x58, v1_t)(t, loc); }
  F(0x48, 0x8c);
  F(0x48, 0x90);
  F(0x50, 0x94);
  F(0x50, 0x98);
  F(0x50, 0x9c);
  F(0x50, 0xa0);
  F(0x50, 0xa4);
  F(0x50, 0xa8);
  F(0x50, 0xac);
  F(0x6c, 0xb0);
  F(0x68, 0xbc);
  for (int i = 0; i < 4; i++) ext_516470(self + 0xbd + i * 0xde, st);
  for (int i = 0; i < 4; i++) ext_516470(self + 0x435 + i * 0xde, st);
  for (int i = 0; i < 4; i++) ext_529d00(self + 0x7ad + i * 0x163, st);
  for (int i = 0; i < 4; i++) ext_529d70(self + 0xd39 + i * 0x133, st);
  ext_516d10(self + 0x1205, st);
  ext_516d10(self + 0x127e, st);
  F(0x48, 0x12f7);
#undef F
  return 1;
}
PCREG(525bc0, fn525bc0);
