// batch1692.cpp - 0x464460 (GUESS, residue 13 gap band, 2026-10-12). Thiscall, one stack argument (a byte flag), ret 4. Stores
// the flag at this+0x70. When it is set, returns (only al is defined: the flag). When it is clear: msg = manager slot
// 0x114("MSG_LNKOBJOUTOFCUTSEQ", 0, "zlnkobj.cpp", 0x671) (word); cam = manager slot 0x138(); cam slot 0x88("MainCamera",
// &local) with local starting at 0; r = manager slot 0x4c(this); returns this's slot 0x12c(local, msg, r). GUESS: names.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

u32 THISCALL GUESS_464460(u8 *self, u32 flag) {
  u8 flagb = (u8)flag;
  AT(u8, self, 0x70) = flagb;
  if (flagb) return flagb;
  u8 *mgr = AT(u8 *, AT(u8 *, 0x70039c, 0), 0x9b);
  u32 msg = vcall<u16>(mgr, 0x114, 0x6859f4u, (u32)0, 0x685834u, (u32)0x671);
  u32 cam = vcall<u32>(mgr, 0x138);
  u32 local = 0;
  vcall<void>((void *)cam, 0x88, 0x685a0cu, (u32)&local);
  u32 r4 = vcall<u32>(mgr, 0x4c, (u32)self);
  return vcall<u32>(self, 0x12c, local, msg, r4);
}
PCREG(464460, GUESS_464460);
