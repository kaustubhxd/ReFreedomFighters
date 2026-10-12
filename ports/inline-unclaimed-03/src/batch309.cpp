// batch309.cpp - unclaimed-03 batch 9 (docs/20-unclaimed-03.md): CCheckInsideBox::Init(ZGEOM*, DBREAD&) at 0x5b8120.
// Name from the GC name map (high). Calls: DBREAD::operator unsigned int twice (original, ext_), two calls on a global
// object's vtable slot +0xcc, one call on this+0x44's slot +0xbc. The first ZGEOM argument is not used.
#include "ff.h"

extern "C" u32 THISCALL ext_4e5e60(void *dbread);   // DBREAD::operator unsigned int(), original code (stubbed by the spec)

// 0x5b8120, CCheckInsideBox::Init(ZGEOM*, DBREAD&) (high): this+0x48 = read u32 from DBREAD; this+0x4c = read u32
// again; this+0x50 = [0x70038c]->vtbl[+0xcc](this+0x48 value); this+0x54 = [0x70038c]->vtbl[+0xcc](this+0x4c value);
// [this+0x44]->vtbl[+0xbc](1); this+0x5c = 0. Callee pops 8 (ret 8).
static void THISCALL checkInsideBoxInit(u8 *self, u32 zgeom, u32 dbread) {
  (void)zgeom;
  typedef u32(THISCALL * call1_fn)(void *, u32);
  typedef void(THISCALL * call1v_fn)(void *, u32);
  *(u32 *)(self + 0x48) = ext_4e5e60((void *)dbread);
  *(u32 *)(self + 0x4c) = ext_4e5e60((void *)dbread);
  void *m = (void *)G(u32, 0x70038c);
  *(u32 *)(self + 0x50) = ((call1_fn)(*(u32 *)(*(u32 *)m + 0xcc)))(m, *(u32 *)(self + 0x48));
  *(u32 *)(self + 0x54) = ((call1_fn)(*(u32 *)(*(u32 *)m + 0xcc)))(m, *(u32 *)(self + 0x4c));
  void *e = (void *)*(u32 *)(self + 0x44);
  ((call1v_fn)(*(u32 *)(*(u32 *)e + 0xbc)))(e, 1);
  *(u32 *)(self + 0x5c) = 0;
}
PCREG(5b8120, checkInsideBoxInit);
