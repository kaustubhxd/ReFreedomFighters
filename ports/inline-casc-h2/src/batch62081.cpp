#include "ff.h"
typedef void (*flush_fn)();
static void THISCALL fn654d60(u8 *self, u32 a, u32 b, u32 c) {
  vcall<void>(self, 0x230, a, b, c);
  u8 *sys = (u8 *)g_pSysInterface;
  G(u8, sys + 0xa10) &= 0x7f; G(u8, sys + 0xa10) &= 0xdf;
  G(u8, sys + 0x13fc) &= 0x7f; G(u8, sys + 0x13fc) &= 0xdf;
  if (G(u32, self + 0x137)) {
    ((flush_fn)G(u32, 0x6761f0))();
    G(u8, self + 0x1185) = 0;
    vcall<void>(self, 0xc8);
  }
  G(u8, sys + 0xad8) &= 0x7f;
  G(u8, sys + 0x13f7) &= 0x7f;
  G(u8, self + 0x1184) = 0;
}
PCREG(654d60, fn654d60);
