// batch4015.cpp - area 70 (residue 9), batch 4015: 0x45f410 (thunk into 0x4dc030) and 0x5fa590 (names GUESS).
#include "ff.h"

extern "C" u32 THISCALL ext_4dc030(void *self);            // exe: recursive scene-node walk, thiscall, plain ret; stubbed by address
extern "C" u32 THISCALL ext_5fa0d0(void *self, u32 a);     // exe: string-table name lookup, ret 4; stubbed by address

// 0x45f410 (name GUESS): thiscall, no arguments, plain ret. Tail-jumps to 0x4dc030 with ECX = [this+8], so its EAX is the
// callee's EAX.
static u32 THISCALL thunk45f410(u8 *self) {
  return ext_4dc030(*(void **)(self + 8));
}
PCREG(45f410, thunk45f410);

// 0x5fa590 (name GUESS): thiscall (ECX = this), two stack arguments (obj, arg2), ret 8. Calls slot 0x38 of this with 1,
// then 0x5fa0d0 (ECX = arg2, one stack argument), then slot 0x2c of obj with that result, then slot 0x2c of obj again with
// the dword at [this+4].
static void THISCALL call5fa590(u8 *self, u8 *obj, u8 *arg2) {
  u32 r = vcall<u32>(self, 0x38, 1u);
  u32 x = ext_5fa0d0(arg2, r);
  vcall<void>(obj, 0x2c, x);
  vcall<void>(obj, 0x2c, *(u32 *)(self + 4));
}
PCREG(5fa590, call5fa590);
