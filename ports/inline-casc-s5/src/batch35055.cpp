// batch35055.cpp - cascade s5 batch 35055: 0x4a22f0 (GUESS look up a string's hash and apply it to every registered target).
#include "ff.h"

extern "C" void THISCALL ext_4a2380(u32 self, u32 h);   // thiscall, ret 4
typedef u32(THISCALL *g1_t)(void *, u32);
typedef u32(THISCALL *f0_t)(u32);

// 0x4a22f0, thiscall(s) ret 4. h = 0 when s is null. Otherwise with E = [0x70038c]: E slot 0x20(s) non-zero gives 0; else when E[8] (a function) is set and E[0xc] <= s < E[0x10] h = E[8](s)
// (thiscall, ECX = s); else (a zero dword at s - 4 first goes through E slot 0xac(s)) h = dword [s - 4]. Then 0x4a2380([this + 0x5c + 4 * i], h) for each i < [this+0x48].
static void THISCALL fn4a22f0(u8 *self, u32 s) {
  u32 h;
  if (!s) {
    h = 0;
  } else {
    u8 *E = G(u8 *, 0x70038c);
    if ((*(g1_t **)E)[0x20 / 4](E, s)) {
      h = 0;
    } else {
      E = G(u8 *, 0x70038c);
      u32 f = *(u32 *)(E + 8);
      if (f && !(*(u32 *)(E + 0xc) > s) && s < *(u32 *)(E + 0x10)) {
        h = ((f0_t)f)(s);
      } else {
        if (*(u32 *)(s - 4) == 0) (*(g1_t **)E)[0xac / 4](E, s);
        h = *(u32 *)(s - 4);
      }
    }
  }
  s32 cnt = *(s32 *)(self + 0x48);
  u8 *p = self + 0x5c;
  for (s32 i = 0; i < cnt; i++) {
    ext_4a2380(*(u32 *)p, h);
    p += 4;
    cnt = *(s32 *)(self + 0x48);
  }
}
PCREG(4a22f0, fn4a22f0);
