// batch1681.cpp - 0x476b50 (GUESS, residue 13 gap band, 2026-10-12). Same queue step as batch 1680 (decrement this+0x60,
// element from this+0x68, manager slot 0x58, reset from this+0x5c), with the object's work in a different order: when the
// element is set, obj's slot 0x288(element, 0, 1) first, then the element's slot 0x74(a2, a3), slot 0x2c(), and slot
// 0x138(word at this+0x70, 0, 0). Seven stack arguments (ret 0x1c); a2 and a3 are the 2nd and 3rd. Returns the element.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

u32 THISCALL GUESS_476b50(u8 *self, u32 obj, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
  u8 *R = AT(u8 *, AT(u8 *, 0x70039c, 0), 0x9b);
  AT(u32, self, 0x60) -= 1;
  u32 idx = AT(u32, self, 0x60);
  u32 elem = AT(u32, AT(u8 *, self, 0x68), idx * 4);
  u32 esi = vcall<u32>(R, 0x58, elem);
  if (AT(u32, self, 0x60) == 0) AT(u32, self, 0x60) = AT(u32, self, 0x5c);
  if (esi) {
    vcall<void>((void *)obj, 0x288, esi, (u32)0, (u32)1);
    vcall<void>((void *)esi, 0x74, a2, a3);
    vcall<void>((void *)esi, 0x2c);
    vcall<void>((void *)esi, 0x138, (u32)AT(u16, self, 0x70), (u32)0, (u32)0);
  }
  return esi;
}
PCREG(476b50, GUESS_476b50);
