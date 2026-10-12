// batch312.cpp - unclaimed-03 batch 12 (docs/20-unclaimed-03.md): ZFFSimpleTrain2::Init2() at 0x5b88a0. Name from the GC name
// map (high). Calls: 0x59b310 on the object at [[0x7003b8] + 0x2c15] (one stack argument, this+0x60); if it returns nonzero,
// the global 0x700390 object's vtable slot +0x20 (two stack arguments 0x6b2690, 0xba) returns X, then X's vtable slot +0x2c
// (caller cleans three stack arguments: X, 0x6b26d4, this+0x60) is called with this = *X; then a tail jump to 0x5b9250 with
// this in ECX. Otherwise the function returns at once.
#include "ff.h"

extern "C" u32 THISCALL ext_59b310(void *self, u32 a);   // original code, stubbed by the spec
extern "C" void THISCALL ext_5b9250(void *self);         // tail-call target, original code, stubbed by the spec

// 0x5b88a0 (high): see the comment above. The slot +0x2c call is followed by 'add esp, 0xc' in the PC (caller cleans),
// so it is made in asm with ECX = *X, pushes edi, 0x6b26d4, X, and 'add $12, %esp' after the call.
static void THISCALL simpleTrain2Init2(u8 *self) {
  typedef u32(THISCALL * call2_fn)(void *, u32, u32);
  u32 a = G(u32, 0x7003b8);
  void *b = (void *)*(u32 *)(a + 0x2c15);
  u32 r = ext_59b310(b, (u32)(self + 0x60));
  if (!r) return;
  void *g = (void *)G(u32, 0x700390);
  u32 x = ((call2_fn)(*(u32 *)(*(u32 *)g + 0x20)))(g, 0x6b2690, 0xba);
  u32 vx = *(u32 *)x;
  u32 target = *(u32 *)(vx + 0x2c);
  u32 edi = (u32)(self + 0x60);
  asm volatile("push %[e]\n\tpush $0x6b26d4\n\tpush %[x]\n\tcall *%[fn]\n\tadd $12, %%esp"
               :
               : "c"(vx), [e] "r"(edi), [x] "r"(x), [fn] "r"(target)
               : "eax", "edx", "memory", "cc");
  ext_5b9250(self);
}
PCREG(5b88a0, simpleTrain2Init2);
