// batch225.cpp - unclaimed area 22 (docs/20-unclaimed-22.md), slice floor(addr/16) mod 20 == 1. One DBREAD reader: four
// reads (u32, u16, u16, u32) into this's fields, a set bit from the first u32, and a last u32. Name GUESS.
#include "ff.h"

extern "C" u32 THISCALL ext_4e5e60(u8 *dbread);   // DBREAD::operator unsigned int(), original, returns eax
extern "C" u32 THISCALL ext_4e5e40(u8 *dbread);   // DBREAD::operator unsigned short(), original, returns ax

// 0x5bd750, thiscall(d): esi = u32(d); [this+0x75] = u16(d); [this+0x77] = u16(d); f = u32(d);
// [this+0x74] = (f != 0); [this+0x79] = 0 then bts(0, esi) (bit index esi mod 32); [this+0x7d] = u32(d).
static void THISCALL readBitsDB_5bd750(u8 *self, u8 *d) {
  u32 esi = ext_4e5e60(d);
  *(u16 *)(self + 0x75) = (u16)ext_4e5e40(d);
  *(u16 *)(self + 0x77) = (u16)ext_4e5e40(d);
  u32 f = ext_4e5e60(d);
  *(u32 *)(self + 0x79) = 0;
  *(u8 *)(self + 0x74) = f != 0;
  u32 bits = *(u32 *)(self + 0x79);
  bits |= 1u << (esi & 31);
  *(u32 *)(self + 0x79) = bits;
  *(u32 *)(self + 0x7d) = ext_4e5e60(d);
}
PCREG(5bd750, readBitsDB_5bd750);
