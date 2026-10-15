#include "ff.h"
static void THISCALL fn512db0(u8 *self, u32 *out) {
  u8 *manager = (u8 *)*(u32 *)(self + 8);
  if (manager) {
    u32 token = vcall<u32>(manager, 0x3a8, out);
    vcall<void>(manager, 0x398, token);
  } else {
    out[0] = out[1] = out[2] = 0;
  }
  u8 *owner = (u8 *)*(u32 *)(self + 4);
  vcall<void>(owner, 0x84, out);
}
PCREG(512db0, fn512db0);
