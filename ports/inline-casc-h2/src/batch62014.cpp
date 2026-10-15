#include "ff.h"

extern "C" void THISCALL ext_6352f0(u8 *self, u32 *out);
extern "C" void THISCALL ext_584b40(u8 *self, u32 *out);

// 0x584680: decode an optional value, populate its fields, notify the owner,
// and report success.
static u8 THISCALL fn584680(u8 *self, u8 *owner) {
  u32 value = 0;
  *(u32 *)(self + 4) &= 0xffffffbf;
  ext_6352f0(self, &value);
  ext_584b40(self, &value);
  vcall<void>(owner, 0x40, self + 0x5e);
  return 1;
}

PCREG(584680, fn584680);
