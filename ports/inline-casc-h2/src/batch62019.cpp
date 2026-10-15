#include "ff.h"

extern "C" void FASTCALL ext_633654(u32 cookie);

// 0x466890: pass a stack-local output buffer and the two inputs to slot 0x10,
// then perform the /GS cookie check.
static void THISCALL fn466890(u8 *self, u32 field, u32 code) {
  u8 *nested = *(u8 **)(self + 0x6c);
  u32 buffer[9];
  vcall<void>(nested, 0x10, buffer, code, field, self);
  ext_633654(G(u32, 0x6f5630));
}

PCREG(466890, fn466890);
