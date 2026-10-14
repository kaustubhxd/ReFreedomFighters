// batch1664.cpp - 0x476300 (GUESS, residue 13 gap band, 2026-10-12). ret 8 (two arguments: a word and an unused dword).
// When the word equals this+0x4c: (unless this+0x52 is the local's address, which never happens here) stores the system
// tick count minus int(this+0x48 * literal at 0x67862c) at this+0x52, then calls this's vslot 0x64(0x10). Returns 0.
// GUESS: the slot 0x64 and the field names. The literal is read from the exe image, not copied.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

u32 THISCALL GUESS_476300(u8 *self, u32 word, u32 unused) {
  if ((u16)word == AT(u16, self, 0x4c)) {
    u32 local = 0;
    if ((u8 *)self + 0x52 != (u8 *)&local) {
      float scaled = AT(float, self, 0x48) * *(float *)0x67862c;
      s32 k = (s32)scaled;
      u32 ticks = AT(u32, AT(u8 *, 0x70039c, 0), 0x40);
      AT(u32, self, 0x52) = ticks - (u32)k;
    }
    vcall<void>(self, 0x64, (u32)0x10);
  }
  return 0;
}
PCREG(476300, GUESS_476300);
