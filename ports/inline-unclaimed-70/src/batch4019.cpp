// batch4019.cpp - area 70 (slice 4/5), batch 4019: three small functions (names GUESS).
#include "ff.h"

extern "C" u32 *THISCALL ext_5003d0(void *list, u32 idx);            // exe: bounded element accessor, ret 4
extern "C" void THISCALL ext_5e0e10(void *self, u32 a, u32 b);       // exe: stubbed by address in the spec, ret 8

// 0x594ed0 (name GUESS): thiscall, one stack argument (flag byte), ret 4. Unless bits 25..27 of [this+0x417] are set, sets
// bit 0x400 of that dword when the flag is non-zero and clears it otherwise.
static void THISCALL setFlag400(u8 *self, u32 flag) {
  u32 f = *(u32 *)(self + 0x417);
  if (f & 0xe000000) return;
  if ((u8)flag) f |= 0x400;
  else f &= 0xfffffbff;
  *(u32 *)(self + 0x417) = f;
}
PCREG(594ed0, setFlag400);

// 0x55ce90 (name GUESS): thiscall (ECX = this), one stack argument obj, ret 4. Stores whether element 0 of the list at
// [obj+4] has a non-zero first dword as a byte at [[this+0x1c]+0x920].
static void THISCALL setNonZeroFromList(u8 *self, u8 *obj) {
  u32 *e = ext_5003d0(*(void **)(obj + 4), 0);
  u8 *t = *(u8 **)(self + 0x1c);
  t[0x920] = (e[0] != 0);
}
PCREG(55ce90, setNonZeroFromList);

// 0x5e1190 (name GUESS): thiscall (ECX = this), two stack arguments (a1 at [ebp+8], a2 at [ebp+0xc]), ret 8. Calls 0x5e0e10
// (ECX = this, a1, a2), then stores the vtable 0x6b78f8 at [this], clears the byte at [this+0x54c] and returns this.
static u8 *THISCALL initObj5e1190(u8 *self, u32 a1, u32 a2) {
  ext_5e0e10(self, a1, a2);
  *(u32 *)self = 0x6b78f8;
  self[0x54c] = 0;
  return self;
}
PCREG(5e1190, initObj5e1190);
