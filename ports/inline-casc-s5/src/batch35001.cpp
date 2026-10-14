// batch35001.cpp - cascade s5 batch 35001: 0x5e9ce0 (GUESS toggle controller mode: update state object at +0x1d0f).
#include "ff.h"

extern "C" void THISCALL ext_4f9680(u32 self, u32 a);    // thiscall, ret 4
extern "C" void THISCALL ext_5ab1e0(u8 *self, u32 a);    // thiscall, ret 4
extern "C" void THISCALL ext_5ab2a0(u8 *self, u32 a);    // thiscall, ret 4
extern "C" u32 THISCALL ext_5e9b70(u8 *self);            // thiscall, plain ret, result in EAX
typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v2_t)(void *, u32, u32);

static inline u8 *&F1d0f(u8 *self) { return *(u8 **)(self + 0x1d0f); }

// 0x5e9ce0, thiscall(flag) ret 4 (the whole dword is passed on to 0x5ab1e0; only its low byte is tested). No-op when [this+0x1d0f] is null.
static void THISCALL fn5e9ce0(u8 *self, u32 flag) {
  if (!F1d0f(self)) return;
  (*(v0_t **)self)[0x90 / 4](self);
  if ((u8)flag) {
    if (!F1d0f(self)[0x3c6]) ext_4f9680(0x700e24, 2);
    ext_5ab1e0(F1d0f(self), flag);
    ext_5ab2a0(F1d0f(self), 0x677b5a);
    return;
  }
  if (!F1d0f(self)[0x3c6]) return;
  ext_5ab1e0(F1d0f(self), 0);
  u32 r = ext_5e9b70(self);
  if (!r) {
    ext_4f9680(0x700e24, 3);
    return;
  }
  ext_4f9680(0x700e24, 1);
  void *o = *(void **)(self + 0x1d0b);
  (*(v0_t **)o)[0x3dc / 4](o);
  o = *(void **)(self + 0x1d0b);
  (*(v2_t **)o)[0x4dc / 4](o, r, 1);
  ext_5ab2a0(F1d0f(self), 0x677b5a);
}
PCREG(5e9ce0, fn5e9ce0);
