// batch1925.cpp - unclaimed-66 batch 25: two scalar deleting destructors (GUESS names). Thiscall with a flag argument, ret 4, return this.
// Original: [this] = a vtable; if flag bit 0 is set (and the test is taken), free(this, size) through 0x634273 (cdecl). The spec keeps
// bit 0 clear, so the free is a documented gap.
#include "ff.h"

extern "C" void ext_634273(void *self, u32 size);  // cdecl CRT free(ptr, size)

// 0x608150: vtable 0x6bc88c; free size 0x14.
static u8 *THISCALL dtorA(u8 *self, u32 flags) {
  *(u32 *)self = 0x6bc88c;
  if (flags & 1) ext_634273(self, 0x14);
  return self;
}
PCREG(608150, dtorA);

// 0x616b10: vtable 0x6bdc38; free size 4.
static u8 *THISCALL dtorB(u8 *self, u32 flags) {
  *(u32 *)self = 0x6bdc38;
  if (flags & 1) ext_634273(self, 4);
  return self;
}
PCREG(616b10, dtorB);
