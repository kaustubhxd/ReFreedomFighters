// batch2439.cpp - decomp area 24, batch 2439 (gap band): five tail-jump forwarders.
#include "ff.h"

extern "C" void THISCALL ext_4db930(void *self, u32 on);           // ZBaseGeom::HideRecursive(bool), ret 4
extern "C" void THISCALL ext_4dceb0(void *self, const float *pos);  // ZBaseGeom::SetRootPos, ret 4
extern "C" void THISCALL ext_4dcf80(void *self, const float *a, const float *b);  // ZBaseGeom::SetRootTM, ret 8
extern "C" u32 THISCALL ext_43f900(void *self, void *dblk);         // ZGROUP::CopyDataBlock(DBLK*), ret 4

// 0x45f080 ZGEOM::HideRecursive(bool), thiscall, ret 4: forwards to the object at +8.
static void THISCALL geomHideRecursive(u8 *self, u32 on) {
  ext_4db930(*(void **)(self + 8), on);
}
PCREG(45f080, geomHideRecursive);

// 0x45fd30 ZGEOM::SetRootPos(const float*), thiscall, ret 4: forwards to the object at +8.
static void THISCALL geomSetRootPos(u8 *self, const float *pos) {
  ext_4dceb0(*(void **)(self + 8), pos);
}
PCREG(45fd30, geomSetRootPos);

// 0x45fd40 ZGEOM::SetRootTM(const float*, const float*), thiscall, ret 8: forwards to the object at +8.
static void THISCALL geomSetRootTM(u8 *self, const float *a, const float *b) {
  ext_4dcf80(*(void **)(self + 8), a, b);
}
PCREG(45fd40, geomSetRootTM);

// 0x454910 ZTemplate::CopyDataBlock(DBLK*), thiscall, ret 4: tail jump to ZGROUP::CopyDataBlock on the same object.
static u32 THISCALL templateCopyDataBlock(u8 *self, void *dblk) {
  return ext_43f900(self, dblk);
}
PCREG(454910, templateCopyDataBlock);

// 0x454b50 ZMaterialDescGroup::AddMaterialDescriptor(ZMaterialDesc*), thiscall, ret 4: slot 4 of the object at +0x5c.
static void THISCALL materialGroupAddDescriptor(u8 *self, void *desc) {
  vcall<void>(*(void **)(self + 0x5c), 4, desc);
}
PCREG(454b50, materialGroupAddDescriptor);
