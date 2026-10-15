#include "ff.h"
static void THISCALL fn4858a0(u8 *self) {
  u8 *sys = (u8 *)g_pSysInterface;
  if (!(vcall<u32>(sys, 0xe8, G(u32, self + 0x50)) & 0xff)) return;
  u8 *manager = (u8 *)G(u32, self + 0x48);
  u32 index = G(u32, self + 0x4c);
  u32 item = vcall<u32>(manager, 0x34, index);
  if (item) {
    u8 *target = (u8 *)G(u32, self + 0x44);
    vcall<void>(target, 0x370, item + 4, item + 0x28);
  }
  u32 count = vcall<u32>(manager, 0x14);
  ++G(u32, self + 0x4c);
  if (count == G(u32, self + 0x4c)) G(u32, self + 0x4c) = 0;
}
PCREG(4858a0, fn4858a0);
