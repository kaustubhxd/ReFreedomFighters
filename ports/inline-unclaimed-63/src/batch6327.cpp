// batch6327.cpp - unclaimed-63 gap-band batch 27 (band 0x4c1000-0x4e1000): 0x4cf230 (C-set; no GC name), thiscall with one stack
// argument (a pointer P), ret 4. If the signed dword [this+0xc] is negative: X = [0x700390]->vtbl[+0x20](0x695b7c, 0x464) (thiscall,
// callee pops 8); then X's vtbl[+0x2c] with ECX = [X] and two stack arguments (X, 0x695c50), the caller cleans 8 (asm). Then:
// e = [P] ? [[P]+4] : [this+0x1c]; [P] = e; if e == 0 return 0; else return e + (2 - [this+0x18]) * 4.
// The call that the caller cleans is written in asm. 0x700390's object and X's vtable are stubbed by the spec.
#include "ff.h"

typedef u32(THISCALL * call2r_fn)(void *, u32, u32);

// 0x4cf230 (C-set).
static u32 THISCALL unnamed4cf230(u8 *self, u32 *p) {
  if ((s32)*(u32 *)(self + 0xc) < 0) {
    u32 g = G(u32, 0x700390);
    u32 x = ((call2r_fn)(*(u32 *)(*(u32 *)g + 0x20)))((void *)g, 0x695b7cu, 0x464u);
    u32 vx = *(u32 *)x;
    u32 target = *(u32 *)(vx + 0x2c);
    asm volatile("push $0x695c50\n\tpush %[x]\n\tcall *%[fn]\n\tadd $8, %%esp"
                 :
                 : "c"(vx), [x] "r"(x), [fn] "r"(target)
                 : "eax", "edx", "memory", "cc");
  }
  u32 e;
  if (*p != 0)
    e = *(u32 *)(*p + 4);
  else
    e = *(u32 *)(self + 0x1c);
  *p = e;
  if (e == 0)
    return 0;
  return e + (2u - *(u32 *)(self + 0x18)) * 4u;
}
PCREG(4cf230, unnamed4cf230);
