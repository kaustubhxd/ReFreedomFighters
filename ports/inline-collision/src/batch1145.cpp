// batch1145.cpp - collision thread, batch 1145 (hard-row lane, name GUESS): 0x43b630. Thiscall (ECX = this), two stack
// arguments (A, B byte), ret 8. Uses the object at [this+0xd] (X): slot 0x14 gives a limit N; a counter at [this+0x11] is
// compared with N (signed), and reset when it reaches it. Otherwise, against the global sys+0x1c: the value at [this+0x16]
// is compared, and a difference over 0x1400 resets the flag byte at Y+4 (slot 0x34 of X with the counter). The entry Z = slot 0x34
// of X: Z[0] must equal A; Z[4] takes the flag B with the counter updates. Finally [this+0x16] = [sys+0x1c].
// The exe's eax on return is not used by the caller here (the port returns void).
#include "ff.h"

static void THISCALL step43b630(u8 *self, u32 A, u32 B) {
  u8 *X = *(u8 **)(self + 0xd);
  if (X == 0) return;
  s32 cnt = *(s32 *)(self + 0x11);
  s32 N = (s32)vcall<u32>(X, 0x14);
  if (cnt >= N) {
    *(u32 *)(self + 0x11) = 0;
    return;
  }
  u8 *sys = G(u8 *, 0x70039c);
  u32 v16 = *(u32 *)(self + 0x16);
  if (*(u32 *)(sys + 0x1c) == v16) return;
  self[0x15] = 0;
  s32 diff = (s32)*(u32 *)(sys + 0x1c) - (s32)v16;
  if (diff > 0x1400) {
    u8 *Y = (u8 *)vcall<u32>(X, 0x34, (u32)cnt);
    Y[4] = 0;
    *(u32 *)(self + 0x11) = 0;
  }
  u8 *Z = (u8 *)vcall<u32>(X, 0x34, *(u32 *)(self + 0x11));
  if (*(u32 *)Z != A) {
    *(u32 *)(self + 0x11) = 0;
    return;
  }
  u8 dl = Z[4];
  u8 cl = (u8)B;
  if (dl == 0) {
    if (cl != 0) {
      Z[4] = 1;
    } else {
      Z[4] = 0;
      *(u32 *)(self + 0x11) = 0;
    }
  } else {
    if (cl != 0) {
      Z[4] = 0;
      *(u32 *)(self + 0x11) = 0;
    } else {
      Z[4] = 0;
      *(u32 *)(self + 0x11) = *(u32 *)(self + 0x11) + 1;
      s32 N2 = (s32)vcall<u32>(X, 0x14);
      if ((s32)*(u32 *)(self + 0x11) >= N2) {
        self[0x15] = 1;
        *(u32 *)(self + 0x11) = 0;
      }
    }
  }
  if (self + 0x16 != sys + 0x1c) *(u32 *)(self + 0x16) = *(u32 *)(sys + 0x1c);
}
PCREG(43b630, step43b630);
