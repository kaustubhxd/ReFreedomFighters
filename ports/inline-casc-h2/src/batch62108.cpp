#include "ff.h"
extern "C" void THISCALL ext_4d92d0(u8 *state);
extern "C" void ext_634273(u32 item, u32 flags);
static void THISCALL fn4d6880(u8 *self) {
  u32 saved_esi;
  asm volatile("movl %%esi, %0" : "=m"(saved_esi));
  ext_4d92d0(self + 4);
  u8 *list = self + 0xa;
  u32 valid = 0;
  vcall<void>(list, 0x4c, &valid);
  u32 item = vcall<u32>(list, 0x5c, &valid);
  while (valid) {
    ext_634273(item, 0x1e);
    item = vcall<u32>(list, 0x5c, &valid);
  }
  asm volatile("movl %0, %%esi" :: "m"(saved_esi) : "esi", "memory");
}
PCREG(4d6880, fn4d6880);
