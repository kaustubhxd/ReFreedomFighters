// batch1636.cpp - ZInputActions::IsActionActive-style check at 0x438d50 (residue 13, 2026-10-11).
// The vtable +0x60 lookup returns the action record for a name (0 = unknown). An action without its enabled byte (+0x10)
// answers that byte. A record of kind 3 (+4) answers the enabled byte; any other kind is ANDed with IsActive of its
// sub-object (+0xc, exe function 0x439670). GUESS: the names of the record fields are read from the code only.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_439670[];  // ZInputActionBase::IsActive (thiscall, no stack args)
typedef u8(THISCALL *IsActiveFn)(void *self);

u8 THISCALL ZInputActions_CheckAction(u8 *self, const char *name) {
  void *a = vcall<void *>(self, 0x60, name);
  if (!a) return 0;
  u8 bl = AT(u8, a, 0x10);
  if (!bl) return bl;
  if (AT(u32, a, 4) != 3) bl &= ((IsActiveFn)(void *)ext_439670)(AT(void *, a, 0xc));
  return bl;
}
PCREG(438d50, ZInputActions_CheckAction);
