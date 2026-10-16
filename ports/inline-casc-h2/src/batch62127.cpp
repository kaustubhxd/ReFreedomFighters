#include "ff.h"
extern "C" void THISCALL ext_562440(u8 *self);
extern "C" void THISCALL ext_563510(u8 *self, u32 resource);

static void THISCALL fn57bf60(u8 *self) {
  ext_562440(self);
  ext_563510(self, 0x6a663cu);
  u8 *sys = G(u8 *, 0x70039c);
  u8 *table = (u8 *)G(u32, sys + 0x9b);
  u8 *resource = (u8 *)vcall<u32>(table, 0x134);
  vcall<void>(resource, 0x68, 0x6a757cu, 0u, 0u);
  resource = (u8 *)vcall<u32>(table, 0x134);
  vcall<void>(resource, 0x68, 0x6a776cu, 0u, 0u);
  resource = (u8 *)vcall<u32>(table, 0x134);
  vcall<void>(resource, 0x68, 0x6aa5ecu, 0u, 0u);
}
PCREG(57bf60, fn57bf60);
