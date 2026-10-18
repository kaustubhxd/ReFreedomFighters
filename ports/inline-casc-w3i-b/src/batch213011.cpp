#include "ff.h"

typedef u32(THISCALL *LogNew)(void *, u32, u32);

// 0x4e5f90: thiscall(this) -> float on st0: typed value at *this: tag byte & 0x3f; 1 = double at +1 (narrowed),
// 2 = float at +1, 3/8/10/11 = u32 at +1 converted to float (after logging through [0x700390]), else 0.0
float THISCALL fn_4e5f90(u8 **self) {
  u8 *p = *self;
  u32 i = (u32)(p[0] & 0x3f) - 1;
  if (i > 10) return 0.0f;
  static const u8 map[11] = {0, 1, 2, 3, 3, 3, 3, 2, 3, 2, 2};
  switch (map[i]) {
    case 0: {
      double d;
      __builtin_memcpy(&d, p + 1, 8);
      return (float)d;
    }
    case 1: {
      float f;
      __builtin_memcpy(&f, p + 1, 4);
      return f;
    }
    case 2: {
      void *L = G(void *, 0x700390);
      u8 *M = (u8 *)(*(LogNew *)(*(u8 **)L + 0x20))(L, 0x697464, 0x4e);
      u32 ra = *(u32 *)(*(u8 **)M + 0x2c), rc = *(u32 *)M;
      asm volatile(
          "pushl $0x69748c\n\t"
          "pushl %[m]\n\t"
          "call *%%eax\n\t"
          "addl $8, %%esp"
          : "+a"(ra), "+c"(rc)
          : [m] "r"(M)
          : "edx", "memory", "cc");
      u32 v;
      __builtin_memcpy(&v, *self + 1, 4);
      return (float)v;
    }
    default: return 0.0f;
  }
}
PCREG(4e5f90, fn_4e5f90);
