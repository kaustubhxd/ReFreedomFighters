// batch35021.cpp - cascade s5 batch 35021: 0x505fa0 (GUESS look an item up in two sources, log when it is missing).
#include "ff.h"

typedef u32(THISCALL *g0_t)(void *);
typedef u32(THISCALL *g1_t)(void *, u32);
typedef u8 *(THISCALL *r2_t)(void *, u32, u32);

// 0x505fa0, thiscall(a) ret 4, returns EAX. P = [this+0x14]. When P slot 0x2c0() (A) is non-null: when P slot 0x2c4() (B) is non-null and B' = P slot 0x2c4() (called again) slot 0x18(a)
// returns r != 0, return r; else r = (P slot 0x2c0() again) slot 0x18(a), return it when non-zero. Otherwise (or r == 0) log through the object at 0x700390: slot 0x20(0x69cd2c, 0x1b4) = x,
// then slot 0x30 of x with ECX = x's vtable and four caller-popped args (x, 0x69cf24, P slot 0x30c(), a); return 0.
static u32 THISCALL fn505fa0(u8 *self, u32 a) {
  u8 *P = *(u8 **)(self + 0x14);
  if ((*(g0_t **)P)[0x2c0 / 4](P)) {
    P = *(u8 **)(self + 0x14);
    if ((*(g0_t **)P)[0x2c4 / 4](P)) {
      P = *(u8 **)(self + 0x14);
      u8 *b = (u8 *)(*(g0_t **)P)[0x2c4 / 4](P);
      u32 r = (*(g1_t **)b)[0x18 / 4](b, a);
      if (r) return r;
    }
    P = *(u8 **)(self + 0x14);
    u8 *x = (u8 *)(*(g0_t **)P)[0x2c0 / 4](P);
    u32 r = (*(g1_t **)x)[0x18 / 4](x, a);
    if (r) return r;
  }
  P = *(u8 **)(self + 0x14);
  u32 name = (*(g0_t **)P)[0x30c / 4](P);
  u8 *lg = G(u8 *, 0x700390);
  u8 *r = (*(r2_t **)lg)[0x20 / 4](lg, 0x69cd2c, 0x1b4);
  u32 vt = *(u32 *)r;
  u32 slot = ((u32 *)vt)[0x30 / 4];
  asm volatile("push %[a]\n\tpush %[name]\n\tpush $0x69cf24\n\tpush %[r]\n\tcall *%[fn]\n\tadd $16, %%esp" : : "c"(vt), [a] "r"(a), [name] "r"(name), [r] "r"(r), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
  return 0;
}
PCREG(505fa0, fn505fa0);
