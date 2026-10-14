// u18_08.cpp - area 18, group 8 (unclaimed-18 thread).
#include "ff.h"

extern "C" void THISCALL ext_4f9c60(void *self, const void *src);  // ZCONTROL::CopyData (original code; hooked in spec)

// 0x661bd0, ZCollisionGC::CreateSubStripId(out, src, orBits) (GC map medium). Stdcall, three stack args (ret 0xc); the
// `this` pointer is not used. out[0] = src[0] | orBits, out[1] = src[1].
static void STDCALL createSubStripId(u32 *out, const u32 *src, u32 orBits) {
  out[0] = src[0] | orBits;
  out[1] = src[1];
}
PCREG(661bd0, createSubStripId);

// 0x4f7dd0, ZSlider::CopyData(const ZGEOM*) (GC map high). thiscall, one stack arg (ret 4). Base copy first (ZCONTROL::
// CopyData), then the dword at +0x97 is copied from the source.
static void THISCALL sliderCopyData(u8 *self, const u8 *src) {
  ext_4f9c60(self, src);
  *(u32 *)(self + 0x97) = *(const u32 *)(src + 0x97);
}
PCREG(4f7dd0, sliderCopyData);

// 0x4fa350, ZCONTROL::OnFocusLost(unsigned int) (GC map medium). thiscall, one stack arg (ret 4); returns 0 in AL. Unless
// the flag byte at +0x6c has bit 1 set, slot 0x2ec of the object is called with 8.
static bool THISCALL controlOnFocusLost(u8 *self, u32 unused) {
  (void)unused;
  if (!(self[0x6c] & 2))
    vcall<u32>(self, 0x2ec, 8u);
  return false;
}
PCREG(4fa350, controlOnFocusLost);

// 0x4cf3d0, REFTAB::RunPrevRef(RefRun*) (GC map high). thiscall, one stack arg (ret 4). Slot 0x74 of this, with the
// run record, gives a pointer; when it is null the result is 0, otherwise the dword it points to.
static u32 THISCALL refTabRunPrevRef(u8 *self, u8 *run) {
  u32 p = vcall<u32>(self, 0x74, run);
  if (p == 0)
    return 0;
  return *(u32 *)p;
}
PCREG(4cf3d0, refTabRunPrevRef);
