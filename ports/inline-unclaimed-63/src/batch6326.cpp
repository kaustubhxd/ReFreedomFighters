// batch6326.cpp - unclaimed-63 gap-band batch 26: two list searches over a virtual iterator (band 0x4c1000-0x4e1000).
//   0x4cde20 (C-set; no GC name): if this is null, return. [this] vtbl[+0x4c](&local); v = vtbl[+0x64](&local); if v == 0 return;
//     loop: if v == target: vtbl[+0x44](&local); [this+0xc] |= 0x80000000; return. Else v = vtbl[+0x64](&local); if v == 0 return; repeat.
//   0x4cdf70 (C-set; no GC name): returns 1 if the target is found, else 0. If this is null return 0. vtbl[+0x4c](&local);
//     v = vtbl[+0x5c](&local); if local == 0 return 0; loop: if v == target return 1; v = vtbl[+0x5c](&local); if local == 0 return 0.
// The &local arguments are stack addresses (the stubs do not record them). Both are thiscall with one stack argument (ret 4).
#include "ff.h"

typedef u32(THISCALL * call1_fn)(void *, u32 *);
typedef void(THISCALL * call1v_fn)(void *, u32 *);

// 0x4cde20 (C-set).
static void THISCALL unnamed4cde20(u8 *self, u32 target) {
  if (self == 0)
    return;
  u32 local = 0;
  ((call1v_fn)(*(u32 *)(*(u32 *)self + 0x4c)))((void *)self, &local);
  u32 v = ((call1_fn)(*(u32 *)(*(u32 *)self + 0x64)))((void *)self, &local);
  if (v == 0)
    return;
  for (;;) {
    if (v == target) {
      ((call1v_fn)(*(u32 *)(*(u32 *)self + 0x44)))((void *)self, &local);
      *(u32 *)(self + 0xc) |= 0x80000000u;
      return;
    }
    v = ((call1_fn)(*(u32 *)(*(u32 *)self + 0x64)))((void *)self, &local);
    if (v == 0)
      return;
  }
}
PCREG(4cde20, unnamed4cde20);

// 0x4cdf70 (C-set): 1 if found, else 0.
static u32 THISCALL unnamed4cdf70(u8 *self, u32 target) {
  if (self == 0)
    return 0;
  u32 local = 0;
  ((call1v_fn)(*(u32 *)(*(u32 *)self + 0x4c)))((void *)self, &local);
  u32 v = ((call1_fn)(*(u32 *)(*(u32 *)self + 0x5c)))((void *)self, &local);
  if (local == 0)
    return 0;
  for (;;) {
    if (v == target)
      return 1;
    v = ((call1_fn)(*(u32 *)(*(u32 *)self + 0x5c)))((void *)self, &local);
    if (local == 0)
      return 0;
  }
}
PCREG(4cdf70, unnamed4cdf70);
