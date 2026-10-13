// batch4030.cpp - area 70 (slice 4/5), batch 4030: 0x5048d0 (name GUESS). n = element 0 of the list at [obj+4]. If n > 0:
// p = [render manager+0x44] + element 0 of the list at [obj+4]; val = slot 0x5c of this with (p, (float)[p+0x60],
// (float)[p+0x64]); otherwise the error helper 0x5057e0 runs with (0x69ce44, n) and val = 0. Then returns 0x5002f0 with ECX =
// element 0 of the list at [obj+8] and the stack argument val. Exe callees 0x5003d0 (run) and 0x5057e0, 0x5002f0 (stubbed).
#include "ff.h"

extern "C" u32 *THISCALL ext_5003d0(void *list, u32 idx);          // exe: bounded accessor (run as exe code)
extern "C" void THISCALL ext_5057e0(void *self, u32 fmt, s32 n);     // exe: error helper, ret 8, stubbed by address
extern "C" u32 THISCALL ext_5002f0(void *self, u32 a);               // exe: stubbed by address, ret 4

// 0x5048d0 (name GUESS): thiscall (ECX = this), one stack argument obj, ret 4.
static u32 THISCALL callChain5048d0(u8 *self, u8 *obj) {
  s32 n = (s32)ext_5003d0(*(void **)(obj + 4), 0)[0];
  u32 val = 0;
  if (n > 0) {
    u32 *e1 = ext_5003d0(*(void **)(obj + 4), 0);
    u8 *sys = G(u8 *, 0x70039c);
    u8 *rm = *(u8 **)(sys + 0x9b);
    u8 *p = *(u8 **)(rm + 0x44) + e1[0];
    float f60 = (float)*(s32 *)(p + 0x60);
    float f64 = (float)*(s32 *)(p + 0x64);
    val = vcall<u32>(self, 0x5c, p, f60, f64);
  } else {
    ext_5057e0(self, 0x69ce44u, n);
  }
  u32 *e2 = ext_5003d0(*(void **)(obj + 8), 0);
  return ext_5002f0(e2, val);
}
PCREG(5048d0, callChain5048d0);
