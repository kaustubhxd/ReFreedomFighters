// batch35130.cpp - cascade s5 batch 35130: 0x4d0fc0 (GUESS append a range record to a table and a (start, length) pair to a bounded array).
#include "ff.h"

typedef u8 *(THISCALL *r2_t)(void *, u32, u32);

// 0x4d0fc0, thiscall(a, b, c) ret 0xc. With k = [this+0x88]: dword [this + 12k + 0x10] = a, [this + 12k + 0x14] = a + b, [this + 12(k + 2)] = c; [this+0x88] = k + 1; [this+0xc] += b. Then the bounded array: n = [this+8]; when n < [this+4]
// and p = [this] + 8n is non-null: [this+8] = n + 1, p[0] = a, p[4] = b; otherwise (also when only the pointer is null, after the count was already bumped) line 0x102 is logged through the logger at 0x700390 (slot 0x20(0x695ec0, 0x102), then slot 0x2c of the result with ECX = its vtable and caller-popped (r, 0x695f3c)).
static void THISCALL fn4d0fc0(u8 *self, u32 a, u32 b, u32 c) {
  u32 k = *(u32 *)(self + 0x88);
  *(u32 *)(self + k * 12 + 0x10) = a;
  k = *(u32 *)(self + 0x88);
  *(u32 *)(self + k * 12 + 0x14) = a + b;
  k = *(u32 *)(self + 0x88);
  *(u32 *)(self + (k + 2) * 12) = c;
  *(u32 *)(self + 0x88) += 1;
  *(u32 *)(self + 0xc) += b;
  u32 n = *(u32 *)(self + 8);
  if (n < *(u32 *)(self + 4)) {
    u32 *p = (u32 *)(*(u8 **)self + n * 8);
    *(u32 *)(self + 8) = n + 1;
    if (p) {
      p[0] = a;
      p[1] = b;
      return;
    }
  }
  u8 *lg = G(u8 *, 0x700390);
  u8 *r = (*(r2_t **)lg)[0x20 / 4](lg, 0x695ec0, 0x102);
  u32 vt = *(u32 *)r;
  u32 slot = ((u32 *)vt)[0x2c / 4];
  asm volatile("push $0x695f3c\n\tpush %[r]\n\tcall *%[fn]\n\tadd $8, %%esp" : : "c"(vt), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
}
PCREG(4d0fc0, fn4d0fc0);
