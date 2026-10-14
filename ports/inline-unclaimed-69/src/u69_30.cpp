// u69_30.cpp - area 69, group 30 (slice 8). No callees.
#include "ff.h"

// 0x6168c0, thiscall with two stack args (ret 8). Sets the vtable 0x6bdda8 at self, stores the first arg at self+4 and the second at self+8, returns self.
static u8 *THISCALL ctorVt6bdda8(u8 *self, u32 a, u32 b) {
  *(u32 *)(self + 4) = a;
  *(u32 *)(self + 8) = b;
  *(u32 *)self = 0x6bdda8;
  return self;
}
PCREG(6168c0, ctorVt6bdda8);

// 0x45acc0, thiscall with one stack arg (a pointer, ret 4). Copies three dwords from src to self+0x18, self+0x1c and self+0x20.
static void THISCALL copyVec3To18(u8 *self, u8 *src) {
  *(u32 *)(self + 0x18) = *(u32 *)src;
  *(u32 *)(self + 0x1c) = *(u32 *)(src + 4);
  *(u32 *)(self + 0x20) = *(u32 *)(src + 8);
}
PCREG(45acc0, copyVec3To18);
