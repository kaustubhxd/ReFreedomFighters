// batch35140.cpp - cascade s5 batch 35140: 0x5f4a00 (GUESS index into one of two 8-byte-entry tables by a tagged id).
#include "ff.h"

typedef u32 (*hook_t)();

// 0x5f4a00, thiscall(a) ret 4, returns a pointer. a has bit 0x4000: i = zero-extended word [this+0xaa] + (s32)(s16)a (cwde sign-extends the low word of a); an index >= [this+0x3c] (unsigned) calls the assert hook
// 0x7003b0 (int3 when null); returns [this+0x34] + 8 * i. Otherwise i = (u16)~(a | 0x4000); i >= [this+0x30] calls the assert hook; returns [this+0x28] + 8 * i.
static u32 THISCALL fn5f4a00(u8 *self, u32 a) {
  if (a & 0x4000) {
    u32 i = (u32)*(u16 *)(self + 0xaa) + (u32)(s32)(s16)a;
    if (i >= *(u32 *)(self + 0x3c)) {
      hook_t h = G(hook_t, 0x7003b0);
      if (!h) __asm__ volatile("int3");
      h();
    }
    return *(u32 *)(self + 0x34) + i * 8;
  }
  u32 i = (u16)~(a | 0x4000);
  if (i >= *(u32 *)(self + 0x30)) {
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  return *(u32 *)(self + 0x28) + i * 8;
}
PCREG(5f4a00, fn5f4a00);
