// batch5744.cpp - unclaimed-57, band batch 44 (name GUESS): 0x5d5fc0, thiscall, no args, ret. a = dword this+0x4c, b = dword this+0x50;
// if a == b return. L = (int) truncation of (float engine+0x48) * (float 0x686098) (engine = dword 0x70039c). n = b - a, clamped:
// if n > 0, n = min(n, L); then, if n < 0 (a negative L can make it so), n = max(n, -L) (two sequential steps, as the original). c = a + n. sub = dword this+0x44. If a == 0: sub->vt[+0xbc](0).
// Then if c != 0: sub->vt[+0x250](c); else sub->vt[+0xbc](1). Finally dword this+0x4c = c.
// The sub-object slots are unverified callees, stubbed in the spec.
#include "ff.h"

#define VT(o) (*(void ***)(o))
#define G(T, addr) (*(T *)(addr))

typedef void(THISCALL *Slot1)(u8 *self, u32 a);

static void THISCALL unnamed5d5fc0(u8 *self) {
  u32 a = *(u32 *)(self + 0x4c);
  u32 b = *(u32 *)(self + 0x50);
  if (a == b) return;
  u8 *engine = G(u8 *, 0x70039c);
  float f = *(float *)(engine + 0x48) * G(float, 0x686098);
  s32 L = _mm_cvttss_si32(_mm_set_ss(f));
  s32 n = (s32)b - (s32)a;
  if (n > 0) {
    if (n > L) n = L;
  }
  if (n < 0) {
    if (n < -L) n = -L;
  }
  u32 c = a + (u32)n;
  u8 *sub = *(u8 **)(self + 0x44);
  if (a == 0) ((Slot1)VT(sub)[0xbc / 4])(sub, 0);
  sub = *(u8 **)(self + 0x44);
  if (c != 0) ((Slot1)VT(sub)[0x250 / 4])(sub, c);
  else ((Slot1)VT(sub)[0xbc / 4])(sub, 1);
  *(u32 *)(self + 0x4c) = c;
}
PCREG(5d5fc0, unnamed5d5fc0);
