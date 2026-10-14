// u69_04.cpp - area 69, group 4 (unclaimed-69 thread): CLensFlare::CopyData (GC map high).
#include "ff.h"

extern "C" void *ext_634d2e(void *inptr, s32 vfDelta, void *srcType, void *targetType, s32 isReference);  // __RTDynamicCast
// (cdecl, five stack arguments; C runtime, stubbed in the spec: GUESS)

// 0x5d5e50, CLensFlare::CopyData(ZEventBase*) (GC map high). thiscall, one stack arg (ret 4). The event is cast to the
// lens-flare class (__RTDynamicCast with the two type descriptors 0x6fab7c and 0x6f6df8), and six fields are copied from it:
// dwords at +0x48, +0x54, +0x58, +0x62, +0x66 and the unaligned dword at +0x5e.
static void THISCALL lensFlareCopyData(u8 *self, u8 *ev) {
  u8 *src = (u8 *)ext_634d2e(ev, 0, (void *)0x6f6df8, (void *)0x6fab7c, 0);
  *(u32 *)(self + 0x48) = *(u32 *)(src + 0x48);
  *(u32 *)(self + 0x54) = *(u32 *)(src + 0x54);
  *(u32 *)(self + 0x58) = *(u32 *)(src + 0x58);
  *(u32 *)(self + 0x5e) = *(u32 *)(src + 0x5e);
  *(u32 *)(self + 0x62) = *(u32 *)(src + 0x62);
  *(u32 *)(self + 0x66) = *(u32 *)(src + 0x66);
}
PCREG(5d5e50, lensFlareCopyData);
