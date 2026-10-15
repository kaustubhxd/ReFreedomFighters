#include "ff.h"
extern "C" u32 THISCALL ext_5aeff0(void *self, u32 value);
extern "C" u32 THISCALL ext_5afe20(void *self, u32 value);
static u32 THISCALL fn5afdd0(u8 *self, u32 value) {
  u8 *collection = (u8 *)G(u32, self + 0x14);
  if (!collection) {
    u8 *logger = G(u8 *, 0x700390);
    u32 msg = vcall<u32>(logger, 0x20, 0x6b10bcu, 0x74u);
    u32 table = G(u32, (u8 *)msg);
    u32 target = G(u32, (u8 *)table + 0x2c);
    u32 label = 0x6b10f8u;
    asm volatile("pushl %3; pushl %2; movl %1, %%ecx; call *%0; addl $8, %%esp"
                 : : "r"(target), "r"(table), "r"(msg), "r"(label)
                 : "eax", "ecx", "edx", "memory", "cc");
    return 0;
  }
  if (!value) return 0;
  u32 index = ext_5aeff0(collection, value);
  return ext_5afe20(self, index);
}
PCREG(5afdd0, fn5afdd0);
