// batch1927.cpp - unclaimed-66 batch 27 (gap band, GUESS names). Thiscall. The CRT free 0x634273 is cdecl (ptr, size).
#include "ff.h"

extern "C" void ext_634273(void *self, u32 size);   // cdecl CRT free
extern "C" void THISCALL ext_500a10(void *self);   // the base destructor: GUESS stub in the spec (hooked by address); not read

// 0x509780, GUESS FUN_00509780: [this] = 0x69c968; if flag bit 0: free(this, 0x10); returns this.
static u8 *THISCALL scalarDtorA(u8 *self, u32 flags) {
  *(u32 *)self = 0x69c968;
  if (flags & 1) ext_634273(self, 0x10);
  return self;
}
PCREG(509780, scalarDtorA);

// 0x5048a0, GUESS FUN_005048a0: [this] = 0x69cc88; the base 0x500a10 (GUESS stub); if flag bit 0: free(this, 0x18); returns this.
static u8 *THISCALL scalarDtorB(u8 *self, u32 flags) {
  *(u32 *)self = 0x69cc88;
  ext_500a10(self);
  if (flags & 1) ext_634273(self, 0x18);
  return self;
}
PCREG(5048a0, scalarDtorB);

// 0x5144a0, GUESS FUN_005144a0 (lazy getter): if [this+0x1d1] == 0, store vtable +0x2e8 of this with [this+0x1cd] there; return it.
static u32 THISCALL lazyGetter(u8 *self) {
  if (*(u32 *)(self + 0x1d1) == 0) {
    *(u32 *)(self + 0x1d1) = vcall<u32>(self, 0x2e8, *(u32 *)(self + 0x1cd));
  }
  return *(u32 *)(self + 0x1d1);
}
PCREG(5144a0, lazyGetter);
