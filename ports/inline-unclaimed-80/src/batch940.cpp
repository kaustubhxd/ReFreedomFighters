#include "ff.h"
// batch940.cpp - unclaimed-80 (docs/20-unclaimed-80.md). ZGROUP::GetAmbientSettings(const float*, float*, float*, float*) const (0x440900,
// GC map name, high). Thiscall, four stack arguments that are not read (ret 16), returns al = 0.
//   Y = (global 0x700390) slot +0x20 with (0x67cbbc, 0xb2) (thiscall, callee-cleaned).
//   then Y's vtable slot +0x2c with (Y, 0x67cbe4) where ecx is the vtable pointer of Y and the caller cleans the two arguments (add esp,8).
// The second call is written in inline asm to keep ecx = vtable and the caller-cleaned convention.

static u8 THISCALL getAmbientSettings(u8 *self, u32 a, u32 b, u32 c, u32 d) {
  (void)self; (void)a; (void)b; (void)c; (void)d;
  typedef u8 *(THISCALL * y_fn)(u8 *, u32, u32);
  u8 *g = G(u8 *, 0x700390);
  u8 *y = ((y_fn)(*(u32 *)(*(u32 *)g + 0x20)))(g, 0x67cbbcu, 0xb2u);
  u32 vt = *(u32 *)y;
  u32 fn = *(u32 *)(vt + 0x2c);
  u32 arg = 0x67cbe4u;
  __asm__ volatile("pushl %[arg]\n\tpushl %[y]\n\tcall *%[fn]\n\taddl $8, %%esp"
                   :
                   : "c"(vt), [arg] "r"(arg), [y] "r"((u32)y), [fn] "r"(fn)
                   : "eax", "edx", "memory", "cc");
  return 0;
}
PCREG(440900, getAmbientSettings);
