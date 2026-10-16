// batch1705.cpp - eight unported leaf functions from the area-13 band (floor(addr/16) mod 20 = 13), 2026-10-12. GUESS names;
// no SEH frames except 0x4478d0, which is hooked as a tail target. Each is a single load/store/return, or a vtable store.
// 0x524390: float this+0xc (st0).           0x614ed0: constant 0x1c.           0x654710: constant 0x6f62b8.
// 0x51c550: float global 0x69f9e8 (st0).    0x60d810: this+0x94 (address).     0x616a50: vtable 0x6bdc38 at +0.
// 0x4529d0: vtable 0x681860 at +0, then tail jump to 0x4478d0 (hooked; no stack arguments).
// 0x613350: bool, this+0x22030 != 0 (al).
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_4478d0[];
typedef u32(THISCALL *Tail0)(void *self);

float THISCALL GUESS_524390(u8 *self) { return AT(float, self, 0xc); }
PCREG(524390, GUESS_524390);

u32 THISCALL GUESS_614ed0(u8 *self) { return 0x1c; }
PCREG(614ed0, GUESS_614ed0);

u32 THISCALL GUESS_654710(u8 *self) { return 0x6f62b8u; }
PCREG(654710, GUESS_654710);

float THISCALL GUESS_51c550(u8 *self) { return *(float *)0x69f9e8; }
PCREG(51c550, GUESS_51c550);

u32 THISCALL GUESS_60d810(u8 *self) { return (u32)(self + 0x94); }
PCREG(60d810, GUESS_60d810);

void THISCALL GUESS_616a50(u8 *self) { AT(u32, self, 0) = 0x6bdc38u; }
PCREG(616a50, GUESS_616a50);

u32 THISCALL GUESS_4529d0(u8 *self) {
  AT(u32, self, 0) = 0x681860u;
  return ((Tail0)(void *)ext_4478d0)(self);
}
PCREG(4529d0, GUESS_4529d0);

u8 THISCALL GUESS_613350(u8 *self) { return AT(u32, self, 0x22030) != 0; }
PCREG(613350, GUESS_613350);
