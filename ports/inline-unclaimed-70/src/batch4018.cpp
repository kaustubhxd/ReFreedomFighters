// batch4018.cpp - area 70 (slice 5), batch 4018: 0x51b210 and 0x55c710 (names GUESS). Element 0 of a list through the exe
// accessor 0x5003d0 (run as exe code); the two callees 0x5002f0 and 0x5a2f10 (one stack argument each) are stubbed by address.
#include "ff.h"

extern "C" u32 *THISCALL ext_5003d0(void *list, u32 idx);     // exe: bounded element accessor, ret 4
extern "C" u32 THISCALL ext_5002f0(void *self, u32 a);        // exe: stubbed by address in the spec, ret 4
extern "C" u32 THISCALL ext_5a2f10(void *self, u32 a);        // exe: stubbed by address in the spec, ret 4

// 0x51b210 (name GUESS): thiscall (ECX = this), one stack argument obj, ret 4. r = slot 0x380 of [this+0x1c]; e = element 0
// of the list at [obj+8]; returns 0x5002f0 with ECX = e and the stack argument r.
static u32 THISCALL callLeft51b210(u8 *self, u8 *obj) {
  u32 r = vcall<u32>(*(void **)(self + 0x1c), 0x380);
  u32 *e = ext_5003d0(*(void **)(obj + 8), 0);
  return ext_5002f0(e, r);
}
PCREG(51b210, callLeft51b210);

// 0x55c710 (name GUESS): thiscall (ECX = this), one stack argument obj, ret 4. e = element 0 of the list at [obj+4];
// returns 0x5a2f10 with ECX = [this+0x1c] and the stack argument e[0].
static u32 THISCALL callRight55c710(u8 *self, u8 *obj) {
  u32 *e = ext_5003d0(*(void **)(obj + 4), 0);
  return ext_5a2f10(*(void **)(self + 0x1c), e[0]);
}
PCREG(55c710, callRight55c710);
