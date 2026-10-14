// batch1680.cpp - 0x476ae0 (GUESS, residue 13 gap band, 2026-10-12). Queue step: thiscall with five stack arguments (ret
// 0x14; only the first, obj, is read), no SEH frame, no cookie. Decrements this+0x60, takes element [this+0x60] of the
// array at this+0x68, asks the manager (sys+0x9b) for its object via slot 0x58(element); when the index reaches zero it
// is reset from this+0x5c. When the object is set: its slot 0x2c(), its slot 0x138(word at this+0x70, 0, 0), then obj's
// slot 0x288(object, 0, 1). Returns the object (0 when none). GUESS: the slot and field names.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

u32 THISCALL GUESS_476ae0(u8 *self, u32 obj, u32 a2, u32 a3, u32 a4, u32 a5) {
  u8 *R = AT(u8 *, AT(u8 *, 0x70039c, 0), 0x9b);
  AT(u32, self, 0x60) -= 1;
  u32 idx = AT(u32, self, 0x60);
  u32 elem = AT(u32, AT(u8 *, self, 0x68), idx * 4);
  u32 esi = vcall<u32>(R, 0x58, elem);
  if (AT(u32, self, 0x60) == 0) AT(u32, self, 0x60) = AT(u32, self, 0x5c);
  if (esi) {
    vcall<void>((void *)esi, 0x2c);
    vcall<void>((void *)esi, 0x138, (u32)AT(u16, self, 0x70), (u32)0, (u32)0);
    vcall<void>((void *)obj, 0x288, esi, (u32)0, (u32)1);
  }
  return esi;
}
PCREG(476ae0, GUESS_476ae0);
