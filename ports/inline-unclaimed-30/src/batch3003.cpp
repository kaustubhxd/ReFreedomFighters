// batch3003.cpp - unclaimed-30: batch 3 (docs/20-unclaimed-30.md, claim 1). ZOffsetAlloc::ZOffsetAlloc(a1, a2, cap) [map
// 0x4ccdd0; thiscall, ret 0xc]. The vtable is 0x695b78; the entry buffer is new(cap * 8) (all ones on overflow); the first
// entry is (a1, a2 - a1), and the count becomes 1. When a2 <= a1 the exe calls the assert hook at 0x7003b0 (int3 when no
// hook is set); the port does the same.
#include "ff.h"

extern "C" void *ext_41e290(u32 size);   // operator new (the exe's allocator path)

static u8 *THISCALL offsetAllocCtor(u8 *self, u32 a1, u32 a2, u32 cap) {
  *(u32 *)(self + 0xc) = cap;
  *(u32 *)self = 0x695b78u;
  u64 bytes = (u64)cap * 8u;
  u32 size = (u32)(bytes >> 32) ? 0xffffffffu : (u32)bytes;
  u8 *buf = (u8 *)ext_41e290(size);
  *(u8 **)(self + 4) = buf;
  *(u32 *)(self + 8) = 0;
  if (!(a2 > a1)) {
    typedef void (*hookfn)();
    hookfn h = G(hookfn, 0x7003b0);
    if (h) h();
    else __builtin_debugtrap();
  }
  u32 idx = *(u32 *)(self + 8);
  u8 *ent = buf + (u32)idx * 8;
  *(u32 *)(self + 8) = idx + 1;
  *(u32 *)(ent + 4) = a2 - a1;
  *(u32 *)ent = a1;
  return self;
}
PCREG(4ccdd0, offsetAllocCtor);
