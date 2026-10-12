#include "ff.h"
// batch931.cpp - unclaimed-80 claim 11 (docs/20-unclaimed-80.md). CActionController::Remove(CAction*) (0x4a1630, map name).
// Thiscall, one argument (a), ret 4. The helper 0x4a1710 (thiscall, one argument: an index) is original code, stubbed by the spec.
//   1. if a != 0: table object T = global 0x70038c. If T slot +0x20 (one argument: a) returns 0: fn = T+8; lo = T+0xc; hi = T+0x10.
//      If fn != 0 and lo <= a < hi (unsigned): a = fn() (thiscall, no arguments). Else: if [a-4] == 0, T slot +0xac (one argument
//      a); a = [a-4]. If T slot +0x20 returned nonzero: a = 0.
//   2. search this+0x70 (count = this+0x88c, plus one; skipped when that is not positive) for a; on a hit at index k, helper(this+0x6c, k).
//   3. for i < this+0x48 (signed): P = [this+0x5c+4i]; search P+4 (count = P+0x820, plus one) for a; on a hit at k, helper(P, k).

extern "C" void THISCALL ext_4a1710(u8 *obj, u32 index);

static void THISCALL actionControllerRemove(u8 *self, u8 *arg) {
  u32 a = (u32)arg;
  typedef u32(THISCALL * r0_fn)(u8 *);
  typedef u32(THISCALL * r1_fn)(u8 *, u32);
  typedef void(THISCALL * v1_fn)(u8 *, u32);
  if (a != 0) {
    u8 *t = G(u8 *, 0x70038c);
    if (((r1_fn)(*(u32 *)(*(u32 *)t + 0x20)))(t, a) != 0) {
      a = 0;
    } else {
      t = G(u8 *, 0x70038c);
      u32 fn = *(u32 *)(t + 8);
      u32 lo = *(u32 *)(t + 0xc);
      u32 hi = *(u32 *)(t + 0x10);
      if (fn != 0 && !(lo > a) && !(a >= hi)) {
        a = ((r0_fn)fn)((u8 *)a);
      } else {
        if (*(u32 *)(a - 4) == 0)
          ((v1_fn)(*(u32 *)(*(u32 *)t + 0xac)))(t, a);
        a = *(u32 *)(a - 4);
      }
    }
  }
  s32 cnt1 = (s32)(*(u32 *)(self + 0x88c)) + 1;
  if (cnt1 > 0) {
    u32 *e = (u32 *)(self + 0x70);
    for (u32 k = 0; k < (u32)cnt1; k++) {
      if (e[k] == a) {
        ext_4a1710(self + 0x6c, k);
        break;
      }
    }
  }
  s32 n = (s32)(*(u32 *)(self + 0x48));
  for (s32 i = 0; i < n; i++) {
    u8 *p = *(u8 **)(self + 0x5c + 4 * i);
    s32 cnt2 = (s32)(*(u32 *)(p + 0x820)) + 1;
    if (cnt2 > 0) {
      u32 *e = (u32 *)(p + 4);
      for (u32 k = 0; k < (u32)cnt2; k++) {
        if (e[k] == a) {
          ext_4a1710(p, k);
          break;
        }
      }
    }
  }
}
PCREG(4a1630, actionControllerRemove);
