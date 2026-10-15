#include "ff.h"

extern "C" void THISCALL ext_6352f0(u8 *self, u32 *out);

// 0x4b0e40: refresh a local value through the object helper and virtual slot,
// clear the cached field, and mark the object dirty.
static void THISCALL fn4b0e40(u8 *self) {
  u32 value = 0;
  ext_6352f0(self, &value);
  vcall<void>(self, 0x98, &value);
  *(u32 *)(self + 0x50) = 0;
  self[0x6c] = 1;
}

PCREG(4b0e40, fn4b0e40);
