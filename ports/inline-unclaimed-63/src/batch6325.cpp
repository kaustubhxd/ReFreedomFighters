// batch6325.cpp - unclaimed-63 gap-band batch 25 (band 0x4c1000-0x4e1000). Four functions:
//   0x4cd430 (C-set): [this] = 0x695b78; 0x634273([this+4], 8) (cdecl); if flags & 1: 0x634273(this, 0x10); returns this (ret 4).
//   0x4d8580 (C-set): [this] = 0x696c14; 0x4cbec0(ECX = this+0x84); 0x4cbec0(ECX = this+4); if flags & 1: 0x634273(this, 0x104);
//     returns this (ret 4).
//   0x4d85c0 (C-set): the same as 0x4d8580 with size 0x108.
//   0x4dc1a0 (A+D+E set): and [this+0x3c] with ~0x40000000; [this+0x5c] (word) = 0; eax = [[this+0x54]+0xc]+0x23 if [this+0x54] is set,
//     else 0x200002; if eax & 0x100000: for each child c of [this+0x54]+0x50 (next at +0x60): recurse on c. Returns nothing.
// 0x4cbec0 and 0x634273 are original code, stubbed by the spec.
#include "ff.h"

extern "C" void THISCALL ext_4cbec0(void *self);   // original, stubbed by the spec
extern "C" void ext_634273(void *p, u32 size);       // cdecl, original, stubbed by the spec

// 0x4cd430 (C-set).
static u8 *THISCALL unnamed4cd430(u8 *self, u32 flags) {
  *(u32 *)self = 0x695b78u;
  ext_634273((void *)*(u32 *)(self + 4), 8u);
  if (((u8)flags & 1) != 0)
    ext_634273((void *)self, 0x10u);
  return self;
}
PCREG(4cd430, unnamed4cd430);

// 0x4d8580 (C-set).
static u8 *THISCALL unnamed4d8580(u8 *self, u32 flags) {
  *(u32 *)self = 0x696c14u;
  ext_4cbec0((void *)(self + 0x84));
  ext_4cbec0((void *)(self + 4));
  if (((u8)flags & 1) != 0)
    ext_634273((void *)self, 0x104u);
  return self;
}
PCREG(4d8580, unnamed4d8580);

// 0x4d85c0 (C-set).
static u8 *THISCALL unnamed4d85c0(u8 *self, u32 flags) {
  *(u32 *)self = 0x696c14u;
  ext_4cbec0((void *)(self + 0x84));
  ext_4cbec0((void *)(self + 4));
  if (((u8)flags & 1) != 0)
    ext_634273((void *)self, 0x108u);
  return self;
}
PCREG(4d85c0, unnamed4d85c0);

// 0x4dc1a0 (A+D+E set): a recursive walk over the children of [this+0x54]+0x50 when the flag 0x100000 is set.
static void THISCALL unnamed4dc1a0(u8 *self) {
  *(u32 *)(self + 0x3c) &= 0xbfffffffu;
  *(u16 *)(self + 0x5c) = 0;
  u32 first = *(u32 *)(self + 0x54);
  u32 eax;
  if (first != 0)
    eax = *(u32 *)(*(u32 *)(first + 0xc) + 0x23);
  else
    eax = 0x200002u;
  if ((eax & 0x100000u) != 0) {
    u32 c = (first != 0) ? *(u32 *)(first + 0x50) : 0u;
    while (c != 0) {
      unnamed4dc1a0((u8 *)c);
      c = *(u32 *)(c + 0x60);
    }
  }
}
PCREG(4dc1a0, unnamed4dc1a0);
