// batch1665.cpp - 0x476240 (GUESS, residue 13 gap band, 2026-10-12). No arguments (plain ret). Continues only when the
// byte at this+0x56 is set and bit 10 of the dword at [[this+0x44]+8]+0x3c is clear. Then, as 0x476300: stores the tick
// count (sys+0x40) minus int(this+0x48 * literal at 0x67862c) at this+0x52 (never the local's address here), then calls
// this's vslot 0x64(0x10). GUESS: the names.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

void THISCALL GUESS_476240(u8 *self) {
  if (!AT(u8, self, 0x56)) return;
  u8 *o = AT(u8 *, self, 0x44);
  u8 *q = AT(u8 *, o, 8);
  u32 v = AT(u32, q, 0x3c);
  if ((v >> 10) & 1) return;
  u32 local = 0;
  if ((u8 *)self + 0x52 != (u8 *)&local) {
    float scaled = AT(float, self, 0x48) * *(float *)0x67862c;
    s32 k = (s32)scaled;
    u32 ticks = AT(u32, AT(u8 *, 0x70039c, 0), 0x40);
    AT(u32, self, 0x52) = ticks - (u32)k;
  }
  vcall<void>(self, 0x64, (u32)0x10);
}
PCREG(476240, GUESS_476240);
