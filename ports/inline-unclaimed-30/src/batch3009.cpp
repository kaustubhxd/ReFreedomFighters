// batch3009.cpp - unclaimed-30: batch 9 (docs/20-unclaimed-30.md, claim 1). AimControl::Save(ZSaveGame*) [map 0x513f50; thiscall,
// ret 4, returns true]. The dwords at +0, +4, +8 go to the save object's slots 0x3c, 0x64, 0x64; the floats at +0xc, +0x10, +0x14,
// +0x30, +0x34 go to slot 0x4c; the addresses of this+0x18 and this+0x24 go to slot 0x68.
#include "ff.h"

static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

static bool THISCALL aimControlSave(u8 *self, u8 *save) {
  vcall<void>(save, 0x3c, rd32u(self));
  vcall<void>(save, 0x64, rd32u(self + 4));
  vcall<void>(save, 0x64, rd32u(self + 8));
  vcall<void>(save, 0x4c, *(const float *)(self + 0xc));
  vcall<void>(save, 0x4c, *(const float *)(self + 0x10));
  vcall<void>(save, 0x4c, *(const float *)(self + 0x14));
  vcall<void>(save, 0x68, (const void *)(self + 0x18));
  vcall<void>(save, 0x68, (const void *)(self + 0x24));
  vcall<void>(save, 0x4c, *(const float *)(self + 0x30));
  vcall<void>(save, 0x4c, *(const float *)(self + 0x34));
  return true;
}
PCREG(513f50, aimControlSave);
