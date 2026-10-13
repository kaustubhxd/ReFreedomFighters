// batch13002.cpp - fresh slice 13, batch 2 (docs/20-fresh-13.md), 2026-10-12.
// 0x5b2550 ZActionControlMap::ZActionControlMap() (name map high). Thiscall, no arguments, returns this. Base constructor
// 0x469870 (thiscall, no arguments, plain ret); flag 0x20 at +4; vtable 0x6b1edc; field clears (1-byte packed); eight
// message ids from the engine database (*(0x70039c)+0x9b, slot +0x114 = RegisterZMsg(name, 0, file 0x6b1f60, line 0x27f..
// 0x286), ret 0x10) stored as words at +0x240..+0x24e; a 0x108-byte object from operator new 0x41e290 (cdecl), built by
// 0x4d83b0(0x6b1ff0, 0x6b1fb0, *(0x7003b8)+0x2c89) (thiscall, ret 0xc) when new succeeds, stored at +0x48 and handed to
// *(0x70039c) slot +0x1a4 (one argument; the caller's epilogue pops edi/esi at fixed offsets, so the callee pops 4).
// The exe's SEH frame and stack cookie are not reproduced (restored before return). Three `if (&field != &local)` guards
// compare object fields with a stack local and are always true for a heap object; the port stores unconditionally.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_469870[], ext_41e290[], ext_4d83b0[];
typedef void(THISCALL *Ctor0)(void *self);
typedef void *(*New1)(u32 n);
typedef u32(THISCALL *Ctor3)(void *self, u32 a, u32 b, u32 c);
typedef u16(THISCALL *Reg4)(void *db, u32 name, u32 zero, u32 file, u32 line);
typedef void(THISCALL *Slot1)(void *self, u32 a);

static void *THISCALL actionControlMapCtor(u8 *self) {
  ((Ctor0)(void *)ext_469870)(self);
  AT(u32, self, 4) |= 0x20;
  AT(u32, self, 0x44) = 0x0u;
  AT(u32, self, 0x0) = 0x6b1edcu;
  AT(u32, self, 0x1be) = 0x0u;
  AT(u8, self, 0x1c2) = 0x0u;
  AT(u32, self, 0x1c3) = 0x0u;
  AT(u32, self, 0x1c7) = 0x100u;
  AT(u32, self, 0x1cb) = 0x0u;
  AT(u8, self, 0x1cf) = 0x0u;
  AT(u32, self, 0x1d0) = 0x0u;
  AT(u32, self, 0x1d4) = 0x100u;
  AT(u32, self, 0x1d8) = 0x0u;
  AT(u8, self, 0x1dc) = 0x0u;
  AT(u32, self, 0x1dd) = 0x0u;
  AT(u32, self, 0x1e1) = 0x100u;
  AT(u32, self, 0x1ea) = 0x0u;
  AT(u32, self, 0x1ee) = 0x100u;
  AT(u16, self, 0x1f2) = 0x0u;
  AT(u32, self, 0x1f4) = 0x0u;
  AT(u32, self, 0x1f8) = 0x100u;
  AT(u32, self, 0x1fc) = 0x0u;
  AT(u16, self, 0x200) = 0x0u;
  AT(u8, self, 0x202) = 0x0u;
  AT(u32, self, 0x203) = 0x0u;
  AT(u32, self, 0x207) = 0x100u;
  AT(u32, self, 0x20b) = 0x0u;
  AT(u32, self, 0x213) = 0x0u;
  AT(u32, self, 0x21b) = 0x0u;
  AT(u32, self, 0x223) = 0x0u;
  AT(u32, self, 0x25c) = 0x0u;
  AT(u8, self, 0x260) = 0x0u;
  AT(u16, self, 0x55) = 0x0u;
  AT(u32, self, 0x1a1) = 0x0u;
  AT(u32, self, 0x16d) = 0x0u;
  AT(u32, self, 0x1b1) = 0x0u;
  AT(u32, self, 0x171) = 0x0u;
  AT(u32, self, 0x175) = 0x0u;
  AT(u32, self, 0x179) = 0x0u;
  AT(u16, self, 0x17d) = 0x0u;
  AT(u32, self, 0x19b) = 0x0u;
  AT(u16, self, 0x19f) = 0x0u;
  AT(u8, self, 0x168) = 0x0u;
  AT(u32, self, 0x1ab) = 0x0u;
  AT(u16, self, 0x1af) = 0x0u;
  AT(u8, self, 0x22b) = 0x0u;
  AT(u32, self, 0x22d) = 0x0u;
  AT(u32, self, 0x1a6) = 0x0u;
  AT(u16, self, 0x189) = 0x0u;
  AT(u8, self, 0x1b5) = 0x0u;
  AT(u8, self, 0x1b7) = 0x0u;
  AT(u32, self, 0x1b8) = 0xbf800000u;
  AT(u16, self, 0x1bc) = 0x0u;
  AT(u32, self, 0x51) = 0x0u;
  AT(u8, self, 0x4c) = 0x0u;
  AT(u32, self, 0x238) = 0x0u;
  AT(u32, self, 0x1e5) = 0x0u;
  AT(u8, self, 0x1e9) = 0x0u;
  AT(u32, self, 0x18b) = 0x0u;
  AT(u32, self, 0x18f) = 0x0u;
  AT(u32, self, 0x193) = 0x0u;
  AT(u32, self, 0x197) = 0x0u;
  AT(u32, self, 0x213) = 0;
  static const u32 kReg[8][3] = {{0x6a6da0, 0x27f, 0x240}, {0x6a9a50, 0x280, 0x242}, {0x6a9a64, 0x281, 0x244}, {0x6b1f98, 0x282, 0x246}, {0x6aacec, 0x283, 0x248}, {0x6a666c, 0x284, 0x24a}, {0x6a6610, 0x285, 0x24c}, {0x6acf90, 0x286, 0x24e}};
  for (u32 k = 0; k < 8; k++) {
    u8 *db = *(u8 **)(G(u32, 0x70039c) + 0x9b);
    Reg4 f = (Reg4)(*(u32 *)(*(u32 *)db + 0x114));
    AT(u16, self, kReg[k][2]) = f(db, kReg[k][0], 0, 0x6b1f60, kReg[k][1]);
  }
  AT(u32, self, 0x250) = 0;
  AT(u32, self, 0x254) = 0;
  AT(u32, self, 0x258) = 0;
  AT(u32, self, 0x20b) = 0;
  AT(u32, self, 0x20f) = 0;
  AT(u32, self, 0x213) = 0;
  AT(u32, self, 0x217) = 0;
  AT(u32, self, 0x21b) = 0;
  AT(u32, self, 0x21f) = 0;
  AT(u32, self, 0x223) = 0;
  AT(u32, self, 0x227) = 0;
  void *mem = ((New1)(void *)ext_41e290)(0x108);
  u32 obj = 0;
  if (mem)
    obj = ((Ctor3)(void *)ext_4d83b0)(mem, 0x6b1ff0, 0x6b1fb0, G(u32, 0x7003b8) + 0x2c89);
  AT(u32, self, 0x48) = obj;
  u8 *sys = (u8 *)G(u32, 0x70039c);
  ((Slot1)(*(u32 *)(*(u32 *)sys + 0x1a4)))(sys, obj);
  AT(u8, self, 0x167) = 0;
  return self;
}
PCREG(5b2550, actionControlMapCtor);
