// batch2436.cpp - decomp area 24, batch 2436 (slice 11 leaves).
#include "ff.h"

extern "C" void THISCALL ext_4dc630(void *self, u32 a, u32 b);  // ZBaseGeom::SetControl(unsigned int, unsigned int)

// 0x59a570 ZGameOSD::InvalidateView(), thiscall, plain ret. The target of the jump at +0x1d0f gets +0x368 = 0.
static void THISCALL gameOSDInvalidateView(u8 *self) {
  u8 *o = *(u8 **)(self + 0x1d0f);
  if (o)
    *(u32 *)(o + 0x368) = 0;
}
PCREG(59a570, gameOSDInvalidateView);

// 0x5f2ef0 LoadSerialInfo_t::loadint16(short&), thiscall, ret 4: slot 0x4c of the object at +0x15 with the same argument.
static void THISCALL loadSerialInfoLoadInt16(u8 *self, void *ref) {
  vcall<void>(*(void **)(self + 0x15), 0x4c, ref);
}
PCREG(5f2ef0, loadSerialInfoLoadInt16);

// 0x5f32b0 SaveSerialInfo_t::saveuint16(unsigned short), thiscall, ret 4: slot 0x40 of the object at +0x15.
static void THISCALL saveSerialInfoSaveUInt16(u8 *self, u32 v) {
  vcall<void>(*(void **)(self + 0x15), 0x40, v);
}
PCREG(5f32b0, saveSerialInfoSaveUInt16);

// 0x43e0f0 ZSTDOBJ::ClassInit(), thiscall, plain ret.
static void THISCALL stdObjClassInit(u8 *self) {
  u8 *g = *(u8 **)(self + 8);
  if (*(u32 *)(g + 0x3c) & 0x40000000u)
    ext_4dc630(g, 0x2000000u, 0u);
}
PCREG(43e0f0, stdObjClassInit);
