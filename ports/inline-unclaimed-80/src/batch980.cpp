#include "ff.h"
// batch980.cpp - unclaimed-80 residue-19 (docs/20-unclaimed-80.md), batch 58: 0x4ce3b0 (thiscall, self in ecx, one stack argument p, ret 4, returns a count).
// n = [self+0xc]; if n == 0 return 0. buf = n bytes zeroed (stack buffer; the exe's stack probe 0x633c90 is not modelled, the zeroing is memset 0x634d10).
// o = [self+8]; if o: o.vt[0x4c](&local); eax = o.vt[0x5c](&local); while local != 0: buf[([self+0x10] & eax) - 1] = 1; eax = o.vt[0x5c](&local).
// Then for i in 0..n-1 (n re-read each step): if buf[i] == 0: if p: p.vt[4]((arr[i] & ~[self+0x10]) + i); count++. Return count.
// The exe's cookie check 0x633654 is omitted (a no-op on valid frames). The stack buffer is a VLA here.
extern "C" void *ext_634d10(void *dst, int c, u32 n);

typedef u32(THISCALL *tc1)(u8 *, u32);

static u32 THISCALL zg4ce3b0(u8 *self, u8 *p) {
  u32 n = *(u32 *)(self + 0xc);
  if (n == 0) return 0;
  u8 buf[n];
  ext_634d10(buf, 0, n);
  u8 *o = *(u8 **)(self + 8);
  if (o != 0) {
    u32 local;
    ((tc1)(*(u32 *)(*(u32 *)o + 0x4c)))(o, (u32)&local);
    u32 eax = ((tc1)(*(u32 *)(*(u32 *)o + 0x5c)))(o, (u32)&local);
    if (local != 0) {
      for (;;) {
        u32 k = *(u32 *)(self + 0x10) & eax;
        buf[k - 1] = 1;
        eax = ((tc1)(*(u32 *)(*(u32 *)o + 0x5c)))(o, (u32)&local);
        if (local == 0) break;
      }
    }
  }
  u32 cnt = 0;
  for (u32 i = 0; i < *(u32 *)(self + 0xc); i++) {
    if (buf[i] == 0) {
      if (p != 0) {
        u32 arr = ((u32 *)*(u32 *)(self + 4))[i];
        u32 arg = (arr & ~*(u32 *)(self + 0x10)) + i;
        ((tc1)(*(u32 *)(*(u32 *)p + 4)))(p, arg);
      }
      cnt++;
    }
  }
  return cnt;
}
PCREG(4ce3b0, zg4ce3b0);
