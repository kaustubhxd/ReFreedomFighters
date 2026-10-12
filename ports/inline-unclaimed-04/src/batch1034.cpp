// batch1034.cpp - unclaimed-04 batch 34 (docs/20-unclaimed-04.md): two slice-3 functions (GUESS labels).
#include "ff.h"

typedef u32(THISCALL *thiscall2_t)(void *self, u32 a, u32 b);
typedef void(THISCALL *thiscall0_t)(void *self);
typedef u32(__attribute__((cdecl)) *cdecl3_t)(u32 a, u32 b, u32 c);

static inline u32 vslot(void *o, u32 off) {
  return *(u32 *)(*(u32 *)o + off);
}

extern "C" void THISCALL ext_64dd20(void *self);  // hooked by address in the spec (GUESS)

// 0x64b070: when the byte at +0x10028 is set, call 0x64dd20, then obj(+0x1005d)->vt[0x24](ptr(+0x10071), 0x4000), then clear.
static void THISCALL unk64b070(u8 *self) {
  if (self[0x10028] == 0) return;
  ext_64dd20(self);
  u8 *obj = *(u8 **)(self + 0x1005d);
  ((thiscall2_t)vslot(obj, 0x24))(obj, *(u32 *)(self + 0x10071), 0x4000);
  *(u32 *)(self + 0x10071) = 0;
  self[0x10028] = 0;
}
PCREG(64b070, unk64b070);

// 0x605570: the logger (see 0x5f94f0): L = obj->vt[0x20](0x6b9bc8, 0x27); L->vt[0x2c](L, 0x69c6b0, 0x6b97ac) (cdecl);
// the callback global 0x7003b0, when non-zero, is called; returns 0.
static u32 __attribute__((cdecl)) unk605570Logger(void) {
  u8 *obj = *(u8 **)0x700390;
  u32 l = ((thiscall2_t)vslot(obj, 0x20))(obj, 0x6b9bc8, 0x27);
  ((cdecl3_t)vslot((void *)l, 0x2c))(l, 0x69c6b0, 0x6b97ac);
  void (*cb)(void) = (void (*)(void)) * (u32 *)0x7003b0;
  if (cb) cb();
  return 0;
}
PCREG(605570, unk605570Logger);
