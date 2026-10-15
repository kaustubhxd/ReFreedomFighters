#include "ff.h"

static s32 THISCALL fn46edb0(u8 *self) {
  if (!*(u32 *)(self + 0x60)) return -1;
  u8 *node = vcall<u8 *>(self, 0x350);
  u32 status = vcall<u32>(node, 0x354);
  if (status) return (s32)status;
  if (!vcall<u8 *>(self, 0x328)) return -1;
  node = vcall<u8 *>(self, 0x328);
  return vcall<s32>(node, 0x31c);
}

PCREG(46edb0, fn46edb0);
