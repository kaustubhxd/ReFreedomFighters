// batch920.cpp - residue-9 slice, two bodies read in full.
//  0x53b690 [thiscall (ECX = this), one stack arg (a flag byte), ret 4, returns this]: vtable 0x6a2b6c at this; 0x53b710 on this (no args);
//           0x4ccf60 on this+0x19 (no args); if bit 0 of the flag is set, 0x634273 (cdecl: this, 0x120a; the caller pops 8).
//  0x631810 [cdecl, three stack args (the first unused), returns a block pointer]: size = a * b (32-bit); block = 0x63a720 (cdecl, size; the caller does
//           not pop, the later cleanup removes it); 0x634d10 (cdecl: block, 0, b, size; the caller pops 0x10).
// Stood in: 0x53b710, 0x4ccf60, 0x634273, 0x63a720, 0x634d10 (none of their bodies is read here).
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_53b710(void *self);       // stood in
extern "C" void THISCALL ext_4ccf60(void *self);       // stood in
extern "C" void ext_634273(void *obj, u32 n);          // stood in (cdecl)
extern "C" void *ext_63a720(u32 size);                 // stood in (cdecl)
extern "C" void ext_634d10(void *blk, u32 zero, u32 b, u32 size);   // stood in (cdecl, four words)

// 0x53b690 (no name in the map).
static u8 *THISCALL Init53b690(u8 *self, u32 flag) {
  U32(self, 0) = 0x6a2b6cu;
  ext_53b710(self);
  ext_4ccf60(self + 0x19);
  if (flag & 1u) ext_634273(self, 0x120au);
  return self;
}
PCREG(53b690, Init53b690);

// 0x631810 (no name in the map).
u8 *Alloc631810(u32 unused, u32 a, u32 b) {   // [ebp+8] is not read by the exe
  (void)unused;
  u32 size = a * b;
  u8 *blk = (u8 *)ext_63a720(size);
  ext_634d10(blk, 0u, b, size);
  return blk;
}
PCREG(631810, Alloc631810);
