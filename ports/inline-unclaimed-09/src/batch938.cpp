// batch938.cpp - unclaimed-09 batch 30: ZOnScreenDisplay::ClassInit() (core list; docs/20-unclaimed-09.md, claim 32).
// thiscall, no arguments, plain ret. Calls go through the engine object and a result object (GUESS recording stubs).
#include "ff.h"

typedef u8 *(THISCALL *GetObj)(u8 *self);            // M.vt[0x138]
typedef u32(THISCALL *Get4c)(u8 *self, u32 a, u32 b); // M.vt[0x4c](this, 0x10)
typedef void(THISCALL *Set60)(u8 *self, u32 k, u32 v); // r.vt[0x60](K, v)

static u32 slot(u8 *obj, u32 off) {
  return *(u32 *)(*(u32 *)obj + off);
}

// 0x5a64c0, ZOnScreenDisplay::ClassInit() (list name): picks a constant K from this+0x360 (2, 3, 4 or other); r = M.vt[0x138]()
// with M = global+0x9b; reads r's vtable word; v = M.vt[0x4c](this, 0x10); then r.vt[0x60](K, v).
static void THISCALL onScreenClassInit(u8 *self) {
  u32 mode = *(u32 *)(self + 0x360);
  u32 k = 0x6a6700;
  if (mode == 2) k = 0x6a6710;
  else if (mode == 3) k = 0x6a6720;
  else if (mode == 4) k = 0x6a6730;
  u8 *m = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *r = ((GetObj)slot(m, 0x138))(m);
  u32 vtr = *(u32 *)r;
  u32 v = ((Get4c)slot(m, 0x4c))(m, (u32)self, 0x10);
  ((Set60)(*(u32 *)(vtr + 0x60)))(r, k, v);
}
PCREG(5a64c0, onScreenClassInit);
