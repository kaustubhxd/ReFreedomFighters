#include "ff.h"

static u32 THISCALL fn5f3c40(u8 *self) {
  u8 state = G(u8, self + 4);
  if (state != 0 && state != 1) {
    u32 logger = G(u32, 0x700390);
    u32 msg = vcall<u32>((void *)logger, 0x20, 0x69c8e0u, 0x104u);
    u32 vt = G(u32, msg);
    u32 target = G(u32, vt + 0x2c);
    u32 ignored;
    asm volatile("push $0x69c938; push $0x69c6b0; push %[msg]; mov %[vt], %%ecx; call *%[target]; add $12, %%esp"
                 : "=a"(ignored)
                 : [msg] "r"(msg), [vt] "r"(vt), [target] "r"(target)
                 : "ecx", "edx", "memory", "cc");
    u32 assertion = G(u32, 0x7003b0);
    if (assertion) ((u32 (FASTCALL *)(void))assertion)();
  }
  return G(u32, self);
}

PCREG(5f3c40, fn5f3c40);
