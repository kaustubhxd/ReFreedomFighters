// batch6329.cpp - unclaimed-63 gap-band batch 29: 0x4cf4b0 (C-set; no GC name), thiscall with one stack argument P (ret 4).
// If the signed dword [this+0xc] is negative: X = [0x700390]->vtbl[+0x20](0x695b7c, 0x1d9) (thiscall, callee pops 8); then X's
// vtbl[+0x2c] with ECX = [X] and (X, 0x695bc8), caller cleans 8 (asm); then the hook at 0x7003b0 is called (cdecl; the PC faults if
// it is null). Then: if [P] == 0 return 0. [P+4] -= [this+0x18]; if that is negative: P's base is advanced to the next node
// (nxt = [[P]]; [P] = nxt; if nxt == 0 return 0), and [P+4] = [this+0x10] - [this+0x18]. Returns [P] + 4*[P+4] + 0x10.
#include "ff.h"

typedef u32(THISCALL * call2r_fn)(void *, u32, u32);
typedef void (*hook_fn)(void);

// 0x4cf4b0 (C-set).
static u32 THISCALL unnamed4cf4b0(u8 *self, u32 *p) {
  if ((s32)*(u32 *)(self + 0xc) < 0) {
    u32 g = G(u32, 0x700390);
    u32 x = ((call2r_fn)(*(u32 *)(*(u32 *)g + 0x20)))((void *)g, 0x695b7cu, 0x1d9u);
    u32 vx = *(u32 *)x;
    u32 target = *(u32 *)(vx + 0x2c);
    asm volatile("push $0x695bc8\n\tpush %[x]\n\tcall *%[fn]\n\tadd $8, %%esp"
                 :
                 : "c"(vx), [x] "r"(x), [fn] "r"(target)
                 : "eax", "edx", "memory", "cc");
    u32 h = G(u32, 0x7003b0);
    if (h == 0)
      __builtin_trap();
    ((hook_fn)h)();
  }
  if (p[0] == 0)
    return 0;
  p[1] -= *(u32 *)(self + 0x18);
  if ((s32)p[1] < 0) {
    u32 nxt = *(u32 *)p[0];
    p[0] = nxt;
    if (nxt == 0)
      return 0;
    p[1] = *(u32 *)(self + 0x10) - *(u32 *)(self + 0x18);
  }
  return p[0] + p[1] * 4u + 0x10u;
}
PCREG(4cf4b0, unnamed4cf4b0);
