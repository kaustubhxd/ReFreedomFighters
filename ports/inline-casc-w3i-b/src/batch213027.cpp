#include "ff.h"

typedef u32(THISCALL *V0)(void *);
typedef u32(THISCALL *LogNew3)(void *, u32, u32);

// 0x486aa0: thiscall(this, a) ret 4: field of this by a's kind (a->[0x330]()): 0 -> +0x14, 1 -> +0x10, 2 -> +0x18, 3/4 -> +0x1c, 5 -> +0x20
// (also stores two float constants at +0x38/+0x3c), 6 -> +0x24, 7 -> +0x28, each falling back to +0x10 when zero; 11, 12 -> 0;
// 8..10 and above 12 log through [0x700390] (slot 0x20, then slot 0x2c with ecx = vtable) and return +0x10. +0x38 is cleared first.
u32 THISCALL fn_486aa0(u8 *self, u8 *a) {
  *(u32 *)(self + 0x38) = 0;
  u32 k = (*(V0 *)(*(u8 **)a + 0x330))(a);
  if (k <= 0xc) {
    u32 v;
    switch (k) {
      case 0: return *(u32 *)(self + 0x14);
      case 1: return *(u32 *)(self + 0x10);
      case 2: return *(u32 *)(self + 0x18);
      case 3:
      case 4: v = *(u32 *)(self + 0x1c); break;
      case 5:
        v = *(u32 *)(self + 0x20);
        *(u32 *)(self + 0x38) = 0x3ee147ae;
        *(u32 *)(self + 0x3c) = 0x3f2e147b;
        break;
      case 6: v = *(u32 *)(self + 0x24); break;
      case 7: v = *(u32 *)(self + 0x28); break;
      case 11:
      case 12: return 0;
      default: goto logit;
    }
    return v ? v : *(u32 *)(self + 0x10);
  }
logit:
  void *L = G(void *, 0x700390);
  u8 *M = (u8 *)(*(LogNew3 *)(*(u8 **)L + 0x20))(L, 0x68cdc4, 0x27f);
  u32 name = *(u32 *)(a + 4);
  if (!name) name = 0x67c8e8;
  u32 ra = *(u32 *)(*(u8 **)M + 0x2c), rc = *(u32 *)M;
  asm volatile(
      "pushl %[n]\n\t"
      "pushl $0x68ce50\n\t"
      "pushl %[m]\n\t"
      "call *%%eax\n\t"
      "addl $12, %%esp"
      : "+a"(ra), "+c"(rc)
      : [n] "r"(name), [m] "r"(M)
      : "edx", "memory", "cc");
  return *(u32 *)(self + 0x10);
}
PCREG(486aa0, fn_486aa0);

// 0x470b00: thiscall(this, x) ret 4: finds a set bit of the mask slot 0x334 returns: x itself when x > 3, else the next of 2, 0, 1, 3 after x
// whose bit is set, polling the slot again for every test; an empty mask logs through [0x700390] (slot 0x20, slot 0x30) and returns x.
u32 THISCALL fn_470b00(u8 *self, u32 x) {
  if ((*(V0 *)(*(u8 **)self + 0x334))(self) == 0) {
    void *L = G(void *, 0x700390);
    u8 *M = (u8 *)(*(LogNew3 *)(*(u8 **)L + 0x20))(L, 0x6887c4, 0x7fb);
    u32 name = *(u32 *)(self + 4);
    if (!name) name = 0x67c8e8;
    u32 ra = *(u32 *)(*(u8 **)M + 0x30), rc = *(u32 *)M;
    asm volatile(
        "pushl %[n]\n\t"
        "pushl $0x688b24\n\t"
        "pushl %[m]\n\t"
        "call *%%eax\n\t"
        "addl $12, %%esp"
        : "+a"(ra), "+c"(rc)
        : [n] "r"(name), [m] "r"(M)
        : "edx", "memory", "cc");
    return x;
  }
  if (x > 3) {
    for (;;) {
      u32 m = (*(V0 *)(*(u8 **)self + 0x334))(self);
      if ((m >> (x & 31)) & 1) return x;
    }
  }
  static const u8 order[4] = {2, 0, 1, 3};
  u32 pos = x == 2 ? 0 : x == 0 ? 1 : x == 1 ? 2 : 3;
  for (;;) {
    pos = (pos + 1) & 3;
    u32 c = order[pos];
    u32 m = (*(V0 *)(*(u8 **)self + 0x334))(self);
    if ((m >> c) & 1) return c;
  }
}
PCREG(470b00, fn_470b00);
