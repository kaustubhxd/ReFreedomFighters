// batch1656.cpp - two gap-band functions (residue 13, 2026-10-12). Both take one stack argument (obj, ret 4).
// 0x476350 (GUESS): clears bit 0x40 of this+4, calls obj's vslot 0x54 with the dword at this+0x52, then obj's vslot 0x60
// with the byte at this+0x56, and returns 1.
// 0x476a20 (GUESS): ZGROUP::CopyData(this, obj) (0x43f8c0, hooked), then (obj's vslot 0x1e0)(0x1000ca); when the result's
// low byte is set, copies obj+0x5c into this+0x5c and returns that value; else returns the slot's result.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_43f8c0[];
typedef void(THISCALL *CopyDataFn)(void *self, void *obj);

u8 THISCALL GUESS_476350(u8 *self, u8 *obj) {
  AT(u32, self, 4) &= 0xffffffbfu;
  vcall<void>(obj, 0x54, AT(u32, self, 0x52));
  vcall<void>(obj, 0x60, (u32)AT(u8, self, 0x56));
  return 1;
}
PCREG(476350, GUESS_476350);

u32 THISCALL GUESS_476a20(u8 *self, u8 *obj) {
  ((CopyDataFn)(void *)ext_43f8c0)(self, obj);
  u32 r = vcall<u32>(obj, 0x1e0, (u32)0x1000ca);
  if ((u8)r) {
    r = AT(u32, obj, 0x5c);
    AT(u32, self, 0x5c) = r;
  }
  return r;
}
PCREG(476a20, GUESS_476a20);
