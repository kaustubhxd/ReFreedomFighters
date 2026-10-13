// batch13007.cpp - fresh slice 13, batch 7 (docs/20-fresh-13.md), 2026-10-12.
// 0x517050 GUESS constructor (no name map entry; vtable 0x69ec64). Thiscall, three stack arguments passed through to the
// base constructor 0x514940 (thiscall, ret 0xc), returns this (ret 0xc). Member constructor 0x5249c0 (thiscall, no args)
// on +0x2d8, field clears (1-byte packed; 120.0f at +0x1610, 1.0f at +0x1641, 3 at +0x1645, byte 1 at +0x1649), one
// RegisterZMsg id (engine db *(0x70039c)+0x9b slot 0x114: name 0x69f024, 0, file 0x69eff8, line 0x2b; ret 0x10) as a word
// at +0x164e, then +0x164a = 0 and byte +0x1614 = 0. The SEH frame and stack cookie are not reproduced.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_514940[], ext_5249c0[];
typedef void(THISCALL *Base3)(void *self, u32 a, u32 b, u32 c);
typedef void(THISCALL *Ctor0)(void *self);
typedef u16(THISCALL *Reg4)(void *db, u32 name, u32 zero, u32 file, u32 line);

static u8 *THISCALL ctor517050(u8 *self, u32 a, u32 b, u32 c) {
  ((Base3)(void *)ext_514940)(self, a, b, c);
  AT(u32, self, 0) = 0x69ec64;
  ((Ctor0)(void *)ext_5249c0)(self + 0x2d8);
  AT(u32, self, 0x1603) = 0x0u;
  AT(u32, self, 0x1607) = 0x0u;
  AT(u32, self, 0x160c) = 0x0u;
  AT(u32, self, 0x1610) = 0x42f00000u;
  AT(u32, self, 0x1615) = 0x0u;
  AT(u32, self, 0x1619) = 0x0u;
  AT(u32, self, 0x161d) = 0x0u;
  AT(u32, self, 0x1621) = 0x0u;
  AT(u32, self, 0x1625) = 0x0u;
  AT(u32, self, 0x1629) = 0x0u;
  AT(u32, self, 0x162d) = 0x0u;
  AT(u8, self, 0x1649) = 0x1u;
  AT(u32, self, 0x163d) = 0x0u;
  AT(u32, self, 0x1641) = 0x3f800000u;
  AT(u32, self, 0x1645) = 0x3u;
  AT(u32, self, 0x15f3) = 0x0u;
  AT(u32, self, 0x15ef) = 0x0u;
  AT(u32, self, 0x15eb) = 0x0u;
  AT(u32, self, 0x15f7) = 0x0u;
  AT(u32, self, 0x15fb) = 0x0u;
  AT(u32, self, 0x15ff) = 0x0u;
  AT(u32, self, 0x1635) = 0x0u;
  AT(u32, self, 0x1639) = 0x0u;
  u8 *db = *(u8 **)(G(u32, 0x70039c) + 0x9b);
  AT(u16, self, 0x164e) = ((Reg4)(*(u32 *)(*(u32 *)db + 0x114)))(db, 0x69f024, 0, 0x69eff8, 0x2b);
  AT(u32, self, 0x164a) = 0;
  AT(u8, self, 0x1614) = 0;
  return self;
}
PCREG(517050, ctor517050);
