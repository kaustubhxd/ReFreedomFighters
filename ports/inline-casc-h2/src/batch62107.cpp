#include "ff.h"
extern "C" void ext_634273(u32 item, u32 flags);
static void THISCALL fn4cdcc0(u8 *self) {
  u32 saved_esi;
  asm volatile("movl %%esi, %0" : "=m"(saved_esi));
  u32 valid = 0;
  vcall<void>(self, 0x4c, &valid);
  u32 item = vcall<u32>(self, 0x5c, &valid);
  while (valid) {
    ext_634273(item, 1);
    item = vcall<u32>(self, 0x5c, &valid);
  }
  *(u32 *)(self + 0xc) |= 0x80000000;
  asm volatile("movl %0, %%esi" :: "m"(saved_esi) : "esi", "memory");
}
PCREG(4cdcc0, fn4cdcc0);
