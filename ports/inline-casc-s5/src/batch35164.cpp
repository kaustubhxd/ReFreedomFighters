// batch35164.cpp - cascade s5 batch 35164: 0x4d2e50 (GUESS read a stored value by id into a byte flag, logging a record that lacks the flag).
#include "ff.h"

extern "C" void ext_634d22(void *dst, const void *src, u32 n);   // cdecl memcpy
typedef u8 *(THISCALL *f2_t)(void *, u32, u32);

// 0x4d2e50, thiscall(a, p) ret 8, returns the stored size n. local = *p (byte); r = this slot 0xb0(a, 0). Null: n = 0 (local stays). Else when bit 0 of [[r+4]+0x10] is clear the logger (0x700390) slot 0x24(logger, 0x696394, a) is called with ECX = the
// vtable, caller-popped; n = [r+8]; memcpy(&local, r + [r] + 0xc, n); finally *p = (local != 0), returns n.
static u32 THISCALL fn4d2e50(u8 *self, u32 a, u8 *p) {
  u32 local = *p;
  u32 n;
  u8 *r = (*(f2_t **)self)[0xb0 / 4](self, a, 0);
  if (!r) {
    n = 0;
  } else {
    if (!(*(u8 *)(*(u8 **)(r + 4) + 0x10) & 1)) {
      u8 *lg = G(u8 *, 0x700390);
      u32 vt = *(u32 *)lg;
      u32 slot = ((u32 *)vt)[0x24 / 4];
      asm volatile("push %[a]\n\tpush $0x696394\n\tpush %[lg]\n\tcall *%[fn]\n\tadd $12, %%esp" : : "c"(vt), [a] "r"(a), [lg] "r"(lg), [fn] "r"(slot) : "eax", "edx", "memory", "cc");
    }
    n = *(u32 *)(r + 8);
    ext_634d22(&local, r + *(u32 *)r + 0xc, n);
  }
  *p = local != 0;
  return n;
}
PCREG(4d2e50, fn4d2e50);
