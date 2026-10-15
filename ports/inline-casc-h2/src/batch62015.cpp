#include "ff.h"

extern "C" void THISCALL ext_489350(u8 *self, u8 *arg);

// 0x5e5bc0: update the argument object, pass its address through slot 0x40,
// look up the possibly replaced pointer, and store that result at this+0x54c.
static u8 THISCALL fn5e5bc0(u8 *self, u8 *arg) {
  ext_489350(self, arg);
  vcall<void>(arg, 0x40, &arg);
  u8 *table = *(u8 **)((u8 *)g_pSysInterface + 0x9b);
  u32 found = vcall<u32>(table, 0x58, arg);
  *(u32 *)(self + 0x54c) = found;
  return 1;
}

PCREG(5e5bc0, fn5e5bc0);
