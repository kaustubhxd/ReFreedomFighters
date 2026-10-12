#include "ff.h"
// batch7905.cpp - unclaimed-79 batch 5 (docs/20-unclaimed-79.md). Name from the GC name map (naming only).

// 0x4a28e0, ZParamAnim::Command(unsigned short, void*) (high). Dispatch on the word command; always returns 0.
static u32 THISCALL paramAnimCommand(u8 *self, u32 cmdArg, u32 arg) {
  u16 cmd = (u16)cmdArg;
  if (cmd == 0x401) {
    if (self[0x11c] == 0)
      vcall<void, u32>(self, 0x64, 0x10u);
  } else if (cmd == 0x400) {
    if (self[0x11c] == 0)
      vcall<void, u32, u32>(self, 0x68, 0x10u, 0u);
  } else if (cmd == *(u16 *)(self + 0x11a)) {
    vcall<void>(*(u8 **)(self + 0x44), 0x2c);
    vcall<void, u32>(self, 0x64, 0x10u);
    u8 *sysField = G(u8 *, 0x70039c) + 0x40;
    if (self + 0x4d != sysField)
      *(u32 *)(self + 0x4d) = *(u32 *)sysField;
    vcall<void>(self, 0x3c);
  }
  if (cmd == G(u16, 0x7002e8)) {
    u8 *sysField = G(u8 *, 0x70039c) + 0x40;
    if (self + 0x49 != sysField)
      *(u32 *)(self + 0x49) = *(u32 *)sysField;
    return 0;
  }
  if (cmd == G(u16, 0x7002ec)) {
    u32 d = *(u32 *)(G(u8 *, 0x70039c) + 0x40) - *(u32 *)(self + 0x49);
    *(u32 *)(self + 0x4d) += d;
    return 0;
  }
  if (cmd == G(u16, 0x7002f0)) {
    *(float *)(self + 0x51) = (float)(s32)arg / G(float, 0x685270);
    return 0;
  }
  if (cmd == G(u16, 0x7002f4))
    *(float *)(self + 0x55) = (float)(s32)arg / G(float, 0x685270);
  return 0;
}
PCREG(4a28e0, paramAnimCommand);
