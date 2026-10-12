// batch6306.cpp - unclaimed-63 batch 6 (docs/20-unclaimed-63.md): CRagdoll2::~CRagdoll2() at 0x640f20 (GC name, medium).
// Two paths on the flags byte f. If f & 2 (array): 0x63418c(this, 0x1df, [this-4], 0x640e80) (stdcall, callee pops 16); if f & 1:
// 0x634273(this-4, [this-4]*0x1df + 4) (cdecl); returns this-4. Otherwise: this->vptr = 0x6c281c; if [this+0x17f] is set, its
// vtbl[+4](1) (thiscall); if f & 1: 0x634273(this, 0x1df) (cdecl); returns this.
// The SEH frame of the PC (fs:[0], handler 0x667420, cookie) is NOT reproduced; no exception is raised on these paths.
// This file is in the claim folder only. The ragdoll source files were not read or edited for this batch.
#include "ff.h"

extern "C" void STDCALL ext_63418c(void *self, u32 size, u32 count, u32 fn);  // original, stubbed by the spec
extern "C" void ext_634273(void *p, u32 size);                                 // cdecl, original, stubbed by the spec

typedef void(THISCALL * call1_fn)(void *, u32);

// 0x640f20, CRagdoll2::~CRagdoll2() (medium). Returns this (ret 4); the array path returns this-4.
static u32 THISCALL ragdoll2Dtor(u8 *self, u32 flags) {
  u8 f = (u8)flags;
  if (f & 2) {
    ext_63418c(self, 0x1df, *(u32 *)(self - 4), 0x640e80);
    if (f & 1)
      ext_634273(self - 4, *(u32 *)(self - 4) * 0x1df + 4);
    return (u32)(self - 4);
  }
  *(u32 *)self = 0x6c281c;
  u32 o = *(u32 *)(self + 0x17f);
  if (o != 0)
    ((call1_fn)(*(u32 *)(*(u32 *)o + 4)))((void *)o, 1);
  if (f & 1)
    ext_634273(self, 0x1df);
  return (u32)self;
}
PCREG(640f20, ragdoll2Dtor);
