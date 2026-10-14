// batch823.cpp - animation layer thread, batch 823: ZLNKOBJ bone-matrix setup and teardown.
#include "ff.h"

#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void *ext_41e290(u32 size);                        // operator new (cdecl)
extern "C" void ext_634273(void *p, u32 size);                // operator delete (cdecl, sized)
extern "C" void ext_634d10(void *d, int v, u32 n);            // memset (cdecl)

static inline void *defsMgr() { return FP(FP(G(void *, 0x70039c), 0x1aa3), 0x18); }

// ZLNKOBJ::CloseObjMatBone() [high]. thiscall, no args. The per-bone list (+0x18) is walked with its
// iterator: every entry's extra object (+0x70) is deleted (its deleting destructor with flag 1), then the list itself
// is deleted. The bone-anim table (+0x1c, 0x18 bytes per bone) is freed, and the modifier at +0x6c gets its deleting
// destructor (flag 1). Both pointers are cleared.
static void THISCALL CloseObjMatBone(u8 *self) {
  if (FP(self, 0x18)) {
    u8 it[12];
    vcall<void>(FP(self, 0x18), 0x4c, it);
    void *n = vcall<void *>(FP(self, 0x18), 0x64, it);
    while (n) {
      void *x = FP(n, 0x70);
      if (x) {
        vcall<void>(x, 0, 1);
        FP(n, 0x70) = 0;
      }
      n = vcall<void *>(FP(self, 0x18), 0x64, it);
    }
    void *l = FP(self, 0x18);
    if (l) vcall<void>(l, 0, 1);
    FP(self, 0x18) = 0;
  }
  if (FP(self, 0x1c)) ext_634273(FP(self, 0x1c), 0x18);
  void *m = FP(self, 0x6c);
  if (m) vcall<void>(m, 0x2c, 1);
  FP(self, 0x6c) = 0;
  FP(self, 0x1c) = 0;
}
PCREG(461f00, CloseObjMatBone);

// ZLNKOBJ::InitObjMatBone() [high]. thiscall, no args. The bone count comes from the geometry definition
// (vt 0xb0 of the definitions manager), the bone modifier from vt 0x8c(count), the table is zeroed (count * 0x18),
// then the modifier is told about this object (vt 0x58) and the object's bone definitions are loaded (vt 0x284).
// A count that would overflow gives 0xffffffff for the allocation (operator new then fails as the exe does).
static void THISCALL InitObjMatBone(u8 *self) {
  void *geom = FP(self, 8);
  u32 gid = F32(geom, 0x6c);
  F32(self, 0x20) = vcall<u32>(defsMgr(), 0xb0, gid);
  // the modifier comes from the manager itself (the exe loads it without the +0x18 step)
  void *mgr = FP(G(void *, 0x70039c), 0x1aa3);
  void *mod = vcall<void *>(mgr, 0x8c, F32(self, 0x20));
  FP(self, 0x6c) = mod;
  u32 count = F32(self, 0x20);
  u64 bytes = (u64)count * 0x18;
  u32 sz = bytes > 0xffffffffULL ? 0xffffffffu : (u32)bytes;
  FP(self, 0x1c) = ext_41e290(sz);
  ext_634d10(FP(self, 0x1c), 0, (u32)count * 0x18);
  void *esi = vcall<void *>(FP(self, 0x6c), 0x58, self);
  void *defs = vcall<void *>(self, 0x2cc);
  vcall<void>(self, 0x284, esi, defs);
}
PCREG(463430, InitObjMatBone);
