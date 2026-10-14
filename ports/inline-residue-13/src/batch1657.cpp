// batch1657.cpp - two gap-band functions (residue 13, 2026-10-12).
// 0x476500 (GUESS, deleting-style): stores the vtable 0x689de4 at +0, frees the blocks at +0x64 and +0x68 (4-byte sized
// delete, __builtin_delete 0x634273, cdecl) when non-null, then tail-jumps to 0x43ea20 with this.
// 0x4690c0 (GUESS): with a non-null this: when bit 4 of +4 is set calls slot 0x4c; sets bit 0x100 of +4; then calls the
// manager's slot 0x148 with (obj, this) (ret 4). obj is the stack argument. Returns void.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_634273[], ext_43ea20[];
typedef void(*BuiltinDelete)(void *p, u32 size);
typedef u32(THISCALL *Tail0)(void *self);

u32 THISCALL GUESS_476500(u8 *self) {
  void *p64 = AT(void *, self, 0x64);
  AT(u32, self, 0) = 0x689de4u;
  if (p64) ((BuiltinDelete)(void *)ext_634273)(p64, 4);
  void *p68 = AT(void *, self, 0x68);
  if (p68) ((BuiltinDelete)(void *)ext_634273)(p68, 4);
  return ((Tail0)(void *)ext_43ea20)(self);
}
PCREG(476500, GUESS_476500);

void THISCALL GUESS_4690c0(u8 *self, u32 obj) {
  if (!self) return;
  if (AT(u32, self, 4) & 4) vcall<void>(self, 0x4c);
  AT(u32, self, 4) |= 0x100;
  u8 *mgr = AT(u8 *, AT(u8 *, 0x70039c, 0), 0x9b);
  vcall<void>(mgr, 0x148, obj, (u32)self);
}
PCREG(4690c0, GUESS_4690c0);
