// batch42008.cpp - Sonnet t3: tier H, no callees.
#include "ff.h"

typedef u32 __attribute__((aligned(1))) u32u;
typedef u16 __attribute__((aligned(1))) u16u;

// 0x5ec090, thiscall(w, h) ret 8: when (w, h) differs from the cached pair at +0x6e/+0x72: store them, then for each of the [+0x3e] entries of the
// pointer array at [+0x62] whose words +0x28/+0x2a differ: store the words, +8 = float(w) / float(word +4), +0xc = float(h) / float(word +6), byte +0xa6 = 1.
static void THISCALL fn5ec090(u8 *self, u32 w, u32 h) {
  if (*(u32u *)(self + 0x6e) == w && *(u32u *)(self + 0x72) == h) return;
  *(u32u *)(self + 0x6e) = w;
  *(u32u *)(self + 0x72) = h;
  for (u32 i = 0; i < *(u32u *)(self + 0x3e); i++) {
    u8 *e = (*(u8 ***)(self + 0x62))[i];
    if ((u32) * (u16u *)(e + 0x28) == w && (u32) * (u16u *)(e + 0x2a) == h) continue;
    u32 a = *(u16u *)(e + 4);
    *(u16u *)(e + 0x28) = (u16)w;
    *(u16u *)(e + 0x2a) = (u16)h;
    u32 b = *(u16u *)(e + 6);
    *(float *)(e + 8) = (float)(s32)w / (float)(s32)a;
    *(float *)(e + 0xc) = (float)(s32)h / (float)(s32)b;
    self[0xa6] = 1;
  }
}
PCREG(5ec090, fn5ec090);
