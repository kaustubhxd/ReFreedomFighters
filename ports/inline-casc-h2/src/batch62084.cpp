#include "ff.h"
static u8 THISCALL fn4c5690(u8 *self, void *target) {
  G(u32, self + 4) &= ~0x40u;
  u8 *sys = (u8 *)g_pSysInterface;
  u8 *list = *(u8 **)(sys + 0x9b);
  u8 *resource = (u8 *)vcall<u32>(list, 0x138);
  u32 key = 0;
  vcall<void>(resource, 0x88, 0x68a9e0u, (u32)&key);
  G(u32, self + 0x53) = vcall<u32>(list, 0x58, key);
  vcall<void>(target, 0x68, (u32)(self + 0x52));
  return 1;
}
PCREG(4c5690, fn4c5690);
