// f16b007.cpp - fresh slice 16, batch 7 (2026-10-12).
// 0x5b7e40 (out = this, rd): rd slot 0x40(&slot) (slot = the argument's own stack word, holding rd); out[0] = db slot 0x58(slot);
//           rd slot 0x50(out+4); rd slot 0x50(out+8); rd slot 0x40(&slot); out[3] = db slot 0x58(slot). Ret 4.
// 0x433ec0 constructor: vtable 0x67a3b0, MYSTR::MYSTR 0x4cbeb0 on +0xc and +0x8c, +4 = +8 = 0. Returns this. SEH not reproduced.
// 0x4f0840 ZWINOBJ::MakeVerticalAlignment(v): flags +0x20 & 0xf0 -> y = -v[1] (+ h if bit 0x10, - h if bit 0x20; h = [+8]+0x44)
//           + [0x679540]; +0x42 = (float)floor((double)y) (CRT floor 0x634dca, result in ST0). Ret 4.
// 0x570680 CSewerMenu::CopyEventDataBlock(rd): ZSoundController::CopyData 0x610100(rd); DBREAD u32 reads 0x4e5e60 into +0x1b0,
//           +0x1b4, +0x1b8, +0x1bc, +0x190; a sixth read non-zero -> +0x1a3 = 1. Ret 4.
// 0x57c480: o = [[0x70039c]+0x9b]+8 slot 0x44(ECX as passed); o != 0 -> CBaseWindow::CBaseWindow 0x561020(o), vtable 0x6aa7b4.
//           Returns o. SEH not reproduced (same shape as 0x5bf780, batch 6).
// 0x421680 ZSysInterfaceGC::InitKeyMap: +0x2c = 0, +0xa03 = 0.2f bits 0x3e4ccccd; memset(+0xa07, 0, 0x500), 256 five-byte
//           records from +0xa0b get |= 0xc; memset(+0xf07, 0, 0xa00), 512 records from +0xf0b get |= 0xc.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_4cbeb0[], ext_634dca[], ext_610100[], ext_4e5e60[], ext_561020[], ext_634d10[];

extern "C" void THISCALL f16_5b7e40(u32 *out, void *rd) {
  void *db;
  u32 slot = (u32)rd;
  vcall<void>(rd, 0x40, &slot);
  db = AT(void *, G(u8 *, 0x70039c), 0x9b);
  out[0] = vcall<u32>(db, 0x58, slot);
  vcall<void>(rd, 0x50, out + 1);
  vcall<void>(rd, 0x50, out + 2);
  vcall<void>(rd, 0x40, &slot);
  db = AT(void *, G(u8 *, 0x70039c), 0x9b);
  out[3] = vcall<u32>(db, 0x58, slot);
}

extern "C" void *THISCALL f16_433ec0(u8 *self) {
  typedef void(THISCALL * Ctor)(void *);
  AT(u32, self, 0) = 0x67a3b0u;
  ((Ctor)(void *)ext_4cbeb0)(self + 0xc);
  ((Ctor)(void *)ext_4cbeb0)(self + 0x8c);
  AT(u32, self, 4) = 0;
  AT(u32, self, 8) = 0;
  return self;
}

extern "C" void THISCALL f16_4f0840(u8 *self, float *v) {
  u8 fl = AT(u8, self, 0x20);
  if (!(fl & 0xf0)) return;
  float y = bitsf(fbits(v[1]) ^ G(u32, 0x67af40));
  if (fl & 0x10) y += AT(float, AT(u8 *, self, 8), 0x44);
  if (fl & 0x20) y -= AT(float, AT(u8 *, self, 8), 0x44);
  y += G(float, 0x679540);
  long double r = ((long double (*)(double))(void *)ext_634dca)((double)y);
  AT(float, self, 0x42) = (float)r;
}

extern "C" void THISCALL f16_570680(u8 *self, void *rd) {
  typedef u32(THISCALL * Rd)(void *);
  ((void(THISCALL *)(void *, void *))(void *)ext_610100)(self, rd);
  AT(u32, self, 0x1b0) = ((Rd)(void *)ext_4e5e60)(rd);
  AT(u32, self, 0x1b4) = ((Rd)(void *)ext_4e5e60)(rd);
  AT(u32, self, 0x1b8) = ((Rd)(void *)ext_4e5e60)(rd);
  AT(u32, self, 0x1bc) = ((Rd)(void *)ext_4e5e60)(rd);
  AT(u32, self, 0x190) = ((Rd)(void *)ext_4e5e60)(rd);
  if (((Rd)(void *)ext_4e5e60)(rd)) AT(u8, self, 0x1a3) = 1;
}

extern "C" void *THISCALL f16_57c480(void *self) {
  void *a = AT(void *, AT(u8 *, G(u8 *, 0x70039c), 0x9b), 8);
  u8 *o = vcall<u8 *>(a, 0x44, self);
  if (o) {
    ((void(THISCALL *)(void *))(void *)ext_561020)(o);
    AT(u32, o, 0) = 0x6aa7b4u;
  }
  return o;
}

extern "C" void THISCALL f16_421680(u8 *self) {
  typedef void *(*Ms)(void *, int, u32);
  AT(u32, self, 0x2c) = 0;
  AT(u32, self, 0xa03) = 0x3e4ccccdu;
  ((Ms)(void *)ext_634d10)(self + 0xa07, 0, 0x500);
  for (u32 i = 0; i < 0x100; ++i) self[0xa0b + 5 * i] |= 0xc;
  ((Ms)(void *)ext_634d10)(self + 0xf07, 0, 0xa00);
  for (u32 i = 0; i < 0x200; ++i) self[0xf0b + 5 * i] |= 0xc;
}

PCREG(5b7e40, f16_5b7e40);
PCREG(433ec0, f16_433ec0);
PCREG(4f0840, f16_4f0840);
PCREG(570680, f16_570680);
PCREG(57c480, f16_57c480);
PCREG(421680, f16_421680);
