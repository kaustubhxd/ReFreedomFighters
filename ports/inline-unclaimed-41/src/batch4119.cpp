// batch4119.cpp - unclaimed-41 batch 19 (slice 13): 0x4c5c50 ZFollowShape::Load(ZLoadGame*) (vtable).
#include "ff.h"

extern "C" void THISCALL ext_4c79f0(u8 *self, u32 zero);   // base Load, one stack argument, callee pops (checksum stub, GUESS)

typedef void(THISCALL * slot_t)(u8 *, u32);

// 0x4c5c50: thiscall, one stack argument (the load object o, ret 4); returns true (al = 1).
//   self.flags(+4) &= ~0x40; the error hook (0x7003b0, must be non-zero); ext_4c79f0(self, 0) (stub, GUESS);
//   then o.vt[+0x48](self+0x5a), o.vt[+0x68](self+0x66), o.vt[+0x48](self+0x67), o.vt[+0x58](self+0x4c).
//   Each vtable call is thiscall with ecx = o and one stack argument; the callee pops it (plain ret 4 in the exe).
static u8 THISCALL fn4c5c50(u8 *self, u8 *o) {
  *(u32 *)(self + 4) &= ~0x40u;
  void (*hook)(void) = (void (*)(void))G(u32, 0x7003b0);
  hook();
  ext_4c79f0(self, 0);
  (*(slot_t *)(*(u32 *)o + 0x48))(o, (u32)(self + 0x5a));
  (*(slot_t *)(*(u32 *)o + 0x68))(o, (u32)(self + 0x66));
  (*(slot_t *)(*(u32 *)o + 0x48))(o, (u32)(self + 0x67));
  (*(slot_t *)(*(u32 *)o + 0x58))(o, (u32)(self + 0x4c));
  return 1;
}
PCREG(4c5c50, fn4c5c50);
