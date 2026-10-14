// batch35014.cpp - cascade s5 batch 35014: 0x5a1ac0 (GUESS dispatch an indexed entry either to the effect object or through two virtual calls).
#include "ff.h"

extern "C" u8 THISCALL ext_5da860(u8 *self, u32 idx, u32 v);                       // ret 8, bool in AL
extern "C" void THISCALL ext_5dabe0(u8 *self, u8 *a, u32 b, u32 c, u32 d);         // ret 0x10
extern "C" void THISCALL ext_467000(u8 *self, u32 a, u32 b, u32 c, u32 d);         // ret 0x10
typedef void(THISCALL *v3_t)(void *, u32, u32, u32);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x5a1ac0, thiscall(a, b, c) ret 0xc. fx = unaligned dword [this+0x93a]; nothing happens when it is null. i = a & 0xff. When 0x5da860(fx, i, [[this+0x54]+4]) returns true:
// c (low byte) set: b != 0 gives 0x5dabe0(fx, this, i, b, 0x6a6e64), otherwise slot 0x6ec(a, 0x6a6e64, 0) of this; c clear: r = slot 0x684(b, 1) (that slot leaves its two
// arguments on the stack), then 0x467000(this, table[i], r, b, 1) (ret 0x10 pops them) with table = unaligned dword [this+0x936].
static void THISCALL fn5a1ac0(u8 *self, u32 a, u32 b, u32 c) {
  u8 *fx = (u8 *)rd32u(self + 0x93a);
  if (!fx) return;
  u32 i = a & 0xff;
  u8 *x = *(u8 **)(self + 0x54);
  if (!ext_5da860(fx, i, *(u32 *)(x + 4))) return;
  if ((u8)c) {
    fx = (u8 *)rd32u(self + 0x93a);
    if (b) {
      ext_5dabe0(fx, self, i, b, 0x6a6e64);
    } else {
      (*(v3_t **)self)[0x6ec / 4](self, a, 0x6a6e64, 0);
    }
    return;
  }
  u32 slot = (*(u32 **)self)[0x684 / 4];
  u32 r;
  asm volatile("push $1\n\tpush %[b]\n\tcall *%[fn]\n\tadd $8, %%esp" : "=a"(r) : "c"(self), [b] "r"(b), [fn] "r"(slot) : "edx", "memory", "cc");
  u32 tbl = rd32u(self + 0x936);
  ext_467000(self, *(u32 *)(tbl + i * 4), r, b, 1);
}
PCREG(5a1ac0, fn5a1ac0);
