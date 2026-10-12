// batch6324.cpp - unclaimed-63 gap-band batch 24 (band 0x4c1000-0x4e1000): three short functions.
//   0x4d2be0 (C-set): r = this->vtbl[+0xb0](a1, 0) (thiscall, two stack arguments, callee pops 8); returns r ? [r+8] : 0 (ret 4).
//   0x4daa00 (A+D set): if [this+0x3c] & 0x40000: return 1 (al). Else obj = [this+0x54]: if obj: return obj->vtbl[+0x60]() (tail call,
//     its al is the result, no arguments); else return 0 (al). Bool result in al (ret).
//   0x4cd1e0 (C-set): 0x4cce40(ECX = this) (thiscall, no arguments; the SEH dtor-like helper, original, stubbed); if (flags & 1):
//     0x634273(this, 0x28) (cdecl, caller cleans); return this (ret 4). The SEH frame of 0x4cce40 is not in this function.
#include "ff.h"

extern "C" void THISCALL ext_4cce40(void *self);     // original helper, stubbed by the spec
extern "C" void ext_634273(void *p, u32 size);        // cdecl, original, stubbed by the spec

typedef u32(THISCALL * call2r_fn)(void *, u32, u32);
typedef u32(THISCALL * call0_fn)(void *);

// 0x4d2be0 (C-set).
static u32 THISCALL unnamed4d2be0(u8 *self, u32 a1) {
  u32 r = ((call2r_fn)(*(u32 *)(*(u32 *)self + 0xb0)))((void *)self, a1, 0u);
  if (r != 0)
    return *(u32 *)(r + 8);
  return 0;
}
PCREG(4d2be0, unnamed4d2be0);

// 0x4daa00 (A+D set). Returns a bool in al.
static u8 THISCALL unnamed4daa00(u8 *self) {
  if ((*(u32 *)(self + 0x3c) & 0x40000u) != 0)
    return 1;
  u32 obj = *(u32 *)(self + 0x54);
  if (obj != 0)
    return (u8)((call0_fn)(*(u32 *)(*(u32 *)obj + 0x60)))((void *)obj);
  return 0;
}
PCREG(4daa00, unnamed4daa00);

// 0x4cd1e0 (C-set).
static u32 THISCALL unnamed4cd1e0(u8 *self, u32 flags) {
  ext_4cce40(self);
  if (((u8)flags & 1) != 0)
    ext_634273((void *)self, 0x28u);
  return (u32)self;
}
PCREG(4cd1e0, unnamed4cd1e0);
