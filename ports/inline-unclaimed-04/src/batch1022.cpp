// batch1022.cpp - unclaimed-04 batch 23 (docs/20-unclaimed-04.md): three slice-3 scalar deleting destructors (GUESS labels).
#include "ff.h"

extern "C" void THISCALL ext_6012e0(void *self);  // base destructor, original code
extern "C" void THISCALL ext_6035a0(void *self);  // base destructor, original code
extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 size);  // delete with size, original code (hooked)

// 0x42acf0: vtable 0x679754, then free (size 0x12) when flag bit 0 is set; returns this.
static u8 *THISCALL unk42acf0Dtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x679754;
  if (flags & 1) ext_634273(self, 0x12);
  return self;
}
PCREG(42acf0, unk42acf0Dtor);

// 0x5f1430: base destructor 0x6012e0, then free (size 0x10) when flag bit 0 is set; returns this.
static u8 *THISCALL unk5f1430Dtor(u8 *self, u32 flags) {
  ext_6012e0(self);
  if (flags & 1) ext_634273(self, 0x10);
  return self;
}
PCREG(5f1430, unk5f1430Dtor);

// 0x601470: base destructor 0x6035a0, then free (size 0x2a) when flag bit 0 is set; returns this.
static u8 *THISCALL unk601470Dtor(u8 *self, u32 flags) {
  ext_6035a0(self);
  if (flags & 1) ext_634273(self, 0x2a);
  return self;
}
PCREG(601470, unk601470Dtor);
