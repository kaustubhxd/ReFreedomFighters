// batch1651.cpp - five one-instruction getters in the 0x461000-0x481000 gap band (residue 13 pass, 2026-10-12). Each is
// a single load and return: no names in the map (GUESS FUN_<addr> for 0x46e6f0, 0x46e7f0, 0x469120, 0x4808c0) except
// 0x462f40 (ZItemTemplate::GetPointerContextPicture in docs/20-unclaimed-77.md, not verified there).
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

u32 THISCALL GUESS_46e6f0(u8 *self) { return AT(u32, self, 0x64); }
PCREG(46e6f0, GUESS_46e6f0);

u32 THISCALL GUESS_46e7f0(u8 *self) { return AT(u32, self, 0x60); }
PCREG(46e7f0, GUESS_46e7f0);

u32 THISCALL GUESS_469120(void *self) { return *(u32 *)0x6e59d8; }
PCREG(469120, GUESS_469120);

u32 THISCALL GUESS_4808c0(void *self) { return *(u32 *)0x6e5ef8; }
PCREG(4808c0, GUESS_4808c0);

u32 THISCALL ZItemTemplate_GetPointerContextPicture(u8 *self) { return AT(u32, self, 0x6c); }
PCREG(462f40, ZItemTemplate_GetPointerContextPicture);
