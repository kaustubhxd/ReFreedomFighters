#include "ff.h"
// batch3504.cpp - area 35 claim 4 (docs/20-unclaimed-35.md): five leaves in slice 14. Names from the GC name map (naming only).
// 0x523650 (called by InitSplineVal) is stubbed in the harness: thiscall, one argument, ret 4.

extern "C" void THISCALL ext_523650(u8 *self, u32 a1);

// 0x5f23e0, ZScriptDll::IsExportingNif() (high): byte at ([this + 0xc])+0x18 through two pointers.
static u8 THISCALL scriptDllIsExportingNif(u8 *self) {
  u8 *p = *(u8 **)(self + 0xc);
  u8 *q = *(u8 **)p;
  return q[0x18];
}
PCREG(5f23e0, scriptDllIsExportingNif);

// 0x60d820, ZRender::GetDrawBase() (high): the dword at this + 0xbd.
static u32 THISCALL renderGetDrawBase(u8 *self) {
  return *(u32 *)(self + 0xbd);
}
PCREG(60d820, renderGetDrawBase);

// 0x496320, ZGeomBuffer::BaseGeomBufferPtr() (medium): the dword at ([this + 0x14]) + 4.
static u32 THISCALL geomBufferBasePtr(u8 *self) {
  u8 *p = *(u8 **)(self + 0x14);
  return *(u32 *)(p + 4);
}
PCREG(496320, geomBufferBasePtr);

// 0x4f65e0, ZTTFONT::GetNumTextures() (medium): the dword at ([this + 0x97]) + 0x14.
static u32 THISCALL ttfontGetNumTextures(u8 *self) {
  u8 *p = *(u8 **)(self + 0x97);
  return *(u32 *)(p + 0x14);
}
PCREG(4f65e0, ttfontGetNumTextures);

// 0x513320, ZMoveOnSpline::InitSplineVal(float) (high): calls 0x523650 on the dword at this + 0x5c with the float bits.
static void THISCALL moveOnSplineInitSplineVal(u8 *self, u32 a1) {
  ext_523650(*(u8 **)(self + 0x5c), a1);
}
PCREG(513320, moveOnSplineInitSplineVal);
