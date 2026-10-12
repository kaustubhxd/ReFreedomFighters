// batch2429.cpp - decomp area 24, batch 2429.
#include "ff.h"

extern "C" void THISCALL ext_63e310(void *alloc, u32 offset, u32 size);  // ZOffsetAllocPointerSort::Free, ret 8
extern "C" u32 THISCALL ext_45e420(void *obj, s32 idx);                  // the target of ZGEOM::GetChunkData

// 0x63e5f0 ZDrawBase::Free(void*, int), thiscall, ret 8: the size is rounded up to 16 and the pointer is made relative
// to the base at +0x64, then the allocator at +0x60 frees it.
static void THISCALL drawBaseFree(u8 *self, u32 ptr, s32 size) {
  u32 rounded = ((u32)size + 0xfu) & 0xfffffff0u;
  u32 offset = ptr - *(u32 *)(self + 0x64);
  ext_63e310(*(void **)(self + 0x60), offset, rounded);
}
PCREG(63e5f0, drawBaseFree);

// 0x45ed70 ZGEOM::GetChunkData(int) const, thiscall, ret 4.
static u32 THISCALL geomGetChunkData(u8 *self, s32 idx) {
  u8 *p = *(u8 **)(self + 0x10);
  if (p) {
    u8 *q = *(u8 **)(p + 0xc);
    if (q)
      return ext_45e420(q, idx);
  }
  return 0;
}
PCREG(45ed70, geomGetChunkData);

// 0x499bf0 (GUESS owner), thiscall, ret 4: slot 0x10 with (argument, 0x24), returns this.
static u8 *THISCALL callSlot10ReturnThis(u8 *self, u32 arg) {
  vcall<void>(self, 0x10, arg, 0x24u);
  return self;
}
PCREG(499bf0, callSlot10ReturnThis);
