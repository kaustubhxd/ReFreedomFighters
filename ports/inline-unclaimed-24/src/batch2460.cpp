// batch2460.cpp - decomp area 24, batch 2460 (gap band).
#include "ff.h"

extern "C" void THISCALL ext_45d5b0(void *self, const void *src);    // ZGEOM::CopyData, ret 4
extern "C" void THISCALL ext_43f8c0(void *self, const void *src);    // ZGROUP::CopyData, ret 4
extern "C" s32 THISCALL ext_44d200(void *self, u32 geom, u32 flag);  // ZBoneParticle::FindParticles(ZBaseGeom*, unsigned int)

// 0x45b180 ZBoxPrimitive::CopyData(const ZGEOM*), thiscall, ret 4.
static void THISCALL boxPrimitiveCopyData(u8 *self, const u8 *src) {
  ext_45d5b0(self, src);
  *(u32 *)(self + 0x18) = *(const u32 *)(src + 0x18);
  *(u32 *)(self + 0x1c) = *(const u32 *)(src + 0x1c);
  *(u32 *)(self + 0x20) = *(const u32 *)(src + 0x20);
  vcall<void>(self, 0xb4, 1u);
}
PCREG(45b180, boxPrimitiveCopyData);

// 0x454870 ZInstance::CopyData(const ZGEOM*), thiscall, ret 4.
static void THISCALL instanceCopyData(u8 *self, const u8 *src) {
  ext_43f8c0(self, src);
  u8 r = vcall<u8>((void *)src, 0x1e0, 0x1000eau);
  if (r != 0)
    *(u32 *)(self + 0x5c) = *(const u32 *)(src + 0x5c);
}
PCREG(454870, instanceCopyData);

// 0x44d320 ZBoneParticle::OwnerDraw(7 dwords), thiscall, ret 28.
static void THISCALL boneParticleOwnerDraw(u8 *self, u32 a8, u32 a0c, u32 a10, u32 a14, u32 a18, u32 a1c, u32 a20) {
  (void)a20;
  s32 idx = ext_44d200(self, a8, a0c);
  if (idx != -1)
    vcall<void>(self, 0x214, (u32)idx, a8, a10, a14, a18, a1c);
}
PCREG(44d320, boneParticleOwnerDraw);
