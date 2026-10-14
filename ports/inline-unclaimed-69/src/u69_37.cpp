// u69_37.cpp - area 69, group 37 (slice 8). No callees.
#include "ff.h"

// 0x4ede80, ZColiTreeCompiled::Init(void*) (GC map high). thiscall, one stack arg (ret 4). Copies src[0], src[4], src[8], src[0xc] to self[0], self[4], self[8], self[0xc] and src[0] (the pointer to the source) to self[0x10]. Returns the last value loaded, src[8].
static u32 THISCALL initFromCompiled4ede80(u8 *self, u8 *src) {
  *(u32 *)(self + 0x10) = (u32)src;
  *(u32 *)(self + 0xc) = *(u32 *)(src + 0xc);
  *(u32 *)self = *(u32 *)src;
  *(u32 *)(self + 4) = *(u32 *)(src + 4);
  u32 v8 = *(u32 *)(src + 8);
  *(u32 *)(self + 8) = v8;
  return v8;
}
PCREG(4ede80, initFromCompiled4ede80);
