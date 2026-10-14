// batch35078.cpp - cascade s5 batch 35078: 0x4750b0 (GUESS clamp an advance of stream b, log it and commit; sibling of 0x486e90).
#include "ff.h"

typedef s32(THISCALL *g1_t)(void *, void *);
typedef s32(THISCALL *g0_t)(void *);
typedef void(THISCALL *v1_t)(void *, s32);
typedef void(THISCALL *v2_t)(void *, void *, s32);
typedef u8 *(THISCALL *r2_t)(void *, u32, u32);

// 0x4750b0, thiscall(b) ret 4, signed arithmetic. want = this slot 0x560(b); end = b slot 0x364(); cur = b slot 0x35c(); stop = min(cur + want, end) (signed); n = stop - cur. The line 0x3fe is logged through the
// object at 0x700390 (slot 0x20(0x68961c, 0x3fe), then slot 0x2c of the result with ECX = its vtable and caller-popped args (r, 0x689820, n)). this slot 0x564(b, want - n); b slot 0x360(stop); b slot 0x358(1).
static void THISCALL fn4750b0(u8 *self, u8 *b) {
  s32 want = (*(g1_t **)self)[0x560 / 4](self, b);
  s32 end = (*(g0_t **)b)[0x364 / 4](b);
  s32 cur = (*(g0_t **)b)[0x35c / 4](b);
  s32 stop = cur + want;
  if (end < stop) stop = end;
  s32 n = stop - cur;
  u8 *lg = G(u8 *, 0x700390);
  u8 *r = (*(r2_t **)lg)[0x20 / 4](lg, 0x68961c, 0x3fe);
  u32 vt = *(u32 *)r;
  u32 slot = ((u32 *)vt)[0x2c / 4];
  asm volatile("push %[n]\n\tpush $0x689820\n\tpush %[r]\n\tcall *%[fn]\n\tadd $12, %%esp" : : "c"(vt), [n] "r"(n), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
  (*(v2_t **)self)[0x564 / 4](self, b, want - n);
  (*(v1_t **)b)[0x360 / 4](b, stop);
  (*(v1_t **)b)[0x358 / 4](b, 1);
}
PCREG(4750b0, fn4750b0);
