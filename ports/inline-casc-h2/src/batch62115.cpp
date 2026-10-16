#include "ff.h"
extern "C" u32 STDCALL ext_49e140(u32 input, u8 *buffer);
typedef u32 (*cd3_t)(u32, u32, u32);
static u32 THISCALL fn49e070(u8 *self, u32 input) {
  u32 buffer = G(u32, self + 4);
  if (!buffer) return 0;
  u32 result = ext_49e140(input, (u8 *)buffer);
  if (!result) {
    u32 logger = G(u32, 0x700390);
    u32 msg = vcall<u32>((void *)logger, 0x20, 0x68f018u, 0xddu);
    u32 vt = G(u32, msg);
    u32 target = G(u32, vt + 0x30);
    asm volatile("push %[input]; push $0x68f040; push %[msg]; mov %[vt], %%ecx; call *%[target]; add $12, %%esp"
                 : : [input] "r"(input), [msg] "r"(msg), [vt] "r"(vt), [target] "r"(target)
                 : "eax", "ecx", "edx", "memory", "cc");
    return 0;
  }
  return (*(u8 *)result & 1) ? result + 1 : 0x677b5a;
}
PCREG(49e070, fn49e070);
