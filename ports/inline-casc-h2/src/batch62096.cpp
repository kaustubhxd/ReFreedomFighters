#include "ff.h"
extern "C" s32 THISCALL ext_63b710(u8 *allocator, u32 aligned_size);
static u32 THISCALL fn63b7e0(u8 *self, u32 request) {
  u32 aligned = (request + 0xf) & ~0xfu;
  ++*(u32 *)(self + 8);
  *(u32 *)(self + 0xc) += aligned;
  s32 offset = ext_63b710((u8 *)*(u32 *)(self + 0x60), aligned);
  if (offset == -1) {
    u8 *global = (u8 *)*(u32 *)0x700390;
    u32 object = vcall<u32>(global, 0x20, 0x6c265c, 0xc7);
    vcall<void>((void *)object, 0x2c, 0x6c2684, object);
    return 0;
  }
  return *(u32 *)(self + 0x64) + (u32)offset;
}
PCREG(63b7e0, fn63b7e0);
