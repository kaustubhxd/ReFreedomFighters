#include "ff.h"
extern "C" u32 THISCALL ext_5003d0(void *self, u32 zero);
static void THISCALL fn503710(u8 *self, u8 *arg) {
  u32 parsed = ext_5003d0((u8 *)G(u32, arg + 4), 0);
  u8 *sys = (u8 *)g_pSysInterface;
  u32 value = G(u32, (u8 *)parsed);
  u32 found = vcall<u32>(*(u8 **)(sys + 0x9b), 0x58, value);
  if (found) { G(u32, self + 0xc) = found; return; }
  u8 *logger = G(u8 *, 0x700390);
  u32 msg = vcall<u32>(logger, 0x20, 0x69ca10u, 0xaau);
  u32 dispatch = G(u32, (u8 *)msg);
  u32 target = G(u32, (u8 *)dispatch + 0x2c);
  u32 label = 0x69ca50u;
  asm volatile("pushl %3; pushl %2; movl %1, %%ecx; call *%0; addl $8, %%esp"
               : : "r"(target), "r"(dispatch), "r"(msg), "r"(label)
               : "eax", "ecx", "edx", "memory", "cc");
}
PCREG(503710, fn503710);
