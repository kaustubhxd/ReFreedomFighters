#include "ff.h"
// batch912.cpp - unclaimed-01 claim 11 (docs/20-unclaimed-01.md). ZFFPRIVATESTDOBJ::Load(ZLoadGame*) (0x5aa140, high).
// 0x45f3c0 (original code, not lifted) is called first with (this, load). The rest of the function:

extern "C" void THISCALL ext_45f3c0(u8 *self, u8 *load);

static u8 THISCALL ffPrivateStdObjLoad(u8 *self, u8 *load) {
  ext_45f3c0(self, load);
  u8 *obj = load;
  u8 *param = load;
  // slot +0x40 of obj with a pointer to the argument slot (a stack address); the load may write through it
  typedef void(THISCALL * slot_fn)(u8 *, u8 *);
  slot_fn f40 = *(slot_fn *)(*(u32 *)obj + 0x40);
  f40(obj, (u8 *)&param);
  // global object's sub-object at +0x9b: slot +0x58 with the (possibly rewritten) argument, result to this+0x1c
  u8 *g = G(u8 *, 0x70039c);
  u8 *m = *(u8 **)(g + 0x9b);
  typedef u32(THISCALL * slot58_fn)(u8 *, u8 *);
  slot58_fn f58 = *(slot58_fn *)(*(u32 *)m + 0x58);
  *(u32 *)(self + 0x1c) = f58(m, param);
  // slot +0x40 of obj with this+0x18
  f40 = *(slot_fn *)(*(u32 *)obj + 0x40);
  f40(obj, self + 0x18);
  return 1;
}
PCREG(5aa140, ffPrivateStdObjLoad);
