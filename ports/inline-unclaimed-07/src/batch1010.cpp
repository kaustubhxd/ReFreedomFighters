// batch1010.cpp - unclaimed-07 batch 10 (docs/20-unclaimed-07.md, slice 6): ZFFActor::ConcealItem.
// Name from the GC name map (high). Body from the PC bytes.
#include "ff.h"

// 0x59e9e0, ZFFActor::ConcealItem(unsigned int) (high): b = (g_sys+0x9b) slot +0x58(a1); when b is 0, returns false.
// When b equals this slot +0x504(): when this slot +0x3f0() is not 6, this slot +0x45c(6, 0); returns true.
// Otherwise, when b equals this slot +0x500(): the same with 5; returns true. Otherwise the engine log (global 0x700390):
// stream = slot +0x20(0x6ae6a0, 0x366); name1 = (this slot +0x20()->+4), or 0x67c8e8 when null; p = b slot +0x2e8();
// name2 = p+4, or 0x67c8e8 when null; then the stream's cdecl slot +0x2c(stream, 0x6ae974, name2, name1); returns false.
static bool THISCALL ffActorConcealItem(u8 *self, u32 a1) {
  u8 *sys = G(u8 *, 0x70039c);
  u8 *ctl = *(u8 **)(sys + 0x9b);
  u32 b = vcall<u32>(ctl, 0x58, a1);
  if (!b)
    return false;
  if (b == vcall<u32>(self, 0x504)) {
    if (vcall<u32>(self, 0x3f0) != 6)
      vcall<void>(self, 0x45c, 6u, 0u);
    return true;
  }
  if (b == vcall<u32>(self, 0x500)) {
    if (vcall<u32>(self, 0x3f0) != 5)
      vcall<void>(self, 0x45c, 5u, 0u);
    return true;
  }
  void *logger = *(void **)0x700390;
  void *stream = vcall<void *>(logger, 0x20, 0x6ae6a0u, 0x366u);
  u32 q = vcall<u32>(self, 0x20);
  u32 name1 = *(u32 *)(q + 4) ? *(u32 *)(q + 4) : 0x67c8e8u;
  u32 p = vcall<u32>((void *)b, 0x2e8);
  u32 name2 = *(u32 *)(p + 4) ? *(u32 *)(p + 4) : 0x67c8e8u;
  typedef void(__attribute__((cdecl)) * printf_t)(void *, u32, u32, u32);
  (*(printf_t *)(*(u8 **)stream + 0x2c))(stream, 0x6ae974u, name2, name1);
  return false;
}
PCREG(59e9e0, ffActorConcealItem);
