// batch1030.cpp - ZCamHelper::Save(ZSaveGame*): the helper's saved fields, in the order the original writes them.
// The table is generated from the disassembly of 0x5d18a0 (87 writes). Kinds: F float (sg slot 0x4c), B byte (0x60),
// W word (0x40), V vector pointer (0x68), M matrix pointer (0x70), H handle value (0x3c), D dword value (0x64).
// Camera thread, 2026-10-11.
#include "cam.h"

enum SaveKind : u8 { F, B, W, V, M, H, D };
struct SaveField {
  u16 off;
  SaveKind k;
};
static const SaveField kZCamSave[] = {
    {0xa54, F},
    {0xa58, F},
    {0xa5c, F},
    {0xa60, F},
    {0xa64, F},
    {0xa68, F},
    {0xa6c, F},
    {0xa70, B},
    {0xa71, B},
    {0xa72, V},
    {0xa7e, V},
    {0xa8a, V},
    {0xa96, F},
    {0xa9a, F},
    {0xa9e, F},
    {0xaa2, F},
    {0xaae, F},
    {0xab6, B},
    {0xad5, W},
    {0xad9, F},
    {0xadd, F},
    {0xad4, B},
    {0xae1, H},
    {0xae5, D},
    {0xae9, F},
    {0xaed, F},
    {0xaf1, F},
    {0xaf5, F},
    {0xaf9, F},
    {0xafd, F},
    {0xb01, F},
    {0xb05, F},
    {0xb09, F},
    {0xb0d, F},
    {0xb11, F},
    {0xb15, F},
    {0xb19, B},
    {0xb1a, B},
    {0xb1f, F},
    {0xb23, F},
    {0xb27, F},
    {0xb2b, F},
    {0xb2f, B},
    {0xb30, B},
    {0xb31, B},
    {0xb32, B},
    {0xb33, B},
    {0xb34, B},
    {0xb35, F},
    {0xb39, V},
    {0xb45, B},
    {0xb47, B},
    {0xb48, B},
    {0xb49, F},
    {0xb4d, B},
    {0xb4f, B},
    {0xb50, H},
    {0xc6d, H},
    {0xc71, V},
    {0xc7d, V},
    {0xc89, M},
    {0xcad, V},
    {0xcb9, M},
    {0xcdd, M},
    {0xd01, V},
    {0xd0d, H},
    {0xd11, H},
    {0xd15, V},
    {0xd21, B},
    {0xd22, V},
    {0xd2e, H},
    {0xd32, B},
    {0xd33, B},
    {0xd34, B},
    {0xd35, B},
    {0xdd8, B},
    {0xdf5, F},
    {0xdf9, F},
    {0xdfd, F},
    {0xe01, F},
    {0xe05, F},
    {0xe09, F},
    {0xe0d, B},
    {0xe0e, B},
    {0xe17, B},
    {0xe18, D},
    {0xe1c, W},
};

// 0x5d18a0 ZCamHelper::Save(ZSaveGame*): clears flag 0x40 of +4, then writes every field of the table.
static THISCALL u32 ZCamHelper_Save(u8 *self, void *sg) {
  at<u32>(self, 4) &= 0xffffffbf;
  for (const SaveField &f : kZCamSave) {
    switch (f.k) {
      case F: vcall<void>(sg, 0x4c, at<float>(self, f.off)); break;
      case B: vcall<void>(sg, 0x60, (u32)at<u8>(self, f.off)); break;
      case W: vcall<void>(sg, 0x40, (u32)at<u16>(self, f.off)); break;
      case V: vcall<void>(sg, 0x68, self + f.off); break;
      case M: vcall<void>(sg, 0x70, self + f.off); break;
      case H: vcall<void>(sg, 0x3c, at<u32>(self, f.off)); break;
      case D: vcall<void>(sg, 0x64, at<u32>(self, f.off)); break;
    }
  }
  return 1;
}
PCREG(5d18a0, ZCamHelper_Save);
