#include "ff.h"

extern "C" u32 THISCALL ext_4cc5f0(u8 *self); // strlen of the pointer at [self]
extern "C" u8 *THISCALL ext_4cc1d0(u8 *self); // returns [self]

// 0x4689e0, thiscall(other) ret 4: if this+0x61 references a nonempty
// string, send the fixed label and its length through other slot 0x20.
static void THISCALL fn4689e0(u8 *self, u8 *other) {
  u8 *name = self + 0x61;
  u32 len = ext_4cc5f0(name);
  if (!len) return;
  u8 *name_string = ext_4cc1d0(name);
  vcall<void>(other, 0x20, 0x685918u, name_string);
}

PCREG(4689e0, fn4689e0);
