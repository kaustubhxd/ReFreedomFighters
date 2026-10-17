#include "ff.h"

// 0x462f80: look up an indexed byte; 0xff and a zero selector return -1.
static s32 THISCALL fn462f80(u8 *self, u32 selector) {
  u8 sel = (u8)selector;
  if (!sel) return -1;
  u8 *param = *(u8 **)(self + 8);
  u32 id = *(u32 *)(param + 0x6c);
  u8 *eng = G(u8 *, 0x70039c);
  u8 *mgr = *(u8 **)(eng + 0x1aa3);
  u8 *table = *(u8 **)(mgr + 0x18);
  u32 base = vcall<u32>(table, 0xc8, id);
  u8 value = *(u8 *)(base + sel);
  return value == 0xff ? -1 : value;
}

PCREG(462f80, fn462f80);
