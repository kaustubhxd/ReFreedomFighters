#include "ff.h"

extern "C" u32 THISCALL ext_54f2b0(u8 *self);

static u32 THISCALL fn54c750(u8 *self, u8 *arg) {
  s32 value = G(s32, arg + 0x70);
  if (value < -0x2710) value = -0x2710;
  if (value > 0x2710) value = 0x2710;
  u32 object = G(u32, self + 0x63ec);
  u8 *object_vt = (u8 *)G(u32, object);
  u32 target = G(u32, object_vt + 0x40);
  u32 result;
  asm volatile("push %[value]; push %[object]; mov %[vt], %%ecx; call *%[target]"
               : "=a"(result)
               : [value] "r"(value), [object] "r"(object), [vt] "r"(object_vt), [target] "r"(target)
               : "ecx", "edx", "memory", "cc");
  return (s32)result < 0 ? ext_54f2b0((u8 *)result) : result;
}

PCREG(54c750, fn54c750);
