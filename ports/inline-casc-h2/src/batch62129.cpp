#include "ff.h"
extern "C" void THISCALL ext_461570(u8 *self, u32 value, u32 key, u32 child);

static u32 THISCALL fn486890(u8 *self) {
  u8 *first = (u8 *)G(u32, self + 0xc);
  u8 *iface = (u8 *)vcall<u32>(first, 0x10);
  u8 *target = (u8 *)vcall<u32>(iface, 0x2e8);
  u32 choose_second = vcall<u32>(target, 0x1e0, 0x1007d4u) & 0xff;
  u32 selected = G(u32, self + (choose_second ? 0x14 : 0x10));
  if (!selected) return vcall<u32>(self, 0x0c);
  u8 *child = (u8 *)G(u32, self + 8);
  u32 result = vcall<u32>(child, 0x230, selected, 1u);
  ext_461570((u8 *)result, 0x41480000u, 0x465710u, 0u);
  return 1;
}
PCREG(486890, fn486890);
