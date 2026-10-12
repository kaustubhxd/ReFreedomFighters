// batch6328.cpp - unclaimed-63 gap-band batch 28: 0x4d2df0 (C-set; no GC name), thiscall, two stack arguments (a1, a2; ret 8).
// r = this->vtbl[+0xb0](a1, 0) (thiscall, callee pops 8). If r == 0 return 0. Else: if (byte [[r+4]+0x10] & 1) == 0:
// G = [0x700390]; G's vtbl[+0x24] with ECX = [G] and three stack arguments (a1, 0x696394, G), caller cleans 12 (asm).
// Then 0x634d22(a2, r + [r] + 0xc, [r+8]) (cdecl, caller cleans 12). Returns [r+8].
// 0x634d22 is an import thunk; it is stubbed by the spec.
#include "ff.h"

extern "C" void ext_634d22(u32 a2, u32 ptr, u32 val);   // cdecl import thunk, stubbed by the spec

typedef u32(THISCALL * call2r_fn)(void *, u32, u32);

// 0x4d2df0 (C-set).
static u32 THISCALL unnamed4d2df0(u8 *self, u32 a1, u32 a2) {
  u32 r = ((call2r_fn)(*(u32 *)(*(u32 *)self + 0xb0)))((void *)self, a1, 0u);
  if (r == 0)
    return 0;
  u32 f = *(u32 *)(r + 4);
  if ((*(u8 *)(f + 0x10) & 1) == 0) {
    u32 g = G(u32, 0x700390);
    u32 vg = *(u32 *)g;
    u32 target = *(u32 *)(vg + 0x24);
    asm volatile("push %[a1]\n\tpush $0x696394\n\tpush %[g]\n\tcall *%[fn]\n\tadd $12, %%esp"
                 :
                 : "c"(vg), [a1] "r"(a1), [g] "r"(g), [fn] "r"(target)
                 : "eax", "edx", "memory", "cc");
  }
  u32 ptr = r + *(u32 *)r + 0xc;
  ext_634d22(a2, ptr, *(u32 *)(r + 8));
  return *(u32 *)(r + 8);
}
PCREG(4d2df0, unnamed4d2df0);
