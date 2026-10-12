// batch307.cpp - unclaimed-03 batch 7 (docs/20-unclaimed-03.md): ZActor::SetRootTM(const float*, const float*) at 0x47c0e0.
// Names from the GC name map (high). The body calls through three globals and a virtual; the callees are original code
// in the exe and stubbed in the spec (see docs/20-unclaimed-03.md, claim 7). Callee pops 8 (ret 8).
#include "ff.h"

typedef u32(THISCALL * call2_fn)(u32 self, u32 a, u32 b);
typedef void(THISCALL * virt2_fn)(u32 self, u32 a, u32 b);
typedef void (*void0_fn)(void);

// 0x47c0e0: the PC order is kept. (1) this = *0x700390; r = vtbl[+0x20](this, 0x68a7c4, 0x424). (2) vx = *r;
// vx->vtbl[+0x2c] with this = vx, args (r, 0x68aa10), caller cleans. (3) if *0x7003b0 is set, call it (no arguments). (4) this->vtbl[+0x578]
// with (a1, a2). The PC code int3-faults if *0x7003b0 is null; the port calls it unconditionally, so the spec always sets it non-null.
static void THISCALL actorSetRootTM(u8 *self, u32 a1, u32 a2) {
  u32 g = G(u32, 0x700390);
  u32 r = ((call2_fn)(*(u32 *)(*(u32 *)g + 0x20)))(g, 0x68a7c4, 0x424);
  u32 vx = *(u32 *)r;
  // The PC call to vx+0x2c is followed by 'add esp, 8' (caller cleans), so the callee does not pop: ECX = vx, push
  // 0x68aa10, push r (r is the first argument), call, add esp, 8. Written in asm, since no C calling convention matches.
  u32 target = *(u32 *)(vx + 0x2c);
  asm volatile("push %[b]\n\tpush %[a]\n\tcall *%[fn]\n\tadd $8, %%esp"
               :
               : "c"(vx), [a] "r"(r), [b] "r"(0x68aa10u), [fn] "r"(target)
               : "eax", "edx", "memory", "cc");
  void0_fn hook = (void0_fn)G(u32, 0x7003b0);
  hook();
  ((virt2_fn)(*(u32 *)(*(u32 *)self + 0x578)))((u32)self, a1, a2);
}
PCREG(47c0e0, actorSetRootTM);
