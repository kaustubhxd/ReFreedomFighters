// batch1906.cpp - unclaimed-66 batch 6: five slice-5 leaves (names GUESS; bodies from the bytes). Thiscall.
#include "ff.h"

// 0x4837d0, GUESS FUN_004837d0: eax = [[this+0x455]+0x10]; ret.
static u32 THISCALL leaf4837d0(u8 *self) {
  u8 *a = *(u8 **)(self + 0x455);
  return *(u32 *)(a + 0x10);
}
PCREG(4837d0, leaf4837d0);

// 0x560310, GUESS FUN_00560310: dword 0x71419c = 0; ret.
static void THISCALL leaf560310(u8 *self) {
  (void)self;
  *(u32 *)0x71419c = 0;
}
PCREG(560310, leaf560310);

// 0x4364d0, GUESS FUN_004364d0: this+4 = 0; byte this+8 = 0; returns this in EAX.
static u8 *THISCALL leaf4364d0(u8 *self) {
  *(u32 *)(self + 4) = 0;
  self[8] = 0;
  return self;
}
PCREG(4364d0, leaf4364d0);

// 0x484d10, GUESS FUN_00484d10: vtable +0x594 of this, called with argument 0; the function's own argument (ret 4) is unused.
static void THISCALL leaf484d10(u8 *self, u32 unused) {
  (void)unused;
  vcall<void>(self, 0x594, (u32)0);
}
PCREG(484d10, leaf484d10);

// 0x612150, GUESS FUN_00612150: x = [this+0x14]; ecx = [x] (the vtable of x); calls [ecx+0x30] with ecx = the vtable and
// the argument x (the callee pops it). Returns EAX of that call.
static u32 THISCALL leaf612150(u8 *self) {
  u8 *x = *(u8 **)(self + 0x14);
  u8 *vt = *(u8 **)x;
  typedef u32(THISCALL * fn_t)(void *, void *);
  fn_t fn = *(fn_t *)(vt + 0x30);
  return fn(vt, x);
}
PCREG(612150, leaf612150);
