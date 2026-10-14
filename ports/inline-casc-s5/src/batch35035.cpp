// batch35035.cpp - cascade s5 batch 35035: 0x514890 (GUESS switch an object's mode on/off and forward a range to its owner).
#include "ff.h"

extern "C" void THISCALL ext_4dcb50(u32 owner, u32 a, u32 b);   // thiscall, ret 8
typedef u32(THISCALL *g0_t)(void *);
typedef u8(THISCALL *b0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);

// 0x514890, stdcall(o, b, c, d, on, set) ret 0x18 (ECX ignored); nothing when o is null; `on` and `set` are tested by their low byte. On: o slot 0x33c(3); slot 0x360(0x64) when slot 0x35c()
// is zero; when slot 0x354() is false slot 0x2d0(6, 0) and slot 0x2d0(0, 0); when `set`: slot 0x32c(b); then slot 0x2d0(3, 0). Off: slot 0x2d0(0, 0). Finally 0x4dcb50([o+8], c, d).
static void STDCALL fn514890(u8 *o, u32 b, u32 c, u32 d, u32 on, u32 set) {
  if (!o) return;
  if ((u8)on) {
    (*(v1_t **)o)[0x33c / 4](o, 3);
    if (!(*(g0_t **)o)[0x35c / 4](o)) (*(v1_t **)o)[0x360 / 4](o, 0x64);
    if (!(*(b0_t **)o)[0x354 / 4](o)) {
      (*(v2_t **)o)[0x2d0 / 4](o, 6, 0);
      (*(v2_t **)o)[0x2d0 / 4](o, 0, 0);
    }
    if ((u8)set) (*(v1_t **)o)[0x32c / 4](o, b);
    (*(v2_t **)o)[0x2d0 / 4](o, 3, 0);
  } else {
    (*(v2_t **)o)[0x2d0 / 4](o, 0, 0);
  }
  ext_4dcb50(*(u32 *)(o + 8), c, d);
}
PCREG(514890, fn514890);
