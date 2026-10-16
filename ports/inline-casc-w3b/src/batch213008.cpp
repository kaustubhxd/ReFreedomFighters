#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *V2)(void *, u32, u32);

// 0x4869e0: thiscall(this, a) ret 4: field by a's kind (a->[0x330]()): 3,4 -> +0x14, 5 -> +0x18, 6 -> +0x1c, 7 -> +0x20,
// 11 -> +0x24, 0..2 -> +0x10; anything else logs through [0x700390] (slot 0x20, then slot 0x30 of the result's vtable) and returns +0x10
u32 THISCALL fn_4869e0(u8 *self, u8 *a) {
  u32 k = (*(V0 *)(*(u8 **)a + 0x330))(a);
  switch (k) {
    case 0: case 1: case 2: return *(u32 *)(self + 0x10);
    case 3: case 4: return *(u32 *)(self + 0x14);
    case 5: return *(u32 *)(self + 0x18);
    case 6: return *(u32 *)(self + 0x1c);
    case 7: return *(u32 *)(self + 0x20);
    case 11: return *(u32 *)(self + 0x24);
    default: break;
  }
  void *L = G(void *, 0x700390);
  u8 *M = (u8 *)(*(V2 *)(*(u8 **)L + 0x20))(L, 0x68cdc4, 0x381);
  u32 name = *(u32 *)(a + 4);
  if (!name) name = 0x67c8e8;
  u32 fn = *(u32 *)(*(u8 **)M + 0x30);
  u32 ra = fn, rc = *(u32 *)M;
  asm volatile(
      "pushl %[n]\n\t"
      "pushl $0x68ce90\n\t"
      "pushl %[m]\n\t"
      "call *%%eax\n\t"
      "addl $12, %%esp"
      : "+a"(ra), "+c"(rc)
      : [n] "r"(name), [m] "r"(M)
      : "edx", "memory", "cc");
  return *(u32 *)(self + 0x10);
}
PCREG(4869e0, fn_4869e0);
